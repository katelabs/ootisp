#include "texteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Text Editor");
    a.setApplicationVersion("0.1");

    a.setOrganizationName("BydyaSoft");
    a.setOrganizationDomain("bstu.bydya.by");
    a.setWindowIcon(QIcon(":/icons/Resources/new.png"));
    texteditor w;
    w.show();
    return a.exec();
}
