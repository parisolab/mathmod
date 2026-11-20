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

#ifndef UICONTROLSERVER_H
#define UICONTROLSERVER_H

#include <QHash>
#include <QHostAddress>
#include <QJsonObject>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class DrawingOptions;

/**
 * @brief Loopback HTTP control API for the MathMod UI.
 *
 * Lets external tools (e.g. an AI agent through the
 * mcp_server/mathmod_ui_mcp.py MCP server) inspect and drive the
 * running application.
 *
 * Security model: the server binds to 127.0.0.1 only, so only
 * processes on this machine can reach it. No authentication.
 *
 * Endpoints (JSON in / JSON out, one request per connection,
 * connection closed after the response):
 *   GET  /         -> {"app":"MathMod","ok":true,"port":...}
 *   GET  /state    -> snapshot of the UI (model, sliders, messages,
 *                     progress, computing flags, viewport, windows)
 *   POST /action   -> {"action":"...","params":{...}}
 *
 * Actions:
 *   select_model{name}          load a model from the current collection
 *   run{}                       run the calculation (Calculate button)
 *   stop{}                      stop running calculations (Stop button)
 *   set_slider{name,value}      move one of the model's sliders
 *   set_t{value}                set the t time slider (4D / animation)
 *   set_threads{value}          set the thread count slider
 *   fill_editor{text}           replace the script editor text (no run)
 *   load_file{path}             load a .js collection file (no dialog)
 *   screenshot{path?}           save the 3D viewport as PNG
 *   open_dialog{which}          editor | select_options | add_param | about
 *   toggle_object_tree{}        show/hide the current object tree
 *   animate{}                   start the rotation animation
 *   morph{}                     start the t-parameter morph animation
 *   toggle_axes{}               show/hide the coordinate axes
 *   toggle_planes{}             show/hide the bounding planes
 *   toggle_bounding_box{}       show/hide the bounding box
 *   render_mode{mode}           triangles | normals | fill | mesh
 *   toggle_uv{}                 show/hide uv coordinates (parametric)
 *   toggle_uv4d{}               show/hide uv coordinates (4D)
 *   undo{}                      restore previous model state
 *   redo{}                      re-apply a model state
 *   clear_history{}             clear the undo/redo history
 *   select_component{name,side?} select a component (name or index)
 *   toggle_component_visibility{} show/hide the current component
 *   apply_slider_set{name}      apply a predefined slider set (name or #)
 *   set_iso_grid{value}         isosurface grid resolution
 *   set_param_grid{value}       parametric (u,v) grid resolution
 *   reset_t{}                   reset the t slider to its minimum
 *   set_scale{x,y,z}            display scale factors
 *   init_matrix{}               reset the 4D rotation matrix + re-run
 *
 * Threading: the server lives on the GUI thread and uses non-blocking
 * I/O (readyRead), so the UI is never stalled waiting on a socket.
 * Requests are answered as soon as the GUI event loop processes them.
 * Note: a modal dialog inside the app (e.g. MemoryErrorMsg) blocks the
 * event loop and therefore requests until it is dismissed.
 */
class UiControlServer : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Start listening on 127.0.0.1:<port>.
     * @param win the main window to control.
     * Port defaults to 61234; override with the MATHMOD_UI_PORT
     * environment variable. A failed listen (e.g. port already in
     * use) is reported on stderr and the server stays inactive.
     */
    explicit UiControlServer(DrawingOptions *win, QObject *parent = nullptr);
    ~UiControlServer();

    bool isListening() const { return m_server.isListening(); }
    quint16 port() const { return m_port; }

    /** UI snapshot as a JSON object. Call on the GUI thread. */
    QJsonObject stateSnapshot() const;
    /** Execute an action and return its result JSON. Call on the GUI thread. */
    QJsonObject dispatchAction(const QString &action, const QJsonObject &params);

private slots:
    void onNewConnection();
    void onSocketReadyRead();
    void onSocketDisconnected();

private:
    void handleRequest(QTcpSocket *socket, const QByteArray &request);
    void writeResponse(QTcpSocket *socket, int code, const QByteArray &body);
    int findSliderIndex(const QString &name) const;

    DrawingOptions *m_win;
    QTcpServer m_server;
    QHash<QTcpSocket *, QByteArray> m_pending;
    quint16 m_port = 0;
};

#endif // UICONTROLSERVER_H
