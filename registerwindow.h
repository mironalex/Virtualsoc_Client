/**
  * A class for the register form window.
  */

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
    int socketDescriptor; /**<socket to the server */

private slots:
    /**
     * @brief on_cancelButton_clicked Closes the register form.
     */
    void on_cancelButton_clicked();
    /**
     * @brief on_registerButton_clicked send a register request to the server when the register button is clicked.
     */
    void on_registerButton_clicked();

private:
    Ui::registerWindow *ui;
};

#endif // REGISTERWINDOW_H
