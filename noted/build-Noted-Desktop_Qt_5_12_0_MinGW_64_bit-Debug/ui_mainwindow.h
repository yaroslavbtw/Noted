/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *horLine;
    QFrame *vertLine;
    QListWidget *noteList;
    QListView *typeList;
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
    QLabel *complLabel;
    QDateTimeEdit *dateComplete;
    QCheckBox *boolPlanned;
    QCheckBox *boolCompleted;
    QCheckBox *boolImportant;
    QPushButton *applyButton;
    QPushButton *addTypeApply;
    QPushButton *addNoteApply;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(922, 599);
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
        typeList = new QListView(centralWidget);
        typeList->setObjectName(QString::fromUtf8("typeList"));
        typeList->setGeometry(QRect(20, 291, 201, 261));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(860, 30, 41, 31));
        toolButton->setFont(font);
        listName = new QLabel(centralWidget);
        listName->setObjectName(QString::fromUtf8("listName"));
        listName->setGeometry(QRect(270, 30, 631, 31));
        listName->setFont(font);
        addNote = new QPushButton(centralWidget);
        addNote->setObjectName(QString::fromUtf8("addNote"));
        addNote->setGeometry(QRect(270, 560, 631, 31));
        addNote->setFont(font);
        addType = new QPushButton(centralWidget);
        addType->setObjectName(QString::fromUtf8("addType"));
        addType->setGeometry(QRect(20, 560, 201, 31));
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
        userName->setGeometry(QRect(120, 30, 101, 41));
        userName->setFont(font);
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
        datePlanned->setGeometry(QRect(750, 120, 151, 31));
        datePlanned->setFont(font);
        planLabel = new QLabel(centralWidget);
        planLabel->setObjectName(QString::fromUtf8("planLabel"));
        planLabel->setGeometry(QRect(750, 80, 101, 31));
        planLabel->setFont(font);
        complLabel = new QLabel(centralWidget);
        complLabel->setObjectName(QString::fromUtf8("complLabel"));
        complLabel->setGeometry(QRect(580, 80, 121, 31));
        complLabel->setFont(font);
        dateComplete = new QDateTimeEdit(centralWidget);
        dateComplete->setObjectName(QString::fromUtf8("dateComplete"));
        dateComplete->setGeometry(QRect(583, 120, 151, 31));
        dateComplete->setFont(font);
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
        addNoteApply->setGeometry(QRect(270, 560, 631, 31));
        addNoteApply->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        addTypeApply->raise();
        noteList->raise();
        horLine->raise();
        vertLine->raise();
        typeList->raise();
        toolButton->raise();
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
        complLabel->raise();
        dateComplete->raise();
        boolPlanned->raise();
        boolCompleted->raise();
        boolImportant->raise();
        applyButton->raise();
        addNoteApply->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        listName->setText(QApplication::translate("MainWindow", "                                                         List Name", nullptr));
        addNote->setText(QApplication::translate("MainWindow", "Add Note", nullptr));
        addType->setText(QApplication::translate("MainWindow", "Add Type", nullptr));
        complTasks->setText(QApplication::translate("MainWindow", "Completed Tasks", nullptr));
        planT->setText(QApplication::translate("MainWindow", "Planned Tasks", nullptr));
        impT->setText(QApplication::translate("MainWindow", "Important Tasks", nullptr));
        dayT->setText(QApplication::translate("MainWindow", "Daily Tasks", nullptr));
        userName->setText(QApplication::translate("MainWindow", "User Name", nullptr));
        editButton->setText(QApplication::translate("MainWindow", "Edit", nullptr));
        returnButton->setText(QApplication::translate("MainWindow", "Return", nullptr));
        textText->setText(QApplication::translate("MainWindow", "Text", nullptr));
        headerText->setText(QApplication::translate("MainWindow", " Header", nullptr));
        planLabel->setText(QApplication::translate("MainWindow", "Planned at:", nullptr));
        complLabel->setText(QApplication::translate("MainWindow", "Completed at:", nullptr));
        boolPlanned->setText(QApplication::translate("MainWindow", "Planned", nullptr));
        boolCompleted->setText(QApplication::translate("MainWindow", "Completed", nullptr));
        boolImportant->setText(QApplication::translate("MainWindow", "Important", nullptr));
        applyButton->setText(QApplication::translate("MainWindow", "Apply Changes", nullptr));
        addTypeApply->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        addNoteApply->setText(QApplication::translate("MainWindow", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
