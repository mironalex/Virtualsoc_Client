#include "friendmanager.h"
#include "ui_friendmanager.h"

friendManager::friendManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::friendManager)
{
    ui->setupUi(this);
}

friendManager::~friendManager()
{
    delete ui;
}
