#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtGui/QTextLine>
#include <QtWidgets/QLineEdit>
#include <QtCore/QTranslator>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QMovie>
#include <QDebug>
#include "LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QMainWindow(parent) {
    this->setFixedSize(480, 270);
//    this->setWindowFlags(Qt::FramelessWindowHint);
    QWidget* background = this->background();
    background->resize(this->size());
    background->setGeometry(this->geometry());
    background->setStyleSheet("border:1px solid yellow;");
    background->setParent(this);
    background->move(0, 0);

    QWidget* main = this->main();
    main->setParent(background);
    main->move((this->width() - main->width())/2, (this->height() - main->height())/3 * 2);
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
    label->setText(tr("Password"));

    QLineEdit* password = new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    password->setPlaceholderText(tr("Please Input Password"));

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
    autoLogin->setText(tr("Auto Login"));

    QCheckBox* rememberPassword = new QCheckBox;
    rememberPassword->setText(tr("Remember Me"));

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
    widget->resize(300, 200);
    widget->setStyleSheet("background:rgba(255, 255, 255, 0.5);");
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

QWidget *LoginWindow::background() {
    // 第一层 背景图片
    QLabel* background = new QLabel;
    background->setAlignment(Qt::AlignTop);

    QMovie* movie = new QMovie(":/image/background/login.gif");
    background->setMovie(movie);
    movie->start();
    // 第二层 半透明
    QLabel* bgOpacity = new QLabel;
    bgOpacity->move(0, 0);
    bgOpacity->resize(background->size());
    bgOpacity->setGeometry(background->geometry());
    bgOpacity->setStyleSheet("background-color:rgba(255,255,255, 0.3);");
    bgOpacity->setParent(background);
    return background;
}
