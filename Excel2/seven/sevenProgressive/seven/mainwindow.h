#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>//библиотека нужная для более простого объявления динамических массивов
#include <QTableWidget>//библиотека для работы с таблицей
#include <QMessageBox>//библиотека для вывода сообщений
#include "math.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_spinBox_count_valueChanged(int arg1);

    bool isCorrectValues();//Объявляем функцию для проверки элементов в таблице

    void on_pushButton_clear_clicked();

    void on_tableWidget_massive_itemChanged(QTableWidgetItem *item);

    void on_pushButton_find_clicked();

    void sorting(double *mas, int row); //функция сортировки массива

    double getK (double x1, double y1, double x2, double y2); //функция нахождения коэффициента k в уравнении стороны

    double getB (double x1, double y1, double x2, double y2); //функция нахождения коэффициента b в уравнении стороны

    bool isCrossing (double x1, double y1, double x2, double y2,double x3, double y3, double x4, double y4); //для определене пересечения

    bool weHaveCrossing(); //проверка есть ли вообще пересечения

private:
    Ui::MainWindow *ui;
    bool Changed=false;
    bool no_auto_change=true; //создаём переменную для запрета изменений в процессе
    QVector <double> x,y,opr,len; //создаём динамические массивы для хранения: координат X и Y, определителей, длин векторов - с помощью QVector
};

#endif // MAINWINDOW_H
