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
    void SubmitButton();

private:
    QWidget* main();
    QWidget* username();
    QWidget* password();
    QWidget* options();
    QWidget* submit();
};

#endif //MYAPP_LOGIN_WINDOW_H
