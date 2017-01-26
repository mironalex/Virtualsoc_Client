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
    int socketDescriptor;
    explicit guestSession(QWidget *parent = 0);
    void showEvent(QShowEvent * event);
    ~guestSession();

private:
    Ui::guestSession *ui;
};

#endif // GUESTSESSION_H
