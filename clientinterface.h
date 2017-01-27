/**
 * A class for the main hub client interface.
 */
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
    int socketDescriptor; /**<Socket descriptor to the server. */
    std::string username; /**<The username of the logged client. */
    explicit clientInterface(QWidget *parent = 0);
    /**
     * @brief showEvent a public function used to initialize the lists of the interface
     * @param event a variable that describes events such as if the windows was drawn for the first time
     */
    void showEvent(QShowEvent * event);
    void getRecentPosts();
    /**
     * @brief getFriendList a function used to populate the friend list
     */
    void getFriendList();
    /**
     * @brief getConversationList a function used to populate the conversation list
     */
    void getConversationList();
    ~clientInterface();

private slots:
    /**
     * @brief on_postButton_clicked a function that sends the post to the server when the post button is clicked
     */
    void on_postButton_clicked();
    /**
     * @brief on_addFriendButton_clicked a function that adds a friend when the add friend button is clicked
     */
    void on_addFriendButton_clicked();
    /**
     * @brief on_manage_friendsButton_clicked a function that opens the friend manager when the apropriate button is clicked
     */
    void on_manage_friendsButton_clicked();
    /**
     * @brief on_friendList_doubleClicked a function that opens a private messanger window to the user that was double clicked
     */
    void on_friendList_doubleClicked();
    /**
     * @brief on_manage_conversationsButton_clicked
     */
    void on_manage_conversationsButton_clicked();
    /**
     * @brief on_convList_doubleClicked a function that opens a private conversation window to the group that was double clicked
     */
    void on_convList_doubleClicked();
    /**
     * @brief on_friendList_clicked a function that copies the friend user to the go to input box
     */
    void on_friendList_clicked();
    /**
     * @brief on_recentPostsButton_clicked a function that displays the most recent posts of his friend that the user can see
     */
    void on_recentPostsButton_clicked();
    /**
     * @brief on_publicPostsButton_clicked a function that displays the most recent public posts of all the users on the service
     */
    void on_publicPostsButton_clicked();
    /**
     * @brief on_go_to_ProfileButton_clicked a function that displays the posts of the user in the go to input box
     */
    void on_go_to_ProfileButton_clicked();

private:
    Ui::clientInterface *ui;
};

#endif // CLIENTINTERFACE_H
