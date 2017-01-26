#include "clientinterface.h"
#include "ui_clientinterface.h"
#include "utilities.h"
#include "conversationwindow.h"
#include "group_conversationwindow.h"
#include "conversation_manager.h"
#include "friendmanager.h"
#include <string>
#include <cstdlib>

using namespace std;

clientInterface::clientInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientInterface)
{
    ui->setupUi(this);
}

clientInterface::~clientInterface()
{
    delete ui;
}

void clientInterface::getRecentPosts(){
    sendMessage(this->socketDescriptor,"GET");
    string packet = this->username;
    packet += ":0:10:";
    sendMessage(this->socketDescriptor,packet);
    int x;
    char messageCount[100];
    x = readInt(this->socketDescriptor);
    read(this->socketDescriptor,messageCount,x);
    ui->postBrowser->clear();
    int n = atoi(messageCount);
    for(int i = 0; i < n; i++){
        char * post, * author, *date;
        int postSize, authorSize,dateSize;
        authorSize = readInt(this->socketDescriptor);
        author = new char[authorSize+1];
        read(this->socketDescriptor,author,authorSize);
        postSize = readInt(this->socketDescriptor);
        post = new char[postSize+3];
        read(this->socketDescriptor,post+1,postSize);
        date = new char[dateSize+1];
        dateSize = readInt(this->socketDescriptor);
        read(this->socketDescriptor,date,dateSize);
        date[dateSize] = post[postSize+2] = author[authorSize] = 0;
        post[postSize+1] = '\n'; post[0] = '\t';
        string header = author; header += " posted on: ";
        header.append(date);
        ui->postBrowser->append(header.c_str());
        ui->postBrowser->append(post);
        delete[] post;
        delete[] author;
        delete[] date;
    }
    ui->postBrowser->moveCursor(QTextCursor::Start,QTextCursor::MoveAnchor);
}

void clientInterface::getFriendList(){
    sendMessage(this->socketDescriptor,"GFL");
    int x = readInt(this->socketDescriptor);
    char friendCount[100];
    read(this->socketDescriptor,friendCount,x);
    int n = atoi(friendCount);
    ui->friendList->clear();
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

void clientInterface::showEvent(QShowEvent * event){
    QWidget::showEvent( event );
    if(event->spontaneous() == false){
        //Getting and displaying the posts of our friends
        this->getRecentPosts();


        //Populating the friend list
        this->getFriendList();

    }
}

void clientInterface::on_postButton_clicked()
{
    if( ui->postBox->toPlainText().toStdString().size() > 0){
        char type = ui->postType->currentIndex() + '0';
        string postText;
        postText+= type;
        postText+= ":";
        postText.append(ui->postBox->toPlainText().toStdString());
        postText += ":";
        sendMessage(this->socketDescriptor,"PST");
        sendMessage(this->socketDescriptor,postText);
        char buffer[1000];
        int bufferSize;
        bufferSize = readInt(this->socketDescriptor);
        read(socketDescriptor,buffer,bufferSize);
        ui->postBox->clear();
    }
}

void clientInterface::on_addFriendButton_clicked()
{
    if ( ui->friendAddBox->text().toStdString().size() > 0){
        string befriend = ui->friendAddBox->text().toStdString();
        char friendType = ui->friendType->currentIndex() + '0';
        sendMessage(this->socketDescriptor,"ADD");
        string request;
        request += friendType;
        request += ":" + befriend +":";
        sendMessage(this->socketDescriptor,request);
        char response[1000];
        int bufferSize;
        bufferSize = readInt(this->socketDescriptor);
        read(this->socketDescriptor,response,bufferSize);
        ui->friendAddBox->clear();
        if(strstr(response,"Successful")!=0) ui->friendList->addItem(befriend.c_str());
    }
}


void clientInterface::on_manage_friendsButton_clicked()
{
    friendManager managerUI;
    managerUI.socketDescriptor = this->socketDescriptor;
    managerUI.username = username;
    managerUI.setModal(true);
    managerUI.exec();
    this->getFriendList();
}

void clientInterface::on_friendList_doubleClicked()
{
    string user = ui->friendList->currentItem()->text().toStdString();
    conversationWindow newConversation;
    newConversation.socketDescriptor = this->socketDescriptor;
    newConversation.username = username;
    newConversation.partner = user;
    newConversation.exec();
}

void clientInterface::on_manage_conversationsButton_clicked()
{
    conversation_manager conv_manager;
    conv_manager.socketDescriptor = this->socketDescriptor;
    conv_manager.username = username;
    conv_manager.setModal(true);
    conv_manager.exec();
}

void clientInterface::on_convList_doubleClicked(const QModelIndex &index)
{
    string groupname = ui->convList->currentItem()->text().toStdString();
    group_conversationwindow newGroupConversation;
    newGroupConversation.socketDescriptor = this->socketDescriptor;
    newGroupConversation.username = username;
    newGroupConversation.groupname = groupname;
    newGroupConversation.exec();
}

void clientInterface::on_friendList_clicked()
{
    std::string user = ui->friendList->currentItem()->text().toStdString();
    ui->go_to_inputBox->setText(user.c_str());
}
