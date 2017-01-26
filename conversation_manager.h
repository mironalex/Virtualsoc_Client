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
    std::string username;
    int socketDescriptor;
    void showEvent(QShowEvent * event);
    void getConversationList();
    explicit conversation_manager(QWidget *parent = 0);
    ~conversation_manager();

private slots:
    void on_leaveButton_clicked();

    void on_createButton_clicked();

private:
    Ui::conversation_manager *ui;
};

#endif // CONVERSATION_MANAGER_H
