#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"//подключаем библиотеку с математическими штуками


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_clear->click();//при запуске убираемся
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_clear_clicked()//когда кнопка СТЕРЕТЬ нажата
{
    ui->lineEdit_side1->clear();//очищаем введённые данные
    ui->lineEdit_angle->clear();
    ui->lineEdit_side2->clear();

    ui->label_P_answ->setText("?");//возвращаем поле ответа в исходное положение
    ui->label_S_answ->setText("?");
}
void MainWindow::on_lineEdit_side1_textChanged(const QString &)//когда текст в поле СТОРОНА 1 изменяют
{
    static double smallest = 4.9E-324;//создаём максимально и минимально допустимые значения
    static double largest = 1.8E+307;
    bool flag;//для проверки
    double value;//создаём переменные
    QString str;//для записи

    str=ui->lineEdit_side1->text();//считываем текст в первом поле
    value=str.toDouble(&flag);//переносим значение в переменную
    QPalette p=ui->lineEdit_side1->palette();//считываем палитру
    if(flag)//проверяем на правильность введённые данные
    {
        if(value>smallest and value<largest)//проверяем на правильность введённые данные
            p.setColor(QPalette::Text, Qt::green);//меняем переменную на ЗЕЛЁНЫЙ сигнал(текст)
        else//если данные некорректно
            p.setColor(QPalette::Text, Qt::red);//меняем переменную на КРАСНЫЙ сигнал(текст)
    }
    else//если данные некорректно
        p.setColor(QPalette::Text, Qt::red);//меняем переменную на КРАСНЫЙ сигнал(текст)

    ui->lineEdit_side1->setPalette(p);//даём цветовой сигнал(окрашиваем текст)
}

void MainWindow::on_lineEdit_side2_textChanged(const QString &)//когда текст в поле СТОРОНА 2 изменяют
{
    static double smallest = 4.9E-324;//создаём максимально и минимально допустимые значения
    static double largest = 1.8E+307;
    bool flag;//для проверки
    double value;//создаём переменные
    QString str;//для записи

    str=ui->lineEdit_side2->text();//считываем текст во втором поле
    value=str.toDouble(&flag);//переносим значение в переменную
    QPalette p=ui->lineEdit_side2->palette();//считываем палитру
    if(flag)//проверяем на правильность введённые данные
    {
        if(value>smallest and value<largest)//проверяем на правильность введённые данные
            p.setColor(QPalette::Text, Qt::green);//меняем переменную на ЗЕЛЁНЫЙ сигнал(текст)
        else//если данные некорректно
            p.setColor(QPalette::Text, Qt::red);//меняем переменную на КРАСНЫЙ сигнал(текст)
    }
    else//если данные некорректно
        p.setColor(QPalette::Text, Qt::red);//меняем переменную на КРАСНЫЙ сигнал(текст)

    ui->lineEdit_side2->setPalette(p);//даём цветовой сигнал(окрашиваем текст)
}

void MainWindow::on_lineEdit_angle_textChanged(const QString &)//когда текст в поле УГОЛ изменяют
{
    static double smallest = 4.9E-324;
    bool flag;//для проверки
    double value;//создаём переменные
    QString str;//для записи

    str=ui->lineEdit_angle->text();//считываем текст в третьем поле
    value=str.toDouble(&flag);//переносим значение в переменную
    QPalette p=ui->lineEdit_angle->palette();//считываем палитру
    if(flag)//проверяем на правильность введённые данные
    {
        if(value>smallest and value<180)//проверяем на правильность введённые данные
            p.setColor(QPalette::Text, Qt::green);//меняем переменную на ЗЕЛЁНЫЙ сигнал(текст)
        else//если данные некорректно
            p.setColor(QPalette::Text, Qt::red);//меняем переменную на КРАСНЫЙ сигнал(текст)
    }
    else//если данные некорректно
        p.setColor(QPalette::Text, Qt::red);//меняем переменную на КРАСНЫЙ сигнал(текст)

    ui->lineEdit_angle->setPalette(p);//даём цветовой сигнал(окрашиваем текст)
}

void MainWindow::on_pushButton_calculate_clicked()//когда кнопка НАЙТИ нажата
{
    static double smallest = 4.9E-324;//создаём максимально и минимально допустимые значения
    static double largest = 1.8E+307;
    double side1,side2,result,angle;//добавляем переменные
    bool flag;//для проверки
    QString str;//для записи

    str=ui->lineEdit_side1->text();//считываем текст в первом поле
    side1=str.toDouble(&flag);//переносим значение в переменную
    if(flag and side1>smallest and side1<largest)//проверяем на правильность введённые данные
    {
        str=ui->lineEdit_side2->text();//считываем текст во втором поле
        side2=str.toDouble(&flag);//переносим значение в переменную
        if(flag and side2>smallest and  side2<largest)//проверяем на правильность введённые данные
        {
            str=ui->lineEdit_angle->text();//считываем текст в третьем поле
            angle=str.toDouble(&flag);//переносим значение в переменную
            if(flag and angle>0 and angle<180)//проверяем на правильность введённые данные
            {
                result=sqrt(pow(side1,2)+pow(side2,2)-2*side1*side2*cos(angle*M_PI/180))+side1+side2;//рассчитываем периметр
                if(qIsInf(result) or qIsNaN(result) or qIsNull(result))//проверяем треугольник на предмет существования в нашем диапозоне
                {
                    QMessageBox::information(this,"Ошибка","Треугольника не существует или его периметр выходит за допустимые рамки измерения!",QMessageBox::Ok);//выводим ошибку
                    ui->pushButton_clear->click();//убираемся
                }
                else//если всё ок
                {
                    str.setNum(result);//считываем значение переменной результата
                    ui->label_P_answ->setText(str);//переносим значение в поле ответа
                    result=side1*side2*sin(angle*M_PI/180)/2;//рассчитываем площадь
                    if(qIsInf(result) or qIsNaN(result) or qIsNull(result))//проверяем треугольник на предмет существования в нашем диапозоне(на всякий случай)
                    {
                        QMessageBox::information(this,"Ошибка","Треугольника не существует или его площадь выходит за допустимые рамки измерения!",QMessageBox::Ok);//выводим ошибку
                        ui->pushButton_clear->click();//убираемся
                    }
                    else
                    {
                        str.setNum(result);//считываем значение переменной результата
                        ui->label_S_answ->setText(str);//переносим значение в поле ответа
                    }
                }
            }
            else if(angle>=180)//сравниваем угол с наибольшим возможным значением
            {
                QMessageBox::information(this,"Ошибка","Параметр \"Угол\" слишком велик.",QMessageBox::Ok);//выводим ошибку
            }
            else//если ничего не подошло
            {
                QMessageBox::information(this,"Ошибка","Параметр \"Угол\" слишком мал или введён некорректно.",QMessageBox::Ok);//выводим ошибку
            }
        }
        else if(side2>largest)//сравниваем сторону с наибольшим возможным значением
        {
            QMessageBox::information(this,"Ошибка","Параметр \"Сторона 1\" слишком велик.",QMessageBox::Ok);//выводим ошибку
        }
        else//если ничего не подошло
        {
            QMessageBox::information(this,"Ошибка","Параметр \"Сторона 2\" слишком мал или введён некорректно.",QMessageBox::Ok);//выводим ошибку
        }
    }
    else if(side1>=largest) //сравниваем сторону с наибольшим возможным значением
    {
        QMessageBox::information(this,"Ошибка","Параметр \"Сторона 1\" слишком велик.",QMessageBox::Ok);//выводим ошибку
    }
    else//если ничего не подошло
    {
        QMessageBox::information(this,"Ошибка","Параметр \"Сторона 1\" слишком мал или введён некорректно.",QMessageBox::Ok);//выводим ошибку
    }

}









