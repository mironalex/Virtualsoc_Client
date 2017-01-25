#include "conversationwindow.h"
#include "ui_conversationwindow.h"

conversationWindow::conversationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::conversationWindow)
{
    ui->setupUi(this);
}

conversationWindow::~conversationWindow()
{
    delete ui;
}

