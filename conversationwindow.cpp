#include "conversationwindow.h"
#include "ui_conversationwindow.h"
#include "utilities.h"
#include <QTimer>

conversationWindow::conversationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::conversationWindow)
{
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refreshPosts()));
    timer->start(1000);
    ui->setupUi(this);
}

conversationWindow::~conversationWindow()
{
    delete ui;
}

void conversationWindow::showEvent(QShowEvent * event){
    QWidget::showEvent( event );
    if(event->spontaneous() == false){
        sendMessage(socketDescriptor,"GPM");
        sendMessage(socketDescriptor,partner);
        int countSize;  char count[100];
        countSize = readInt(socketDescriptor);
        read(socketDescriptor,count,countSize);
        int n = atoi(count);
        for(int i = 0; i < n; i++){
            char *sender, *message, *time;
            int senderSize, messageSize, timeSize;

            senderSize = readInt(socketDescriptor);
            sender = new char[senderSize+1];
            read(socketDescriptor,sender,senderSize);
            sender[senderSize] = 0;

            messageSize = readInt(socketDescriptor);
            message = new char[messageSize+1];
            read(socketDescriptor,message,messageSize);
            message[messageSize] = 0;

            timeSize = readInt(socketDescriptor);
            time = new char[timeSize+1];
            time[timeSize] = 0;
            read(socketDescriptor,time,timeSize);

            std::string header = "<"; header.append(time); header+= ">"; header.append(sender); header+= ":";

            ui->pmBrowser->append(header.c_str());
            ui->pmBrowser->append(message);
            delete[] sender;
            delete[] message;
            delete[] time;
        }
    }
}

void conversationWindow::on_enterButton_clicked()
{
    //send whatever's in the input text box and send it to the server

    std::string message = ui->inputBox->toPlainText().toStdString();
    if(message.length()>0){
        sendMessage(socketDescriptor,"SPM");
        sendMessage(socketDescriptor,partner);
        sendMessage(socketDescriptor,message);
        ui->inputBox->clear();
    }
}


void conversationWindow::refreshPosts(){
    ui->pmBrowser->clear();
    sendMessage(socketDescriptor,"GPM");
    sendMessage(socketDescriptor,partner);
    int countSize;  char count[100];
    countSize = readInt(socketDescriptor);
    read(socketDescriptor,count,countSize);
    int n = atoi(count);
    for(int i = 0; i < n; i++){
        char *sender, *message, *time;
        int senderSize, messageSize, timeSize;

        senderSize = readInt(socketDescriptor);
        sender = new char[senderSize+1];
        read(socketDescriptor,sender,senderSize);
        sender[senderSize] = 0;

        messageSize = readInt(socketDescriptor);
        message = new char[messageSize+1];
        read(socketDescriptor,message,messageSize);
        message[messageSize] = 0;

        timeSize = readInt(socketDescriptor);
        time = new char[timeSize+1];
        time[timeSize] = 0;
        read(socketDescriptor,time,timeSize);

        std::string header = "<"; header.append(time); header+= ">"; header.append(sender); header+= ":";

        ui->pmBrowser->append(header.c_str());
        ui->pmBrowser->append(message);
        delete[] sender;
        delete[] message;
        delete[] time;
    }
}
