#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "qpaintwidget.h"
//Отрезок прямой,
//проведённой из левого
//верхнего в правый нижний
//угол экрана

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow ui;
    // ”казатель на объект нашего класса
    QPaintWidget *wgt;
};
#endif // MAINWINDOW_H
