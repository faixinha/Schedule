#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

#include "search.h"

class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;

class Search : public QDialog
{
    Q_OBJECT

public:
    Search(QWidget *parent);

private:
    QLabel *labelName;
    QLabel *labelPhone;
    QLabel *labelTeste;
    QLineEdit *findEditName;
    QLineEdit *findEditPhone;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;
    QPushButton *findContactButton;
    QPushButton *removeButton;
    QPushButton *exitButton;
    QWidget *extension;
};

#endif // SEARCH_H

