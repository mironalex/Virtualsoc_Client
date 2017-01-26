#include "group_conversationwindow.h"
#include "ui_group_conversationwindow.h"
#include <QShowEvent>
#include <QTimer>

#include "utilities.h"

group_conversationwindow::group_conversationwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::group_conversationwindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(getMessages()));
    timer->start(1000);
}

group_conversationwindow::~group_conversationwindow()
{
    delete ui;
}

void group_conversationwindow::getParticipants(){
    sendMessage(socketDescriptor,"GGP");
    sendMessage(socketDescriptor,groupname);
    int x = readInt(this->socketDescriptor);
    char participantsCount[100];
    read(socketDescriptor,participantsCount,x);
    int n = atoi(participantsCount);
    ui->participantsList->clear();
    for(int i = 0; i < n; i++){
        char * user;
        int userSize = readInt(socketDescriptor);
        user = new char[userSize+1];
        read(socketDescriptor,user,userSize);
        user[userSize] = 0;

        ui->participantsList->addItem(user);
    }
}

void group_conversationwindow::getMessages(){
    sendMessage(socketDescriptor,"GGM");
    sendMessage(socketDescriptor,groupname);
    int x = readInt(this->socketDescriptor);
    char messageCount[100];
    read(this->socketDescriptor,messageCount,x);
    int n = atoi(messageCount);
    ui->messageBrowser->clear();
    for(int i = 0; i < n; i++){
        char * message, * author, * date;

        int authorSize = readInt(socketDescriptor);
        author = new char[authorSize+1];
        read(socketDescriptor,author,authorSize);
        author[authorSize] = 0;

        int messageSize = readInt(socketDescriptor);
        message = new char[messageSize+1];
        read(socketDescriptor,message,messageSize);
        message[messageSize] = 0;

        int dateSize = readInt(socketDescriptor);
        date = new char[dateSize+1];
        read(socketDescriptor,date,dateSize);
        date[dateSize] = 0;

        std::string header = "<"; header.append(date); header+= ">"; header.append(author); header+= ":";

        ui->messageBrowser->append(header.c_str());
        ui->messageBrowser->append(message);
    }
}

void group_conversationwindow::showEvent(QShowEvent * event){
    QWidget::showEvent( event );
    if(event->spontaneous() == false){
        this->getMessages();
        this->getParticipants();
    }
}

void group_conversationwindow::on_sendButton_clicked()
{
    sendMessage(socketDescriptor,"SGM");
    std::string message = ui->inputBox->toPlainText().toStdString();
    ui->inputBox->clear();
    sendMessage(socketDescriptor,groupname);
    sendMessage(socketDescriptor,message);
}

void group_conversationwindow::on_addButton_clicked()
{
    std::string user = ui->userBox->text().toStdString();
    ui->userBox->clear();
    sendMessage(socketDescriptor,"ITG");
    sendMessage(socketDescriptor,user);
    sendMessage(socketDescriptor,groupname);
    this->getParticipants();
}
