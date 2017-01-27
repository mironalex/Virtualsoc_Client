/**
  * A simple class for the login screen.
  */
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
    int sd; /**< socket descriptor to the server */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /**
     * @brief on_loginButton_clicked a function that sends a login request when the login button is clicked.
     */
    void on_loginButton_clicked();
    /**
     * @brief on_registerButton_clicked a function that opens up a register form window.
     */
    void on_registerButton_clicked();
    /**
     * @brief on_guestButton_clicked a function that opens up a guest session window.
     */
    void on_guestButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
