#include(./orm/QxOrm.pri)

#INCLUDEPATH += F:\qt\myApp\orm\include
#LIBS += -LF:\qt\myApp\orm\lib

#CONFIG(debug, debug|release) {
#TARGET = Demo
#LIBS += -l"QxOrmd"
#} else {
#TARGET = Demo
#LIBS += -l"QxOrm"
#})

#DEFINES += _BUILDING_QX_DEMO
#QT -= gui

#!contains(DEFINES, _QX_NO_PRECOMPILED_HEADER) {
#PRECOMPILED_HEADER = ./orm/precompiled.h
#} # !contains(DEFINES, _QX_NO_PRECOMPILED_HEADER)

CONFIG += c++11
CONFIG -= app_bundle console

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/common/menu_bar.cpp \
    src/common/status_bar.cpp \
    src/db/user.cpp \
    src/util/font_awesome.cpp \
    src/window/login/LoginWindow.cpp \
    src/window/main/MainWindow.cpp

HEADERS += \
    src/common/menu_bar.h \
    src/common/status_bar.h \
    src/db/user.h \
    src/util/font_awesome.h \
    src/window/login/LoginWindow.h \
    src/window/main/MainWindow.h

FORMS +=

TRANSLATIONS += \
    src/i18n/zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Test.qml \
    src/i18n/zh_CN.qm \
    src/i18n/zh_CN.ts

QT       += sql

RESOURCES += \
    src/resource.qrc
