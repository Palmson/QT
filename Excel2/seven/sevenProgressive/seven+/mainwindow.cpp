#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_clear->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_count_valueChanged(int arg1)
{
    x.resize(arg1); //изменяем размеры динамического массива
    y.resize(arg1);//изменяем размеры динамического массива
    opr.resize(arg1);//изменяем размеры динамического массива
    len.resize(arg1);//изменяем размеры динамического массива
    ui->tableWidget_massive->setRowCount(arg1); //меняем количество строк в массиве
}
bool MainWindow::isCorrectValues()//функция для проверки введённых значений
{
    int size = ui->tableWidget_massive->rowCount();//создаём переменную для хранения количества элементов
    x.resize(size); //изменяем размеры динамического массива
    y.resize(size);//изменяем размеры динамического массива
    opr.resize(size);//изменяем размеры динамического массива
    len.resize(size);//изменяем размеры динамического массива
    bool flag;//создаём переменную для проверки
    double item = 0.0;//создаём переменную для хранения текущего элемента
    for (int i = 0;i<size;i++) //двумерный цикл перебора массива
    {
        for (int j = 0;j<2;j++)
        {
            if (ui->tableWidget_massive->item(i,j)!=nullptr)//если текущий элемент существует
            {
                item = ui->tableWidget_massive->item(i,j)->text().toDouble(&flag);//переносим значение в переменную с проверкой
                if (!flag or qIsNaN(item) or qIsInf(item)) //если ошибка
                {
                    ui->tableWidget_massive->item(i,j)->setBackground(Qt::red);//красим ячейку в красный
                }
                else
                {
                    ui->tableWidget_massive->item(i,j)->setBackground(Qt::white);//красим ячейку в белый
                }
            }
            else
            {
                QTableWidgetItem *ti = new QTableWidgetItem;//создаём ярлык для создания элемента таблицы
                ui->tableWidget_massive->setItem(i,j,ti);//создаём текущий элемент таблицы
                ui->tableWidget_massive->item(i,j)->setBackground(Qt::red);//красим ячейку в красный
            }
        }
    }
    if(!Changed)
    {
        QMessageBox::information(this, "Ошибка","Вы не заполнили таблицу!");//выводим ошибку
        return false;//возвращаем отрицательное значение
    }
    for (int i=0;i<size;i++) //цикл перебора массива
    {
        if (ui->tableWidget_massive->item(i,0)!=nullptr)//если текущий элемент существует
        {
            x[i] =  ui->tableWidget_massive->item(i,0)->text().toDouble(&flag);//переносим значение в элемент массива координат X с проверкой
            if (!flag) //если ошибка
            {
                ui->label_S_value->clear();//очищаем поля ответа
                ui->label_P_value->clear();
                QMessageBox::information(this, "Ошибка","Некоторые значения X заполнены некорректно! Например, X" + QString::number(i+1),QMessageBox::Ok);//выводим ошибку
                return false;//возвращаем отрицательное значение
            }
        }
        else
        {
            ui->label_S_value->clear();//очищаем поля ответа
            ui->label_P_value->clear();
            QMessageBox::information(this, "Ошибка","Некоторые значения X не заполнены! Например, X" + QString::number(i+1),QMessageBox::Ok);//выводим ошибку
            return false;//возвращаем отрицательное значение
        }

        if (ui->tableWidget_massive->item(i,1)!=nullptr)//если текущий элемент существует
        {
            y[i] =  ui->tableWidget_massive->item(i,1)->text().toDouble(&flag); //переносим значение в элемент массива координат Y с проверкой
            if (!flag)//если ошибка
            {
                ui->label_S_value->clear();//очищаем поля ответа
                ui->label_P_value->clear();
                QMessageBox::information(this, "Ошибка","Некоторые значения Y заполнены некорректно! Например, Y" + QString::number(i+1),QMessageBox::Ok);//выводим ошибку
                return false;//возвращаем отрицательное значение
            }
        }
        else
        {
            ui->label_S_value->clear();//очищаем поля ответа
            ui->label_P_value->clear();
            QMessageBox::information(this, "Ошибка","Некоторые значения Y не заполнены! Например, Y" + QString::number(i+1),QMessageBox::Ok);//выводим ошибку
            return false;//возвращаем отрицательное значение
        }
    }
    return true;//возвращаем положительное значение
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->label_P_value->clear();//очищаем поля ответа
    ui->label_S_value->clear();
    Changed=false;//ставим поверку на изменения в отрицательное значение
    ui->tableWidget_massive->clear();//очищаем таблицу
    ui->spinBox_count->setValue(3);//ставим три элемента
    ui->tableWidget_massive->setHorizontalHeaderLabels(QStringList() << "X" << "Y");//ставим названия столбцов
}

void MainWindow::on_tableWidget_massive_itemChanged(QTableWidgetItem *item)
{
    if (no_auto_change)//если изменения разрешены
    {
        ui->label_P_value->clear();//очищаем результаты
        ui->label_S_value->clear();
        if(item==nullptr)//если в строке ничего нет
        {
            item->setBackground(QBrush(Qt::red));//меняем цвет ячейки на красный
        }
        else
        {
            bool flag;//создаём переменную для проверки
            double val = item->text().toDouble(&flag);//переносим значение из элемента в переменную с проверкой
            if(!flag or qIsInf(val) or qIsNaN(val))//Если не подходит
            {
                item->setBackground(QBrush(Qt::red));//меняем цвет ячейки на красный
            }
            else
            {
                item->setBackground(QBrush(Qt::white));//меняем цвет ячейки на белый
            }
        }
        Changed=true;//ставим поверку на изменения в положительное значение
    }

}
double MainWindow::side(double ax,double bx,double ay,double by)
{
    return sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
}
void MainWindow::on_pushButton_find_clicked()
{
    no_auto_change = false;//блокируем изменения
    if(isCorrectValues())//если все значения подходят
    {
        int size = ui->tableWidget_massive->rowCount(); //создаём переменную для хранения количества элементов
        if(size==3)
        {
            double x1 =x[0];
            double y1 =y[0];
            double x2 =x[1];
            double y2 =y[1];
            double x3 =x[2];
            double y3 =y[2];
            double a=side(x2,x1,y2,y1);
            double b=side(x3,x1,y3,y1);
            double c=side(x2,x3,y2,y3);
            double angle =((acos((a*a+b*b-c*c)/(2*a*b)))*180)/M_PI;
            static double smallest = 4.9E-324;//создаём минимально допустимое значение для дабла
            static double largest = 1.8E+307;//создаём максимально допустимое значение для дабла
            static double wrongangle1 = 180;//создаём переменную наибольшего угла в вырожденном треугольнике
            static double wrongangle2 = 360;//создаём переменную малого угла в вырожденном треугольнике
            static double fmodMAX = 180E+20;//создаём максимально допустимое значение для функции fmod
            static double fmodMIN = -180E+20;//создаём минимально допустимое значение для функции fmod
            double side1,side2,result;//добавляем переменные для хранения значений параметров и результата
            side1=a;//переносим значение в переменную
            if(side1>smallest and side1<largest)//проверяем на правильность введённые данные
            {
                side2=b;//переносим значение в переменную
                if(side2>smallest and  side2<largest)//проверяем на правильность введённые данные
                {
                    if((fmod(angle,wrongangle1) == 0.0) or (fmod(angle,wrongangle1) == -0.0))//проверяем треугольник на вырожденный
                    {
                        if((fmod(angle,wrongangle2) == 0.0) or (fmod(angle,wrongangle2) == -0.0) or qIsNull(angle))//проверяем кратен ли угол 360 или равен 0(является ли малым в треугольнике)
                        {
                            double maxSide=fmax(side1,side2);//находим максимальную из сторон
                            double minSide=fmin(side1,side2);//находим минимальную из сторон
                            result=side1+side2+maxSide-minSide;//вычисляем периметр вырожденного треугольника
                            if(qIsInf(result) or qIsNaN(result) or qIsNull(result))//проверяем треугольник на предмет существования в нашем диапозоне(на всякий случай)
                            {
                                QMessageBox::information(this,"Ошибка","Треугольника не существует или его периметр выходит за допустимые рамки измерения!",QMessageBox::Ok);//выводим ошибку
                                ui->label_S_value->clear();//очищаем результаты
                                ui->label_P_value->clear();
                            }
                            else
                            {
                                ui->label_P_value->setNum(result);//выводим периметр
                            }
                            ui->label_S_value->setNum(0);//выводим площадь
                        }
                        else
                        {
                            result=2*side2+2*side1;//вычисляем периметр вырожденного треугольника
                            ui->label_P_value->setNum(result);//выводим периметр
                            if(qIsInf(result) or qIsNaN(result) or qIsNull(result))//проверяем треугольник на предмет существования в нашем диапозоне(на всякий случай)
                            {
                                QMessageBox::information(this,"Ошибка","Треугольника не существует или его периметр выходит за допустимые рамки измерения!",QMessageBox::Ok);//выводим ошибку
                                ui->label_S_value->clear();//очищаем результаты
                                ui->label_P_value->clear();
                            }
                            else
                            {
                               ui->label_P_value->setNum(result);//выводим периметр
                            }
                            ui->label_S_value->setNum(0);//выводим площадь
                        }
                    }
                    else if(angle>fmodMIN and   angle<fmodMAX)//проверяем попадает ли угол в диапозон
                    {
                        angle=fabs(angle);//находим модуль угла
                        result=sqrt(pow(side1,2)+pow(side2,2)-2*side1*side2*cos(angle*M_PI/180))+side1+side2;//рассчитываем периметр

                        if(qIsInf(result) or qIsNaN(result) or qIsNull(result))//проверяем треугольник на предмет существования в нашем диапозоне
                        {
                            QMessageBox::information(this,"Ошибка","Треугольника не существует или его периметр выходит за допустимые рамки измерения!",QMessageBox::Ok);//выводим ошибку
                            ui->label_S_value->clear();//очищаем результаты
                            ui->label_P_value->clear();
                        }
                        else//если всё ок
                        {
                            ui->label_P_value->setNum(result);//выводим периметр
                            result=side1*side2*sin(angle*M_PI/180)/2;//рассчитываем площадь
                            if(qIsInf(result) or qIsNaN(result) or qIsNull(result))//проверяем треугольник на предмет существования в нашем диапозоне(на всякий случай)
                            {
                                QMessageBox::information(this,"Ошибка","Треугольника не существует или его площадь выходит за допустимые рамки измерения!",QMessageBox::Ok);//выводим ошибку
                                ui->label_S_value->clear();//очищаем результаты
                            }
                            else
                            {
                                ui->label_S_value->setNum(result);//выводим площадь
                            }
                        }
                    }
                    else if(angle<fmodMIN or angle>fmodMAX)
                    {
                        QMessageBox::information(this,"Ошибка","Угол треугольника выходит за пределы проверки \"fmod\".",QMessageBox::Ok);//выводим ошибку
                        ui->label_S_value->clear();//очищаем результаты
                        ui->label_P_value->clear();
                    }
                    else//если ничего не подошло
                    {
                        QMessageBox::information(this,"Ошибка","Угол треугольника выходит за пределы или введён некорректно.",QMessageBox::Ok);//выводим ошибку
                        ui->label_S_value->clear();//очищаем результаты
                        ui->label_P_value->clear();
                    }
                }
                else if(side2>largest)//сравниваем сторону с наибольшим возможным значением
                {
                    QMessageBox::information(this,"Ошибка","Сторона треугольника слишком большая",QMessageBox::Ok);//выводим ошибку
                    ui->label_S_value->clear();//очищаем результаты
                    ui->label_P_value->clear();
                }
                else//если ничего не подошло
                {
                    QMessageBox::information(this,"Ошибка","Сторона треугольника слишком меленькая",QMessageBox::Ok);//выводим ошибку
                    ui->label_S_value->clear();//очищаем результаты
                    ui->label_P_value->clear();
                }
            }
            else if(side1>=largest) //сравниваем сторону с наибольшим возможным значением
            {
                QMessageBox::information(this,"Ошибка","Сторона треугольника слишком большая",QMessageBox::Ok);//выводим ошибку
                ui->label_S_value->clear();//очищаем результаты
                ui->label_P_value->clear();
            }
            else//если ничего не подошло
            {
                QMessageBox::information(this,"Ошибка","Сторона треугольника слишком маленькая",QMessageBox::Ok);//выводим ошибку
                ui->label_S_value->clear();//очищаем результаты
                ui->label_P_value->clear();
            }
        }
        else
        {
            double S = 1.0,sum = 0.0,P = 0.0; //создаём переменные для хранения значений площади, периметра, суммы

            for (int i=0;i<size-1;i++) //цикл перебора массива
            {
                opr[i] = x[i] * y[i+1] - x[i+1] * y [i]; //находим определители по формуле
                sum += opr[i];//считаем сумму определителей
                len[i] = sqrt((x[i+1]-x[i])*(x[i+1]-x[i]) + (y[i+1]-y[i])*(y[i+1]-y[i]));//находим длины векторов по формуле
                P=P+len[i]; //суммируем все длины векторов
            }
            opr[size-1] = x[size-1]*y[0] - x[0]*y[size-1]; //находим последний определитель
            sum += opr[size-1]; //добавляем последний определитель к сумме
            len[size-1] = sqrt((x[0]-x[size-1])*(x[0]-x[size-1]) + (y[0]-y[size-1])*(y[0]-y[size-1])); //считаем длину последнего вектора
            P+=len[size-1];//добавляем последнюю длину к периметру

            if ((S<1e-15) and (S>-1)) //если значение площади около нуля
            {
                ui->label_S_value->clear();//очищаем результаты
                ui->label_P_value->clear();
            }
            else
            {
                if (qIsInf(P) or qIsNaN(P))//если значение периметра выходит за диапозон
                {
                    ui->label_S_value->clear();//очищаем результаты
                    ui->label_P_value->clear();
                    QMessageBox::information(this, "Ошибка","Значение периметра вышло за диапазон!",QMessageBox::Ok);//выводим ошибку
                    return;//завершаем код
                }
                else
                {
                    ui->label_P_value->setNum(P);//выводим периметр
                }

            }
            S = abs(sum/2); //считаем площадь по формуле Гаусса
            if (qIsInf(S) or qIsNaN(S)) //если значение площади выходит за диапозон
            {
                ui->label_S_value->clear();//очищаем результаты
                ui->label_P_value->clear();
                QMessageBox::information(this, "Ошибка","Значение площади вышло за диапазон!",QMessageBox::Ok);//выводим ошибку
            }
            else
            {
                if (weHaveCrossing()) //если есть пересечение сторон
                {
                    ui->label_S_value->setText("...");//выводим площадь
                    QMessageBox::information(this,"Информация","Многоугольник самопересекается",QMessageBox::Ok);//выводим ошибку
                } else
                {
                    if ((S<1e-15) and (S>-1))  //если значение площади около нуля
                    {
                        if ((P<1e-15) and (P>-1))  //если значение периметра около нуля
                        {
                            QMessageBox::information(this, "Информация","Дана точка",QMessageBox::Ok);//выводим информацию
                        }
                        else
                        {
                            ui->label_P_value->setNum(P);//выводим периметр
                            QMessageBox::information(this, "Информация","Дана прямая",QMessageBox::Ok);//выводим информацию
                        }
                    } else
                    {
                        ui->label_S_value->setNum(S);//выводим площадь
                    }
                }
            }
        }
    }

    no_auto_change = true;//разблокируем изменения
}
double MainWindow::getB(double x1, double y1, double x2, double y2) //функция нахождения коэффициента b в уравнении стороны
{
    return y2 - (x2*(y2-y1))/(x2-x1); //находим коэффициент по формуле
}

double MainWindow::getK(double x1, double y1, double x2, double y2) //функция нахождения коэффициента k в уравнении стороны
{
    return (y2-y1)/(x2-x1); //находим коэффициент по формуле
}

bool MainWindow::isCrossing(double x1, double y1, double x2, double y2,double x3, double y3, double x4, double y4) //функция для локальной проверки пересечения
{
    double k1 = getK(x1,y1,x2,y2); //объявляем переменные для хранения коэффициентов K
    double k2 = getK(x3,y3,x4,y4);
    double b1 = getB(x1,y1,x2,y2); //объявляем переменные для хранения коэффициентов b
    double b2 = getB(x3,y3,x4,y4);
    double x_crossing = (b2-b1)/(k1-k2); //переменная для хранения пересечения по X
    double y_crossing = k1 * x_crossing + b1; //переменная для хранения пересечения по Y
    double px1 = 0.0; //задаём переменный для хранения координат X вершин прямоугольника
    double px2 = 0.0;
    double py1 = 0.0; //задаём переменный для хранения координат Y вершин прямоугольника
    double py2 = 0.0;
    double X_Mas[4];//создаём массив для хранения текущих координат X
    double Y_Mas[4];//создаём массив для хранения текущих координат Y
    X_Mas[0] = x1; //заполняем массив координатами по X
    X_Mas[1] = x2;
    X_Mas[2] = x3;
    X_Mas[3] = x4;
    Y_Mas[0] = y1;//заполняем массив координатами по Y
    Y_Mas[1] = y2;
    Y_Mas[2] = y3;
    Y_Mas[3] = y4;
    sorting(X_Mas,4);//Сортируем массивы
    sorting(Y_Mas,4);
    px1 = X_Mas[1];//Записываем центральные значения X
    px2 = X_Mas[2];
    py1 = Y_Mas[1];//Записываем центральные значения Y
    py2 = Y_Mas[2];

    return (((x_crossing > px1) or (abs(x_crossing - px1) < pow(10, -15))) //возвращаем ответ полученный из формулы проверки на пересечения
            and ((x_crossing < px2) or (abs(x_crossing - px2) < pow(10,-15)))
            and ((y_crossing > py1) or (abs(y_crossing - py1) < pow(10, -15)))
            and ((y_crossing < py2) or (abs(y_crossing - py2) < pow(10, -15))));
}

void MainWindow::sorting(double *mas, int row) //функция сортировки типа Пузырёк
{
    for (int j=1;j<row; j++)//цикл перебора массива с 2 элемента
    {
        for (int i = 0;i<row-1; i++)//цикл перебора массива
        {
            if(mas[i] > mas[j])//если элемент по i больше элемента по j
            {
                double t = mas [i]; //создаём переменную для хранения текущего эллемента
                mas [i] = mas [j];//меняем элементы местами
                mas [j] = t;
            }
        }
    }
}

bool MainWindow::weHaveCrossing() //проверка на наличие пересечений
{
    int size = ui->tableWidget_massive->rowCount();//создаём переменную для хранения количества элементов
    if (size<4)//если элементов меньше 4
    {
        return false;//возвращаем отрицательное значение
    }

    for (int i =0; i<size-1;i++) //двумерный цикл перебора массива
    {
        for (int j =0; j<size-1;j++)
        {
            if (abs(i-j)>1) //если элементы не совпадают
            {
                double x1 = x[i];//записываем координаты первой точки в переменную
                double y1 = y[i];
                double x2 = x[i+1];//записываем координаты второй точки в переменную
                double y2 = y[i+1];

                double x3 = x[j];//записываем координаты третьей точки в переменную
                double y3 = y[j];
                double x4 = x[j+1];//записываем координаты четвёртой точки в переменную
                double y4 = y[j+1];

                bool crossing = isCrossing(x1,y1,x2,y2,x3,y3,x4,y4); //проверяем пересечение отрезков через функцию
                if (crossing) //если отрезки перечекаются
                {
                    return crossing;//возвращаем положительное значение
                }
            }
        }
    }

    for (int j=1;j<size-2;j++)//цикл перебора элементов последней стороны
    {
        double x1 = x[0];//записываем координаты первой точки массива в переменную
        double y1 = y[0];
        double x2 = x[size-1];//записываем координаты последней точки массива в переменную
        double y2 = y[size-1];

        double x3 = x[j];//записываем координаты соседних точек в переменную
        double y3 = y[j];
        double x4 = x[j+1];
        double y4 = y[j+1];

        bool crossing = isCrossing(x1,y1,x2,y2,x3,y3,x4,y4); //проверяем пересечение отрезков через функцию
        if (crossing) //если отрезки перечекаются
        {
            return crossing;//возвращаем положительное значение
        }
    }
    return false;//возвращаем отрицательное значение
}

