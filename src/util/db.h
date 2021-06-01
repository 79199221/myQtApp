#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql/QSqlDatabase>


class DB : public QObject
{
    Q_OBJECT
public:
    DB(QObject* parent = nullptr);

private:
    QSqlDatabase Connection;
};

#endif // DATABASE_H
