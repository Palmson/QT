#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    //не нужен так как есть в коде кнопки
    ui->radioButton_normalmode->click();//Запускаемся в нормальном режиме
    ui->radioButton_plus->click();//Включаем режим сложения
    ui->lineEdit_res->setReadOnly(true);//последнее поле в режим только чтение
    ui->lineEdit_YellowFlag->setReadOnly(true);//Patriot
    ui->lineEdit_BlueFlag->setReadOnly(true);//POWER
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_radioButton_BigDatamode_clicked()//настройки режима больших чисел
{
    ui->label_higher->setVisible(true);//Показываем воодушивительный лейбл
    ui->label_standart->setVisible(false);//Убираем лебл с описанием стандартного режима
    ui->label_razr->setVisible(true);//включаем изминение количества разрядов после запятой
    ui->lineEdit_razr->setVisible(true);
    ui->lineEdit_razr->setReadOnly(false);
    ui->radioButton_tg->setVisible(false);//выключаем не нужные в этом режиме кнопки
    ui->radioButton_sin->setVisible(false);
    ui->radioButton_cos->setVisible(false);
    ui->radioButton_asin->setVisible(false);
    ui->radioButton_acos->setVisible(false);
    ui->radioButton_atan->setVisible(false);
}
void MainWindow::on_radioButton_normalmode_clicked()
{
    ui->label_higher->setVisible(false);//Убираем воодушивительный лейбл
    ui->label_standart->setVisible(true);//Показываем лейбл с описанием стандартного режима
    ui->label_razr->setVisible(false);//выключаем изминение количества разрядов после запятой
    ui->lineEdit_razr->setVisible(false);
    ui->lineEdit_razr->setReadOnly(true);
    ui->radioButton_tg->setVisible(true);//включаем не нужные в том режиме кнопки
    ui->radioButton_sin->setVisible(true);
    ui->radioButton_cos->setVisible(true);
    ui->radioButton_asin->setVisible(true);
    ui->radioButton_acos->setVisible(true);
    ui->radioButton_atan->setVisible(true);
}
void MainWindow::on_pushButton_clear_clicked()//настройки режима ОЧИСТКА
{
    ui->lineEdit_res->clear();//очищаем строки
    ui->lineEdit_op1->clear();
    ui->lineEdit_op2->clear();
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
}
void MainWindow::on_radioButton_plus_clicked()//настройки режима СЛОЖЕНИЕ
{
    ui->label_op1->setText("Слагаемое 1");//меняем лейблы под операцию
    ui->label_op2->setText("Слагаемое 2");
    ui->label_res->setText("Сумма");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->setReadOnly(false);//открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);//показываем второе поле

}
void MainWindow::on_radioButton_minus_clicked()//настройки режима ВЫЧИТАНИЕ
{
    ui->label_op1->setText("Уменьшаемое");//меняем лейблы под операцию
    ui->label_op2->setText("Вычитаемое");
    ui->label_res->setText("Разность");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->setReadOnly(false);//открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);
}
void MainWindow::on_radioButton_mul_clicked()//настройки режима УМНОЖЕНИЕ
{
    ui->label_op1->setText("Множитель 1");//меняем лейблы под операцию
    ui->label_op2->setText("Множитель 2");
    ui->label_res->setText("Произведение");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->setReadOnly(false);//открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);
}
void MainWindow::on_radioButton_div_clicked()//настройки режима ДЕЛЕНИЕ
{
    ui->label_op1->setText("Делимое");//меняем лейблы под операцию
    ui->label_op2->setText("Делитель");
    ui->label_res->setText("Частное");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->setReadOnly(false);//открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);
}
void MainWindow::on_radioButton_quad_clicked()//настройки режима ВОЗВЕДЕНИЕ В СТЕПЕНЬ
{
    ui->label_op1->setText("Число"); // меняем лейблы под операцию
    ui->label_op2->setText("Степень");
    ui->label_res->setText("Результат");
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_op2->setVisible(true);
    ui->lineEdit_op2->setReadOnly(false); //открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);
    ui->lineEdit_res->clear(); // очищаем строку результата
    ui->label_condition->hide();//убираем сообщение об ошибке
}
void MainWindow::on_radioButton_S_clicked()//настройки режима КВАДРАТНЫЙ КОРЕНЬ
{
    ui->label_op1->setText("Число");//меняем лейблы под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Корень");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//Убираем второе поле
}
void MainWindow::on_radioButton_factorial_clicked()//настройки режима ФАКТОРИАЛ
{
    ui->label_op1->setText("Число");//меняем лейблы под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Факториал");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//Убираем второе поле
}
void MainWindow::on_radioButton_sin_clicked()//настройки режима СИНУС
{
    ui->label_op1->setText("Число°");//меняем лейблы под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Синус рад.");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_cos_clicked()//настройки режима КОСИНУС
{
    ui->label_op1->setText("Число°");//меняем лейблы под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Косинус рад.");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_asin_clicked()//настройки режима АРКСИНУС
{
    ui->label_op1->setText("Число рад.");//меняем лейблы под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Арксинус°");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_tg_clicked()//настройки режима ТАНГЕНС
{
    ui->label_op1->setText("Число°");//меняем лейблы под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Тангенс рад.");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_acos_clicked()//настройки режима АРККОСИНУС
{
    ui->label_op1->setText("Число рад.");//меняем лейблы под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Арккосинус°");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_atan_clicked()//настройки режима АРКТАНГЕНС
{
    ui->label_op1->setText("Число рад.");//меняем лейблы под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Арктангенс°");
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}

void MainWindow::on_pushButton_equals_clicked()//основная часть(при нажатии кнопки =
{
    //обработчик результата
    double op1,op2,result;//добавляем переменные типа double
    QString str;//добавляем переменную типа Qstring
    bool flag;//Добавляем переменную для проверки результата типа Bool
    int razr;
    if (ui->radioButton_plus->isChecked())                                          //модуль для сложения
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            str=ui->lineEdit_op2->text();//содержимое второго поля помещаем в переменную
            op2=str.toDouble(&flag);//переносим значение строки в вторую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=op1+op2;//высчитываем результат
                ui->label_condition->hide();
                if(qIsNaN(result) or qIsInf(result)) //проверяем результат на допустимость
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Число выходит за принятый диапозон");//выводим сообщение об ошибке
                    ui->label_condition->show();
                }
                else {
                    if(ui->radioButton_normalmode->isChecked())//проверяем включен ли нормальный режим
                    {
                        str.setNum(result);//Переносим результат в строчную переменную
                        ui->lineEdit_res->setText(str);//выводим результат
                        ui->label_condition->hide();//Скрываем сообщение об ошибке
                    }
                    else
                    {
                        str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                        razr=str.toInt(&flag);
                        if(flag){
                            if(razr<0)
                            {
                                ui->lineEdit_res->clear();//очищаем поле результата
                                ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                                ui->label_condition->show();
                            }
                            else
                            {
                                str.setNum(result, 'e', razr);//Переносим результат в строчную переменную
                                ui->lineEdit_res->setText(str);//выводим результат
                                ui->label_condition->hide();//Скрываем сообщение об ошибке
                            }
                        }
                        else
                        {
                            ui->lineEdit_res->clear();//очищаем поле результата
                            ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                            ui->label_condition->show();
                        }
                    }

                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в слагаемом 2");//выводим сообщение об ошибке
                ui->label_condition->show();
            }
        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в слагаемом 1");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);


        }
    }
    else if (ui->radioButton_minus->isChecked())                               //модуль для вычитания
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            str=ui->lineEdit_op2->text();//содержимое второго поля помещаем в переменную
            op2=str.toDouble(&flag);//переносим значение строки в вторую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=op1-op2;//высчитываем результат
                ui->label_condition->hide();
                if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Число выходит за принятый диапозон");//выводим сообщение об ошибке
                    ui->label_condition->show();
                }
                else {
                    if(ui->radioButton_normalmode->isChecked())//проверяем включен ли нормальный режим
                    {
                        str.setNum(result);//Переносим результат в строчную переменную
                        ui->lineEdit_res->setText(str);//выводим результат
                        ui->label_condition->hide();//Скрываем сообщение об ошибке
                    }
                    else
                    {
                        str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                        razr=str.toInt(&flag);
                        if(flag){
                            if(razr<0)
                            {
                                ui->lineEdit_res->clear();//очищаем поле результата
                                ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                                ui->label_condition->show();
                            }
                            else
                            {
                                str.setNum(result, 'e', razr);//Переносим результат в строчную переменную
                                ui->lineEdit_res->setText(str);//выводим результат
                                ui->label_condition->hide();//Скрываем сообщение об ошибке
                            }
                        }
                        else
                        {
                            ui->lineEdit_res->clear();//очищаем поле результата
                            ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                            ui->label_condition->show();
                        }
                    }
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в вычитаемом");//выводим сообщение об ошибке
                ui->label_condition->show();
            }
        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в уменьшаемом");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);


        }
    }
    else if (ui->radioButton_mul->isChecked())                                          //модуль для умножения
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            str=ui->lineEdit_op2->text();//содержимое второго поля помещаем в переменную
            op2=str.toDouble(&flag);//переносим значение строки в вторую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=op1*op2;//высчитываем результат
                ui->label_condition->hide();
                if(qIsNaN(result) or qIsInf(result)) //проверяем результат на допустимость
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("За гранью моего понимания!");//выводим сообщение об ошибке
                    ui->label_condition->show();
                }
                else {
                    if(ui->radioButton_normalmode->isChecked())//проверяем включен ли нормальный режим
                    {
                        str.setNum(result);//Переносим результат в строчную переменную
                        ui->lineEdit_res->setText(str);//выводим результат
                        ui->label_condition->hide();//Скрываем сообщение об ошибке
                    }
                    else
                    {
                        str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                        razr=str.toInt(&flag);
                        if(flag){
                            if(razr<0)
                            {
                                ui->lineEdit_res->clear();//очищаем поле результата
                                ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                                ui->label_condition->show();
                            }
                            else
                            {
                                str.setNum(result, 'e', razr);//Переносим результат в строчную переменную
                                ui->lineEdit_res->setText(str);//выводим результат
                                ui->label_condition->hide();//Скрываем сообщение об ошибке
                            }
                        }
                        else
                        {
                            ui->lineEdit_res->clear();//очищаем поле результата
                            ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                            ui->label_condition->show();
                        }
                    }
                }

            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в множителе 2");//выводим сообщение об ошибке
                ui->label_condition->show();
            }
        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в множителе 1");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);


        }
    }
    else if (ui->radioButton_div->isChecked())                                              //модуль для деления
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            str=ui->lineEdit_op2->text();//содержимое второго поля помещаем в переменную
            op2=str.toDouble(&flag);//переносим значение строки в вторую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=op1/op2;//высчитываем результат
                ui->label_condition->hide();
                if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("За гранью моего понимания!");//выводим сообщение об ошибке
                    ui->label_condition->show();
                }
                else
                {
                    if(ui->radioButton_normalmode->isChecked())//проверяем включен ли нормальный режим
                    {
                        str.setNum(result);//Переносим результат в строчную переменную
                        ui->lineEdit_res->setText(str);//выводим результат
                        ui->label_condition->hide();//Скрываем сообщение об ошибке
                    }
                    else
                    {
                        str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                        razr=str.toInt(&flag);
                        if(flag){
                            if(razr<0)
                            {
                                ui->lineEdit_res->clear();//очищаем поле результата
                                ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                                ui->label_condition->show();
                            }
                            else
                            {
                                str.setNum(result, 'e', razr);//Переносим результат в строчную переменную
                                ui->lineEdit_res->setText(str);//выводим результат
                                ui->label_condition->hide();//Скрываем сообщение об ошибке
                            }
                        }
                        else
                        {
                            ui->lineEdit_res->clear();//очищаем поле результата
                            ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                            ui->label_condition->show();
                        }
                    }
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в делителе");//выводим сообщение об ошибке
                ui->label_condition->show();
            }
        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в делимом");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
    else if (ui->radioButton_quad->isChecked())                                         //модуль для возведения в степень
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            str=ui->lineEdit_op2->text();//содержимое второго поля помещаем в переменную
            op2=str.toDouble(&flag);//переносим значение строки в вторую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                if(qIsNull(op1))
                {
                    str.setNum(0);//меняем ответ строку на 0
                    ui->lineEdit_res->setText(str);//выводим результат
                    ui->label_condition->hide();//Скрываем сообщение об ошибке
                }
                else
                {
                    result=pow(op1,op2);//высчитываем результат
                    ui->label_condition->hide();//Скрываем сообщение об ошибке

                    if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("За гранью моего понимания!");//выводим сообщение об ошибке
                        ui->label_condition->show();
                    }
                    else
                    {
                        if(ui->radioButton_normalmode->isChecked())//проверяем включен ли нормальный режим
                        {
                            str.setNum(result);//Переносим результат в строчную переменную
                            ui->lineEdit_res->setText(str);//выводим результат
                            ui->label_condition->hide();//Скрываем сообщение об ошибке
                        }
                        else
                        {
                            str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                            razr=str.toInt(&flag);
                            if(flag){
                                if(razr<0)
                                {
                                    ui->lineEdit_res->clear();//очищаем поле результата
                                    ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                                    ui->label_condition->show();
                                }
                                else
                                {
                                    str.setNum(result, 'e', razr);//Переносим результат в строчную переменную
                                    ui->lineEdit_res->setText(str);//выводим результат
                                    ui->label_condition->hide();//Скрываем сообщение об ошибке
                                }
                            }
                            else
                            {
                                ui->lineEdit_res->clear();//очищаем поле результата
                                ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                                ui->label_condition->show();
                            }
                        }
                    }
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в степени");//выводим сообщение об ошибке
                ui->label_condition->show();
            }
        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в основании");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
    else if (ui->radioButton_S->isChecked())                                             //модуль для извлечения корня квадратного
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            result=sqrt(op1);//высчитываем результат
            ui->label_condition->hide();
            if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
            {
                ui->lineEdit_res->clear();
                ui->label_condition->setText("За гранью моего понимания!");//выводим сообщение об ошибке
                ui->label_condition->show();
            }
            else
            {
                if(ui->radioButton_normalmode->isChecked())//проверяем включен ли нормальный режим
                {
                    str.setNum(result);//Переносим результат в строчную переменную
                    ui->lineEdit_res->setText(str);//выводим результат
                    ui->label_condition->hide();//Скрываем сообщение об ошибке
                }
                else
                {
                    str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                    razr=str.toInt(&flag);
                    if(flag){
                        if(razr<0)
                        {
                            ui->lineEdit_res->clear();//очищаем поле результата
                            ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                            ui->label_condition->show();
                        }
                        else
                        {
                            str.setNum(result, 'e', razr);//Переносим результат в строчную переменную
                            ui->lineEdit_res->setText(str);//выводим результат
                            ui->label_condition->hide();//Скрываем сообщение об ошибке
                        }
                    }
                    else
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                        ui->label_condition->show();
                    }
                }
            }
        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка под корнем");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
    else if(ui->radioButton_factorial->isChecked())                                     //модуль для извлечения факториала
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            result=1;                   //высчитываем результат
            for(auto i=1; i<=op1;i++)
                result *= i;
            ui->label_condition->hide();
            if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("За гранью моего понимания!");//выводим сообщение об ошибке
                ui->label_condition->show();
            }
            else
            {
                if(ui->radioButton_normalmode->isChecked())//проверяем включен ли нормальный режим
                {
                    str.setNum(result);//Переносим результат в строчную переменную
                    ui->lineEdit_res->setText(str);//выводим результат
                    ui->label_condition->hide();//Скрываем сообщение об ошибке
                }
                else
                {
                    str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                    razr=str.toInt(&flag);
                    if(flag){
                        if(razr<0)
                        {
                            ui->lineEdit_res->clear();//очищаем поле результата
                            ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                            ui->label_condition->show();
                        }
                        else
                        {
                            str.setNum(result, 'e', razr);//Переносим результат в строчную переменную
                            ui->lineEdit_res->setText(str);//выводим результат
                            ui->label_condition->hide();//Скрываем сообщение об ошибке
                        }
                    }
                    else
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("Ошибка в числе разрядов!");//выводим сообщение об ошибке
                        ui->label_condition->show();
                    }
                }
            }

        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в числе");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
    else if (ui->radioButton_sin->isChecked())                                          //модуль для синуса
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            result=sin(op1*M_PI/180);//высчитываем результат
            if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
            {
                ui->lineEdit_res->clear();
                ui->label_condition->setText("Число выходит за требуемый диапозон");//выводим сообщение об ошибке
                ui->label_condition->setVisible(true);
            }
            else
            {

                str.setNum(result);//Переносим результат в строчную переменную
                ui->lineEdit_res->setText(str);//выводим результат
                ui->label_condition->hide();//Скрываем сообщение об ошибке
            }

        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в числе");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
    else if (ui->radioButton_cos->isChecked())                                          //модуль для косинуса
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            result=cos(op1*M_PI/180);//высчитываем результат
            if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Число выходит за требуемый диапозон");//выводим сообщение об ошибке
                ui->label_condition->setVisible(true);
            }
            else
            {

                str.setNum(result);//Переносим результат в строчную переменную
                ui->lineEdit_res->setText(str);//выводим результат
                ui->label_condition->hide();//Скрываем сообщение об ошибке
            }


        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в числе");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
    else if (ui->radioButton_tg->isChecked())                                        //модуль для тангенса
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            result=tan(op1*M_PI/180);//высчитываем результат
            if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
            {
                ui->label_condition->setText("Число выходит за принятый диапозон");//выводим сообщение об ошибке
                ui->label_condition->setVisible(true);
                ui->lineEdit_res->clear();//очищаем поле результата
            }
            else
            {
                str.setNum(result);//Переносим результат в строчную переменную
                ui->lineEdit_res->setText(str);//выводим результат
                ui->label_condition->hide();//Скрываем сообщение об ошибке
            }

        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в числе");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
    else if (ui->radioButton_acos->isChecked())                                  //модуль для арккосинуса
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            result=acos(op1*180/M_PI);//высчитываем результат
            if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
            {
                ui->label_condition->setText("Число выходит за принятый диапозон");//выводим сообщение об ошибке
                ui->label_condition->setVisible(true);
                ui->lineEdit_res->clear();//очищаем поле результата
            }

            else
            {
                str.setNum(result);//Переносим результат в строчную переменную
                ui->lineEdit_res->setText(str);//выводим результат
                ui->label_condition->hide();//Скрываем сообщение об ошибке
            }
        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в числе");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
    else if (ui->radioButton_asin->isChecked())                                 //модуль для арксинуса
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            result=asin(op1*180/M_PI);//высчитываем результат
            if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
            {
                ui->label_condition->setText("Число выходит за принятый диапозон");//выводим сообщение об ошибке
                ui->label_condition->setVisible(true);
                ui->lineEdit_res->clear();//очищаем поле результата
            }
            else
            {
                str.setNum(result);//Переносим результат в строчную переменную
                ui->lineEdit_res->setText(str);//выводим результат
                ui->label_condition->hide();//Скрываем сообщение об ошибке
            }

        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в числе");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
    else if(ui->radioButton_atan->isChecked())                                  //модуль для арктангенса
    {
        str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
        op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
        if(flag)//если перенос прошел успешно
        {
            result=atan(op1*180/M_PI);//высчитываем результат
            if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
            {
                ui->label_condition->setText("Число выходит за принятый диапозон");//выводим сообщение об ошибке
                ui->label_condition->setVisible(true);
                ui->lineEdit_res->clear();//очищаем поле результата
            }
            else
            {
                str.setNum(result);//Переносим результат в строчную переменную
                ui->lineEdit_res->setText(str);//выводим результат
                ui->label_condition->hide();//Скрываем сообщение об ошибке
            }

        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Ошибка в числе");//выводим сообщение об ошибке
            ui->label_condition->setVisible(true);
        }
    }
}



































