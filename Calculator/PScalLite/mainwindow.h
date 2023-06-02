#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_radioButton_plus_clicked();

    void on_radioButton_minus_clicked();

    void on_radioButton_mul_clicked();

    void on_radioButton_div_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_equals_clicked();

    void on_radioButton_sin_clicked();

    void on_radioButton_cos_clicked();

    void on_radioButton_asin_clicked();

    void on_radioButton_acos_clicked();

    void on_radioButton_quad_clicked();

    void on_radioButton_S_clicked();

    void on_radioButton_tg_clicked();

    void on_radioButton_clicked();

    void on_radioButton_factorial_clicked();

    void on_radioButton_atan_clicked();

    void on_radioButton_BigDatamode_clicked();

    void on_radioButton_normalmode_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
