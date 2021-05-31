
#ifndef MYAPP_STATUS_BAR_H
#define MYAPP_STATUS_BAR_H


#include <QtWidgets/QStatusBar>

class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    StatusBar(QWidget *parent = nullptr);
    ~StatusBar();

private:

};


#endif //MYAPP_STATUS_BAR_H
