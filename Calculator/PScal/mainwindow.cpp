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
    ui->label_razr->setVisible(true);//показываем лейбл изминения количества разрядов после запятой
    ui->lineEdit_razr->setVisible(true);//показываем поле изминения количества разрядов после запятой
    ui->lineEdit_razr->setReadOnly(false);//открываем изменение поля изминения количества разрядов после запятой
    ui->radioButton_tg->setVisible(false);//убираем режим тангенса
    ui->radioButton_sin->setVisible(false);//убираем режим синуса
    ui->radioButton_cos->setVisible(false);//убираем режим косинуса
    ui->radioButton_asin->setVisible(false);//убираем режим арксинуса
    ui->radioButton_acos->setVisible(false);//убираем режим арккосинуса
    ui->radioButton_atan->setVisible(false);//убираем режим арктангенса
}
void MainWindow::on_radioButton_normalmode_clicked()
{
    ui->label_higher->setVisible(false);//Убираем воодушивительный лейбл
    ui->label_standart->setVisible(true);//Показываем лейбл с описанием стандартного режима
    ui->label_razr->setVisible(false);//Убираем лебл изминения количества разрядов после запятой
    ui->lineEdit_razr->setVisible(false);//Убираем поле изминения количества разрядов после запятой
    ui->lineEdit_razr->setReadOnly(true);//закрываем изменение лебла изминения количества разрядов после запятой
    ui->radioButton_tg->setVisible(true);//Показываем режим тангенса
    ui->radioButton_sin->setVisible(true);//Показываем режим синуса
    ui->radioButton_cos->setVisible(true);//Показываем режим косинуса
    ui->radioButton_asin->setVisible(true);//Показываем режим арккасинуса
    ui->radioButton_acos->setVisible(true);//Показываем режим арккосинуса
    ui->radioButton_atan->setVisible(true);//Показываем режим арктангенса
}
void MainWindow::on_pushButton_clear_clicked()//настройки режима ОЧИСТКА
{
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->lineEdit_op1->clear();// очищаем строку первого элемента
    ui->lineEdit_op2->clear();// очищаем строку второго элемента
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
}
void MainWindow::on_radioButton_plus_clicked()//настройки режима СЛОЖЕНИЕ
{
    ui->label_op1->setText("Слагаемое 1");//меняем лейбл первого элемента под операцию
    ui->label_op2->setText("Слагаемое 2");//меняем лейбл второго элемента под операцию
    ui->label_res->setText("Сумма");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->setReadOnly(false);//открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);//показываем второе поле
}
void MainWindow::on_radioButton_minus_clicked()//настройки режима ВЫЧИТАНИЕ
{
    ui->label_op1->setText("Уменьшаемое");//меняем лейбл первого элемента под операцию
    ui->label_op2->setText("Вычитаемое");//меняем лейбл второго элемента под операцию
    ui->label_res->setText("Разность");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->setReadOnly(false);//открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);//показываем второе поле
}
void MainWindow::on_radioButton_mul_clicked()//настройки режима УМНОЖЕНИЕ
{
    ui->label_op1->setText("Множитель 1");//меняем лейбл первого элемента под операцию
    ui->label_op2->setText("Множитель 2");//меняем лейбл второго элемента под операцию
    ui->label_res->setText("Произведение");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->setReadOnly(false);//открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);//показываем второе поле
}
void MainWindow::on_radioButton_div_clicked()//настройки режима ДЕЛЕНИЕ
{
    ui->label_op1->setText("Делимое");//меняем лейбл первого элемента под операцию
    ui->label_op2->setText("Делитель");//меняем лейбл второго элемента под операцию
    ui->label_res->setText("Частное");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->setReadOnly(false);//открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);//показываем второе поле
}
void MainWindow::on_radioButton_quad_clicked()//настройки режима ВОЗВЕДЕНИЕ В СТЕПЕНЬ
{
    ui->label_op1->setText("Число");//меняем лейбл первого элемента под операцию
    ui->label_op2->setText("Степень");//меняем лейбл второго элемента под операцию
    ui->label_res->setText("Результат");//меняем лейбл результата под операцию
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->label_op2->setVisible(true);//показываем второй лейбл
    ui->lineEdit_op2->setReadOnly(false); //открываем изменение второго поля
    ui->lineEdit_op2->setVisible(true);//показываем второе поле
    ui->lineEdit_res->clear(); //очищаем строку результата
    ui->label_condition->hide();//убираем сообщение об ошибке
}
double MainWindow::factorial(double x)//Добавляем функцию для операции ФАКТОРИАЛ
{
    return std::tgamma(x+1);//возвращаем значение гамма-функции от x(Г(x+1)-это гамма функция факториала) tgamma - "true gamma function"
}
void MainWindow::on_radioButton_S_clicked()//настройки режима КВАДРАТНЫЙ КОРЕНЬ
{
    ui->label_op1->setText("Число");//меняем лейбл первого элемента под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Корень");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//Убираем второе поле
}
void MainWindow::on_radioButton_factorial_clicked()//настройки режима ФАКТОРИАЛ
{
    ui->label_op1->setText("Число");//меняем лейбл первого элемента под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Факториал");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//Убираем второе поле
}
void MainWindow::on_radioButton_sin_clicked()//настройки режима СИНУС
{
    ui->label_op1->setText("Число радиан");//меняем лейбл первого элемента под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Синус");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_cos_clicked()//настройки режима КОСИНУС
{
    ui->label_op1->setText("Число радиан");//меняем лейбл первого элемента под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Косинус");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_asin_clicked()//настройки режима АРКСИНУС
{
    ui->label_op1->setText("Число");//меняем лейбл первого элемента под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Арксинус рад. ");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_tg_clicked()//настройки режима ТАНГЕНС
{
    ui->label_op1->setText("Число радиан");//меняем лейбл первого элемента под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Тангенс");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_acos_clicked()//настройки режима АРККОСИНУС
{
    ui->label_op1->setText("Число");//меняем лейбл первого элемента под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Арккосинус рад.");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_radioButton_atan_clicked()//настройки режима АРКТАНГЕНС
{
    ui->label_op1->setText("Число");//меняем лейбл первого элемента под операцию
    ui->label_op2->setVisible(false);//Убираем второй лейбл
    ui->label_res->setText("Арктангенс рад.");//меняем лейбл результата под операцию
    ui->lineEdit_res->clear();//очищаем строку результата
    ui->label_condition->setVisible(false);//убираем сообщение об ошибке
    ui->lineEdit_op2->clear();//очищаем очищаем ненужную строку
    ui->lineEdit_op2->setReadOnly(true);//закрываем изменение второго поля
    ui->lineEdit_op2->setVisible(false);//убираем второе поле
}
void MainWindow::on_pushButton_equals_clicked()//при нажатии кнопки =
{
    double op1,op2,result;//добавляем переменные типа double
    QString str;//добавляем переменную типа Qstring
    bool flag;//Добавляем переменную для проверки результата типа Bool
    int razr;//Добавляем переменную для разрядов после запятой

    if(ui->radioButton_BigDatamode->isChecked())//Если включен режим больших чисел
    {
        if (ui->radioButton_plus->isChecked())//Если включен режим СЛОЖЕНИЕ
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
                    ui->label_condition->hide();//Скрываем сообщение об ошибке
                    if(qIsNaN(result) or qIsInf(result)) //проверяем результат на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("Число выходит за принятый диапозон");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
                    }
                    else
                    {
                        str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                        razr=str.toInt(&flag);//переносим количество разрядов в переменную
                        if(flag)//если перенос прошел успешно
                        {
                            if(razr<0)//проверяем число разрядов на подходящее значение
                            {
                                ui->lineEdit_res->clear();//очищаем поле результата
                                ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                                ui->label_condition->show();//показываем сообщение об ошибке
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
                            ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                            ui->label_condition->show();//показываем сообщение об ошибке
                        }
                    }
                }
                else
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Ошибка в слагаемом 2");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в слагаемом 1");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_minus->isChecked())//Если включен режим ВЫЧИТАНИЕ
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
                    ui->label_condition->hide();//Скрываем сообщение об ошибке
                    if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("Число выходит за принятый диапозон");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
                    }
                    else
                    {
                        str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                        razr=str.toInt(&flag);//переносим количество разрядов в переменную
                        if(flag)//если перенос прошел успешно
                        {
                            if(razr<0)//проверяем число разрядов на подходящее значение
                            {
                                ui->lineEdit_res->clear();//очищаем поле результата
                                ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                                ui->label_condition->show();//показываем сообщение об ошибке
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
                            ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                            ui->label_condition->show();//показываем сообщение об ошибке
                        }
                    }
                }
                else
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Ошибка в вычитаемом");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в уменьшаемом");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_mul->isChecked())//Если включен режим УМНОЖЕНИЕ
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
                    ui->label_condition->hide();//Скрываем сообщение об ошибке
                    if(qIsNaN(result) or qIsInf(result)) //проверяем результат на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
                    }
                    else
                    {
                        str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                        razr=str.toInt(&flag);//переносим количество разрядов в переменную
                        if(flag)//если перенос прошел успешно
                        {
                            if(razr<0)//проверяем число разрядов на подходящее значение
                            {
                                ui->lineEdit_res->clear();//очищаем поле результата
                                ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                                ui->label_condition->show();//показываем сообщение об ошибке
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
                            ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                            ui->label_condition->show();//показываем сообщение об ошибке
                        }
                    }
                }
                else
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Ошибка в множителе 2");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в множителе 1");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_div->isChecked())//Если включен режим ДЕЛЕНИЕ
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
                    ui->label_condition->hide();//Скрываем сообщение об ошибке
                    if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
                    }
                    else
                    {
                        str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                        razr=str.toInt(&flag);//переносим количество разрядов в переменную
                        if(flag)//если перенос прошел успешно
                        {
                            if(razr<0)//проверяем число разрядов на подходящее значение
                            {
                                ui->lineEdit_res->clear();//очищаем поле результата
                                ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                                ui->label_condition->show();//показываем сообщение об ошибке
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
                            ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                            ui->label_condition->show();//показываем сообщение об ошибке
                        }
                    }
                }
                else
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Ошибка в делителе");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в делимом");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_quad->isChecked())//Если включен режим СТЕПЕНЬ
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                str=ui->lineEdit_op2->text();//содержимое второго поля помещаем в переменную
                op2=str.toDouble(&flag);//переносим значение строки в вторую переменную(с проверкой)
                if(flag)//если перенос прошел успешно
                {
                    if(qIsNaN(op2) or qIsInf(op2))//проверяем вторую переменную на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
                    }
                    else
                    {
                        if(qIsNull(op1))//если основание равно 0
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
                                ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                                ui->label_condition->show();//показываем сообщение об ошибке
                            }
                            else
                            {
                                str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                                razr=str.toInt(&flag);//переносим количество разрядов в переменную
                                if(flag)//если перенос прошел успешно
                                {
                                    if(razr<0)//проверяем число разрядов на подходящее значение
                                    {
                                        ui->lineEdit_res->clear();//очищаем поле результата
                                        ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                                        ui->label_condition->show();//показываем сообщение об ошибке
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
                                    ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                                    ui->label_condition->show();//показываем сообщение об ошибке
                                }
                            }
                        }
                    }
                }
                else
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Ошибка в степени");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в основании");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_S->isChecked())//Если включен режим КОРЕНЬ КВАДРАТНЫЙ
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=sqrt(op1);//высчитываем результат
                ui->label_condition->hide();//Скрываем сообщение об ошибке
                if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
                else
                {
                    str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                    razr=str.toInt(&flag);//переносим количество разрядов в переменную
                    if(flag)//если перенос прошел успешно
                    {
                        if(razr<0)//проверяем число разрядов на подходящее значение
                        {
                            ui->lineEdit_res->clear();//очищаем поле результата
                            ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                            ui->label_condition->show();//показываем сообщение об ошибке
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
                        ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
                    }
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка под корнем");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if(ui->radioButton_factorial->isChecked())//Если включен режим ФАКТОРИАЛ
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                if(qIsNaN(op1) or qIsInf(op1) or qIsNull(op1))//проверяем введённые данные на допустимые для функции значения
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
                else
                {
                    static double maxfact = 170.62435;//вводим предельно возможное значение для функции факториала
                    op2=str.toDouble();//переносим значение во вторую переменную,чтобы не искажать первую
                    if(op2<maxfact)//Сравниваем вторую переменную с пределом
                    {
                        result=factorial(op1);//Считаем результат используя нашу функцию и первую перменную
                        ui->label_condition->hide();//Убираем поле ошибки
                        if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                        {
                            ui->lineEdit_res->clear();//очищаем поле результата
                            ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                            ui->label_condition->show();//показываем сообщение об ошибке
                        }
                        else
                        {
                            str=ui->lineEdit_razr->text();//считываем количество разрядов после запятой
                            razr=str.toInt(&flag);//переносим количество разрядов в переменную
                            if(flag)//если перенос прошел успешно
                            {
                                if(razr<0)//проверяем число разрядов на подходящее значение
                                {
                                    ui->lineEdit_res->clear();//очищаем поле результата
                                    ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                                    ui->label_condition->show();//показываем сообщение об ошибке
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
                                ui->label_condition->setText("Ошибка в числе разрядов!");//меняем текст лейбла ошибки
                                ui->label_condition->show();//показываем сообщение об ошибке
                            }
                        }
                    }
                    else
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("Число выходит за требуемый диапозон");//меняем текст лейбла ошибки
                        ui->label_condition->setVisible(true);//показываем сообщение об ошибке
                    }
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в числе");//выводим сообщение об ошибке
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else
        {
            ui->lineEdit_res->clear();//очищаем поле результата
            ui->label_condition->setText("Похоже вы находитесь не в том режиме!!!");//меняем текст лейбла ошибки
            ui->label_condition->setVisible(true);//показываем сообщение об ошибке
        }
    }
    else if(ui->radioButton_normalmode->isChecked())//если включен нормальный режим
    {
        if (ui->radioButton_plus->isChecked())//Если включен режим СЛОЖЕНИЕ
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
                    ui->label_condition->hide();//Убираем поле ошибки
                    if(qIsNaN(result) or qIsInf(result)) //проверяем результат на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("Число выходит за принятый диапозон");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
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
                    ui->label_condition->setText("Ошибка в слагаемом 2");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в слагаемом 1");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_minus->isChecked())//Если включен режим ВЫЧИТАНИЕ
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
                    ui->label_condition->hide();//Убираем поле ошибки
                    if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("Число выходит за принятый диапозон");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
                    }
                    else {
                        str.setNum(result);//Переносим результат в строчную переменную
                        ui->lineEdit_res->setText(str);//выводим результат
                        ui->label_condition->hide();//Скрываем сообщение об ошибке
                    }
                }
                else
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Ошибка в вычитаемом");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в уменьшаемом");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_mul->isChecked())//Если включен режим УМНОЖЕНИЕ
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
                    ui->label_condition->hide();//Убираем поле ошибки
                    if(qIsNaN(result) or qIsInf(result)) //проверяем результат на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
                    }
                    else {
                        str.setNum(result);//Переносим результат в строчную переменную
                        ui->lineEdit_res->setText(str);//выводим результат
                        ui->label_condition->hide();//Скрываем сообщение об ошибке
                    }
                }
                else
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Ошибка в множителе 2");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в множителе 1");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_div->isChecked()) //Если включен режим ДЕЛЕНИЕ
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
                    ui->label_condition->hide();//Убираем поле ошибки
                    if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
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
                    ui->label_condition->setText("Ошибка в делителе");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в делимом");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_quad->isChecked())//Если включен режим ВОЗВЕДЕНИЕ В СТЕПЕНЬ
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                str=ui->lineEdit_op2->text();//содержимое второго поля помещаем в переменную
                op2=str.toDouble(&flag);//переносим значение строки в вторую переменную(с проверкой)
                if(flag)//если перенос прошел успешно
                {
                    if(qIsNaN(op2) or qIsInf(op2))//проверяем вторую переменную на допустимость
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                        ui->label_condition->show();//показываем сообщение об ошибке
                    }
                    else
                    {
                        if(qIsNull(op1))//Если основание равно нулю
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
                                ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                                ui->label_condition->show();//показываем сообщение об ошибке
                            }
                            else
                            {
                                str.setNum(result) ;//Переносим результат в строчную переменную
                                ui->lineEdit_res->setText(str);//выводим результат
                                ui->label_condition->hide();//Скрываем сообщение об ошибке
                            }
                        }
                    }
                }
                else
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Ошибка в степени");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в основании");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_S->isChecked())//Если включен режим КОРЕНЬ КВАДРАТНЫЙ
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=sqrt(op1);//высчитываем результат
                ui->label_condition->hide();//Убираем поле ошибки
                if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
                else
                {
                    str.setNum(result) ;//Переносим результат в строчную переменную
                    ui->lineEdit_res->setText(str);//выводим результат
                    ui->label_condition->hide();//Скрываем сообщение об ошибке
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка под корнем");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if(ui->radioButton_factorial->isChecked())//Если включен режим ФАКТОРИАЛ
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                if(qIsNaN(op1) or qIsInf(op1) or qIsNull(op1))
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                    ui->label_condition->show();//показываем сообщение об ошибке
                }
                else
                {
                    static double maxfact = 170.62435;//вводим предельно возможное значение для функции факториала
                    op2=str.toDouble();//Переносим значение поля во вторую переменную(чтобы не портить первую)
                    if(op2<maxfact)//сравниваем вторую переменную с предельно возможным значением для функции факториала
                    {
                        result=factorial(op1);//Считаем результат используя функцию факториала и первую переменную
                        ui->label_condition->hide();//Скрываем поле ошибки
                        if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                        {
                            ui->lineEdit_res->clear();//очищаем поле результата
                            ui->label_condition->setText("За гранью моего понимания!");//меняем текст лейбла ошибки
                            ui->label_condition->show();//показываем сообщение об ошибке
                        }
                        else
                        {
                            str.setNum(result) ;//Переносим результат в строчную переменную
                            ui->lineEdit_res->setText(str);//выводим результат
                            ui->label_condition->hide();//Скрываем сообщение об ошибке
                        }
                    }
                    else
                    {
                        ui->lineEdit_res->clear();//очищаем поле результата
                        ui->label_condition->setText("Число выходит за требуемый диапозон");//меняем текст лейбла ошибки
                        ui->label_condition->setVisible(true);//показываем сообщение об ошибке
                    }
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в числе");//выводим сообщение об ошибке
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_sin->isChecked())//Если включен режим СИНУС
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=sin(op1);//высчитываем результат
                if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Число выходит за требуемый диапозон");//меняем текст лейбла ошибки
                    ui->label_condition->setVisible(true);//показываем сообщение об ошибке
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
                ui->label_condition->setText("Ошибка в числе");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_cos->isChecked())//Если включен режим КОСИНУС
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=cos(op1);//высчитываем результат
                if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                {
                    ui->lineEdit_res->clear();//очищаем поле результата
                    ui->label_condition->setText("Число выходит за требуемый диапозон");//меняем текст лейбла ошибки
                    ui->label_condition->setVisible(true);//показываем сообщение об ошибке
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
                ui->label_condition->setText("Ошибка в числе");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_tg->isChecked())//Если включен режим ТАНГЕНС
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=tan(op1);//высчитываем результат
                if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                {
                    ui->label_condition->setText("Число выходит за принятый диапозон");//меняем текст лейбла ошибки
                    ui->label_condition->setVisible(true);//показываем сообщение об ошибке
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
                ui->label_condition->setText("Ошибка в числе");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_acos->isChecked())//Если включен режим АРККОСИНУС
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=acos(op1);//высчитываем результат
                if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                {
                    ui->label_condition->setText("Число выходит за принятый диапозон");//меняем текст лейбла ошибки
                    ui->label_condition->setVisible(true);//показываем сообщение об ошибке
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
                ui->label_condition->setText("Ошибка в числе");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if (ui->radioButton_asin->isChecked())//Если включен режим АРКСИНУС
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                result=asin(op1);//высчитываем результат
                if(qIsNaN(result) or qIsInf(result) )//проверяем результат на допустимость
                {
                    ui->label_condition->setText("Число выходит за принятый диапозон");//меняем текст лейбла ошибки
                    ui->label_condition->setVisible(true);//показываем сообщение об ошибке
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
                ui->label_condition->setText("Ошибка в числе");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
        else if(ui->radioButton_atan->isChecked())//Если включен режим АРКТАНГЕНС
        {
            str=ui->lineEdit_op1->text();//содержимое первого поля помещаем в переменную
            op1=str.toDouble(&flag);//переносим значение строки в первую переменную(с проверкой)
            if(flag)//если перенос прошел успешно
            {
                if(qIsNaN(op1) or qIsInf(op1))
                {
                    ui->label_condition->setText("Число выходит за принятый диапозон");//меняем текст лейбла ошибки
                    ui->label_condition->setVisible(true);//показываем сообщение об ошибке
                    ui->lineEdit_res->clear();//очищаем поле результата
                }
                else
                {
                    result=atan(op1);//высчитываем результат
                    if(qIsNaN(result) or qIsInf(result))//проверяем результат на допустимость
                    {
                        ui->label_condition->setText("Число выходит за принятый диапозон");//меняем текст лейбла ошибки
                        ui->label_condition->setVisible(true);//показываем сообщение об ошибке
                        ui->lineEdit_res->clear();//очищаем поле результата
                    }
                    else
                    {
                        str.setNum(result);//Переносим результат в строчную переменную
                        ui->lineEdit_res->setText(str);//выводим результат
                        ui->label_condition->hide();//Скрываем сообщение об ошибке
                    }
                }
            }
            else
            {
                ui->lineEdit_res->clear();//очищаем поле результата
                ui->label_condition->setText("Ошибка в числе");//меняем текст лейбла ошибки
                ui->label_condition->setVisible(true);//показываем сообщение об ошибке
            }
        }
    }
}
