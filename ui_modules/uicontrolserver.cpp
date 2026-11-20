/***************************************************************************
 *   Copyright (C) 2025 by Abderrahman Taha                                *
 *                                                                         *
 *   This program is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                          *
 *   Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,       *
 *   Boston, MA 02110-1301 USA.                                            *
 ***************************************************************************/

#include "uicontrolserver.h"
#include "drawingoptions.h"

#include <QApplication>
#include <QComboBox>
#include <QDir>
#include <QFile>
#include <QImage>
#include <QJsonArray>
#include <QJsonDocument>
#include <QListWidget>
#include <QProgressBar>
#include <QScrollBar>
#include <QTextEdit>

namespace
{
const int kDefaultPort = 61234;
const int kMaxPendingBytes = 1024 * 1024; // 1 MiB request cap

quint16 resolvePort()
{
    // qgetenv keeps this portable across Qt 5 / Qt 6 (the
    // qEnvironmentVariableIntValue signature changed between versions).
    const QByteArray v = qgetenv("MATHMOD_UI_PORT");
    if (!v.isEmpty())
    {
        bool ok = false;
        const int p = v.toInt(&ok);
        if (ok && p > 0 && p < 65536)
            return quint16(p);
    }
    return kDefaultPort;
}

QJsonObject errJson(const QString &msg)
{
    QJsonObject o;
    o["status"] = "error";
    o["error"] = msg;
    return o;
}
} // namespace

UiControlServer::UiControlServer(DrawingOptions *win, QObject *parent)
    : QObject(parent), m_win(win)
{
    m_port = resolvePort();
    m_server.listen(QHostAddress::LocalHost, m_port);
    if (m_server.isListening())
    {
        qInfo().noquote()
            << "[MathMod UI control] API listening on http://127.0.0.1:"
            << m_port;
        connect(&m_server, &QTcpServer::newConnection,
                this, &UiControlServer::onNewConnection);
    }
    else
    {
        qWarning().noquote()
            << "[MathMod UI control] could not listen on 127.0.0.1:"
            << m_port << "->" << m_server.errorString()
            << "(control API disabled; set MATHMOD_UI_PORT to another port)";
    }
}

UiControlServer::~UiControlServer()
{
    m_server.close();
}

void UiControlServer::onNewConnection()
{
    while (QTcpSocket *socket = m_server.nextPendingConnection())
    {
        m_pending.insert(socket, QByteArray());
        connect(socket, &QTcpSocket::readyRead,
                this, &UiControlServer::onSocketReadyRead);
        connect(socket, &QTcpSocket::disconnected,
                this, &UiControlServer::onSocketDisconnected);
    }
}

void UiControlServer::onSocketReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (!socket || !m_pending.contains(socket))
        return;

    QByteArray &buf = m_pending[socket];
    buf += socket->readAll();

    if (buf.size() > kMaxPendingBytes)
    {
        writeResponse(socket, 413,
                      QJsonDocument(errJson("request too large")).toJson(QJsonDocument::Compact));
        m_pending.remove(socket);
        socket->disconnectFromHost();
        return;
    }

    const int headerEnd = buf.indexOf("\r\n\r\n");
    if (headerEnd < 0)
        return; // headers not complete yet

    int contentLength = 0;
    const QList<QByteArray> headerLines = buf.left(headerEnd).split('\n');
    for (int i = 1; i < headerLines.size(); ++i)
    {
        const QByteArray line = headerLines[i].trimmed(); // drops the '\r'
        const int colon = line.indexOf(':');
        if (colon <= 0)
            continue;
        if (line.left(colon).compare("Content-Length", Qt::CaseInsensitive) == 0)
        {
            contentLength = line.mid(colon + 1).trimmed().toInt();
            break;
        }
    }
    if (contentLength < 0)
        contentLength = 0;

    const int bodyStart = headerEnd + 4;
    if (buf.size() < bodyStart + contentLength)
        return; // body not complete yet

    const QByteArray request = buf.left(bodyStart + contentLength);
    buf.remove(0, bodyStart + contentLength);

    handleRequest(socket, request);
    // One request per connection: close after the response.
    socket->disconnectFromHost();
}

void UiControlServer::onSocketDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (!socket)
        return;
    m_pending.remove(socket);
    socket->deleteLater();
}

void UiControlServer::writeResponse(QTcpSocket *socket, int code,
                                    const QByteArray &body)
{
    static const QByteArray kStatusTexts[] = {
        "", "Bad Request", "Unauthorized", "Forbidden", "Not Found",
        "Method Not Allowed", "Internal Server Error", "No Content"};
    QByteArray resp;
    resp += "HTTP/1.1 ";
    resp += QByteArray::number(code);
    resp += " ";
    if (code >= 1 && code < int(sizeof(kStatusTexts) / sizeof(kStatusTexts[0]))
            && !kStatusTexts[code].isEmpty())
        resp += kStatusTexts[code];
    resp += "\r\nContent-Type: application/json\r\n";
    resp += "Content-Length: " + QByteArray::number(body.size()) + "\r\n";
    resp += "Connection: close\r\n\r\n";
    resp += body;
    socket->write(resp);
}

void UiControlServer::handleRequest(QTcpSocket *socket,
                                    const QByteArray &request)
{
    const QList<QByteArray> lines = request.split('\n');
    if (lines.isEmpty())
        return;
    const QList<QByteArray> parts = lines.first().trimmed().split(' ');
    const QByteArray method = parts.value(0);
    const QByteArray rawPath = parts.value(1);
    const QString path = QString::fromUtf8(rawPath).section('?', 0, 0);
    const int bodyStart = request.indexOf("\r\n\r\n") + 4;
    const QByteArray body = request.mid(bodyStart);

    if (method == "GET" && (path == "/" || path == "/health"))
    {
        QJsonObject info;
        info["app"] = "MathMod";
        info["ok"] = true;
        info["port"] = int(m_port);
        writeResponse(socket, 200, QJsonDocument(info).toJson(QJsonDocument::Compact));
        return;
    }

    if (method == "GET" && path == "/state")
    {
        writeResponse(socket, 200,
                      QJsonDocument(stateSnapshot()).toJson(QJsonDocument::Compact));
        return;
    }

    if (method == "POST" && path == "/action")
    {
        QJsonParseError err;
        const QJsonObject req =
            QJsonDocument::fromJson(body, &err).object();
        if (err.error != QJsonParseError::NoError)
        {
            writeResponse(socket, 400,
                          QJsonDocument(errJson("invalid JSON body: " + err.errorString()))
                              .toJson(QJsonDocument::Compact));
            return;
        }
        const QString action = req["action"].toString();
        if (action.isEmpty())
        {
            writeResponse(socket, 400,
                          QJsonDocument(errJson("missing \"action\" field"))
                              .toJson(QJsonDocument::Compact));
            return;
        }
        const QJsonObject params = req["params"].toObject();
        QJsonObject result = dispatchAction(action, params);
        const bool ok = result.value("status").toString() != "error";
        writeResponse(socket, ok ? 200 : 400,
                      QJsonDocument(result).toJson(QJsonDocument::Compact));
        return;
    }

    writeResponse(socket, 404,
                  QJsonDocument(errJson("unknown endpoint or method"))
                      .toJson(QJsonDocument::Compact));
}

// ---------------------------------------------------------------------------
// /state
// ---------------------------------------------------------------------------

QJsonObject UiControlServer::stateSnapshot() const
{
    DrawingOptions *win = m_win;
    QJsonObject st;
    st["app"] = "MathMod";
    st["window_title"] = win->windowTitle();

    // Model combo ("choice"): item 0 is the "Examples (N)" header row.
    QJsonArray models;
    for (int i = 0; i < win->ui.choice->count(); ++i)
        models.append(win->ui.choice->itemText(i));
    st["models"] = models;
    st["current_model"] = win->ui.choice->currentText();

    st["script_editor"] = win->ui.ScriptEditor->toPlainText();

    // Model sliders (C1..C20 groups that are active, i.e. not explicitly
    // hidden by HideSliders()). isHidden() rather than isVisible() because
    // the group boxes live inside a tab page that may not be the current
    // one (isVisible() would then report false even for active sliders).
    QJsonArray sliders;
    const int nb = win->MathmodRef->IsoObjet->masterthread->Nb_Sliders;
    for (int i = 0; i < 20 && i < int(nb); ++i)
    {
        if (win->SliderArray[i].SliderGroupeBox->isHidden())
            continue;
        QJsonObject s;
        s["name"] =
            QString::fromStdString(win->MathmodRef->IsoObjet->masterthread->SliderNames[i]);
        s["value"] = win->SliderArray[i].SliderScrollBar->value();
        s["min"] = win->SliderArray[i].SliderScrollBar->minimum();
        s["max"] = win->SliderArray[i].SliderScrollBar->maximum();
        sliders.append(s);
    }
    st["sliders"] = sliders;

    // Parameters list box (item 0 is the header row).
    QJsonArray parameters;
    for (int i = 1; i < win->ui.ParametersList->count(); ++i)
        parameters.append(win->ui.ParametersList->itemText(i));
    st["parameters"] = parameters;

    st["message"] = win->ui.Messagetext->toPlainText();
    st["iso_message"] = win->MathmodRef->IsoObjet->message;
    st["par_message"] = win->MathmodRef->ParObjet->message;
    st["computing_iso"] = win->MathmodRef->IsoObjet->isRunning();
    st["computing_par"] = win->MathmodRef->ParObjet->isRunning();
    st["progress"] = win->ui.progressBar->value();

    st["t"] = win->ui.TimeStepScrollBar->value();
    st["t_min"] = win->ui.TimeStepScrollBar->minimum();
    st["t_max"] = win->ui.TimeStepScrollBar->maximum();

    QJsonObject threads;
    threads["value"] = win->ui.ThreadNumberScrollBar->value();
    threads["min"] = win->ui.ThreadNumberScrollBar->minimum();
    threads["max"] = win->ui.ThreadNumberScrollBar->maximum();
    st["threads"] = threads;

    QJsonObject viewport;
    viewport["xgrid"] = int(win->MathmodRef->Xgrid);
    viewport["ygrid"] = int(win->MathmodRef->Ygrid);
    viewport["zgrid"] = int(win->MathmodRef->Zgrid);
    viewport["ugrid"] = int(win->MathmodRef->Ugrid);
    viewport["vgrid"] = int(win->MathmodRef->Vgrid);
    viewport["box_min"] = QJsonArray({win->MathmodRef->BoxMinX,
                                      win->MathmodRef->BoxMinY,
                                      win->MathmodRef->BoxMinZ});
    viewport["box_max"] = QJsonArray({win->MathmodRef->BoxMaxX,
                                      win->MathmodRef->BoxMaxY,
                                      win->MathmodRef->BoxMaxZ});
    st["viewport"] = viewport;

    // Component combo boxes and the current model's component names.
    st["iso_component"] = win->ui.IsoComponent->currentText();
    st["param_component"] = win->ui.ParamComponent->currentText();
    QJsonArray components;
    const QJsonObject cur = win->MathmodRef->RootObjet.CurrentJsonObject;
    const QJsonObject surf =
        cur["Iso3D"].isObject() ? cur["Iso3D"].toObject()
        : cur["Param3D"].isObject() ? cur["Param3D"].toObject()
        : cur["Param4D"].isObject() ? cur["Param4D"].toObject()
        : cur["Param3D_C"].isObject() ? cur["Param3D_C"].toObject()
        : cur["Param4D_C"].isObject() ? cur["Param4D_C"].toObject()
        : QJsonObject();
    const QJsonArray compArray = surf["Component"].toArray();
    for (const QJsonValue &v : compArray)
        components.append(v.toString());
    st["components"] = components;

    // Predefined slider sets (item 0 is the "Predefined Sets (N)" header).
    QJsonArray sets;
    for (int i = 1; i < win->ui.PredefinedSets->count(); ++i)
        sets.append(win->ui.PredefinedSets->itemText(i));
    st["predefined_sets"] = sets;

    // View toggles (1 = on, -1 = off).
    st["axes_on"] = win->MathmodRef->LocalScene.axe > 0;
    st["planes_on"] = win->MathmodRef->LocalScene.plan > 0;
    st["boundingbox_on"] = win->MathmodRef->LocalScene.boundingbox > 0;

    // Grid resolution sliders.
    st["iso_grid"] = win->ui.xyzg->value();
    st["iso_grid_min"] = win->ui.xyzg->minimum();
    st["iso_grid_max"] = win->ui.xyzg->maximum();
    st["param_grid"] = win->ui.linecolumn_2->value();
    st["param_grid_min"] = win->ui.linecolumn_2->minimum();
    st["param_grid_max"] = win->ui.linecolumn_2->maximum();

    st["scale"] = QJsonArray({win->MathmodRef->factx,
                               win->MathmodRef->facty,
                               win->MathmodRef->factz});

    // Undo/redo history of model states.
    QJsonObject history;
    history["index"] = win->MathmodRef->RootObjet.IndexCurrentJsonObject;
    history["size"] = win->MathmodRef->RootObjet.PreviousJsonObject.size();
    st["undo_history"] = history;

    // Visible top-level windows (main window + dialogs).
    QJsonArray windows;
    const QList<QWidget *> topLevel = qApp->topLevelWidgets();
    for (QWidget *w : topLevel)
    {
        if (!w->isVisible())
            continue;
        windows.append(w->objectName().isEmpty()
                           ? QString(w->metaObject()->className())
                           : w->objectName());
    }
    st["windows"] = windows;

    return st;
}

// ---------------------------------------------------------------------------
// /action
// ---------------------------------------------------------------------------

int UiControlServer::findSliderIndex(const QString &name) const
{
    const int nb = m_win->MathmodRef->IsoObjet->masterthread->Nb_Sliders;
    for (int i = 0; i < nb && i < 20; ++i)
    {
        if (QString::fromStdString(
                m_win->MathmodRef->IsoObjet->masterthread->SliderNames[i]) == name)
            return i;
    }
    return -1;
}

QJsonObject UiControlServer::dispatchAction(const QString &action,
                                            const QJsonObject &params)
{
    DrawingOptions *win = m_win;
    QJsonObject out;

    if (action == "select_model")
    {
        const QString wanted = params["name"].toString();
        if (wanted.isEmpty())
            return errJson("params.name is required");
        QComboBox *cb = win->ui.choice;
        int idx = cb->findText(wanted);
        if (idx < 0)
        {
            for (int i = 0; i < cb->count(); ++i)
                if (cb->itemText(i).compare(wanted, Qt::CaseInsensitive) == 0)
                {
                    idx = i;
                    break;
                }
        }
        if (idx < 0)
        {
            QJsonObject e = errJson("model not found: " + wanted);
            QJsonArray avail;
            for (int i = 0; i < cb->count(); ++i)
                avail.append(cb->itemText(i));
            e["models"] = avail;
            return e;
        }
        cb->setCurrentIndex(idx);
        win->on_choice_activated(cb->itemText(idx));
        out["status"] = "ok";
        out["selected"] = cb->itemText(idx);
        return out;
    }

    if (action == "run")
    {
        win->on_calculate_clicked();
        out["status"] = "ok";
        out["message"] = "calculation started; poll GET /state for progress";
        return out;
    }

    if (action == "stop")
    {
        win->on_StopCalculationsButton_clicked();
        out["status"] = "ok";
        return out;
    }

    if (action == "set_slider")
    {
        const QString name = params["name"].toString();
        if (name.isEmpty() || !params.contains("value"))
            return errJson("params.name and params.value are required");
        const QJsonValue v = params["value"];
        const int iv = v.isDouble() ? int(v.toDouble()) : v.toString().toInt();
        const int idx = findSliderIndex(name);
        if (idx < 0)
        {
            QJsonObject e = errJson("slider not found: " + name);
            QJsonArray names;
            const int nb = win->MathmodRef->IsoObjet->masterthread->Nb_Sliders;
            for (int i = 0; i < nb && i < 20; ++i)
                names.append(QString::fromStdString(
                    win->MathmodRef->IsoObjet->masterthread->SliderNames[i]));
            e["sliders"] = names;
            return e;
        }
        win->SliderArray[idx].SliderScrollBar->setValue(iv);
        out["status"] = "ok";
        out["name"] = name;
        out["value"] = win->SliderArray[idx].SliderScrollBar->value();
        return out;
    }

    if (action == "set_t")
    {
        if (!params.contains("value"))
            return errJson("params.value is required");
        const int iv = params["value"].toInt();
        win->ui.TimeStepScrollBar->setValue(iv);
        out["status"] = "ok";
        out["t"] = win->ui.TimeStepScrollBar->value();
        return out;
    }

    if (action == "set_threads")
    {
        if (!params.contains("value"))
            return errJson("params.value is required");
        const int iv = params["value"].toInt();
        win->ui.ThreadNumberScrollBar->setValue(iv);
        out["status"] = "ok";
        out["threads"] = win->ui.ThreadNumberScrollBar->value();
        return out;
    }

    if (action == "fill_editor")
    {
        const QString text = params["text"].toString();
        if (text.isEmpty())
            return errJson("params.text is required");
        win->ui.ScriptEditor->setPlainText(text);
        out["status"] = "ok";
        out["chars"] = int(text.size());
        return out;
    }

    if (action == "load_file")
    {
        const QString path = params["path"].toString();
        if (path.isEmpty() || !QFile::exists(path))
            return errJson("params.path is required and the file must exist");
        if (!win->LoadCollectionFileDirect(path))
            return errJson("failed to load collection file: " + path);
        out["status"] = "ok";
        out["file"] = path;
        out["model_count"] = win->ui.choice->count() - 1; // minus "Examples" row
        return out;
    }

    if (action == "screenshot")
    {
        QString path = params["path"].toString();
        if (path.isEmpty())
            path = QDir::tempPath() + "/mathmod_ui_screenshot.png";
        const QImage img = win->MathmodRef->Copyscreenshot();
        if (img.isNull())
            return errJson("screenshot failed (GL framebuffer unavailable)");
        if (!img.save(path, "PNG"))
            return errJson("failed to write screenshot to: " + path);
        out["status"] = "ok";
        out["path"] = path;
        out["width"] = img.width();
        out["height"] = img.height();
        return out;
    }

    if (action == "open_dialog")
    {
        const QString which = params["which"].toString();
        if (which == "editor")
            win->editorwin();
        else if (which == "select_options")
            win->select.show();
        else if (which == "add_param")
            win->on_AddParam_clicked();
        else if (which == "about")
            win->ab.show();
        else
            return errJson("params.which must be one of: editor, select_options, "
                           "add_param, about");
        out["status"] = "ok";
        out["dialog"] = which;
        return out;
    }

    if (action == "toggle_object_tree")
    {
        win->on_TreeViewButton_clicked();
        out["status"] = "ok";
        return out;
    }

    if (action == "animate")
    {
        win->MathmodRef->anim();
        out["status"] = "ok";
        return out;
    }

    if (action == "morph")
    {
        win->MathmodRef->morph();
        out["status"] = "ok";
        return out;
    }

    if (action == "toggle_axes")
    {
        win->on_actionAxe_triggered();
        out["status"] = "ok";
        out["axes_on"] = win->MathmodRef->LocalScene.axe > 0;
        return out;
    }

    if (action == "toggle_planes")
    {
        win->on_actionPlan_triggered();
        out["status"] = "ok";
        out["planes_on"] = win->MathmodRef->LocalScene.plan > 0;
        return out;
    }

    if (action == "toggle_bounding_box")
    {
        // The slot is private; triggering the menu QAction is equivalent.
        win->ui.actionbox->trigger();
        out["status"] = "ok";
        out["boundingbox_on"] = win->MathmodRef->LocalScene.boundingbox > 0;
        return out;
    }

    if (action == "render_mode")
    {
        const QString mode = params["mode"].toString().toLower();
        if (mode == "triangles")
            win->MathmodRef->slot_triangles_clicked();
        else if (mode == "normals")
            win->MathmodRef->draw_norm_clicked();
        else if (mode == "fill")
            win->MathmodRef->fill();
        else if (mode == "mesh")
            win->MathmodRef->Mesh();
        else
            return errJson("params.mode must be one of: triangles, normals, fill, mesh");
        out["status"] = "ok";
        out["mode"] = mode;
        return out;
    }

    if (action == "toggle_uv")
    {
        win->on_uv_clicked();
        out["status"] = "ok";
        return out;
    }

    if (action == "toggle_uv4d")
    {
        win->on_uv4D_clicked();
        out["status"] = "ok";
        return out;
    }

    if (action == "undo")
    {
        if (win->MathmodRef->RootObjet.IndexCurrentJsonObject <= 0)
            return errJson("nothing to undo (history is empty)");
        win->ui.actionUndo->trigger(); // private slot; menu action equivalent
        out["status"] = "ok";
        out["history_index"] = win->MathmodRef->RootObjet.IndexCurrentJsonObject;
        out["history_size"] = win->MathmodRef->RootObjet.PreviousJsonObject.size();
        return out;
    }

    if (action == "redo")
    {
        const int idx = win->MathmodRef->RootObjet.IndexCurrentJsonObject;
        if (idx >= win->MathmodRef->RootObjet.PreviousJsonObject.size() - 1)
            return errJson("nothing to redo (already at newest state)");
        win->ui.actionRedo->trigger(); // private slot; menu action equivalent
        out["status"] = "ok";
        out["history_index"] = win->MathmodRef->RootObjet.IndexCurrentJsonObject;
        out["history_size"] = win->MathmodRef->RootObjet.PreviousJsonObject.size();
        return out;
    }

    if (action == "clear_history")
    {
        win->ui.actionClear->trigger(); // private slot; menu action equivalent
        out["status"] = "ok";
        return out;
    }

    if (action == "select_component")
    {
        const QString wanted = params["name"].toString();
        const QString side = params["side"].toString().toLower(); // "" | "iso" | "param"
        if (wanted.isEmpty())
            return errJson("params.name (component name or index) is required");
        QComboBox *isoCb = win->ui.IsoComponent;
        QComboBox *parCb = win->ui.ParamComponent;
        auto findByText = [](QComboBox *cb, const QString &t) -> int {
            int i = cb->findText(t);
            if (i < 0)
                for (int k = 0; k < cb->count(); ++k)
                    if (cb->itemText(k).compare(t, Qt::CaseInsensitive) == 0)
                    {
                        i = k;
                        break;
                    }
            return i;
        };
        int idx = -1;
        bool isoSide = false;
        // 1) by name (exact, then case-insensitive)
        if (side != "param")
        {
            idx = findByText(isoCb, wanted);
            if (idx >= 0)
                isoSide = true;
        }
        if (idx < 0 && side != "iso")
        {
            idx = findByText(parCb, wanted);
            if (idx >= 0)
                isoSide = false;
        }
        // 2) by numeric index
        if (idx < 0)
        {
            bool okNum = false;
            const int iv = wanted.toInt(&okNum);
            if (okNum)
            {
                if (side == "param" && iv >= 0 && iv < parCb->count())
                {
                    idx = iv;
                    isoSide = false;
                }
                else if (side == "iso" && iv >= 0 && iv < isoCb->count())
                {
                    idx = iv;
                    isoSide = true;
                }
                else if (isoCb->count() > 0 && iv < isoCb->count())
                {
                    idx = iv;
                    isoSide = true;
                }
                else if (parCb->count() > 0 && iv < parCb->count())
                {
                    idx = iv;
                    isoSide = false;
                }
            }
        }
        if (idx < 0)
        {
            QJsonObject e = errJson("component not found: " + wanted);
            QJsonArray avail;
            for (int i = 0; i < isoCb->count(); ++i)
                avail.append("iso:" + isoCb->itemText(i));
            for (int i = 0; i < parCb->count(); ++i)
                avail.append("param:" + parCb->itemText(i));
            e["components"] = avail;
            return e;
        }
        if (isoSide)
            win->on_IsoComponent_activated(idx);
        else
            win->on_ParamComponent_activated(idx);
        out["status"] = "ok";
        out["side"] = isoSide ? "iso" : "param";
        out["index"] = idx;
        out["component"] = (isoSide ? isoCb : parCb)->itemText(idx);
        return out;
    }

    if (action == "toggle_component_visibility")
    {
        // A model's top-level object carries exactly one surface block
        // (ParIso models wrap theirs in a "ParIso" array and use the iso side).
        const QJsonObject &cur = win->MathmodRef->RootObjet.CurrentJsonObject;
        const bool parSide = cur["Param3D"].isObject() || cur["Param4D"].isObject()
                             || cur["Param3D_C"].isObject() || cur["Param4D_C"].isObject();
        if (parSide)
            win->on_ShowParComp_clicked();
        else
            win->on_ShowIsoComp_clicked();
        out["status"] = "ok";
        // Button text is "Hide" while the component is visible.
        out["iso_button"] = win->ui.ShowIsoComp->text();
        out["param_button"] = win->ui.ShowParComp->text();
        return out;
    }

    if (action == "apply_slider_set")
    {
        const QString wanted = params["name"].toString();
        QComboBox *cb = win->ui.PredefinedSets;
        int idx = -1;
        if (!wanted.isEmpty())
        {
            idx = cb->findText(wanted);
            if (idx < 0)
                for (int i = 0; i < cb->count(); ++i)
                    if (cb->itemText(i).compare(wanted, Qt::CaseInsensitive) == 0)
                    {
                        idx = i;
                        break;
                    }
            if (idx < 0) // maybe a 1-based set number
            {
                bool okNum = false;
                const int n = wanted.toInt(&okNum);
                if (okNum && n >= 1 && n < cb->count())
                    idx = n;
            }
        }
        if (idx <= 0)
        {
            QJsonObject e = errJson("slider set not found: " + wanted +
                                    " (combo index 0 is the list header)");
            QJsonArray avail;
            for (int i = 1; i < cb->count(); ++i)
                avail.append(cb->itemText(i));
            e["sets"] = avail;
            return e;
        }
        win->on_PredefinedSets_activated(idx);
        out["status"] = "ok";
        out["set"] = cb->itemText(idx);
        return out;
    }

    if (action == "set_iso_grid")
    {
        if (!params.contains("value"))
            return errJson("params.value is required");
        const int iv = params["value"].toInt();
        win->ui.xyzg->setValue(iv); // triggers on_xyzg_valueChanged
        out["status"] = "ok";
        out["iso_grid"] = win->ui.xyzg->value();
        out["note"] = win->MathmodRef->IsoObjet->isRunning()
                          ? "iso computation is running; value may be discarded by the app until it finishes"
                          : "applied (triggers recomputation)";
        return out;
    }

    if (action == "set_param_grid")
    {
        if (!params.contains("value"))
            return errJson("params.value is required");
        const int iv = params["value"].toInt();
        win->ui.linecolumn_2->setValue(iv); // sets both u and v resolution
        out["status"] = "ok";
        out["param_grid"] = win->ui.linecolumn_2->value();
        out["note"] = win->MathmodRef->ParObjet->isRunning()
                          ? "param computation is running; value may be discarded by the app until it finishes"
                          : "applied (triggers recomputation)";
        return out;
    }

    if (action == "reset_t")
    {
        win->ui.TimeStepScrollBar->setValue(win->ui.TimeStepScrollBar->minimum());
        out["status"] = "ok";
        out["t"] = win->ui.TimeStepScrollBar->value();
        return out;
    }

    if (action == "set_scale")
    {
        if (!params.contains("x") || !params.contains("y") || !params.contains("z"))
            return errJson("params.x, params.y and params.z are required");
        const double fx = params["x"].toDouble();
        const double fy = params["y"].toDouble();
        const double fz = params["z"].toDouble();
        win->ui.lineEditSx->setText(QString::number(fx));
        win->ui.lineEditSy->setText(QString::number(fy));
        win->ui.lineEditSz->setText(QString::number(fz));
        win->on_ScaleButton_clicked();
        out["status"] = "ok";
        out["scale"] = QJsonArray({win->MathmodRef->factx,
                                    win->MathmodRef->facty,
                                    win->MathmodRef->factz});
        return out;
    }

    if (action == "init_matrix")
    {
        // Resets the 4D rotation matrix and restarts the calculation.
        win->on_InitMatrix_clicked();
        out["status"] = "ok";
        out["message"] = "4D matrix reset; calculation restarted";
        return out;
    }

    QJsonObject e = errJson("unknown action: " + action);
    e["actions"] = QJsonArray({"select_model", "run", "stop", "set_slider",
                               "set_t", "set_threads", "fill_editor",
                               "load_file", "screenshot", "open_dialog",
                               "toggle_object_tree", "animate", "morph",
                               "toggle_axes", "toggle_planes",
                               "toggle_bounding_box", "render_mode",
                               "toggle_uv", "toggle_uv4d", "undo", "redo",
                               "clear_history", "select_component",
                               "toggle_component_visibility",
                               "apply_slider_set", "set_iso_grid",
                               "set_param_grid", "reset_t", "set_scale",
                               "init_matrix"});
    return e;
}
