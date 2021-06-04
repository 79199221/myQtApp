#ifndef MYAPP_MAIN_WINDOW_H
#define MYAPP_MAIN_WINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* layout();
    QWidget* iconSection();
    QWidget* menuSection();
    QWidget* contentSection();
};


#endif //MYAPP_MAIN_WINDOW_H
