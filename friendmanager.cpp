#include "friendmanager.h"
#include "ui_friendmanager.h"
#include "utilities.h"
#include <string>

friendManager::friendManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendManager)
{
    ui->setupUi(this);
}

friendManager::~friendManager()
{
    delete ui;
}

void friendManager::populateFriendLists(){
    sendMessage(this->socketDescriptor,"GFR");
    int x = readInt(this->socketDescriptor);
    char friendCount[100];
    read(this->socketDescriptor,friendCount,x);
    int n = atoi(friendCount);
    for(int i = 0; i < n; i++){
        char * friendUser;
        int friendSize;
        friendSize = readInt(this->socketDescriptor);
        friendUser = new char[friendSize+1];
        read(this->socketDescriptor,friendUser,friendSize);
        friendUser[friendSize] = 0;
        ui->requestList->addItem(friendUser);
        delete[] friendUser;
    }
    sendMessage(this->socketDescriptor,"GFL");
    x = readInt(this->socketDescriptor);
    read(this->socketDescriptor,friendCount,x);
    friendCount[x] = 0;
    n = atoi(friendCount);
    for(int i = 0; i < n; i++){
        char * friendUser;
        int friendSize;
        friendSize = readInt(this->socketDescriptor);
        friendUser = new char[friendSize+1];
        read(this->socketDescriptor,friendUser,friendSize);
        friendUser[friendSize] = 0;
        ui->friendList->addItem(friendUser);
        delete[] friendUser;
    }
}

void friendManager::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    if(event->spontaneous() == false){
        //Populate the friend request list

        sendMessage(this->socketDescriptor,"GFR");
        int x = readInt(this->socketDescriptor);
        char friendCount[100];
        read(this->socketDescriptor,friendCount,x);
        int n = atoi(friendCount);
        for(int i = 0; i < n; i++){
            char * friendUser;
            int friendSize;
            friendSize = readInt(this->socketDescriptor);
            friendUser = new char[friendSize+1];
            read(this->socketDescriptor,friendUser,friendSize);
            friendUser[friendSize] = 0;
            ui->requestList->addItem(friendUser);
            delete[] friendUser;
        }

        //Populate the friend list

        sendMessage(this->socketDescriptor,"GFL");
        x = readInt(this->socketDescriptor);
        read(this->socketDescriptor,friendCount,x);
        friendCount[x] = 0;
        n = atoi(friendCount);
        for(int i = 0; i < n; i++){
            char * friendUser;
            int friendSize;
            friendSize = readInt(this->socketDescriptor);
            friendUser = new char[friendSize+1];
            read(this->socketDescriptor,friendUser,friendSize);
            friendUser[friendSize] = 0;
            ui->friendList->addItem(friendUser);
            delete[] friendUser;
        }
    }
}

void friendManager::on_requestList_itemClicked(QListWidgetItem *item)
{
    std::string user = ui->requestList->currentItem()->text().toStdString();
    ui->userBox->setText(user.c_str());
}

void friendManager::on_friendList_clicked(const QModelIndex &index)
{
    std::string user = ui->friendList->currentItem()->text().toStdString();
    ui->userBox->setText(user.c_str());
}

void friendManager::on_Accept_clicked()
{
    std::string user = ui->userBox->text().toStdString();
        if(user.length()>0){
        char friendType = ui->friendType->currentIndex() + '0';
        sendMessage(this->socketDescriptor,"ADD");
        std::string request;
        request += friendType;
        request += ":" + user +":";
        sendMessage(this->socketDescriptor,request);
        char response[1000];
        int bufferSize;
        bufferSize = readInt(this->socketDescriptor);
        read(this->socketDescriptor,response,bufferSize);
        ui->friendList->clear();
        ui->requestList->clear();
        ui->userBox->clear();
        if(strstr(response,"Successful")!=0) this->populateFriendLists();
    }
}

void friendManager::on_deleteButton_clicked()
{
    std::string user = ui->userBox->text().toStdString();
    if(user.length()>0){
        sendMessage(socketDescriptor,"DEL");
        sendMessage(socketDescriptor,user);
        ui->friendList->clear();
        ui->requestList->clear();
        ui->userBox->clear();
        this->populateFriendLists();
    }
}
