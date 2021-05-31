#include "src/window/main/MainWindow.h"
#include <QApplication>
#include <QTranslator>
#include <src/window/login/LoginWindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTranslator *qtTranslator = new QTranslator;
    if(qtTranslator->load("src/i18n/zh_CN.qm")){
        app.installTranslator(qtTranslator);
    }
    MainWindow w;
    w.resize(500, 500);
//    w.show();
    LoginWindow login;
    login.setFixedSize(400, 400);
//    login.setWindowFlags(Qt::FramelessWindowHint);
    login.show();

    return app.exec();
}
