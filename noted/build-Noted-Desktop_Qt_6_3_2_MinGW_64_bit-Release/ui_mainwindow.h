/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *horLine;
    QFrame *vertLine;
    QListWidget *noteList;
    QToolButton *toolButton;
    QLabel *listName;
    QPushButton *addNote;
    QPushButton *addType;
    QPushButton *complTasks;
    QPushButton *planT;
    QPushButton *impT;
    QPushButton *dayT;
    QLabel *userName;
    QPushButton *editButton;
    QPushButton *returnButton;
    QTextBrowser *textBrowser;
    QLineEdit *headerLine;
    QLabel *textText;
    QLabel *headerText;
    QDateTimeEdit *datePlanned;
    QLabel *planLabel;
    QCheckBox *boolPlanned;
    QCheckBox *boolCompleted;
    QCheckBox *boolImportant;
    QPushButton *applyButton;
    QPushButton *addTypeApply;
    QPushButton *addNoteApply;
    QWidget *gridLayoutWidget;
    QGridLayout *buttonGroup;
    QPushButton *btnList4;
    QWidget *widget;
    QPushButton *btnList1;
    QPushButton *btnList5;
    QPushButton *btnList2;
    QPushButton *btnList3;
    QPushButton *btnList6;
    QLabel *labelPhoto;
    QPushButton *loadPhotoButton;
    QPushButton *deleteType;
    QWidget *screenWidget;
    QGroupBox *authGroupBox;
    QPushButton *loginButton;
    QPushButton *registrationButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *authLoginLabel;
    QLineEdit *authLoginLineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *authPassLabel;
    QLineEdit *authPassLineEdit;
    QLabel *authLabel;
    QCheckBox *authShowPass;
    QLabel *authWarningLabel;
    QGroupBox *regGroupBox;
    QLabel *authLabel_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *regLoginLabel;
    QLineEdit *regLoginLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *regPasslabel;
    QLineEdit *regPassLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *regRepeatpassLabel;
    QLineEdit *regRepeatpassLineEdit;
    QPushButton *registerButton;
    QPushButton *authorizationButton;
    QCheckBox *regShowPass;
    QLabel *regWarningLabel;
    QPushButton *cancelNote;
    QPushButton *removeNote;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(922, 599);
        MainWindow->setMinimumSize(QSize(922, 599));
        MainWindow->setMaximumSize(QSize(922, 599));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-Noted-Desktop_Qt_6_3_2_MinGW_64_bit-Debug/2109008.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horLine = new QFrame(centralWidget);
        horLine->setObjectName(QString::fromUtf8("horLine"));
        horLine->setGeometry(QRect(0, 270, 241, 16));
        horLine->setFrameShadow(QFrame::Plain);
        horLine->setLineWidth(2);
        horLine->setMidLineWidth(1);
        horLine->setFrameShape(QFrame::HLine);
        vertLine = new QFrame(centralWidget);
        vertLine->setObjectName(QString::fromUtf8("vertLine"));
        vertLine->setGeometry(QRect(230, -10, 20, 611));
        vertLine->setFrameShadow(QFrame::Plain);
        vertLine->setLineWidth(2);
        vertLine->setMidLineWidth(2);
        vertLine->setFrameShape(QFrame::VLine);
        noteList = new QListWidget(centralWidget);
        noteList->setObjectName(QString::fromUtf8("noteList"));
        noteList->setGeometry(QRect(270, 60, 631, 481));
        QFont font;
        font.setPointSize(12);
        noteList->setFont(font);
        noteList->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        noteList->setFrameShape(QFrame::NoFrame);
        noteList->setFrameShadow(QFrame::Raised);
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(860, 24, 41, 31));
        toolButton->setFont(font);
        listName = new QLabel(centralWidget);
        listName->setObjectName(QString::fromUtf8("listName"));
        listName->setGeometry(QRect(270, 24, 631, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setUnderline(false);
        listName->setFont(font1);
        listName->setLayoutDirection(Qt::LeftToRight);
        listName->setAlignment(Qt::AlignCenter);
        addNote = new QPushButton(centralWidget);
        addNote->setObjectName(QString::fromUtf8("addNote"));
        addNote->setGeometry(QRect(270, 560, 311, 31));
        addNote->setFont(font);
        addType = new QPushButton(centralWidget);
        addType->setObjectName(QString::fromUtf8("addType"));
        addType->setGeometry(QRect(18, 560, 101, 31));
        addType->setFont(font);
        complTasks = new QPushButton(centralWidget);
        complTasks->setObjectName(QString::fromUtf8("complTasks"));
        complTasks->setGeometry(QRect(20, 232, 201, 31));
        complTasks->setFont(font);
        planT = new QPushButton(centralWidget);
        planT->setObjectName(QString::fromUtf8("planT"));
        planT->setGeometry(QRect(20, 190, 201, 31));
        planT->setFont(font);
        impT = new QPushButton(centralWidget);
        impT->setObjectName(QString::fromUtf8("impT"));
        impT->setGeometry(QRect(20, 150, 201, 31));
        impT->setFont(font);
        dayT = new QPushButton(centralWidget);
        dayT->setObjectName(QString::fromUtf8("dayT"));
        dayT->setGeometry(QRect(20, 112, 201, 31));
        dayT->setFont(font);
        userName = new QLabel(centralWidget);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setGeometry(QRect(20, 70, 201, 31));
        QFont font2;
        font2.setPointSize(10);
        userName->setFont(font2);
        editButton = new QPushButton(centralWidget);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(270, 560, 271, 31));
        editButton->setFont(font);
        returnButton = new QPushButton(centralWidget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setGeometry(QRect(630, 560, 271, 31));
        returnButton->setFont(font);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(270, 270, 631, 281));
        textBrowser->setFont(font);
        headerLine = new QLineEdit(centralWidget);
        headerLine->setObjectName(QString::fromUtf8("headerLine"));
        headerLine->setGeometry(QRect(270, 210, 631, 31));
        headerLine->setFont(font);
        textText = new QLabel(centralWidget);
        textText->setObjectName(QString::fromUtf8("textText"));
        textText->setGeometry(QRect(570, 240, 31, 31));
        textText->setFont(font);
        headerText = new QLabel(centralWidget);
        headerText->setObjectName(QString::fromUtf8("headerText"));
        headerText->setGeometry(QRect(560, 180, 61, 31));
        headerText->setFont(font);
        datePlanned = new QDateTimeEdit(centralWidget);
        datePlanned->setObjectName(QString::fromUtf8("datePlanned"));
        datePlanned->setGeometry(QRect(550, 120, 181, 31));
        datePlanned->setFont(font);
        datePlanned->setDateTime(QDateTime(QDate(2022, 12, 28), QTime(0, 0, 0)));
        datePlanned->setMinimumDateTime(QDateTime(QDate(2022, 12, 28), QTime(0, 0, 0)));
        datePlanned->setCalendarPopup(true);
        datePlanned->setTimeSpec(Qt::LocalTime);
        planLabel = new QLabel(centralWidget);
        planLabel->setObjectName(QString::fromUtf8("planLabel"));
        planLabel->setGeometry(QRect(550, 80, 101, 31));
        planLabel->setFont(font);
        boolPlanned = new QCheckBox(centralWidget);
        boolPlanned->setObjectName(QString::fromUtf8("boolPlanned"));
        boolPlanned->setGeometry(QRect(280, 80, 101, 17));
        boolPlanned->setFont(font);
        boolCompleted = new QCheckBox(centralWidget);
        boolCompleted->setObjectName(QString::fromUtf8("boolCompleted"));
        boolCompleted->setGeometry(QRect(280, 100, 101, 17));
        boolCompleted->setFont(font);
        boolImportant = new QCheckBox(centralWidget);
        boolImportant->setObjectName(QString::fromUtf8("boolImportant"));
        boolImportant->setGeometry(QRect(280, 120, 101, 17));
        boolImportant->setFont(font);
        applyButton = new QPushButton(centralWidget);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setGeometry(QRect(270, 560, 271, 31));
        applyButton->setFont(font);
        addTypeApply = new QPushButton(centralWidget);
        addTypeApply->setObjectName(QString::fromUtf8("addTypeApply"));
        addTypeApply->setGeometry(QRect(270, 560, 631, 31));
        addTypeApply->setFont(font);
        addNoteApply = new QPushButton(centralWidget);
        addNoteApply->setObjectName(QString::fromUtf8("addNoteApply"));
        addNoteApply->setGeometry(QRect(270, 560, 311, 31));
        addNoteApply->setFont(font);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 300, 203, 251));
        buttonGroup = new QGridLayout(gridLayoutWidget);
        buttonGroup->setSpacing(6);
        buttonGroup->setContentsMargins(11, 11, 11, 11);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->setContentsMargins(0, 0, 0, 0);
        btnList4 = new QPushButton(gridLayoutWidget);
        btnList4->setObjectName(QString::fromUtf8("btnList4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(201);
        sizePolicy.setVerticalStretch(31);
        sizePolicy.setHeightForWidth(btnList4->sizePolicy().hasHeightForWidth());
        btnList4->setSizePolicy(sizePolicy);
        btnList4->setMinimumSize(QSize(201, 31));
        btnList4->setMaximumSize(QSize(201, 31));
        btnList4->setFont(font);

        buttonGroup->addWidget(btnList4, 3, 0, 1, 1);

        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        buttonGroup->addWidget(widget, 6, 0, 1, 1);

        btnList1 = new QPushButton(gridLayoutWidget);
        btnList1->setObjectName(QString::fromUtf8("btnList1"));
        sizePolicy.setHeightForWidth(btnList1->sizePolicy().hasHeightForWidth());
        btnList1->setSizePolicy(sizePolicy);
        btnList1->setMinimumSize(QSize(201, 31));
        btnList1->setMaximumSize(QSize(201, 31));
        btnList1->setFont(font);

        buttonGroup->addWidget(btnList1, 0, 0, 1, 1);

        btnList5 = new QPushButton(gridLayoutWidget);
        btnList5->setObjectName(QString::fromUtf8("btnList5"));
        sizePolicy.setHeightForWidth(btnList5->sizePolicy().hasHeightForWidth());
        btnList5->setSizePolicy(sizePolicy);
        btnList5->setMinimumSize(QSize(201, 31));
        btnList5->setMaximumSize(QSize(201, 31));
        btnList5->setFont(font);

        buttonGroup->addWidget(btnList5, 4, 0, 1, 1);

        btnList2 = new QPushButton(gridLayoutWidget);
        btnList2->setObjectName(QString::fromUtf8("btnList2"));
        sizePolicy.setHeightForWidth(btnList2->sizePolicy().hasHeightForWidth());
        btnList2->setSizePolicy(sizePolicy);
        btnList2->setMinimumSize(QSize(201, 31));
        btnList2->setMaximumSize(QSize(201, 31));
        btnList2->setFont(font);

        buttonGroup->addWidget(btnList2, 1, 0, 1, 1);

        btnList3 = new QPushButton(gridLayoutWidget);
        btnList3->setObjectName(QString::fromUtf8("btnList3"));
        sizePolicy.setHeightForWidth(btnList3->sizePolicy().hasHeightForWidth());
        btnList3->setSizePolicy(sizePolicy);
        btnList3->setMinimumSize(QSize(201, 31));
        btnList3->setMaximumSize(QSize(201, 31));
        btnList3->setFont(font);

        buttonGroup->addWidget(btnList3, 2, 0, 1, 1);

        btnList6 = new QPushButton(gridLayoutWidget);
        btnList6->setObjectName(QString::fromUtf8("btnList6"));
        sizePolicy.setHeightForWidth(btnList6->sizePolicy().hasHeightForWidth());
        btnList6->setSizePolicy(sizePolicy);
        btnList6->setMinimumSize(QSize(201, 31));
        btnList6->setMaximumSize(QSize(201, 31));
        btnList6->setFont(font);

        buttonGroup->addWidget(btnList6, 5, 0, 1, 1);

        labelPhoto = new QLabel(centralWidget);
        labelPhoto->setObjectName(QString::fromUtf8("labelPhoto"));
        labelPhoto->setGeometry(QRect(20, 10, 71, 61));
        labelPhoto->setScaledContents(true);
        loadPhotoButton = new QPushButton(centralWidget);
        loadPhotoButton->setObjectName(QString::fromUtf8("loadPhotoButton"));
        loadPhotoButton->setGeometry(QRect(110, 30, 91, 29));
        deleteType = new QPushButton(centralWidget);
        deleteType->setObjectName(QString::fromUtf8("deleteType"));
        deleteType->setGeometry(QRect(123, 560, 101, 31));
        deleteType->setFont(font);
        screenWidget = new QWidget(centralWidget);
        screenWidget->setObjectName(QString::fromUtf8("screenWidget"));
        screenWidget->setGeometry(QRect(-1, -1, 931, 601));
        screenWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        authGroupBox = new QGroupBox(screenWidget);
        authGroupBox->setObjectName(QString::fromUtf8("authGroupBox"));
        authGroupBox->setGeometry(QRect(310, 200, 291, 211));
        authGroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        authGroupBox->setFlat(false);
        loginButton = new QPushButton(authGroupBox);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setGeometry(QRect(12, 170, 131, 29));
        loginButton->setStyleSheet(QString::fromUtf8("background-color: #c8c8c8;"));
        registrationButton = new QPushButton(authGroupBox);
        registrationButton->setObjectName(QString::fromUtf8("registrationButton"));
        registrationButton->setGeometry(QRect(150, 170, 131, 29));
        registrationButton->setStyleSheet(QString::fromUtf8("background-color: #c8c8c8;"));
        layoutWidget = new QWidget(authGroupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 271, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        authLoginLabel = new QLabel(layoutWidget);
        authLoginLabel->setObjectName(QString::fromUtf8("authLoginLabel"));

        horizontalLayout_2->addWidget(authLoginLabel);

        authLoginLineEdit = new QLineEdit(layoutWidget);
        authLoginLineEdit->setObjectName(QString::fromUtf8("authLoginLineEdit"));

        horizontalLayout_2->addWidget(authLoginLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        authPassLabel = new QLabel(layoutWidget);
        authPassLabel->setObjectName(QString::fromUtf8("authPassLabel"));

        horizontalLayout->addWidget(authPassLabel);

        authPassLineEdit = new QLineEdit(layoutWidget);
        authPassLineEdit->setObjectName(QString::fromUtf8("authPassLineEdit"));
        authPassLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(authPassLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        authLabel = new QLabel(authGroupBox);
        authLabel->setObjectName(QString::fromUtf8("authLabel"));
        authLabel->setGeometry(QRect(100, 10, 111, 20));
        QFont font3;
        font3.setPointSize(11);
        authLabel->setFont(font3);
        authShowPass = new QCheckBox(authGroupBox);
        authShowPass->setObjectName(QString::fromUtf8("authShowPass"));
        authShowPass->setGeometry(QRect(10, 110, 131, 24));
        authWarningLabel = new QLabel(authGroupBox);
        authWarningLabel->setObjectName(QString::fromUtf8("authWarningLabel"));
        authWarningLabel->setGeometry(QRect(12, 140, 271, 20));
        authWarningLabel->setStyleSheet(QString::fromUtf8("color: red;"));
        regGroupBox = new QGroupBox(screenWidget);
        regGroupBox->setObjectName(QString::fromUtf8("regGroupBox"));
        regGroupBox->setGeometry(QRect(310, 200, 291, 231));
        authLabel_2 = new QLabel(regGroupBox);
        authLabel_2->setObjectName(QString::fromUtf8("authLabel_2"));
        authLabel_2->setGeometry(QRect(100, 10, 111, 20));
        authLabel_2->setFont(font3);
        layoutWidget1 = new QWidget(regGroupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 271, 100));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        regLoginLabel = new QLabel(layoutWidget1);
        regLoginLabel->setObjectName(QString::fromUtf8("regLoginLabel"));

        horizontalLayout_3->addWidget(regLoginLabel);

        regLoginLineEdit = new QLineEdit(layoutWidget1);
        regLoginLineEdit->setObjectName(QString::fromUtf8("regLoginLineEdit"));

        horizontalLayout_3->addWidget(regLoginLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        regPasslabel = new QLabel(layoutWidget1);
        regPasslabel->setObjectName(QString::fromUtf8("regPasslabel"));

        horizontalLayout_5->addWidget(regPasslabel);

        regPassLineEdit = new QLineEdit(layoutWidget1);
        regPassLineEdit->setObjectName(QString::fromUtf8("regPassLineEdit"));
        regPassLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(regPassLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        regRepeatpassLabel = new QLabel(layoutWidget1);
        regRepeatpassLabel->setObjectName(QString::fromUtf8("regRepeatpassLabel"));

        horizontalLayout_4->addWidget(regRepeatpassLabel);

        regRepeatpassLineEdit = new QLineEdit(layoutWidget1);
        regRepeatpassLineEdit->setObjectName(QString::fromUtf8("regRepeatpassLineEdit"));
        regRepeatpassLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(regRepeatpassLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        registerButton = new QPushButton(regGroupBox);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(10, 190, 131, 29));
        registerButton->setStyleSheet(QString::fromUtf8("background-color: #c8c8c8;"));
        authorizationButton = new QPushButton(regGroupBox);
        authorizationButton->setObjectName(QString::fromUtf8("authorizationButton"));
        authorizationButton->setGeometry(QRect(148, 190, 131, 29));
        authorizationButton->setStyleSheet(QString::fromUtf8("background-color: #c8c8c8;"));
        regShowPass = new QCheckBox(regGroupBox);
        regShowPass->setObjectName(QString::fromUtf8("regShowPass"));
        regShowPass->setGeometry(QRect(10, 130, 131, 24));
        regWarningLabel = new QLabel(regGroupBox);
        regWarningLabel->setObjectName(QString::fromUtf8("regWarningLabel"));
        regWarningLabel->setGeometry(QRect(10, 160, 271, 20));
        regWarningLabel->setStyleSheet(QString::fromUtf8("color: red;"));
        regGroupBox->raise();
        authGroupBox->raise();
        cancelNote = new QPushButton(centralWidget);
        cancelNote->setObjectName(QString::fromUtf8("cancelNote"));
        cancelNote->setGeometry(QRect(590, 560, 311, 31));
        cancelNote->setFont(font);
        removeNote = new QPushButton(centralWidget);
        removeNote->setObjectName(QString::fromUtf8("removeNote"));
        removeNote->setGeometry(QRect(590, 560, 311, 31));
        removeNote->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        removeNote->raise();
        addTypeApply->raise();
        noteList->raise();
        horLine->raise();
        vertLine->raise();
        listName->raise();
        addNote->raise();
        addType->raise();
        complTasks->raise();
        planT->raise();
        impT->raise();
        dayT->raise();
        userName->raise();
        editButton->raise();
        returnButton->raise();
        textBrowser->raise();
        headerLine->raise();
        textText->raise();
        headerText->raise();
        datePlanned->raise();
        planLabel->raise();
        boolPlanned->raise();
        boolCompleted->raise();
        boolImportant->raise();
        applyButton->raise();
        addNoteApply->raise();
        gridLayoutWidget->raise();
        labelPhoto->raise();
        loadPhotoButton->raise();
        toolButton->raise();
        deleteType->raise();
        cancelNote->raise();
        screenWidget->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Noted", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        listName->setText(QCoreApplication::translate("MainWindow", "List Name", nullptr));
        addNote->setText(QCoreApplication::translate("MainWindow", "Add Note", nullptr));
        addType->setText(QCoreApplication::translate("MainWindow", "   Create list", nullptr));
        complTasks->setText(QCoreApplication::translate("MainWindow", "Completed Tasks", nullptr));
        planT->setText(QCoreApplication::translate("MainWindow", "Planned Tasks", nullptr));
        impT->setText(QCoreApplication::translate("MainWindow", "Important Tasks", nullptr));
        dayT->setText(QCoreApplication::translate("MainWindow", "Daily Tasks", nullptr));
        userName->setText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        editButton->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        returnButton->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        textText->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
        headerText->setText(QCoreApplication::translate("MainWindow", " Header", nullptr));
        planLabel->setText(QCoreApplication::translate("MainWindow", "Planned at:", nullptr));
        boolPlanned->setText(QCoreApplication::translate("MainWindow", "Planned", nullptr));
        boolCompleted->setText(QCoreApplication::translate("MainWindow", "Completed", nullptr));
        boolImportant->setText(QCoreApplication::translate("MainWindow", "Important", nullptr));
        applyButton->setText(QCoreApplication::translate("MainWindow", "Apply Changes", nullptr));
        addTypeApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        addNoteApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        btnList4->setText(QCoreApplication::translate("MainWindow", "List4", nullptr));
        btnList1->setText(QCoreApplication::translate("MainWindow", "List1", nullptr));
        btnList5->setText(QCoreApplication::translate("MainWindow", "List5", nullptr));
        btnList2->setText(QCoreApplication::translate("MainWindow", "List2", nullptr));
        btnList3->setText(QCoreApplication::translate("MainWindow", "List3", nullptr));
        btnList6->setText(QCoreApplication::translate("MainWindow", "List6", nullptr));
        labelPhoto->setText(QString());
        loadPhotoButton->setText(QCoreApplication::translate("MainWindow", "Load photo", nullptr));
        deleteType->setText(QCoreApplication::translate("MainWindow", "Delete list", nullptr));
        authGroupBox->setTitle(QString());
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        registrationButton->setText(QCoreApplication::translate("MainWindow", "Registation", nullptr));
        authLoginLabel->setText(QCoreApplication::translate("MainWindow", "Login:      ", nullptr));
        authLoginLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "example@gmail.com", nullptr));
        authPassLabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        authPassLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "qwerty", nullptr));
        authLabel->setText(QCoreApplication::translate("MainWindow", "Authorization", nullptr));
        authShowPass->setText(QCoreApplication::translate("MainWindow", "Show password", nullptr));
        authWarningLabel->setText(QString());
        regGroupBox->setTitle(QString());
        authLabel_2->setText(QCoreApplication::translate("MainWindow", "Registration", nullptr));
        regLoginLabel->setText(QCoreApplication::translate("MainWindow", "Login:      ", nullptr));
        regLoginLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "example@gmail.com", nullptr));
        regPasslabel->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        regPassLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "qwerty", nullptr));
        regRepeatpassLabel->setText(QCoreApplication::translate("MainWindow", "Repeat password:", nullptr));
        regRepeatpassLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "qwerty", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        authorizationButton->setText(QCoreApplication::translate("MainWindow", "Authorization", nullptr));
        regShowPass->setText(QCoreApplication::translate("MainWindow", "Show password", nullptr));
        regWarningLabel->setText(QString());
        cancelNote->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        removeNote->setText(QCoreApplication::translate("MainWindow", "Remove note", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
