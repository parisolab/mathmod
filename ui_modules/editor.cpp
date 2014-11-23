#include <QWidget>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include "editor.h"



editor::editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editor)
{
    this->setWindowFlags( Qt::WindowStaysOnTopHint );
    ui->setupUi(this);
}

editor::~editor()
{
    delete ui;
}

void editor::about()
{
    QMessageBox::about(this, tr("About Syntax Highlighter"),
                       tr("<p>The <b>Syntax Highlighter</b> example shows how " \
                          "to perform simple syntax highlighting by subclassing " \
                          "the QSyntaxHighlighter class and describing " \
                          "highlighting rules using regular expressions.</p>"));
}

void editor::newFile()
{
    ui->textEdit->clear();
}

void editor::openFile(const QString &path)
{
    QString fileName = path;

    //if (fileName.isNull())
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "Files (*.js *.*)");

    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            ui->textEdit->setPlainText(file.readAll());
    }
}

void editor::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    ui->textEdit = new QTextEdit;
    ui->textEdit->setFont(font);

    //highlighter = new Highlighter(ui->textEdit->document());
    QFile file("mainwindow.h");
    if (file.open(QFile::ReadOnly | QFile::Text))
        ui->textEdit->setPlainText(file.readAll());
}

void editor::on_actionOpen_triggered()
{
    openFile("");
}

void editor::save()
{
    if ( filename.isEmpty() )
    {
        saveAs();
        return;
    }
    QString text = ui->textEdit->toPlainText();
    QFile f( filename );
    if ( !f.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        statusBar()->showMessage( tr("Could not write to %1").arg(filename),2000 );
        return;
    }

    QTextStream t( &f );
    t << text;
    f.close();

    //e->setModified( FALSE );
    //setCaption( filename );
    statusBar()->showMessage( tr( "File %1 saved" ).arg( filename ), 2000 );
}

void editor::saveAs()
{
    QString fn= QFileDialog::getSaveFileName(this,tr("Save file"), "", tr("All Files (*.*)"));

    if ( !fn.isEmpty() )
    {
        filename = fn;
        save();
    }
    else
    {
        statusBar()->showMessage( tr("Saving aborted"), 2000 );
    }
    workfile = fn;
}


void editor::on_actionNew_triggered()
{
    newFile();
}

void editor::on_actionAbout_triggered()
{
    about();
}

void editor::on_actionSave_triggered()
{
    save();
}

void editor::on_actionSave_As_triggered()
{
    saveAs();
}

void editor::on_actionExit_triggered()
{
    this->close();
}

void editor::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void editor::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void editor::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void editor::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void editor::on_actionAbout_MathMod_triggered()
{
    ab.show();
}

void editor::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
