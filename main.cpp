#include "src/window/main/MainWindow.h"
#include <QApplication>
#include <QTranslator>
#include <QDebug>
#include <src/window/login/LoginWindow.h>
#include <QtCore/QFile>
#include <QtSql/QSqlDatabase>
#include <src/util/db.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator *qtTranslator = new QTranslator;
    DB* Db = new DB;

    if(qtTranslator->load(":/i18n/zh_CN.qm")){
        app.installTranslator(qtTranslator);
    }
    MainWindow w;
    w.resize(500, 500);
//    w.show();
    (new LoginWindow)->show();

    return app.exec();
}
