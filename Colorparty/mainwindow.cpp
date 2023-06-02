#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox_count->setValue(1);//ставим три элемента

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_count_valueChanged(int arg1)
{
    ui->tableWidget_massive->setRowCount(arg1);//выставляем количество строк
}

void MainWindow::Colorparty()
{
    size= ui->tableWidget_massive->rowCount();
    for(int i=0; i<size;i++)
    {
        int r,g,b;
        r=0;
        g=0;
        b=0;
        bool Rcor,Gcor,Bcor;
        Rcor=false;
        Gcor=false;
        Bcor=false;
        QTableWidgetItem *itemR=ui->tableWidget_massive->item(i, 0);//используем item как команду вызова значения элемента
        if(itemR==nullptr)
        {
            itemR =  new QTableWidgetItem(); //выделяем память
            ui->tableWidget_massive->setItem(i,0,itemR); //помещаем ячейку в таблицу
            ui->tableWidget_massive->item(i,0)->setBackgroundColor(Qt::red);//меняем цвет ячейки на красный
        }
        else
        {
            r = itemR->text().toInt(&Rcor);//переносим значение из элемента в переменную с проверкой
            if(Rcor and !(r>255 or r<0))
                ui->tableWidget_massive->item(i,0)->setBackgroundColor(Qt::white);//меняем цвет ячейки
            else
            {
                ui->tableWidget_massive->item(i,0)->setBackgroundColor(Qt::red);//меняем цвет ячейки на красный
                Rcor=false;
            }
        }
        QTableWidgetItem *itemG=ui->tableWidget_massive->item(i, 1);//используем item как команду вызова значения элемента
        if(itemG==nullptr)
        {
            itemG =  new QTableWidgetItem(); //выделяем память
            ui->tableWidget_massive->setItem(i,1,itemG); //помещаем ячейку в таблицу
            ui->tableWidget_massive->item(i,1)->setBackgroundColor(Qt::red);//меняем цвет ячейки на красный
        }
        else
        {
            g = itemG->text().toInt(&Gcor);//переносим значение из элемента в переменную с проверкой
            if(Gcor and !(g>255 or g<0))
                ui->tableWidget_massive->item(i,1)->setBackgroundColor(Qt::white);//меняем цвет ячейки
            else
            {
                ui->tableWidget_massive->item(i,1)->setBackgroundColor(Qt::red);//меняем цвет ячейки на красный
                Gcor=false;
            }
        }
        QTableWidgetItem *itemB=ui->tableWidget_massive->item(i, 2);//используем item как команду вызова значения элемента
        if(itemB==nullptr)
        {
            itemB =  new QTableWidgetItem(); //выделяем память
            ui->tableWidget_massive->setItem(i,2,itemB); //помещаем ячейку в таблицу
            ui->tableWidget_massive->item(i,2)->setBackgroundColor(Qt::red);//меняем цвет ячейки на красный
        }
        else
        {
            b = itemB->text().toInt(&Bcor);//переносим значение из элемента в переменную с проверкой
            if(Bcor and !(b>255 or b<0))
                ui->tableWidget_massive->item(i,2)->setBackgroundColor(Qt::white);//меняем цвет ячейки
            else
            {
                ui->tableWidget_massive->item(i,2)->setBackgroundColor(Qt::red);//меняем цвет ячейки на красный
                Bcor=false;
            }

        }
        QTableWidgetItem *itemC=ui->tableWidget_massive->item(i, 3);//используем item как команду вызова значения элемента
        if(Rcor and Gcor and Bcor)
        {
            if(itemC==nullptr)
            {
                itemC =  new QTableWidgetItem(); //выделяем память
                ui->tableWidget_massive->setItem(i,3,itemC); //помещаем ячейку в таблицу
                ui->tableWidget_massive->item(i,3)->setBackgroundColor(QColor(r, g, b));//меняем цвет ячейки
                itemC->setText("");
            }
            else
            {
                ui->tableWidget_massive->item(i,3)->setBackgroundColor(QColor(r, g, b));//меняем цвет ячейки
                itemC->setText("");
            }
        }
        else
        {
            if(itemC==nullptr)
            {
                itemC =  new QTableWidgetItem(); //выделяем память
                ui->tableWidget_massive->setItem(i,3,itemC); //помещаем ячейку в таблицу
                ui->tableWidget_massive->item(i,3)->setBackgroundColor(Qt::white);//меняем цвет ячейки
                itemC->setText("Ошибка");
            }
            else
            {
                ui->tableWidget_massive->item(i,3)->setBackgroundColor(Qt::white);//меняем цвет ячейки
                itemC->setText("Ошибка");
            }
        }
    }
}
void MainWindow::on_tableWidget_massive_itemChanged(QTableWidgetItem *)
{
    Colorparty();
}
void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget_massive->clear();
    ui->spinBox_count->setValue(1);//ставим три элемента
    ui->tableWidget_massive->setHorizontalHeaderLabels(QStringList() << "R" << "G" <<"B" <<"Color");//ставим названия столбцов
}
