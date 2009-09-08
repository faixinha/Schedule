#ifndef SQLHANDLER_H
#define SQLHANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

class SQLHandler
{

public:
    SQLHandler();
    ~SQLHandler();
    QSqlDatabase db;
    void addContact(QString nomeDigitado, QString eMail, QString birthday, QString sexo, QString telefoneCelular, QString telefoneFixo);
    QString findContactByName(QString nameToBeFound);
    QString findContactByPhone(QString phoneToBeFound);
    void removeContactsByName(QString nameToBeFound);

};

#endif // SQLHANDLER_H
