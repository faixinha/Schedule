#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>

class QDateEdit;
class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QRadioButton;

class Register : public QDialog
{
    Q_OBJECT

public:
    Register(QWidget *parent);

private:
    QLabel *labelName;
    QLabel *labelEmail;
    QLabel *labelBirthday;
    QLabel *labelSexo;
    QLabel *labelMobilePhone;
    QLabel *labelFixedPhone;
    QLineEdit *lineEditName;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditMobilePhone;
    QLineEdit *lineEditFixedPhone;
    QPushButton *buttonAdd;
    QPushButton *buttonCancel;
    QPushButton *buttonClean;
    QDialogButtonBox *box;
    QRadioButton *maleButton;
    QRadioButton *femaleButton;
    QDateEdit *birthdayEdit;
    QWidget *extension;

public slots:
    void addClicked();
    void cancelClicked();
    void clearClicked();

};

#endif // REGISTER_H

