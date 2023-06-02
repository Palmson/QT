#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>//добавляем библиотеку для вывода сообщений
#include "math.h"//добавляем библиотеку с математическими формулами

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

    void on_tableWidget_massive_itemChanged(QTableWidgetItem *item);

    void on_pushButton_clicked();

    void Colorparty();

private:
    Ui::MainWindow *ui;
    int size = 1;//создаём глобальную переменную для хранения размера массива
};

#endif // MAINWINDOW_H
