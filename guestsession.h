/**
  * A simple class for the guest session interface.
  */
#ifndef GUESTSESSION_H
#define GUESTSESSION_H

#include <QDialog>

namespace Ui {
class guestSession;
}

class guestSession : public QDialog
{
    Q_OBJECT

public:
    int socketDescriptor; /**< socket to the server */
    explicit guestSession(QWidget *parent = 0);
    /**
     * @brief showEvent a public function used to initialize the lists of the interface
     * @param event a variable that describes events such as if the windows was drawn for the first time
     */
    void showEvent(QShowEvent * event);
    ~guestSession();

private:
    Ui::guestSession *ui;
};

#endif // GUESTSESSION_H
