#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <unistd.h>
#include "utilities.h"

registerWindow::registerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerWindow)
{
    ui->setupUi(this);
    if(socketDescriptor <= 0){
        ui->labelStatus->setText("Status: Cannot connect to the server.");
    }
    else{
        ui->labelStatus->setText("Status: Connected to the server.");
    }
}

registerWindow::~registerWindow()
{
    delete ui;
}

void registerWindow::on_cancelButton_clicked()
{
    this->hide();
}

void registerWindow::on_registerButton_clicked()
{
    std::string user,pass1,pass2;
    user = ui->userField->text().toStdString();
    pass1 = ui->passField->text().toStdString();
    pass2 = ui->passField_2->text().toStdString();
    if(pass1 != pass2){
        ui->labelStatus->setText("Status: Passwords do not match.");
        return;
    }
    sendMessage(socketDescriptor,"REG");
    sendMessage(socketDescriptor,user);
    sendMessage(socketDescriptor,pass1);
}
