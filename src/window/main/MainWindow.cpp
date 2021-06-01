#include "MainWindow.h"
#include <QtWidgets/QPushButton>
#include <QDebug>
#include <QtWidgets/QMenuBar>
#include <src/common/menu_bar.h>
#include <src/common/status_bar.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->setMenuBar(new MenuBar);
    this->setStatusBar(new StatusBar);
    this->setWindowTitle("ha ha");

    auto* button = new QPushButton;
    button->setText("world");
    button->move(10, 40);
    button->resize(100, 50);
    button->setParent(this);
}

MainWindow::~MainWindow()
{
}

