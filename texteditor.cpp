#include "texteditor.h"
#include "ui_texteditor.h"

texteditor::texteditor(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::texteditor)
{
    ui->setupUi(this);
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));
    setWindowTitle("Новый документ[*]");
    loadFile(fileName);
}

texteditor::~texteditor()
{
    delete ui;
}


void texteditor::on_actionNew_triggered()
{
    texteditor *textedit = new texteditor();
    textedit->setAttribute(Qt::WA_DeleteOnClose);
    textedit->show();
}

void texteditor::closeEvent(QCloseEvent *e)
{
    if (isWindowModified())
    {
        switch(QMessageBox::warning(this, "Document Modified",
           "The document has been modified. "
           "Do you want to save your changes?\n"
           "You will lose and unsaved changes.",
           QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
           QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            saveFile();
            e->accept();
            break;
        case QMessageBox::No:
            e->accept();
            break;
        case QMessageBox::Cancel:
            e->ignore();
            break;
        }
    }
    else
    {
        e->accept();
    }
}

void texteditor::on_actionClose_triggered()
{
    this->close();
}

void texteditor::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void texteditor::documentModified()
{
    setWindowModified(true);
}

void texteditor::on_actionSelectFont_triggered()
{
    bool ok;

    QFont fnt = QFontDialog::getFont(&ok, ui->textEdit->font(), this);
    if (ok) ui->textEdit->setFont(fnt);
}

void texteditor::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void texteditor::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void texteditor::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void texteditor::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void texteditor::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void texteditor::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void texteditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About programm", "Created by Bydyakov Vladislav");
}

void texteditor::loadFile(const QString &fileName)
{
    if (fileName.isEmpty())
    {
        setFileName(QString());
        return;
    }
    QFile myfile(fileName);
    if (!myfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Warning!", "Can't open the file");
        setFileName(QString());
        return;
    }
    else
    {
        QTextStream stream(&myfile);
        ui->textEdit->setText(stream.readAll());
        myfile.close();
        setFileName(fileName);
        setWindowModified(false);
    }

}

void texteditor::setFileName(const QString &str)
{
    m_fileName = str;
    setWindowTitle(QString("%1[*] - %2")
                   .arg(m_fileName.isNull()?"untitled":QFileInfo(m_fileName).fileName())
                   .arg(QApplication::applicationName()));
    ui->textEdit->setFont(QApplication::font());
}

void texteditor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        "Open document", QDir::currentPath(), "Text documents (*.txt)");
    if (fileName.isNull()) return;
    else
    {
        if((m_fileName.isNull()) && (!isWindowModified())) loadFile(fileName);
        else
        {
            texteditor *textedit = new texteditor(fileName);
            textedit->setAttribute(Qt::WA_DeleteOnClose);
            textedit->show();
        }
    }
}

bool texteditor::saveFile()
{
    if (m_fileName.isNull()) return saveFileAs();
    else
    {
        QFile myfile(m_fileName);
        if (!myfile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, "Warning!", "Can't open the file");
            setFileName(QString());
            return false;
        }
        else
        {
            QTextStream stream(&myfile);
            stream << ui->textEdit->toPlainText();
            myfile.close();
            setWindowModified(false);
            return true;
        }


    }
}

bool texteditor::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
       m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");
    if(fileName.isNull()) return false;
    else
    {
        setFileName(fileName);
        return saveFile();
    }
}

void texteditor::on_actionSave_triggered()
{
    saveFile();
}

void texteditor::on_actionSaveAs_triggered()
{
    saveFileAs();
}
