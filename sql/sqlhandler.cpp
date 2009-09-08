#include "sqlhandler.h"
#include <qsqlquery.h>

#include <QtGui>
#include <QtSql>

SQLHandler::SQLHandler()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "INdT-Schedule");
    db.setDatabaseName("contacts.db");

    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);

    }

    QSqlQuery query(db);
    query.exec("create table if not exists contacts ( "
               "name varchar(30), email varchar(35), birthday varchar(10), sex varchar(9), celphone varchar(13), fixedphone varchar(13))");
}

void SQLHandler::addContact(QString name, QString email, QString birth, QString sex, QString cel, QString fixed)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO contacts (name, email, birthday, sex, celphone, fixedphone)"
                  "VALUES (:name, :email, :birthday, :sex, :celphone, :fixedphone)");
    query.bindValue(":name", name);
    query.bindValue(":email", email);
    query.bindValue(":birthday", birth);
    query.bindValue(":sex", sex);
    query.bindValue(":celphone", cel);
    query.bindValue(":fixedphone", fixed);
    query.exec();
}

QString SQLHandler::findContactByName(QString nameToBeFound)
{
    QString name, contacts;

    QSqlQuery query(QString ("SELECT  name, email, birthday, sex, celphone, fixedphone FROM contacts") + QString(" ORDER BY email"), db);
    QSqlRecord buffer = query.record();
    int fieldCount = buffer.count();
    int fieldPosition = query.record().indexOf("name");
    qDebug() << "fieldPosition: " << fieldPosition;
    while (query.next()){
        if (query.value(fieldPosition).toString() == nameToBeFound){

            contacts.append("Nome: ");
            contacts.append(query.value(0).toString());
            contacts.append("\n");

            contacts.append("E-mail: ");
            contacts.append(query.value(1).toString());
            contacts.append("\n");

            contacts.append("Birthday: ");
            contacts.append(query.value(2).toString());
            contacts.append("\n");

            contacts.append("Sexo: ");
            contacts.append(query.value(3).toString());
            contacts.append("\n");

            contacts.append("Celular: ");
            contacts.append(query.value(4).toString());
            contacts.append("\n");

            contacts.append("Fixo: ");
            contacts.append(query.value(5).toString());
            contacts.append("\n\n");
        }
    }

    return contacts;
}

QString SQLHandler::findContactByPhone(QString phoneToBeFound)
{
    QString name, contacts;

    QSqlQuery query(QString ("SELECT  name, email, birthday, sex, celphone, fixedphone FROM contacts ORDER BY name"), db);
    QSqlRecord buffer = query.record();
    int fieldCount = buffer.count();
    int fieldPosition1 = query.record().indexOf("celphone");
    int fieldPosition2 = query.record().indexOf("fixedphone");
    qDebug() << "fieldPosition1: " << fieldPosition1;
    qDebug() << "fieldPosition2: " << fieldPosition2;
    while (query.next()){
        if ((query.value(fieldPosition1).toString() == phoneToBeFound) || (query.value(fieldPosition2).toString() == phoneToBeFound)){

            contacts.append("Nome: ");
            contacts.append(query.value(0).toString());
            contacts.append("\n");

            contacts.append("E-mail: ");
            contacts.append(query.value(1).toString());
            contacts.append("\n");

            contacts.append("Birthday: ");
            contacts.append(query.value(2).toString());
            contacts.append("\n");

            contacts.append("Sexo: ");
            contacts.append(query.value(3).toString());
            contacts.append("\n");

            contacts.append("Celular: ");
            contacts.append(query.value(4).toString());
            contacts.append("\n");

            contacts.append("Fixo: ");
            contacts.append(query.value(5).toString());
            contacts.append("\n\n");
        }
    }

    return contacts;
}

void SQLHandler::removeContactsByName(QString nameToBeFound)
{
    QSqlQuery query(QString ("DELETE FROM contacts WHERE name = :name") , db);
    query.bindValue(":name", nameToBeFound);
    if (!query.exec())
        qDebug() << query.lastError();

}

SQLHandler::~SQLHandler()
{
    db.close();
}

