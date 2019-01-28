#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>
#include "ui_editor.h"
#include "about.h"

namespace Ui
{
class editor;
}

class editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit editor(QWidget *parent = nullptr);
    ~editor();
    void about();
    void newFile();
    void openFile(const QString &);
    void setupEditor();
    void save();
    void saveAs();
    About ab;
private slots:
    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionAbout_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionAbout_MathMod_triggered();

    void on_actionPaste_triggered();

public:
    Ui::editor *ui;
    QString filename;
    QString workfile;
};

#endif // EDITOR_H
