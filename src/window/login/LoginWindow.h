#ifndef MYAPP_LOGIN_WINDOW_H
#define MYAPP_LOGIN_WINDOW_H

#include <QMainWindow>

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
public slots:
    void LoginButtonClicked();
    void userFieldTextEdited(QString value);

private:
    QWidget* background();
    QWidget* main();
};

#endif //MYAPP_LOGIN_WINDOW_H
