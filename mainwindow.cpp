#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "client.h"
#include "clientinterface.h"
#include "registerwindow.h"
#include "utilities.h"
#include "guestsession.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    sd = startConnection();
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    string password = ui->passField->text().toStdString();
    string username = ui->userField->text().toStdString();
    if(username.length() * password.length() > 0){
        sendMessage(sd,"LOG");
        sendMessage(sd,username);
        sendMessage(sd,password);
        int size = readInt(sd);
        char * message = new char[size+1];
        read(sd,message,size);
        printf("%s",message);
        if(strstr(message,"Successful")){
            this->hide();
            clientInterface clientUI;
            clientUI.socketDescriptor = this->sd;
            clientUI.username = username;
            clientUI.setModal(true);
            clientUI.exec();
        }
        delete[] message;
    }
}

void MainWindow::on_passFIeld_returnPressed()
{

}

void MainWindow::on_registerButton_clicked()
{
    registerWindow registerForm;
    registerForm.socketDescriptor = this->sd;
    registerForm.setModal(true);
    registerForm.exec();
}

void MainWindow::on_guestButton_clicked()
{
    guestSession guest;

    guest.socketDescriptor = sd;
    guest.setModal(true);
    guest.exec();
}
