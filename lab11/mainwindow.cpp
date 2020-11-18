#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    point.setX(100);
    point.setY((sqrt(pow(point.x(),3) / (a-point.x()))));

    timer=new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(50);
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    painter.setPen(QPen(Qt::black,1));

    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    QPolygon triangle;
    triangle<< QPoint(point.x()+60,point.y()+15) << QPoint(point.x()+30,point.y()+60) << QPoint(point.x()+90,point.y()+60);
    painter.drawPolygon(triangle);

    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter.drawEllipse(QPoint(point.x()+60,point.y()+90), 30, 30);

    if(point.x() < 400){
        point.setX(point.x() + 5);
        point.setY((sqrt(pow(point.x(),3) / (a-point.x()))));
    }
    else{
        point.setX(0);
        point.setY((sqrt(pow(point.x(),3) / (a-point.x()))));
    }

    painter.rotate(90);
    painter.setFont(QFont("Light", 12));
    painter.drawText(QPoint(40, -40), "Lab 1: Graphic primitives of the QT Library");

}
