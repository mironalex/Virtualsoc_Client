#ifndef GROUP_CONVERSATIONWINDOW_H
#define GROUP_CONVERSATIONWINDOW_H

#include <QDialog>
#include <string>

namespace Ui {
class group_conversationwindow;
}

class group_conversationwindow : public QDialog
{
    Q_OBJECT

public:
    explicit group_conversationwindow(QWidget *parent = 0);
    std::string username,groupname;
    int socketDescriptor;
    ~group_conversationwindow();

private slots:
    void on_sendButton_clicked();

    void on_addButton_clicked();

private:
    Ui::group_conversationwindow *ui;
};

#endif // GROUP_CONVERSATIONWINDOW_H
