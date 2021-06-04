#include "MainWindow.h"
#include <QtWidgets/QPushButton>
#include <QDebug>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTableView>
#include <QtGui/QStandardItemModel>
#include "src/common/menu_bar.h"
#include "src/common/status_bar.h"
#include "src/util/font_awesome.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->setMenuBar(new MenuBar);
    this->setStatusBar(new StatusBar);
    this->setWindowTitle("ha ha");
    this->setCentralWidget(this->layout());
    this->resize(600, 400);
}

MainWindow::~MainWindow()
{
}

QWidget *MainWindow::layout()
{
    QWidget* widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(this->iconSection());
    layout->addWidget(this->menuSection());
    layout->addWidget(this->contentSection());
    widget->setLayout(layout);

    QPushButton* loginButton = (new QWidget)->findChild<QPushButton*>("loginButton");
//    loginButton->setText("loginButton haha");
    return widget;
}

QWidget *MainWindow::iconSection()
{
    QWidget* widget = new QWidget;
    widget->setFixedWidth(48);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignTop);

    QPushButton* dashboardButton = new QPushButton;
    dashboardButton->setText(QChar(0xf0e4));
    dashboardButton->setFont(FONT_AWESOME);

    QPushButton* homeButton = new QPushButton;
    homeButton->setText(QChar(0xf015));
    homeButton->setFont(FONT_AWESOME);

    QPushButton* userButton = new QPushButton;
    userButton->setText(QChar(0xf007));
    userButton->setFont(FONT_AWESOME);

    QPushButton* userButton2 = new QPushButton;
    userButton2->setText(QChar(0xf050));
    userButton2->setFont(FONT_AWESOME);

    layout->addWidget(dashboardButton);
    layout->addWidget(homeButton);
    layout->addWidget(userButton);
    layout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget(userButton2);
    widget->setLayout(layout);
    return widget;
}

QWidget *MainWindow::menuSection()
{
    QWidget* widget = new QWidget;
    widget->setFixedWidth(128);
    widget->setStyleSheet("background:#69B;margin:0;");

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignTop);

    QPushButton* homeButton = new QPushButton;
    homeButton->setText("Home");
    QPushButton* userButton = new QPushButton;
    userButton->setText("User");
    layout->addWidget(homeButton);
    layout->addWidget(userButton);
    widget->setLayout(layout);
    return widget;
}

QWidget *MainWindow::contentSection()
{
    QWidget* widget = new QWidget;
    QTableView* tableView = new QTableView;
    QStandardItemModel* m_model = new QStandardItemModel(10, 5, this);                          //设置数据模型，一开始设置为默认的2行6列表的一个表
    QItemSelectionModel* m_selectModel = new QItemSelectionModel(m_model, this);                //设置选择模型

    tableView->setModel(m_model);                                      //设置数据模型
    tableView->setSelectionModel(m_selectModel);                       //设置选择模型
    tableView->setSelectionMode(QAbstractItemView::ExtendedSelection); //设置选择模式
    tableView->setSelectionBehavior(QAbstractItemView::SelectItems);   //设置选择行为
    tableView->setParent(widget);
    m_model->setItem(1, new QStandardItem(QString("a")));
    m_model->setItem(1, new QStandardItem(QString("b")));


    return widget;
}

