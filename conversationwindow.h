#ifndef CONVERSATIONWINDOW_H
#define CONVERSATIONWINDOW_H

#include <QDialog>
#include <string.h>

namespace Ui {
class conversationWindow;
}

class conversationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit conversationWindow(QWidget *parent = 0);
    std::string username;
    int socketDescriptor;
    ~conversationWindow();

private slots:
    void on_postBox_destroyed();

private:
    Ui::conversationWindow *ui;
};

#endif // CONVERSATIONWINDOW_H
