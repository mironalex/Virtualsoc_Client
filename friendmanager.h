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
    void showEvent(QShowEvent * event);
    explicit friendManager(QWidget *parent = 0);
    int socketDescriptor;
    std::string username;
    ~friendManager();
    void populateFriendLists();

private slots:
    void on_Accept_clicked();

    void on_requestList_itemClicked(QListWidgetItem *item);

    void on_friendList_clicked(const QModelIndex &index);

    void on_deleteButton_clicked();

private:
    Ui::friendManager *ui;
};

#endif // FRIENDMANAGER_H
