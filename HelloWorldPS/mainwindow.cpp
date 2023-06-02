#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label1->setText("Красава!");
}

void MainWindow::on_pushSetTextButton_clicked()
{
    ui->label1->setText(ui->lineEdit->text());
}

void MainWindow::on_pushWriteNumber_clicked()
{
    int numerasik;
    numerasik=17;
    ui->label1->setNum(numerasik+1000-7);
}

void MainWindow::on_pushGetNumberButter_clicked() //настройка кнопки Первый!
{
    int chiselka; //задача переменных и их вида
    QString strochochek;
    bool flag;

    strochochek=ui->lineEdit->text();//считывание строки в переменную
    chiselka=strochochek.toInt(&flag,10);//перевод в числовую переменную с указанной СС + установка флага

    if (flag)//проверка флага
    {
        strochochek.setNum(chiselka,8);//если да, то преобразование в нужную СС

        ui->label1->setText(strochochek);
    }

    else {
        ui->label1->setText("Не существует в заданной SS");//если нет - ошибка
    }

}

