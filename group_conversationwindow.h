/**
 * A class for the group conversation window interface
 */
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
    QTimer * timer; /**< timer that refreshes the messages */
    explicit group_conversationwindow(QWidget *parent = 0);
    std::string username,groupname;
    int socketDescriptor;
    /**
     * @brief showEvent a public function used to initialize the lists of the interface
     * @param event a variable that describes events such as if the windows was drawn for the first time
     */
     void showEvent(QShowEvent * event);
     /**
      * @brief getParticipants a public function that populates the participant list when it is called.
      */
     void getParticipants();
    ~group_conversationwindow();

public slots:
     /**
      * @brief getMessages a public function that is called by the timer and refreshes the message list.
      */
     void getMessages();


private slots:
     /**
     * @brief on_sendButton_clicked a private function that sends a message when the send button is clicked.
     */
    void on_sendButton_clicked();
    /**
     * @brief on_addButton_clicked a private function that adds a user to the conversation when the add button is clicked.
     */
    void on_addButton_clicked();

private:
    Ui::group_conversationwindow *ui;
};

#endif // GROUP_CONVERSATIONWINDOW_H
