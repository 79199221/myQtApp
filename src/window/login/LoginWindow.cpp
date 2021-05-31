#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtGui/QTextLine>
#include <QtWidgets/QLineEdit>
#include <QtCore/QTranslator>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QDebug>
#include "LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget* main = this->main();
    main->setStyleSheet("border:1px solid gray;");
    main->setGeometry(50, 50, 280, 200);
    main->setParent(this);
}

LoginWindow::~LoginWindow() {

}

QWidget *LoginWindow::username() {
    QWidget* widget = new QWidget;
//    widget->setFixedHeight(80);
    widget->setStyleSheet("border:1px solid #abc");
    QHBoxLayout* layout = new QHBoxLayout;

    QLabel* label = new QLabel;
    label->setText("用户名：");

    QLineEdit* text = new QLineEdit;
    text->setPlaceholderText("请输入用户名");

    layout->addWidget(label);
    layout->addWidget(text);
    widget->setLayout(layout);

    return widget;
}

QWidget *LoginWindow::password() {
    QWidget* widget = new QWidget;
//    widget->setFixedHeight(80);
    widget->setStyleSheet("border:1px solid #abc");
    QHBoxLayout* layout = new QHBoxLayout;

    QLabel* label = new QLabel;
    label->setText(tr("password"));

    QLineEdit* password = new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    password->setPlaceholderText(tr("please input password"));

    layout->addWidget(label);
    layout->addWidget(password);
    widget->setLayout(layout);

    return widget;
}

QWidget *LoginWindow::options() {
    QWidget* widget = new QWidget;
    widget->setStyleSheet("border:1px solid #abc");
    QHBoxLayout* layout = new QHBoxLayout;

    QCheckBox* autoLogin = new QCheckBox;
    autoLogin->setText("自动登录");

    QCheckBox* rememberPassword = new QCheckBox;
    rememberPassword->setText("记住密码");

    layout->addWidget(autoLogin);
    layout->addWidget(rememberPassword);
    widget->setLayout(layout);

    return widget;
}

QWidget *LoginWindow::submit() {
    QWidget* widget = new QWidget;
    widget->setStyleSheet("border:1px solid #abc");
    QHBoxLayout* layout = new QHBoxLayout;

    QPushButton* submit = new QPushButton;
    submit->setText("登录");
    connect(submit, SIGNAL(clicked()), this, SLOT(SubmitButton()));

    layout->addWidget(submit);
    widget->setLayout(layout);

    return widget;
}

QWidget *LoginWindow::main() {
    QWidget* widget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;

    layout->addSpacerItem(new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(this->username());
    layout->addSpacerItem(new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(this->password());
    layout->addSpacerItem(new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(this->options());
    layout->addSpacerItem(new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(this->submit());
    layout->addSpacerItem(new QSpacerItem(1, 10, QSizePolicy::Minimum, QSizePolicy::Expanding));

    widget->setLayout(layout);

    return widget;
}

void LoginWindow::SubmitButton() {
    qDebug() << "submit....." <<endl;
//    Database DB = new Database("myApp");
}
