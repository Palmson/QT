#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QMessageBox>//добавляем библиотеку для вывода сообщений
#include "math.h"//добавляем библиотеку с математическими формулами

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox_count->setValue(2);//задаём начальное количество столбцов
    checkChange=false;//ставим проверку на изменения в положение false
    checkSorting=false;//ставим проверку на сортировку в положение false
    allowChange=true;//ставим проверку на допустимость изменения в положение false
    ui->lineEdit_searching_itemsStroke->setReadOnly(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_spinBox_count_valueChanged(int arg1)//когда меняем значение спинбокса
{
    ui->tableWidget_massive->setRowCount(arg1);//выставляем количество строк
}
void MainWindow::on_pushButton_random_clicked()//когда нажимается кнопка Рандомное количество ячеек
{
    int rows =1 + rand()%100;// Генерируем рандомное значение от 1 до 100
    ui->spinBox_count->setValue(rows);//выставляем количество строк
}
void MainWindow::on_pushButton_removelast_clicked()//когда нажимается кнопка Удалить последнюю ячейку
{
    int rows = ui->tableWidget_massive->rowCount();//считываем количество строк
    ui->spinBox_count->setValue(rows-1);//уменьшаем количество строк на 1
}
void MainWindow::on_pushButton_randomValues_clicked()//когда нажимается кнопка Рандомное заполнение ячеек
{   
    size=ui->tableWidget_massive->rowCount();//обновляем глобальную переменную размера массива(количества строк)
    if(size==0)//если нет строк
    {
        QMessageBox::information(this,"Ошибка","Строки отсутствуют!",QMessageBox::Ok);//выводим ошибку
    }
    else
    {
        for (int i=0; i<size; i++)//цикл для перебора массива
        {
            int number =1+rand()%1000;//создаём номер от 1 до 1000
            int sign = rand()%2;//создаём номер от 0 до 1
            if (sign < 1)//проверяем на одно из двух значений
                number *= -1;//меняем знак
            QString str;//создаём переменную для записи текста
            str.setNum(number);//записываем число
            if(ui->tableWidget_massive->item(i, 0)==nullptr)//если в строке ничего нет
            {
                ui->tableWidget_massive->setItem(i, 0, new QTableWidgetItem(str));//создаём элемент и вписываем значение
            }
            else
            {
                ui->tableWidget_massive->item(i, 0)->setText(str);//вписываем значение
            }
        }
        checkChange=true;//ставим проверку на изменения в положение true
        checkSorting=false;//ставим проверку на сортировку в положение false
    }

}
bool MainWindow::isCorrectItem(QTableWidgetItem *item)//создаём функцию для проверки введённых значений
{
    if(item->text()=="")//если в строке ничего нет
    {
        item->setBackground(QBrush(Qt::red));//меняем цвет ячейки на красный
        return false;//возвращаем значение
    }
    else
    {
        bool flag;//создаём переменную для проверки
        double val = item->text().toDouble(&flag);//переносим значение из элемента в переменную с проверкой
        if(!flag or qIsInf(val) or qIsNaN(val))//Если не подходит
        {
            item->setBackground(QBrush(Qt::red));//меняем цвет ячейки красный
            return false;//возвращаем значение
        }
        else
        {
            item->setBackground(QBrush(Qt::white));//меняем цвет ячейки на белый
            return true;//возвращаем значение
        }
    }
}
bool MainWindow::isCorrectValues()//создаём функцию для проверки введённых значений
{
    size=ui->tableWidget_massive->rowCount();//обновляем глобальную переменную размера массива(количества строк)
    if (!checkChange)//если ничего не изменяли
    {
        QMessageBox::information(this,"Ошибка","Вы не заполнили таблицу",QMessageBox::Ok);//выводим ошибку
        for(int i=0; i<size;i++)//цикл перебора массива
        {
            QTableWidgetItem * itemx; //создали указатель
            itemx =  new QTableWidgetItem(); //выделяем память
            ui->tableWidget_massive->setItem(i,0,itemx); //помещаем ячейку в таблицу
            ui->tableWidget_massive->item(i,0)->setBackgroundColor(Qt::red);//меняем цвет ячейки красный
        }
        QTableWidgetItem *Singleitem=ui->tableWidget_massive->item(0, 0);//создаём указатель первого элемента
        ui->tableWidget_massive->scrollToItem(Singleitem);//скроллим до первого элемента
        checkChange = false;//ставим проверку на изменения в положение false
        return false;//возвращаем значение
    }
    else if(size==1)//если одна строка
    {
        QTableWidgetItem *Singleitem=ui->tableWidget_massive->item(0, 0);//используем Singleitem как указатель вызова значения элемента
        if(Singleitem==nullptr)//если в строке ничего нет
        {
            QMessageBox::information(this,"Ошибка","Строка не заполнена!",QMessageBox::Ok);//выводим ошибку
            ui->tableWidget_massive->scrollToItem(Singleitem);//прокручиваем до ошибочного элемента
            return false;//возвращаем значение
        }
        else
        {
            bool correct = isCorrectItem(Singleitem);//проверяем значение элемента
            if(!correct)//если неправильное
            {
                QMessageBox::information(this,"Ошибка","Некоторые строки заполнены некорректно!",QMessageBox::Ok);//выводим ошибку
                ui->tableWidget_massive->scrollToItem(Singleitem);//прокручиваем до ошибочного элемента
                return false;//возвращаем значение
            }
        }
        return true;//возвращаем значение
    }
    else
    {
        for(int i=0; i<size;i++)//для перебора массива
        {
            QTableWidgetItem *item=ui->tableWidget_massive->item(i, 0);//используем item как команду вызова значения элемента
            if(item==nullptr)//если в строке ничего нет
            {
                QMessageBox::information(this,"Ошибка","Некоторые строки не заполнены!",QMessageBox::Ok);//выводим ошибку
                ui->tableWidget_massive->scrollToItem(item);//прокручиваем до ошибочного элемента
                return false;//возвращаем значение
            }
            else
            {
                bool correct = isCorrectItem(item);//проверяем значение элемента
                if(!correct)//если неправильное
                {
                    QMessageBox::information(this,"Ошибка","Некоторые строки заполнены некорректно!",QMessageBox::Ok);//выводим ошибку
                    ui->tableWidget_massive->scrollToItem(item);//прокручиваем до ошибочного элемента
                    return false;//возвращаем значение
                }
            }
        }
        return true;//возвращаем значение
    }
}
void MainWindow::on_pushButton_min_clicked()//когда нажимается кнопка Минимальное значение
{
    if(isCorrectValues())//Если все значения подходят
    {
        double min = ui->tableWidget_massive->item(0,0)->text().toDouble();//создаём переменную для хранения минимального значения и вписываем туда первый элемент
        for(int i=1;i<size;i++)//цикл для перебора массива
        {
            double val = ui->tableWidget_massive->item(i,0)->text().toDouble();//создаём переменную для хранения текущего значения и вписываем туда текущий элемент
            if(val<min)//сравниваем значения
                min=val;//меняем минимум
        }
        ui->label_min->setNum(min);//выводим минимальное значение
    }
    else
    {
        ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
        ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
        ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
        ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
        ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
    }
}
void MainWindow::on_pushButton_max_clicked()//когда нажимается кнопка Максимальное значение
{
    if(isCorrectValues())//Если все значения подходят
    {
        double max = ui->tableWidget_massive->item(0,0)->text().toDouble();//создаём переменную для хранения максимального значения и вписываем туда первый элемент
        for(int i=1; i<size;i++)//цикл для перебора массива
        {
            double val = ui->tableWidget_massive->item(i,0)->text().toDouble();//создаём переменную для хранения текущего значения и вписываем туда текущий элемент
            if(val>max)//сравниваем значения
                max=val;//меняем максимум
        }
        ui->label_max->setNum(max);//выводим минимальное значение
    }
    else
    {
        ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
        ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
        ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
        ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
        ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
    }
}
void MainWindow::on_pushButton_mid_clicked()//когда нажимается кнопка Среднее значение
{
    if(isCorrectValues())//Если все значения подходят
    {
        double mid = ui->tableWidget_massive->item(0,0)->text().toDouble();//когда нажимается кнопка Среднее значение
        for(int i=1; i<size;i++)//цикл для перебора массива
        {
            double val = ui->tableWidget_massive->item(i,0)->text().toDouble();//создаём переменную для хранения текущего значения и вписываем туда текущий элемент
            mid+=val;//суммируем значения
        }
        mid=mid/static_cast<double>(size);//вычисляем среднее арифметическое
        ui->label_mid->setNum(mid);//выводим минимальное значение
    }
    else
    {
        ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
        ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
        ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
        ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
        ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
    }
}
void MainWindow::on_tableWidget_massive_itemChanged(QTableWidgetItem *item)//при изменении значений элементов массива
{
    if(allowChange)//проверяем на допустимость изменения
    {
        isCorrectItem(item);//проверяем корректность значения
        checkChange=true;//ставим проверку на изменения в положение true
        checkSorting=false;//ставим проверку на сортировку в положение false
        ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
        ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
        ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
        ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
        ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
    }

}
void MainWindow::on_pushButton_Comb_clicked()//когда нажимается кнопка Расческа
{
    if(isCorrectValues())//Если все значения подходят
    {
        readMassive();//Читаем массив
        allowChange=false;//ставим проверку на допустимость изменения в положение false
        double factor = 1.2473309;//фактор уменьшения
        int step = size-1;//шаг сортировки
        while (step>=1)//пока шаг больше одного
        {
            for(int i=0; i+step< size; i++)//цикл для перебора массива
            {
                if(mas[i] > mas[i+step])//сравниваем текщий элемент массива с элементом через шаг сортировки
                {
                    std::swap(mas[i],mas[i +step]);//меняем значения местами
                }
            }
            step /=factor;//делим шаг на фактор уменьшения
        }
        writeMassive();//выводим массив
        checkSorting=true;//ставим проверку на сортировку в положение true
        allowChange=true;//ставим проверку на допустимость изменения в положение true
    }
    else
    {
        ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
        ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
        ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
        ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
        ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
    }
}
void MainWindow::readMassive()//функция чтения массива
{
    size = ui->tableWidget_massive->rowCount();//обновляем глобальную переменную размера массива(количества строк)
    for(int i=0; i<size;i++)//цикл для перебора массива
    {
        mas[i]=ui->tableWidget_massive->item(i,0)->text().toDouble();//записываем значения из таблицы в глобальный масссив
    }
}
void MainWindow::writeMassive()//функция вывода массива
{
    for(int i=0; i<size;i++)//цикл для перебора массива
    {
        ui->tableWidget_massive->item(i,0)->setText(QString::number(mas[i]));//выводим значения из массива в таблицу
    }
}
void MainWindow::on_pushButton_Bubble_clicked()//когда нажимается кнопка Пузырёк
{
    if(isCorrectValues())//Если все значения подходят
    {
        readMassive();//Читаем массив
        allowChange=false;//ставим проверку на допустимость изменения в положение false
        for(int i=0;i<size-1;i++)//для перебора массива
        {
            for(int j=0;j<size-1;j++)//цикл для перебора массива
            {
                if(mas[j]>mas[j+1])//сравниваем текщий элемент массива с соседним
                {
                    double sup = mas[j];//создаём переменную  для хранения текущего элемента массива
                    mas[j]=mas[j+1];//меняем элементы местами
                    mas[j+1]=sup;
                }
            }
        }
        writeMassive();//выводим массив
        checkSorting=true;//ставим проверку на сортировку в положение true
        allowChange=true;//ставим проверку на допустимость изменения в положение true
    }
    else
    {
        ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
        ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
        ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
        ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
        ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
    }
}
void MainWindow::on_pushButton_Fast_clicked()//когда нажимается кнопка Быстрая
{
    if(isCorrectValues())//Если все значения подходят
    {
        readMassive();//Читаем массив
        allowChange=false;//ставим проверку на допустимость изменения в положение false
        quickSort(mas,size);//Функция быстрой сортировки
        writeMassive();//выводим массив
        checkSorting=true;//ставим проверку на сортировку в положение true
        allowChange=true;//ставим проверку на допустимость изменения в положение true
    }
    else
    {
        ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
        ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
        ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
        ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
        ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
    }
}
void MainWindow::quickSort(double *array,int scale)//функция быстрой сортировки
{
    int left=0;//указатель начала массива
    int right = scale-1;//указатель конца массива
    double mid = array[scale/2];//центральный элемент массива
    do//делать
    {
        while(array[left] < mid)//пока текущий элемент слева меньше центрального элемента
        {
            left++;//сдвигаем левую границу к центру
        }
        while(array[right]> mid)//пока текущий элемент справа большего центрального элемента
        {
            right--;//сдвигаем правую границу к центру
        }
        if (left<= right)//если границы не встретились
        {
            double tmp =array[left];//меняем элементы местами
            array[left] = array[right];
            array[right] = tmp;
            left++;//сдвигаем границы к центру
            right--;
        }
    }
    while (left <= right);//пока границы не встретились

    if(right>0)//правая граница больше нуля
    {
        quickSort(array,right +1);//рекурсия левой части
    }
    if (left < scale)//левая граница меньше размера массива
    {
        quickSort(&array[left],scale - left);//рекурсия правой части
    }
}
void MainWindow::on_pushButton_MONKE_clicked()//когда нажимается кнопка Обезьянья
{
    if(isCorrectValues())//Если все значения подходят
    {
        if(size>5)//Если элементов больше 5
        {
            QMessageBox::information(this,"Ошибка","Наши обезьянки не могут отсортировать больше 5 элементов. Воооот...",QMessageBox::Ok);//выводим ошибку
        }
        else
        {
            int count = 0;//переменная для подсчета попыток
            readMassive();//Читаем массив
            allowChange=false;//ставим проверку на допустимость изменения в положение false
            while(!isCorrect(mas))//Пока не отсортируется
            {
                if(count>=1000)//если количество попыток меньше тысячи
                {
                    break;//завершаем цикл
                }
                shuffle(mas);//мешаем элементы
                count++;//прибавляем попытку к счётчику
            }
            if(isCorrect(mas))//Если отсортировалось
            {
                writeMassive();//выводим массив
                checkSorting=true;//ставим проверку на сортировку в положение true
            }
            else
            {
                QMessageBox::information(this,"Ошибка","Сделав тысячу попыток, обезьянки так и не смогли выдать правильный ответ :(",QMessageBox::Ok);//выводим ошибку
            }
            allowChange=true;//ставим проверку на допустимость изменения в положение true
        }
    }
    else
    {
        ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
        ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
        ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
        ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
        ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
    }
}
bool MainWindow::isCorrect(double *array)//функция для проверки сортировки массива
{
    for (int i=0; i<size-1; i++)//цикл для перебора массива
    {
        if(array[i]>array[i+1])//сравниваем соседние элементы массива
        {
            return false;//возвращаем значение
        }
    }
    return true;//возвращаем значение
}
void MainWindow::shuffle(double *array)//функция для перемешки элементов
{
    for(int i = 0;i<size;i++)//цикл для перебора массива
    {
        std::swap(array[i],array[(rand()%size)]);//заменяем текущий элемент на случайный
    }
}
void MainWindow::on_pushButton_GNOMED_clicked()//когда нажимается кнопка Гномья
{
    if(isCorrectValues())//Если все значения подходят
    {
        readMassive();//Читаем массив
        allowChange=false;//ставим проверку на допустимость изменения в положение false
        int i = 0;//берём переменную равную нулю
        while (i < size)//пока переменная меньше длины массива
        {
            if (i == 0 || mas[i - 1] <= mas[i])//если переменная равна нулю или предыдущий элемент массива меньше или равен текущему
                ++i;//повышаем значение переменной
            else
            {
                double tmp = mas[i];//меняем предыдущий элемент и текущий местами
                mas[i] = mas[i - 1];
                mas[i - 1] = tmp;
                --i;//уменьшаем значение переменной
            }
        }
        writeMassive();//выводим массив
        checkSorting=true;//ставим проверку на сортировку в положение true
        allowChange=true;//ставим проверку на допустимость изменения в положение true
    }
    else
    {
        ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
        ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
        ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
        ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
        ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
    }
}


void MainWindow::on_pushButton_find_clicked()//когда кнопка ПОИСК нажата
{

    bool flag;//создаём переменную для проверки
    double Value = ui->lineEdit_searchValue->text().toDouble(&flag);//создаём переменную для хранения введённых данных с проверкой
    if(!flag or qIsInf(Value) or qIsNaN(Value))//если ошибка или выходит диапозон
    {
        QMessageBox::information(this,"Ошибка","Некорректное число в поле поиска",QMessageBox::Ok);//выводим ошибку

    }
    else
    {
        if(isCorrectValues())//если все значения таблицы подходят
        {
            readMassive();//считываем массив
            int answersCount = 0;//вводим переменную для подсчета подходящих строк
            QString rightItemsNumbers = "";//создаём переменную для хранения номеров строк
            allowChange=false;//ставим проверку на допустимость изменения в положение false
            if(!checkSorting)//если не таблица не отсортирована
            {
                for(int i=0; i<size; i++ )//цикл перебора массива
                {
                    if(abs(mas[i]-Value)<pow(10,-5))//сравниваем числа с ограничением по Double
                    {
                        answersCount++;//прибавляем 1 к количеству подходящих строк
                        ui->tableWidget_massive->item(i,0)->setBackground(QBrush(Qt::green));//окрашиваем подходящую ячейкуу в ЗЕЛЁНЫЙ
                        if(rightItemsNumbers != "")//если подходящие строки были
                        {
                            rightItemsNumbers.append(", ");//добавляем запятую и пробел между ответами
                        }
                        rightItemsNumbers.append(QString::number(i+1));//добавляем ответ
                    }
                }
            }
            else
            {
                int middle = size/2;//переменная центра массива
                int left = 0;//левая граница
                int right = size-1;//правая граница
                int lastL = -1;//-1 для избежания ошибок при первом запуске
                int lastR = -1;

                while(abs(mas[middle]-Value)>pow(10,-5) and abs(mas[middle+1]-Value)>pow(10,-5))//пока условие со сравнением чисел с ограничением по Double выполняется
                {
                    if((left==lastL)and(right==lastR))//проверка на бесконечный цикл(на всякий случай)
                        break;//завершаем цикл
                    lastL = left;//приравниваем последние значения к границам
                    lastR = right;
                    if(Value<mas[middle])//если число меньше центрального
                        right = middle;//сдвигаем правую границу к центру
                    else
                        left = middle;//сдвигаем левую границу к центру
                    middle=(left+right)/2;//расчитываем новый центр
                }
                if(abs(mas[middle]-Value)<pow(10,-5))//сравниваем числа с ограничением по Double
                {
                    //пустовато
                }
                else if(abs(mas[middle+1]-Value)<pow(10,-5))//сравниваем числа с ограничением по Double
                    middle++;//сдвигаем центральное число
                else
                    middle=-1;//приравниваем центральное число к -1

                if(middle!=-1)//если центр не был приравнен к -1
                {
                    if(middle>0)//если центр больше нуля
                    {
                        int index = middle-1;//создаём переменную индекса
                        while(abs(mas[index]-Value)>pow(10,-5))//пока условие со сравнением чисел с ограничением по Double выполняется
                        {
                            if(index==0)//если индекс равен нулю
                            {
                                index--;//уменьшаем индекс
                                break;//завершаем цикл
                            }
                            index--;//уменьшаем индекс
                        }
                        index++;//увеличиваем индекс
                    }
                    rightItemsNumbers.append(QString::number(middle+1));//добавляем ответ
                    if(middle<size-1)//если середина не дошла до конца массива
                    {
                        int index = middle+1;//приравниваем индекс к левому от центра элементу
                        while(abs(mas[index]-Value)>pow(10,-5))//пока условие со сравнением чисел с ограничением по Double выполняется
                        {
                            if(index==size-1)//если индекс дошел до конца массива
                                break;//завершаем цикл
                            index++;//увеличиваем индекс
                        }
                        index--;//уменьшаем индекс
                        for(int i = middle+1;i<index;i++)//цикл перебора массива
                        {
                            answersCount++;
                            ui->tableWidget_massive->item(i,0)->setBackground(QBrush(Qt::green));//окрашиваем подходящую ячейкуу в ЗЕЛЁНЫЙ
                            if(rightItemsNumbers !="")//если подходящие строки были
                                rightItemsNumbers.append(", ");//добавляем запятую и пробел между ответами
                            rightItemsNumbers.append(QString::number(i+1));//добавляем ответ
                        }
                    }
                }
                else
                    rightItemsNumbers = "Ничего не найдено :/";//выводим 404

            }
            allowChange=true;//ставим проверку на допустимость изменения в положение true
            ui->label_searching_countValue->setNum(answersCount);//записываем результаты
            ui->lineEdit_searching_itemsStroke->setText(rightItemsNumbers);

        }
        else
        {
            ui->label_min->clear();//очищаем лейбл минимального значения при ошибке
            ui->label_mid->clear();//очищаем лейбл среднего значения при ошибке
            ui->label_max->clear();//очищаем лейбл максимального значения при ошибке
            ui->label_searching_countValue->clear();//очищаем лейбл количества результатов поиска
            ui->lineEdit_searching_itemsStroke->clear();//очищаем лейбл номеров строк результатов поиска
        }
    }

}
