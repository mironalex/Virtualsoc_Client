/**
 * A class for the conversation window interface
 */
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

    QTimer * timer; /**< a timer used to refresh the messages. */
    std::string username; /**<holds the username of the logged client. */
    std::string partner; /**<holds the username of the conversation partner. */
    /**
     * @brief showEvent a public function used to initialize the lists of the interface
     * @param event a variable that describes events such as if the windows was drawn for the first time
     */
    void showEvent(QShowEvent * event);
    int socketDescriptor; /**<socket descriptor to the server */
    explicit conversationWindow(QWidget *parent = 0);
    ~conversationWindow();

public slots:
    /**
     * @brief refreshPosts a function that refreshes the messages displayed
     */
    void refreshPosts();

private slots:
    /**
     * @brief on_enterButton_clicked a function that sends a given message when the button is clicked.
     */
    void on_enterButton_clicked();

private:
    Ui::conversationWindow *ui;
};

#endif // CONVERSATIONWINDOW_H
