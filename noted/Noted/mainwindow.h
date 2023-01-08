#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFileDialog>
#include <QPainterPath>
#include <QPainter>
#include <QButtonGroup>
#include <QMenu>
#include <QMessageBox>
#include <QDateTime>
#include <QValidator>

namespace Ui {
class MainWindow;
}

class User
{
private:
    int id;
    QString strId;
    QString mail;
    QString password;
    QString image;

public:
    User(QSqlRecord rec)
    {
        id = rec.value("id").toInt();
        strId = rec.value("id").toString();
        mail = rec.value("mail").toString();
        password = rec.value("password").toString();
        image = rec.value("image").toString();
    }

    User()
    {

    }

    friend class MainWindow;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    
    void on_addNote_clicked();

    void on_returnButton_clicked();

    void on_dayT_clicked();

    void on_impT_clicked();

    void on_planT_clicked();

    void on_complTasks_clicked();

    void on_boolPlanned_toggled(bool checked);

    void on_boolCompleted_toggled(bool checked);

    void on_addType_clicked();

    void on_noteList_doubleClicked(const QModelIndex &index);

    void on_applyButton_clicked();

    void on_editButton_clicked();

    void on_addTypeApply_clicked();

    void on_addNoteApply_clicked();

    void on_loadPhotoButton_clicked();

    void on_toolButton_clicked();


    void on_registrationButton_clicked();

    void on_authorizationButton_clicked();

    void on_authShowPass_stateChanged(int arg1);

    void on_regShowPass_stateChanged(int arg1);

    void on_loginButton_clicked();

    void on_registerButton_clicked();

    void on_btnList1_clicked();

    void on_btnList2_clicked();

    void on_btnList3_clicked();

    void on_btnList4_clicked();

    void on_btnList5_clicked();

    void on_btnList6_clicked();

    void on_deleteType_clicked();

    void btns_click();

    void on_boolPlanned_stateChanged(int arg1);

    void on_cancelNote_clicked();

    void sortByTitle();

    void sortByDateOfCreate();

    void sortByTitleACK();

    void sortByDateOfCreateDESC();

    void on_removeNote_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery query;
    int countOfButtons = 0;
    QWidget *widg = new QWidget;
    User loginedUser;
    QPushButton **listBtn;
    QPushButton *currentBtn;
    QString prevStr;
};

#endif // MAINWINDOW_H
