#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class registerWindow;
}

class registerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit registerWindow(QWidget *parent = 0);
    ~registerWindow();
    int socketDescriptor;

private slots:
    void on_cancelButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::registerWindow *ui;
};

#endif // REGISTERWINDOW_H
