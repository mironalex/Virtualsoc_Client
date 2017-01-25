#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QDialog>
#include <string>;

namespace Ui {
class conversationWindow;
}

class conversationWindow : public QDialog
{
    Q_OBJECT

public:
    std::string username,partner;
    void showEvent(QShowEvent * event);
    int socketDescriptor;
    explicit conversationWindow(QWidget *parent = 0);
    ~conversationWindow();

private slots:
    void on_pushButton_clicked();

    void on_enterButton_clicked();

private:
    Ui::conversationWindow *ui;
};

#endif // CONVERSATIONWINDOW_H
