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
#include <QtWidgets/QFormLayout>
#include "LoginWindow.h"
#include "src/window/main/MainWindow.h"
#include "src/db/user.h"

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

QWidget *LoginWindow::main() {
    auto widget = new QWidget;
    widget->resize(300, 200);
    widget->setStyleSheet("background:rgba(255, 255, 255, 0.5);");
    auto layout = new QFormLayout;

    // 用户名
    auto userLabel = new QLabel;
    userLabel->setText("用户名：");
    auto userField = new QLineEdit;
    userField->setObjectName("userLineEdit");
    userField->setPlaceholderText("请输入用户名");
    layout->addRow(userLabel, userField);

    // 密码
    auto passwordLabel = new QLabel;
    passwordLabel->setText(tr("Password"));
    auto passwordField = new QLineEdit;
    userField->setObjectName("passwordLineEdit");
    passwordField->setEchoMode(QLineEdit::Password);
    passwordField->setPlaceholderText(tr("Please Input Password"));
    layout->addRow(passwordLabel, passwordField);

    // 选项
    auto options = new QWidget;
    auto optionLayout = new QHBoxLayout;
    auto autoLogin = new QCheckBox;
    autoLogin->setText(tr("Auto Login"));
    autoLogin->setObjectName("authLoginCheckBox");
    optionLayout->addWidget(autoLogin);
    auto rememberPassword = new QCheckBox;
    rememberPassword->setText(tr("Remember Me"));
    optionLayout->addWidget(rememberPassword);
    options->setLayout(optionLayout);
    layout->addRow(options);

    // 登录按钮
    auto loginPushButton = new QPushButton;
    loginPushButton->setText("登录");
    loginPushButton->setObjectName("loginPushButton");
    layout->addRow(loginPushButton);

    widget->setLayout(layout);

    connect(loginPushButton, SIGNAL(clicked()), this, SLOT(LoginButtonClicked()));
    connect(userField, SIGNAL(textEdited(QString)), this, SLOT(userFieldTextEdited(QString)));
    return widget;
}

void LoginWindow::LoginButtonClicked() {
    auto userEditLine = findChild<QLineEdit*>("userEditLine");
    auto passwordEditLine = findChild<QLineEdit*>("passwordEditLine");
    auto user = User::Login(userEditLine->text(), passwordEditLine->text());
    qDebug() << user->Id << user->Name <<endl;
    if (user->Id > 0) {
        close();
        (new MainWindow)->show();
    }
//    Database DB = new Database("myApp");
}

QWidget *LoginWindow::background() {
    // 第一层 背景图片
    auto background = new QLabel;
    background->setAlignment(Qt::AlignTop);

    auto movie = new QMovie(":/image/background/login.gif");
    background->setMovie(movie);
    movie->start();
    // 第二层 半透明
    auto bgOpacity = new QLabel;
    bgOpacity->move(0, 0);
    bgOpacity->resize(background->size());
    bgOpacity->setGeometry(background->geometry());
    bgOpacity->setStyleSheet("background-color:rgba(255,255,255, 0.3);");
    bgOpacity->setParent(background);
    return background;
}

void LoginWindow::userFieldTextEdited(QString value) {
    qDebug() << value <<endl;
}
