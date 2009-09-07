#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>

class Schedule : public QDialog
{
    Q_OBJECT

public:
    Schedule();

public slots:
    void registerForm();
    void searchContact();
    void sairClicked();
};

#endif // SCHEDULE_H

