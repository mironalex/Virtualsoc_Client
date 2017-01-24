#ifndef FRIENDMANAGER_H
#define FRIENDMANAGER_H

#include <QDialog>
#include <string.h>

namespace Ui {
class friendManager;
}

class friendManager : public QDialog
{
    Q_OBJECT

public:
    explicit friendManager(QWidget *parent = 0);
    int socketDescriptor;
    std::string username;
    ~friendManager();

private:
    Ui::friendManager *ui;
};

#endif // FRIENDMANAGER_H
