#include "qpaintwidget.h"
#include <QPainter>
#include <QTextStream>
#include <QtMath>
QTextStream cout(stdout);
QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdatePixmap()));
    timer->start(10); // И запустим таймер
}
void QPaintWidget::paintEvent(QPaintEvent *) {
    QPainter p(this); // Создаём новый объект рисовальщика
    p.setPen(QPen(Qt::red,6,Qt::SolidLine));
    // Настройки кисти
    p.setFont(QFont("Yu Gothic", 10, QFont::Bold)); // Настройки шрифта
    QTransform transform;
    // создание объекта
   // трансформации transform
            // Как в unity ☺
    transform.rotate(90,Qt::ZAxis); // поворот по Z
    transform.rotate(0,Qt::YAxis); // поворот по Y
    transform.rotate(0,Qt::XAxis); // поворот по X
    transform.translate(60,-20);
    // так как Z повернут на 90 двигаем x -
  //  вниз, y - вправо
            p.setTransform(transform);
    // устанавливаем наши трансформации
   // transform к рисовальщику.
            p.drawText(rect(), "Лабораторная работа No8"); // рисуется с учётом
   // transform
            p.resetTransform();
    p.setPen(QPen(Qt::blue,3,Qt::SolidLine));
    // Настройки кисти
    p.drawLine(0,0,width(),height());
    //в том случае если картинка не меняется
    p.drawRect(showRect(rect1));
    p.drawRect(showRect(rect2));
}
QRectF QPaintWidget::showRect(QRectF &rect)
{
    float k=(float)height()/(float)width();
    float Ux=rect.x()+1;
    float Uy=Ux*(k);
    rect.moveTopLeft(QPointF(Ux,Uy));
    return rect;
}
void QPaintWidget::UpdatePixmap()
{
    update();
}
