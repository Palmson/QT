#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>
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

    void on_pushButton_random_clicked();

    void on_pushButton_removelast_clicked();

    void on_pushButton_randomValues_clicked();

    void on_pushButton_min_clicked();

    bool isCorrectValues();//Объявляем функцию для проверки значений в таблице

    bool isCorrectItem(QTableWidgetItem *item);//Объявляем функцию для проверки элемента в таблице

    void on_pushButton_max_clicked();

    void on_pushButton_mid_clicked();

    void on_tableWidget_massive_itemChanged(QTableWidgetItem *item);

    void on_pushButton_Comb_clicked();

    void readMassive();//Объявляем функцию для чтения массива

    void writeMassive();//Объявляем функцию для записи массива

    void on_pushButton_Bubble_clicked();

    void on_pushButton_Fast_clicked();

    void quickSort(double *array, int scale);//Объявляем функцию для быстрой сортировки

    void on_pushButton_MONKE_clicked();

    bool isCorrect(double *array);//Объявляем функцию для проверки результата во время обезьяньей сортировки
    void shuffle(double *array);//Обьявляем функцию для перемешивания значений во время обезьяньей сортировки

    void on_pushButton_GNOMED_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_delete_doubles_clicked();

    void on_lineEdit_searchValue_textChanged(const QString &arg1);

    void on_pushButton_const_clicked();

    void on_lineEdit_const_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    bool checkChange=false;
    bool checkSorting = false;
    bool allowChange = true;
    bool allright = false;
    double *mas = nullptr;
    int size = 0;//создаём глобальную переменную для хранения размера массива
};

#endif // MAINWINDOW_H
