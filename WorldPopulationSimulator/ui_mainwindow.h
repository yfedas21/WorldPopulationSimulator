/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QWidget *quickSettingsTab;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *textbox_runtime;
    QLabel *label_3;
    QCheckBox *checkBox;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QCheckBox *checkBox_2;
    QLabel *label_6;
    QDateEdit *dateEdit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_2;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QGraphicsView *worldMapView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QMenu *menuWorld_Population_Simulator;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1600, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1080, 720));
        MainWindow->setMaximumSize(QSize(1600, 1080));
        MainWindow->setSizeIncrement(QSize(5, 5));
        MainWindow->setBaseSize(QSize(1600, 1080));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMaximumSize(QSize(1920, 1080));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Adequate"));
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setBaseSize(QSize(0, 720));
        QFont font1;
        font1.setFamily(QStringLiteral("Simplex_IV25"));
        font1.setPointSize(11);
        tabWidget->setFont(font1);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabShape(QTabWidget::Triangular);
        quickSettingsTab = new QWidget();
        quickSettingsTab->setObjectName(QStringLiteral("quickSettingsTab"));
        verticalLayout_2 = new QVBoxLayout(quickSettingsTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(20);
        label = new QLabel(quickSettingsTab);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setFamily(QStringLiteral("Simplex_IV50"));
        font2.setPointSize(12);
        label->setFont(font2);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textbox_runtime = new QLineEdit(quickSettingsTab);
        textbox_runtime->setObjectName(QStringLiteral("textbox_runtime"));
        sizePolicy3.setHeightForWidth(textbox_runtime->sizePolicy().hasHeightForWidth());
        textbox_runtime->setSizePolicy(sizePolicy3);
        textbox_runtime->setMaximumSize(QSize(16777215, 40));
        textbox_runtime->setMaxLength(32770);
        textbox_runtime->setClearButtonEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, textbox_runtime);

        label_3 = new QLabel(quickSettingsTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        checkBox = new QCheckBox(quickSettingsTab);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy5);
        checkBox->setIconSize(QSize(12, 12));

        formLayout->setWidget(1, QFormLayout::FieldRole, checkBox);

        label_4 = new QLabel(quickSettingsTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox = new QComboBox(quickSettingsTab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox);

        label_5 = new QLabel(quickSettingsTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        checkBox_2 = new QCheckBox(quickSettingsTab);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        sizePolicy5.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy5);

        formLayout->setWidget(2, QFormLayout::FieldRole, checkBox_2);

        label_6 = new QLabel(quickSettingsTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        dateEdit = new QDateEdit(quickSettingsTab);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2018, 4, 29), QTime(0, 0, 0)));

        formLayout->setWidget(4, QFormLayout::FieldRole, dateEdit);


        verticalLayout_6->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout_5);

        tabWidget->addTab(quickSettingsTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));

        verticalLayout_3->addLayout(formLayout_2);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        worldMapView = new QGraphicsView(tab);
        worldMapView->setObjectName(QStringLiteral("worldMapView"));
        worldMapView->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_4->addWidget(worldMapView);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(1);
        sizePolicy6.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy6);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(1);
        sizePolicy7.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy7);
        pushButton_2->setMinimumSize(QSize(150, 50));
        QFont font3;
        font3.setFamily(QStringLiteral("Simplex_IV50"));
        font3.setPointSize(10);
        pushButton_2->setFont(font3);

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy7.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy7);
        pushButton->setMinimumSize(QSize(150, 50));
        pushButton->setBaseSize(QSize(150, 50));
        pushButton->setFont(font3);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 17));
        menuWorld_Population_Simulator = new QMenu(menuBar);
        menuWorld_Population_Simulator->setObjectName(QStringLiteral("menuWorld_Population_Simulator"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuWorld_Population_Simulator->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuWorld_Population_Simulator->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "World Population Simulator", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Welcome to the World Population Simulator!", nullptr));
        label->setText(QApplication::translate("MainWindow", "Simulation Runtime (Days):", nullptr));
        textbox_runtime->setInputMask(QString());
        textbox_runtime->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Enable Disasters?", nullptr));
        checkBox->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Focus On One Continent?", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "No", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Africa", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "Asia", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "Australia", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "Europe", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "North America", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "South America", nullptr));

        comboBox->setCurrentText(QApplication::translate("MainWindow", "No", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Enable Migration?", nullptr));
        checkBox_2->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Start Date:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(quickSettingsTab), QApplication::translate("MainWindow", "Quick Start", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Advaced Settings", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Simulation", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Begin Simulation", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Reset Values", nullptr));
        menuWorld_Population_Simulator->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
