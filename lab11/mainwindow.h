#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QTimer>
#include <QPoint>
#include <math.h>
#include <QMouseEvent>
#include <QFont>
#include <QPolygon>
#include <QRect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    QPoint point;
    QTimer *timer;

private:
    int a = 500;
};

#endif // MAINWINDOW_H
