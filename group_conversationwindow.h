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
    QTimer * timer;
    explicit group_conversationwindow(QWidget *parent = 0);
    std::string username,groupname;
    int socketDescriptor;
     void showEvent(QShowEvent * event);
     void getParticipants();
    ~group_conversationwindow();

public slots:
     void getMessages();


private slots:
    void on_sendButton_clicked();

    void on_addButton_clicked();

private:
    Ui::group_conversationwindow *ui;
};

#endif // GROUP_CONVERSATIONWINDOW_H
