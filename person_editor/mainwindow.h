#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>//подключение сообщений из библиотеки

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
    void on_pushButton_clear_clicked();

    void on_pushButton_create_clicked();

    void on_radioButton_race_human_clicked();

    void on_radioButton_race_darkelf_clicked();

    void on_radioButton_race_ogr_clicked();

    void on_radioButton_race_Khajiit_clicked();

    void on_lineEdit_name_textChanged(const QString &arg1);

    void on_lineEdit_str_textChanged(const QString &arg1);

    void on_lineEdit_int_textChanged(const QString &arg1);

    void on_lineEdit_dex_textChanged(const QString &arg1);

    void on_lineEdit_luck_textChanged(const QString &arg1);

    void on_lineEdit_race_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    void points_calculation(void);
};

#endif // MAINWINDOW_H
