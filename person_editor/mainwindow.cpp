#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"

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

void MainWindow::on_pushButton_clear_clicked()//Clear
{
    int w = ui->label_iconframe->width();
    int h = ui->label_iconframe->height();
    QPixmap myst(":/images/mystery_hero.png"); //установка картинки по умолчанию
    ui->label_iconframe->setPixmap(myst.scaled(w,h));



    ui->lineEdit_dex->clear();//очищаем поля для заполнения
    ui->lineEdit_name->clear();
    ui->lineEdit_int->clear();
    ui->lineEdit_luck->clear();
    ui->lineEdit_str->clear();
    ui->lineEdit_pointsleft->clear();

    QPalette p=ui->lineEdit_str->palette();//сброс цветовых индикаций
    p.setColor(QPalette::Text,Qt::black);
    ui->label_int->setPalette(p);
    ui->label_luck->setPalette(p);
    ui->label_str->setPalette(p);
    ui->label_dex->setPalette(p);

    ui->label_hp_value->clear();//очищаем статистику
    ui->label_mp_value->clear();
    ui->label_atc_value->clear();
    ui->label_def_value->clear();
    ui->label_class_value->clear();

    ui->label_hp_status->clear();//очищаем статусы по статистике
    ui->label_mp_status->clear();
    ui->label_atc_status->clear();
    ui->label_def_status->clear();
    ui->label_class_status->clear();

    ui->label_nicknamebar->setVisible(false);

    ui->radioButton_sex_M->setChecked(true);//выбираем пол по умолчанию
    ui->radioButton_race_human->setChecked(true);//выбираем расу по умолчанию
    ui->lineEdit_pointsleft->setReadOnly(true);//закрываем изминение поля очков

    ui->lineEdit_pointsleft->setText("22");//записываем максимальное количество очков в поле очков
}
void MainWindow::on_radioButton_race_human_clicked()//если раса ЧЕЛОВЕК
{
    ui->label_raceability->setText("Наука");//переименовываем пассивку в НАУКА
}
void MainWindow::on_radioButton_race_darkelf_clicked()//если раса ТЁМНЫЙ ЭЛЬФ
{
    ui->label_raceability->setText("Тьма");//переименовываем пассивку в ТЬМА
}
void MainWindow::on_radioButton_race_ogr_clicked()//если раса ОГР
{
    ui->label_raceability->setText("Гигантизм");//переименовываем пассивку в ГИГАНТИЗМ
}
void MainWindow::on_radioButton_race_Khajiit_clicked()//если раса КАДЖИТ
{
    ui->label_raceability->setText("Когти");//переименовываем пассивку в КОГТИ
}
void MainWindow::on_pushButton_create_clicked()//Создать
{
    QString name;//имя персонажа
    int w = ui->label_iconframe->width();//размер картинки персонажа
    int h = ui->label_iconframe->height();
    int dlina;//переменная длины имени
    int str, dex, intel, luck,spec;//переменная параметров
    bool flag;//переменная для проверки

    name=ui->lineEdit_name->text();//ставим имя в переменную
    dlina=name.length();//считваем длину переменной имени
    //чекаем длину имени на допустимость
    if((dlina < 3) || (dlina > 20))
    {
        flag=false;
        QMessageBox::information(this,"Ошибка","Длина имени должна быть от 3 до 20 символов",QMessageBox::Ok);
    }
    else
    {
        flag=true;
    }
    //можно добавлять в поле для никнейма
    ui->label_nicknamebar->setText(name);
    ui->label_nicknamebar->setVisible(true);
    //сила
    str=0;

    if(flag)//вместо вложенных циклов(так для инфы, заметка бесполезна бтв)
    {
        str=ui->lineEdit_str->text().toInt(&flag);
        if(flag)
        {   if((str<1)||(str>10))
            {
                flag=false;
                QMessageBox::information(this,"Ошибка","\"Сила\" Должна быть от 1 до 10 .",QMessageBox::Ok);
            }

        }
        else
        {
            QMessageBox::information(this,"Ошибка","Неверное значение параметра \"Сила\".",QMessageBox::Ok);
        }
    }
    //ловкость
    dex=0;
    if(flag)//вместо вложенных циклов(так для инфы, заметка бесполезна бтв)
    {
        dex=ui->lineEdit_dex->text().toInt(&flag);
        if(flag)
        {   if((dex<1)||(dex>10))
            {
                flag=false;
                QMessageBox::information(this,"Ошибка","\"Ловкость\" Должна быть от 1 до 10 .",QMessageBox::Ok);
            }

        }
        else
        {
            QMessageBox::information(this,"Ошибка","Неверное значение параметра \"Ловкость\".",QMessageBox::Ok);
        }
    }
    //интеллект
    intel=0;
    if(flag)//вместо вложенных циклов(так для инфы, заметка бесполезна бтв)
    {
        intel=ui->lineEdit_int->text().toInt(&flag);
        if(flag)
        {   if((intel<1)||(intel>10))
            {
                flag=false;
                QMessageBox::information(this,"Ошибка","\"Интелект\" Должна быть от 1 до 10 .",QMessageBox::Ok);
            }

        }
        else
        {
            QMessageBox::information(this,"Ошибка","Неверное значение параметра \"Интелект\".",QMessageBox::Ok);
        }
    }
    //удача
    luck=0;
    if(flag)//вместо вложенных циклов(так для инфы, заметка бесполезна бтв)
    {
        luck=ui->lineEdit_luck->text().toInt(&flag);
        if(flag)
        {   if((luck<1)||(luck>10))
            {
                flag=false;
                QMessageBox::information(this,"Ошибка","\"Удача\" Должна быть от 1 до 10 .",QMessageBox::Ok);
            }

        }
        else
        {
            QMessageBox::information(this,"Ошибка","Неверное значение параметра \"Удача\".",QMessageBox::Ok);
        }
    }
    //пассивка
    spec=0;
    if(flag)//вместо вложенных циклов(так для инфы, заметка бесполезна бтв)
    {
        spec=ui->lineEdit_race->text().toInt(&flag);
        if(flag)
        {   if((spec<1)||(spec>10))
            {
                flag=false;
                if(ui->radioButton_race_human->isChecked())
                {
                    QMessageBox::information(this,"Ошибка","\"Наука\" Должна быть от 1 до 10 .",QMessageBox::Ok);
                }
                else if(ui->radioButton_race_ogr->isChecked())
                {
                    QMessageBox::information(this,"Ошибка","\"Гигантизм\" Должна быть от 1 до 10 .",QMessageBox::Ok);
                }
                else if(ui->radioButton_race_Khajiit->isChecked())
                {
                    QMessageBox::information(this,"Ошибка","\"Когти\" Должна быть от 1 до 10 .",QMessageBox::Ok);
                }
                else if(ui->radioButton_race_darkelf->isChecked())
                {
                    QMessageBox::information(this,"Ошибка","\"Тьма\" Должна быть от 1 до 10 .",QMessageBox::Ok);
                }
            }
        }
        else
        {
            if(ui->radioButton_race_human->isChecked())
            {
                QMessageBox::information(this,"Ошибка","Неверное значение параметра \"Наука\".",QMessageBox::Ok);
            }
            else if(ui->radioButton_race_ogr->isChecked())
            {
                QMessageBox::information(this,"Ошибка","Неверное значение параметра \"Гигантизм\".",QMessageBox::Ok);
            }
            else if(ui->radioButton_race_Khajiit->isChecked())
            {
                QMessageBox::information(this,"Ошибка","Неверное значение параметра \"Когти\".",QMessageBox::Ok);
            }
            else if(ui->radioButton_race_darkelf->isChecked())
            {
                QMessageBox::information(this,"Ошибка","Неверное значение параметра \"Тьма\".",QMessageBox::Ok);
            }
        }
    }
    //проверка количества очков
    if(flag)
    {
        int score_left=22-str-dex-intel-luck-spec;
        ui->lineEdit_pointsleft->setText(QString::number(score_left));
        if(score_left !=0)
        {
            if(score_left<0)
            {
                flag=false;
                QMessageBox::information(this,"Ошибка","Нельзя тратить больше 22 очков!",QMessageBox::Ok);
            }
            else
            {
                QMessageBox::information(this,"Ошибка","Нужно потратить все очки!",QMessageBox::Ok);
            }
        }
    }
    //подсчет характеристик
    if(flag)
    {
        int hp, mp, atk, def;//переменные характеристик
        if(ui->radioButton_race_human->isChecked())//расщет в зависимости от расы
        {
            hp=8*str+2*dex;
            mp=8*intel+dex+luck+2*spec;
            atk=6*str+2*dex+2*luck;
            def=7*dex+3*luck+spec;
        }
        else if(ui->radioButton_race_ogr->isChecked())
        {
            hp=8*str+2*dex+2*spec;
            mp=8*intel+dex+luck;
            atk=6*str+spec*str+2*dex+2*luck;
            def=7*dex+3*luck;
        }
        else if(ui->radioButton_race_darkelf->isChecked())
        {
            hp=8*str+2*dex;
            mp=8*intel+dex+luck+spec;
            atk=6*str+2*dex+2*luck;
            def=7*dex+3*luck+2*spec;
        }
        else
        {
            hp=8*str+2*dex+spec;
            mp=8*intel+dex+luck;
            atk=6*str+2*spec*str+2*dex+2*luck;
            def=7*dex+3*luck;
        }
        //запись характеристик в таблицу
        if(hp<0)
            ui->label_hp_value->setNum(0);
        else
            ui->label_hp_value->setNum(hp);
        if(mp<0)
            ui->label_mp_value->setNum(0);
        else
            ui->label_mp_value->setNum(mp);
        if(atk<0)
            ui->label_atc_value->setNum(0);
        else
            ui->label_atc_value->setNum(atk);
        if(def<0)
            ui->label_def_value->setNum(0);
        else
            ui->label_def_value->setNum(def);
        //подбор статуса для обозначения состояния характеристики
        if(hp<10)
            ui->label_hp_status->setText("одной ногой в могиле");
        else if(hp<25)
            ui->label_hp_status->setText("прострелили колено");
        else if(hp<50)
            ui->label_hp_status->setText("на пару тычек БАМ БАМ БИМ БИМ");
        else if(hp<70)
            ui->label_hp_status->setText("здоровья как у быка");
        else if(hp<100)
        {
            if(ui->radioButton_sex_M->isChecked())
                ui->label_hp_status->setText("посмотрел все выпуски ЖИТЬ ЗДОРОВО");
            else
                ui->label_hp_status->setText("посмотрела все выпуски ЖИТЬ ЗДОРОВО");
        }
        else
            ui->label_hp_status->setText("СМЕРТНОСТЬ УПАЛА ДО 0%");

        if(mp<10)
            ui->label_mp_status->setText("у тебя не закончится мана, если её нет");
        else if(mp<25)
            ui->label_mp_status->setText("хватит на то чтобы сварить макароны");
        else if(mp<50)
        {
            if(ui->radioButton_sex_M->isChecked())
                ui->label_mp_status->setText("отчислен из Хогвартса");
            else
                ui->label_mp_status->setText("отчислена из Хогвартса");
        }
        else if(mp<60)
            ui->label_mp_status->setText("хоть на миду трать");
        else if(mp<80)
            ui->label_mp_status->setText("мановый шейх");
        else
            ui->label_mp_status->setText("ТВОЯ ДУША ПРИНАДЛЕЖИТ МНЕ!");

        if(atk<10)
        {
            if(ui->radioButton_sex_M->isChecked())
                ui->label_atc_status->setText("Пацифист");
            else
                ui->label_atc_status->setText("Пацифистка");
        }
        else if(atk<25)
            ui->label_atc_status->setText("спец по боям подушками");
        else if(atk<50)
            ui->label_atc_status->setText("боец на пальцах");
        else if(atk<60)
            ui->label_atc_status->setText("разящий клинок");
        else if(atk<89)
            ui->label_atc_status->setText("славный воин");
        else if(atk<120)
        {
            if(ui->radioButton_sex_M->isChecked())
                ui->label_atc_status->setText("копил силу 10000 лет");
            else
                ui->label_atc_status->setText("копила силу 10000 лет");
        }
        else
        {
            if(ui->radioButton_sex_M->isChecked())
                ui->label_atc_status->setText("БОГ ВОЙНЫ");
            else
                ui->label_atc_status->setText("БОГИНЯ ВОЙНЫ");
        }


        if(def<10)
            ui->label_def_status->setText("тонкая корочка льда");
        else if(def<25)
            ui->label_def_status->setText("есть пробитие ");
        else if(def<50)
        {
            if(ui->radioButton_sex_M->isChecked())
                ui->label_def_status->setText("посещал курсы самообороны");
            else
                ui->label_def_status->setText("посещала курсы самообороны");
        }
        else if(def<80)
            ui->label_def_status->setText("прочнее стали");
        else if(def<100)
            ui->label_def_status->setText("передвижная крепость");
        else
        {
            if(ui->radioButton_sex_M->isChecked())
                ui->label_def_status->setText("НЕПРОБИВАЕМЫЙ");
            else
                ui->label_def_status->setText("НЕПРОБИВАЕМАЯ");
        }

        //Подбор класса в зависимости от преобладающей характеристики
        //подбор статуса класса от состояния характеристик
        if(str>dex and str>luck and str>intel)
        {
            if(dex>luck and dex>intel)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("БЕРСЕРКИЧ"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_ber_m(":/images/human_berserker_M.png");
                        ui->label_iconframe->setPixmap(human_ber_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_ber_m(":/images/ogre_beerserker_M.png");
                        ui->label_iconframe->setPixmap(ogr_ber_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_ber_m(":/images/darkelf_berserker_M.png");
                        ui->label_iconframe->setPixmap(dark_ber_m.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_ber_m(":/images/kajiit_berserker_M.png");
                        ui->label_iconframe->setPixmap(kaj_ber_m.scaled(w,h));
                    }

                }
                else
                {
                    ui->label_class_value->setText("БЕРСЕРКОВНА");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_ber_f(":/images/human_berserker_F.png");
                        ui->label_iconframe->setPixmap(human_ber_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_ber_f(":/images/ogre_berserker_F.png");
                        ui->label_iconframe->setPixmap(ogr_ber_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_ber_f(":/images/darkelf_berserker_F.png");
                        ui->label_iconframe->setPixmap(dark_ber_f.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_ber_f(":/images/kajiit_berserker_F.png");
                        ui->label_iconframe->setPixmap(kaj_ber_f.scaled(w,h));
                    }
                }
                if(atk<50)
                    ui->label_class_status->setText("на пол рубля");
                else if(atk<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else if(luck>dex and luck>intel)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("ВОИТЕЛЬ"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_warrior_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_warrior_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_warrior_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_warrior_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }

                }
                else
                {
                    ui->label_class_value->setText("ВОИТЕЛЬНИЦА");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_warrior_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_warrior_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_warrior_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_warrior_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(def<50)                                          //статус от вторичной характеристики
                    ui->label_class_status->setText("на пол рубля");
                else if(def<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else if(intel>dex and intel>luck)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("ШАМАН"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_shaman_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_shaman_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_shaman_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_shaman_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("ШАМАНКА");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_shaman_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_shaman_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_shaman_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_shaman_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(mp<50)
                    ui->label_class_status->setText("на пол рубля");
                else if(mp<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("МОНАХ");//картинка в зависимости от расы
                    ui->label_class_status->setText("достиг идеального баланса");
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_bal_m(":/images/human_balance_M.png");
                        ui->label_iconframe->setPixmap(human_bal_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_bal_m(":/images/ogre_balance_M.png");
                        ui->label_iconframe->setPixmap(ogr_bal_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_bal_m(":/images/darkelf_balance_M.png");
                        ui->label_iconframe->setPixmap(dark_bal_m.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_bal_m(":/images/kajiit_balance_M.png");
                        ui->label_iconframe->setPixmap(kaj_bal_m.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("МОНАХИНЯ");//картинка в зависимости от расы
                    ui->label_class_status->setText("достигла идеального боланса");
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_bal_f(":/images/human_balance_F.png");
                        ui->label_iconframe->setPixmap(human_bal_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_bal_f(":/images/ogre_balance_F.png");
                        ui->label_iconframe->setPixmap(ogr_bal_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_bal_f(":/images/darkelf_balance_F.png");
                        ui->label_iconframe->setPixmap(dark_bal_f.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_bal_f(":/images/kajiit_balance_F.png");
                        ui->label_iconframe->setPixmap(kaj_bal_f.scaled(w,h));
                    }
                }
            }
        }
        else if(dex>str and dex>luck and dex>intel)
        {
            if(str>luck and str>intel)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("БЕРСЕРКИЧ"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_ber_m(":/images/human_berserker_M.png");
                        ui->label_iconframe->setPixmap(human_ber_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_ber_m(":/images/ogre_beerserker_M.png");
                        ui->label_iconframe->setPixmap(ogr_ber_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_ber_m(":/images/darkelf_berserker_M.png");
                        ui->label_iconframe->setPixmap(dark_ber_m.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_ber_m(":/images/kajiit_berserker_M.png");
                        ui->label_iconframe->setPixmap(kaj_ber_m.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("БЕРСЕРКОВНА");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_ber_f(":/images/human_berserker_F.png");
                        ui->label_iconframe->setPixmap(human_ber_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_ber_f(":/images/ogre_berserker_F.png");
                        ui->label_iconframe->setPixmap(ogr_ber_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_ber_f(":/images/darkelf_berserker_F.png");
                        ui->label_iconframe->setPixmap(dark_ber_f.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_ber_f(":/images/kajiit_berserker_F.png");
                        ui->label_iconframe->setPixmap(kaj_ber_f.scaled(w,h));
                    }
                }
                if(atk<50)
                    ui->label_class_status->setText("на пол рубля");
                else if(atk<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }

            else if(luck>str and luck>intel)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("ВОР"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_thief_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_thief_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_thief_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_thief_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("ВОРОВКА");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_thief_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_thief_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_thief_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_thief_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(def<50)                                          //статус от вторичной характеристики
                    ui->label_class_status->setText("на пол рубля");
                else if(def<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");

            }
            else if(intel>str and intel>luck)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("ДРУИД"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_druid_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_druid_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_druid_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_druid_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("ДРУИД");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_druid_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_druid_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_druid_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_druid_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(mp<50)//статус от вторичной характеристики
                    ui->label_class_status->setText("на пол рубля");
                else if(mp<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("МОНАХ");//картинка в зависимости от расы
                    ui->label_class_status->setText("достиг идеального баланса");
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_bal_m(":/images/human_balance_M.png");
                        ui->label_iconframe->setPixmap(human_bal_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_bal_m(":/images/ogre_balance_M.png");
                        ui->label_iconframe->setPixmap(ogr_bal_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_bal_m(":/images/darkelf_balance_M.png");
                        ui->label_iconframe->setPixmap(dark_bal_m.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_bal_m(":/images/kajiit_balance_M.png");
                        ui->label_iconframe->setPixmap(kaj_bal_m.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("МОНАХИНЯ");//картинка в зависимости от расы
                    ui->label_class_status->setText("достигла идеального боланса");
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_bal_f(":/images/human_balance_F.png");
                        ui->label_iconframe->setPixmap(human_bal_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_bal_f(":/images/ogre_balance_F.png");
                        ui->label_iconframe->setPixmap(ogr_bal_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_bal_f(":/images/darkelf_balance_F.png");
                        ui->label_iconframe->setPixmap(dark_bal_f.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_bal_f(":/images/kajiit_balance_F.png");
                        ui->label_iconframe->setPixmap(kaj_bal_f.scaled(w,h));
                    }
                }
            }
        }
        else if(luck>str and luck>dex and luck>intel)
        {
            if(str>dex and str>intel)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("ВОИТЕЛЬ"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_warrior_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_warrior_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_warrior_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_warrior_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }

                }
                else
                {
                    ui->label_class_value->setText("ВОИТЕЛЬНИЦА");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_warrior_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_warrior_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_warrior_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_warrior_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(def<50)
                    ui->label_class_status->setText("на пол рубля");
                else if(def<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else if(dex>str and dex>intel)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("ВОР"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_thief_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_thief_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_thief_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_thief_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("ВОРОВКА");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_thief_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_thief_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_thief_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_thief_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(def<50)
                    ui->label_class_status->setText("на пол рубля");
                else if(def<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else if (intel>str and intel>dex)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("МАГ"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_magic_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_magic_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_magic_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_magic_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("МАГ");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_magic_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_magic_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_magic_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_magic_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(mp<50)
                    ui->label_class_status->setText("на пол рубля");
                else if(mp<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("МОНАХ");//картинка в зависимости от расы
                    ui->label_class_status->setText("достиг идеального баланса");
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_bal_m(":/images/human_balance_M.png");
                        ui->label_iconframe->setPixmap(human_bal_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_bal_m(":/images/ogre_balance_M.png");
                        ui->label_iconframe->setPixmap(ogr_bal_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_bal_m(":/images/darkelf_balance_M.png");
                        ui->label_iconframe->setPixmap(dark_bal_m.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_bal_m(":/images/kajiit_balance_M.png");
                        ui->label_iconframe->setPixmap(kaj_bal_m.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("МОНАХИНЯ");//картинка в зависимости от расы
                    ui->label_class_status->setText("достигла идеального боланса");
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_bal_f(":/images/human_balance_F.png");
                        ui->label_iconframe->setPixmap(human_bal_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_bal_f(":/images/ogre_balance_F.png");
                        ui->label_iconframe->setPixmap(ogr_bal_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_bal_f(":/images/darkelf_balance_F.png");
                        ui->label_iconframe->setPixmap(dark_bal_f.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_bal_f(":/images/kajiit_balance_F.png");
                        ui->label_iconframe->setPixmap(kaj_bal_f.scaled(w,h));
                    }
                }
            }
        }
        else if(intel>str and intel>dex and intel>luck)
        {
            if(str>dex and str>luck)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("ШАМАН"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_shaman_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_shaman_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_shaman_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_shaman_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("ШАМАНКА");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_shaman_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_shaman_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_shaman_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_shaman_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(mp<50)//статус от вторичной характеристики
                    ui->label_class_status->setText("на пол рубля");
                else if(mp<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else if(dex>str and dex>luck)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("ДРУИД"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_druid_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_druid_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_druid_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_druid_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("ДРУИД");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_druid_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_druid_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_druid_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_druid_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(mp<50)//статус от вторичной характеристики
                    ui->label_class_status->setText("на пол рубля");
                else if(mp<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else if(luck>str and luck>dex)
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("МАГ"); //картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_magic_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_magic_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_magic_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_magic_M.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("МАГ");//картинка в зависимости от расы
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap item(":/images/human_magic_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap item(":/images/ogre_magic_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap item(":/images/darkelf_magic_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                    else
                    {
                        QPixmap item(":/images/kajiit_magic_F.png");
                        ui->label_iconframe->setPixmap(item.scaled(w,h));
                    }
                }
                if(mp<50)//статус от вторичной характеристики
                    ui->label_class_status->setText("на пол рубля");
                else if(mp<85)
                {
                    if(ui->radioButton_sex_M->isChecked())
                        ui->label_class_status->setText("подающий надежды");
                    else
                        ui->label_class_status->setText("подающая надежды");
                }
                else
                    ui->label_class_status->setText("небывалых высот");
            }
            else
            {
                if(ui->radioButton_sex_M->isChecked())
                {
                    ui->label_class_value->setText("МОНАХ");//картинка в зависимости от расы
                    ui->label_class_status->setText("достиг идеального баланса");
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_bal_m(":/images/human_balance_M.png");
                        ui->label_iconframe->setPixmap(human_bal_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_bal_m(":/images/ogre_balance_M.png");
                        ui->label_iconframe->setPixmap(ogr_bal_m.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_bal_m(":/images/darkelf_balance_M.png");
                        ui->label_iconframe->setPixmap(dark_bal_m.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_bal_m(":/images/kajiit_balance_M.png");
                        ui->label_iconframe->setPixmap(kaj_bal_m.scaled(w,h));
                    }
                }
                else
                {
                    ui->label_class_value->setText("МОНАХИНЯ");//картинка в зависимости от расы
                    ui->label_class_status->setText("достигла идеального боланса");
                    if(ui->radioButton_race_human->isChecked())
                    {
                        QPixmap human_bal_f(":/images/human_balance_F.png");
                        ui->label_iconframe->setPixmap(human_bal_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_ogr->isChecked())
                    {
                        QPixmap ogr_bal_f(":/images/ogre_balance_F.png");
                        ui->label_iconframe->setPixmap(ogr_bal_f.scaled(w,h));
                    }
                    else if(ui->radioButton_race_darkelf->isChecked())
                    {
                        QPixmap dark_bal_f(":/images/darkelf_balance_F.png");
                        ui->label_iconframe->setPixmap(dark_bal_f.scaled(w,h));
                    }
                    else
                    {
                        QPixmap kaj_bal_f(":/images/kajiit_balance_F.png");
                        ui->label_iconframe->setPixmap(kaj_bal_f.scaled(w,h));
                    }
                }
            }
        }
        else
        {
            if(ui->radioButton_sex_M->isChecked())
            {
                ui->label_class_value->setText("МОНАХ");//картинка в зависимости от расы
                ui->label_class_status->setText("достиг идеального баланса");
                if(ui->radioButton_race_human->isChecked())
                {
                    QPixmap human_bal_m(":/images/human_balance_M.png");
                    ui->label_iconframe->setPixmap(human_bal_m.scaled(w,h));
                }
                else if(ui->radioButton_race_ogr->isChecked())
                {
                    QPixmap ogr_bal_m(":/images/ogre_balance_M.png");
                    ui->label_iconframe->setPixmap(ogr_bal_m.scaled(w,h));
                }
                else if(ui->radioButton_race_darkelf->isChecked())
                {
                    QPixmap dark_bal_m(":/images/darkelf_balance_M.png");
                    ui->label_iconframe->setPixmap(dark_bal_m.scaled(w,h));
                }
                else
                {
                    QPixmap kaj_bal_m(":/images/kajiit_balance_M.png");
                    ui->label_iconframe->setPixmap(kaj_bal_m.scaled(w,h));
                }
            }
            else
            {
                ui->label_class_value->setText("МОНАХИНЯ");//картинка в зависимости от расы
                ui->label_class_status->setText("достигла идеального боланса");
                if(ui->radioButton_race_human->isChecked())
                {
                    QPixmap human_bal_f(":/images/human_balance_F.png");
                    ui->label_iconframe->setPixmap(human_bal_f.scaled(w,h));
                }
                else if(ui->radioButton_race_ogr->isChecked())
                {
                    QPixmap ogr_bal_f(":/images/ogre_balance_F.png");
                    ui->label_iconframe->setPixmap(ogr_bal_f.scaled(w,h));
                }
                else if(ui->radioButton_race_darkelf->isChecked())
                {
                    QPixmap dark_bal_f(":/images/darkelf_balance_F.png");
                    ui->label_iconframe->setPixmap(dark_bal_f.scaled(w,h));
                }
                else
                {
                    QPixmap kaj_bal_f(":/images/kajiit_balance_F.png");
                    ui->label_iconframe->setPixmap(kaj_bal_f.scaled(w,h));
                }
            }
        }
    }
    //очистка характеристик и статусов при ошибке
    else
    {
        QPixmap myst(":/images/mystery_hero.png"); //установка картинки по умолчанию
        ui->label_iconframe->setPixmap(myst.scaled(w,h));

        ui->label_hp_value->clear();
        ui->label_mp_value->clear();
        ui->label_atc_value->clear();
        ui->label_def_value->clear();
        ui->label_class_value->clear();

        ui->label_hp_status->clear();
        ui->label_mp_status->clear();
        ui->label_atc_status->clear();
        ui->label_def_status->clear();
        ui->label_class_status->clear();

        ui->label_nicknamebar->clear();
    }

}


void MainWindow::on_lineEdit_name_textChanged(const QString &)
{
    int value;
    QString str;
    QPalette pal=ui->lineEdit_name->palette();
    str=ui->lineEdit_name->text();
    value= str.length();
    if(value>2 and value<21)
        pal.setColor(QPalette::Text, Qt::green);
    else
        pal.setColor(QPalette::Text, Qt::red);
    ui->lineEdit_name->setPalette(pal);
}
void MainWindow::points_calculation() //функция вычисления остатка очков
{
    int str,dex,intel,luck,spec,score_left;

    str=ui->lineEdit_str->text().toInt();
    dex=ui->lineEdit_dex->text().toInt();
    intel=ui->lineEdit_int->text().toInt();
    luck=ui->lineEdit_luck->text().toInt();
    spec=ui->lineEdit_race->text().toInt();

    score_left=22-str-dex-intel-luck-spec;

    QPalette pal=ui->lineEdit_pointsleft->palette();

    if (score_left!=0)
        pal.setColor(QPalette::Text,Qt::green);
    else
        pal.setColor(QPalette::Text,Qt::red);

    ui->lineEdit_pointsleft->setPalette(pal);
    ui->lineEdit_pointsleft->setText(QString::number(score_left));
}

void MainWindow::on_lineEdit_str_textChanged(const QString &)
{
    uint value;
    QString str;
    bool flag;
    QColor oranges, trueyellow;
    oranges.setRgb(255,94,19);
    trueyellow.setRgb(255, 214, 0);



    str=ui->lineEdit_str->text();
    value=str.toUInt(&flag);
    QPalette p=ui->lineEdit_str->palette();
    if(flag and value>0 and value<=10)
        p.setColor(QPalette::Text,Qt::green);
    else
        p.setColor(QPalette::Text,Qt::red);
    ui->lineEdit_str->setPalette(p);

    if((value<=0) || (value>10))
        p.setColor(QPalette::WindowText,Qt::red);
    else if((value>0) && (value<4))
        p.setColor(QPalette::WindowText,oranges);
    else if((value>3) && (value<7))
        p.setColor(QPalette::WindowText,trueyellow);
    else if((value>=7) && (value<11))
        p.setColor(QPalette::WindowText,Qt::green);
    ui->label_str->setPalette(p);
    points_calculation();
}

void MainWindow::on_lineEdit_int_textChanged(const QString &)
{
    uint value;
    QString str;
    bool flag;
    QColor oranges, trueyellow;
    oranges.setRgb(255,94,19);
    trueyellow.setRgb(255, 214, 0);



    str=ui->lineEdit_int->text();
    value=str.toUInt(&flag);
    QPalette p=ui->lineEdit_int->palette();
    if(flag and value>0 and value<=10)
        p.setColor(QPalette::Text,Qt::green);
    else
        p.setColor(QPalette::Text,Qt::red);
    ui->lineEdit_int->setPalette(p);

    if((value<=0) || (value>10))
        p.setColor(QPalette::WindowText,Qt::red);
    else if((value>0) && (value<4))
        p.setColor(QPalette::WindowText,oranges);
    else if((value>3) && (value<7))
        p.setColor(QPalette::WindowText,trueyellow);
    else if((value>=7) && (value<11))
        p.setColor(QPalette::WindowText,Qt::green);
    ui->label_int->setPalette(p);
    points_calculation();
}

void MainWindow::on_lineEdit_dex_textChanged(const QString &)
{
    uint value;
    QString str;
    bool flag;
    QColor oranges, trueyellow;
    oranges.setRgb(255,94,19);
    trueyellow.setRgb(255, 214, 0);



    str=ui->lineEdit_dex->text();
    value=str.toUInt(&flag);
    QPalette p=ui->lineEdit_dex->palette();
    if(flag and value>0 and value<=10)
        p.setColor(QPalette::Text,Qt::green);
    else
        p.setColor(QPalette::Text,Qt::red);
    ui->lineEdit_dex->setPalette(p);

    if((value<=0) || (value>10))
        p.setColor(QPalette::WindowText,Qt::red);
    else if((value>0) && (value<4))
        p.setColor(QPalette::WindowText,oranges);
    else if((value>3) && (value<7))
        p.setColor(QPalette::WindowText,trueyellow);
    else if((value>=7) && (value<11))
        p.setColor(QPalette::WindowText,Qt::green);
    ui->label_dex->setPalette(p);
    points_calculation();
}

void MainWindow::on_lineEdit_luck_textChanged(const QString &)
{
    uint value;
    QString str;
    bool flag;
    QColor oranges, trueyellow;
    oranges.setRgb(255,94,19);
    trueyellow.setRgb(255, 214, 0);



    str=ui->lineEdit_luck->text();
    value=str.toUInt(&flag);
    QPalette p=ui->lineEdit_str->palette();
    if(flag and value>0 and value<=10)
        p.setColor(QPalette::Text,Qt::green);
    else
        p.setColor(QPalette::Text,Qt::red);
    ui->lineEdit_luck->setPalette(p);

    if((value<=0) || (value>10))
        p.setColor(QPalette::WindowText,Qt::red);
    else if((value>0) && (value<4))
        p.setColor(QPalette::WindowText,oranges);
    else if((value>3) && (value<7))
        p.setColor(QPalette::WindowText,trueyellow);
    else if((value>=7) && (value<11))
        p.setColor(QPalette::WindowText,Qt::green);
    ui->label_luck->setPalette(p);
    points_calculation();
}

void MainWindow::on_lineEdit_race_textChanged(const QString &)
{
    uint value;
    QString str;
    bool flag;
    QColor oranges, trueyellow;
    oranges.setRgb(255,94,19);
    trueyellow.setRgb(255, 214, 0);



    str=ui->lineEdit_race->text();
    value=str.toUInt(&flag);
    QPalette p=ui->lineEdit_race->palette();
    if(flag and value>0 and value<=10)
        p.setColor(QPalette::Text,Qt::green);
    else
        p.setColor(QPalette::Text,Qt::red);
    ui->lineEdit_race->setPalette(p);

    if((value<=0) || (value>10))
        p.setColor(QPalette::WindowText,Qt::red);
    else if((value>0) && (value<4))
        p.setColor(QPalette::WindowText,oranges);
    else if((value>3) && (value<7))
        p.setColor(QPalette::WindowText,trueyellow);
    else if((value>=7) && (value<11))
        p.setColor(QPalette::WindowText,Qt::green);
    ui->label_raceability->setPalette(p);
    points_calculation();
}
