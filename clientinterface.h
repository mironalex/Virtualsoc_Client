#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include <string>
#include <QTimer>
#include <QDialog>
#include "utilities.h"

namespace Ui {
class clientInterface;
}

class clientInterface : public QDialog
{
    Q_OBJECT

public:
    int socketDescriptor;
    std::string username;
    explicit clientInterface(QWidget *parent = 0);
    void showEvent(QShowEvent * event);
    void getRecentPosts();
    void getFriendList();
    void getConversationList();
    ~clientInterface();

private slots:
    void on_postButton_clicked();

    void on_addFriendButton_clicked();

    void on_manage_friendsButton_clicked();

    void on_friendList_doubleClicked();

    void on_manage_conversationsButton_clicked();

    void on_convList_doubleClicked(const QModelIndex &index);

    void on_friendList_clicked();

private:
    Ui::clientInterface *ui;
};

#endif // CLIENTINTERFACE_H
