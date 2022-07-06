#include "database.h"
#include <QDebug>
#include <QSqlError>
#include <vector>
#include "zugangsdaten.data"

#define debug qDebug()<<__FILE__<<":"<<__LINE__

Database::Database()
{  debug<<"ctor DB()";
}

Database::Database(QString driver)
{
    if(QSqlDatabase::isDriverAvailable(driver))
    {

        // verbinden
        db = QSqlDatabase::addDatabase("QMYSQL");

        // Userdaten für den Zugang
        debug<<"Treiber ist "<<db.driverName();
        db.setHostName(server); // "localhost"
        db.setUserName(user);   // "root"
        db.setPassword(pw);     // ""
        if(db.open()) // Anmeldeversuch
        {

           debug<<"open sucessfull";
           connected= true;
        }
        else
        {
            // Fehler ausgeben
           QSqlError err = db.lastError();
            debug<<"open failed "<<err.databaseText();
        }

    }
    else
    {
        debug<<"Treiber "<<driver<<" ist nicht verfügbar";
        debug<<"Es sind nur "<<db.drivers()<<" vorhanden";

    }

}

QSqlQuery Database::query(QString cmd)
{

    return db.exec(cmd);
}

std::vector<QStringList> Database::results(QString cmd)
{
    std::vector<QStringList> matrix; // Datensätze mit Spalten
    QStringList list;
    QSqlQuery q = db.exec(cmd);
    debug<<q.lastError();
    // Überschriften der Spalten
    for(int i = 0; i < q.record().count();i++) // 1 record per Zeile
    list.append( q.record().fieldName(i));
    matrix.push_back(list);

    while (q.next())
    { // nächster Datensatz der Antwort
      list.clear();
        for(int i = 0; i < q.record().count();i++)
       { QString info = q.value(i).toString();
            debug<<"Result("<<i<<") : "<<info;
            list.append(info);
       }
        //debug<<list;
        //debug<<"Matrix "<<matrix;
        matrix.push_back(list);
    }

    debug<<"matrix übergibt "<<matrix.size()<<" Zeilen";
    return matrix;
}
