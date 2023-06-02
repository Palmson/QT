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
    void on_pushButton_clicked();

    void on_pushSetTextButton_clicked();

    void on_pushWriteNumber_clicked();

    void on_pushGetNumberButter_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_timeEdit_userTimeChanged(const QTime &time);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
