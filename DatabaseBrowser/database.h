/*DB class erbt von QSqlDatabase
// erfordert QT += sql, sonst Linker error
// erfordert QMYSQL driver bundled with libmysql and OpenSSL
// download von https://github.com/thecodemonkey86/qt_mysql_driver/releases?page=2
// expand and place files according to directives at end of this file

    put qsqlmysql.dll (if release build) / qsqlmysqld.dll (if debug build, but note that when using MinGW 8.1.0 the debug build is named qsqlmysql.dll as well) in application subdirectory "sqldrivers"
    put libmysql.dll (the MySQL library itself) and the OpenSSL v1.1 libraries, libcrypto-1_1 and libssl-1_1, in your application dir
*/



#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QSqlQuery>
#include <vector>




class Database // : public QSqlDatabase
{
public:
    static QSqlDatabase db;
    Database();
    Database(QString driver); // mit Angabe des gewünschten DBMS oracle, maria, mysql , sqlserver
    static bool connected;
    QSqlQuery query(QString cmd);
    static std::vector<QStringList> results(QString cmd);


};

#endif // DATABASE_H
