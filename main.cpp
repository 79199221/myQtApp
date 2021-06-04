#include "src/window/main/MainWindow.h"
#include <QApplication>
#include <QTranslator>
#include <QDebug>
#include "src/window/login/LoginWindow.h"
#include <QtCore/QFile>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include "src/util/font_awesome.h"

void sqlite();
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    sqlite();
    QTranslator *qtTranslator = new QTranslator;

    if(qtTranslator->load(QString(":/i18n/%0.qm").arg("zh_CN"))){
        app.installTranslator(qtTranslator);
    }
//    (new MainWindow)->show();
//    (new LoginWindow)->show();
    (new LoginWindow)->show();

    return app.exec();
}

void sqlite()
{
    auto connection = QSqlDatabase::addDatabase("QSQLITE");
    connection.setDatabaseName(QCoreApplication::applicationDirPath() + "/database.db");
    if (!connection.open()) {
        QSqlError err = connection.lastError();
        qDebug() << connection.lastError().text();
    }
}
