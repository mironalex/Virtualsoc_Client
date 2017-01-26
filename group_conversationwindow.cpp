#include "group_conversationwindow.h"
#include "ui_group_conversationwindow.h"

group_conversationwindow::group_conversationwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::group_conversationwindow)
{
    ui->setupUi(this);
}

group_conversationwindow::~group_conversationwindow()
{
    delete ui;
}

void group_conversationwindow::on_sendButton_clicked()
{

}

void group_conversationwindow::on_addButton_clicked()
{

}
