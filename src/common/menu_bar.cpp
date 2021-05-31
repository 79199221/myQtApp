#include "menu_bar.h"


MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent)
{
    this->addMenu(this->fileMenu());
    this->addMenu(this->editMenu());
    this->addMenu(this->helpMenu());
}

MenuBar::~MenuBar() {}

QMenu *MenuBar::fileMenu() {
    QMenu* menu = new QMenu;
    menu->setTitle("打开(&F)");
    menu->addAction("打开");
    menu->addAction("保存");
    menu->addAction("退出");
    return menu;
}

QMenu *MenuBar::editMenu() {
    QMenu* menu = new QMenu;
    menu->setTitle("编辑(&E)");
    menu->addAction("打开");
    menu->addAction("保存");
    menu->addAction("退出");
    return menu;
}

QMenu *MenuBar::helpMenu() {
    QMenu* menu = new QMenu;
    menu->setTitle("帮助(&H)");
    menu->addAction("关于");
    return menu;
}
