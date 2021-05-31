#include "status_bar.h"


StatusBar::StatusBar(QWidget *parent) : QStatusBar(parent)
{
    this->showMessage("hello world");
    this->setStyleSheet("border:1px solid #abc;");
}

StatusBar::~StatusBar() {}
