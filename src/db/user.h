#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QtSql/QSqlQuery>

class User : public QObject
{
    Q_OBJECT
public:
    int Id;
    QString Name;
    QString Password;
    User(QObject *parent = nullptr);
    ~User();
    void Insert(QString name);
    static User* Login(QString name, QString password);

signals:

};

#endif // USER_H
