#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QDialog>
#include <string>

namespace Ui {
class conversationWindow;
}

class conversationWindow : public QDialog
{
    Q_OBJECT

public:

    QTimer * timer;
    std::string username,partner;
    void showEvent(QShowEvent * event);
    int socketDescriptor;
    explicit conversationWindow(QWidget *parent = 0);
    ~conversationWindow();
    //void refreshPosts();

public slots:
    void refreshPosts();

private slots:
    void on_enterButton_clicked();

private:
    Ui::conversationWindow *ui;
};

#endif // CONVERSATIONWINDOW_H
