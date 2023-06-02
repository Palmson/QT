#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>//подключение системы вывода сообщений



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

    void on_pushButton_calculate_clicked();

    void on_lineEdit_side1_textChanged(const QString &arg1);

    void on_lineEdit_side2_textChanged(const QString &arg1);

    void on_lineEdit_angle_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
