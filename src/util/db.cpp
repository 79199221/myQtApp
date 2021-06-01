#include "db.h"
#include <QtCore/QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>

DB::DB(QObject* parent) : QObject(parent)
{
    Connection = QSqlDatabase::addDatabase("QSQLITE");
    Connection.setDatabaseName(QCoreApplication::applicationDirPath() + "/database.db");
    if (!Connection.open()) {
        QSqlError err = Connection.lastError();
        qDebug() << Connection.lastError().text();
    }
}
