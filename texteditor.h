#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QSettings>
#include <QTextStream>
#include <QFileInfo>
#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class texteditor; }
QT_END_NAMESPACE

class texteditor : public QMainWindow
{
    Q_OBJECT

public:
    texteditor(const QString &fileName=QString(), QWidget *parent = 0);
    ~texteditor();

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void documentModified();

    void on_actionSelectFont_triggered();

    void on_actionAboutQt_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    bool saveFile();

    bool saveFileAs();

    void on_actionSave_triggered();

    void on_actionSaveAs_triggered();

private:
    Ui::texteditor *ui;
    void loadFile(const QString &fileName);
    void setFileName(const QString &);
    QString m_fileName;
};
#endif // TEXTEDITOR_H
