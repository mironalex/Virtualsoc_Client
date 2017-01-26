#include "conversation_manager.h"
#include "ui_conversation_manager.h"
#include "utilities.h"
#include <QShowEvent>

conversation_manager::conversation_manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::conversation_manager)
{
    ui->setupUi(this);
}

conversation_manager::~conversation_manager()
{
    delete ui;
}

void conversation_manager::on_leaveButton_clicked()
{
    ui->inputBox->clear();
}

void conversation_manager::showEvent(QShowEvent * event){
    QWidget::showEvent( event );
    if(event->spontaneous() == false){
        getConversationList();
    }
}
void conversation_manager::getConversationList(){
    sendMessage(socketDescriptor,"GGL");
    int x = readInt(this->socketDescriptor);
    char groupCount[100];
    read(this->socketDescriptor,groupCount,x);
    int n = atoi(groupCount);
    ui->conversationList->clear();
    for(int i = 0; i < n; i++){
        char * groupName;
        int groupSize = readInt(socketDescriptor);
        groupName = new char[groupSize+1];
        read(socketDescriptor,groupName,groupSize);
        groupName[groupSize] = 0;
        ui->conversationList->addItem(groupName);
        delete[] groupName;
    }
}

void conversation_manager::on_createButton_clicked()
{
    std::string groupName =ui->inputBox->text().toStdString();

    sendMessage(socketDescriptor,"ITG");
    sendMessage(socketDescriptor,username);
    sendMessage(socketDescriptor,groupName);

    getConversationList();
}
