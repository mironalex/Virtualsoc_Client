/**
 * A class for the conversation manager window.
 */
#ifndef CONVERSATION_MANAGER_H
#define CONVERSATION_MANAGER_H

#include <QDialog>
#include <string>


namespace Ui {
class conversation_manager;
}

class conversation_manager : public QDialog
{
    Q_OBJECT

public:
    std::string username; /**<the username of the logged client. */
    int socketDescriptor; /**<socket descriptor to the server.*/
    /**
     * @brief showEvent a public function used to initialize the lists of the interface
     * @param event a variable that describes events such as if the windows was drawn for the first time
     */
    void showEvent(QShowEvent * event);
    /**
     * @brief getConversationList a public function that populates the conversation list.
     */
    void getConversationList();
    explicit conversation_manager(QWidget *parent = 0);
    ~conversation_manager();

private slots:
    /**
     * @brief on_leaveButton_clicked a function that leaves the group selected
     */
    void on_leaveButton_clicked();
    /**
     * @brief on_createButton_clicked a function that creates a group with the given name
     */
    void on_createButton_clicked();
    /**
     * @brief on_conversationList_itemClicked a function that copies the items name to the input box
     */
    void on_conversationList_itemClicked();

private:
    Ui::conversation_manager *ui;
};

#endif // CONVERSATION_MANAGER_H
