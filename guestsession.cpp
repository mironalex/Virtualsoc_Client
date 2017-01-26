#include "guestsession.h"
#include "ui_guestsession.h"
#include "utilities.h"
#include <QShowEvent>

guestSession::guestSession(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guestSession)
{
    ui->setupUi(this);
}

guestSession::~guestSession()
{
    delete ui;
}

void guestSession::showEvent(QShowEvent * event){
    QWidget::showEvent( event );
    if(event->spontaneous() == false){
        sendMessage(socketDescriptor,"GET");
        std::string request = "GUEST:0:100:";
        sendMessage(socketDescriptor,request.c_str());
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
            std::string header = author; header += " posted on: ";
            header.append(date);
            ui->postBrowser->append(header.c_str());
            ui->postBrowser->append(post);
            delete[] post;
            delete[] author;
            delete[] date;
        }
        ui->postBrowser->moveCursor(QTextCursor::Start,QTextCursor::MoveAnchor);
    }
}
