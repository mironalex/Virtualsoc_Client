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
    int sd;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

    void on_passFIeld_returnPressed();

    void on_registerButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
