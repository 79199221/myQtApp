#include "font_awesome.h"
#include <QFontDatabase>
#include <QFont>

QFont fontAwesome(){
    int fontId = QFontDatabase::addApplicationFont(":/font/awesome");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont iconFont = QFont(fontName);
    iconFont.setPixelSize(32);
    return iconFont;
}
