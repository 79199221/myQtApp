//
// Created by Administrator on 2021/5/31.
//

#ifndef MYAPP_MENU_BAR_H
#define MYAPP_MENU_BAR_H


#include <QtWidgets/QMenuBar>

class MenuBar : public QMenuBar
{
    Q_OBJECT
public:
    MenuBar(QWidget *parent = nullptr);
    ~MenuBar();

private:
    QMenu* fileMenu();
    QMenu* editMenu();
    QMenu* helpMenu();

};


#endif //MYAPP_MENU_BAR_H
