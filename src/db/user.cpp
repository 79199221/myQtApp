#include "user.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QVariant>

User::User(QObject *parent) : QObject(parent)
{
    auto query = new QSqlQuery;
    auto sql = QString("select count(*) from sqlite_master where type= 'table' and name = 'users';");
    if (query->exec(sql)) {
        query->next();
        if (query->value(0).toInt() == 0) {
            sql = QString(""\
                "CREATE TABLE `users` ( " \
                    "`id` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," \
                    "`name` TEXT NOT NULL DEFAULT ''"\
                    "`PASSWORD` TEXT NOT NULL DEFAULT ''"\
                ");"\
            "");
            query->exec(sql);
        }
    }

}

User::~User(){}

void User::Insert(QString name) {
    auto query = new QSqlQuery;
    auto sql = QString("INSERT INTO `users` (`name`) VALUES('%2')").
            arg(name);
    if (!query->exec(sql)){
        qDebug() << sql << query->lastError();
    }
}
User* User::Login(QString name, QString password) {
    auto user = new User;
    auto query = new QSqlQuery;
    auto sql = QString("SELECT * FROM `users` WHERE `name`=\"%0\" AND `password`=\"%1\"").
            arg(name).arg(password);
    if (query->exec(sql) && query->next()){
        user->Id = query->value("id").toInt();
        user->Name = query->value("name").toString();
    }
    return user;
}
