/**
  * A class for the friend manager window interface
  */
#ifndef FRIENDMANAGER_H
#define FRIENDMANAGER_H

#include <QDialog>
#include <string>
#include <QShowEvent>
#include <QListWidget>

namespace Ui {
class friendManager;
}

class friendManager : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief showEvent a public function used to initialize the lists of the interface
     * @param event a variable that describes events such as if the windows was drawn for the first time
     */
    void showEvent(QShowEvent * event);
    explicit friendManager(QWidget *parent = 0);
    int socketDescriptor; /**<socket descriptor to the server */
    std::string username; /**< holds the username of the logged client */
    ~friendManager();
    /**
     * @brief populateFriendLists a function that populates the friend list.
     */
    void populateFriendLists();

private slots:
    /**
     * @brief on_Accept_clicked a function that accepts a friend request when the accept button is clicked.
     */
    void on_Accept_clicked();
    /**
     * @brief on_requestList_itemClicked a function that copies the items name to the input box when it is clicked.
     */
    void on_requestList_itemClicked();
    /**
     * @brief on_friendList_clicked a function that copies the items name to the input box when it is clicked.
     */
    void on_friendList_clicked();
    /**
     * @brief on_deleteButton_clicked a function that deletes a friend when the delete button is clicked.
     */
    void on_deleteButton_clicked();

private:
    Ui::friendManager *ui;
};

#endif // FRIENDMANAGER_H
