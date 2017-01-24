#include "clientinterface.h"
#include "ui_clientinterface.h"
#include "utilities.h"
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

void clientInterface::showEvent(QShowEvent * event){
    QWidget::showEvent( event );
    if(event->spontaneous() == false){
        sendMessage(this->socketDescriptor,"GET");
        string packet = this->username;
        packet += ":0:10:";
        sendMessage(this->socketDescriptor,packet);
        int x;
        char messageCount[100];
        x = readInt(this->socketDescriptor);
        read(this->socketDescriptor,messageCount,x);
        int n = atoi(messageCount);
        for(int i = 0; i < n; i++){
            char * post, * author, *date;
            int postSize, authorSize,dateSize;
            authorSize = readInt(this->socketDescriptor);
            author = new char[authorSize+2];
            read(this->socketDescriptor,author,authorSize);
            postSize = readInt(this->socketDescriptor);
            post = new char[postSize+1];
            read(this->socketDescriptor,post,postSize);
            date = new char[dateSize+1];
            dateSize = readInt(this->socketDescriptor);
            read(this->socketDescriptor,date,dateSize);
            date[dateSize] = 0;
            post[postSize] = 0;
            author[authorSize] =':';
            author[authorSize+1]=0;
            string header = author; header += " posted on: ";
            header.append(date);
            ui->postBrowser->append(header.c_str());
            ui->postBrowser->append('\t'+post);
            delete[] post;
            delete[] author;
        }
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
    }
}

void clientInterface::on_listWidget_clicked(const QModelIndex &index){

}

void clientInterface::on_manage_friendsButton_clicked()
{
    friendManager managerUI;
    managerUI.socketDescriptor = this->socketDescriptor;
    managerUI.username = username;
    managerUI.setModal(true);
    managerUI.exec();
}
