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

class User                                                           // класс представляющий пользователя
{
private:
    int id;                                                          // уникальный идентификатор пользователя
    QString strId;                                                   // строчное представления id
    QString mail;                                                    // логин пользователя
    QString password;                                                // пароль пользователя
    QString image;                                                   // изображение профиля пользователя

public:
    User(QSqlRecord rec)                                             // функция доступа к данным
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

    
    void on_addNote_clicked();                                              // отображение формы с заполняемыми полями для создания заметки

    void on_returnButton_clicked();                                         // отмена редактирования заметки

    void on_dayT_clicked();                                                 // отображение заметок группы "Daily tasks"

    void on_impT_clicked();                                                 // отображение заметок группы "Important tasks"

    void on_planT_clicked();                                                // отображение заметок группы "Planned tasks"

    void on_complTasks_clicked();                                           // отображение заметок группы "Completed tasks"

    void on_boolPlanned_toggled(bool checked);                              // отображение виджета дата/время

    void on_boolCompleted_toggled(bool checked);                            // отображение формы для ввода названия новой группы заметок

    void on_addType_clicked();                                              // отображение формы для редактирования заметки с выводом текущих значений

    void on_noteList_doubleClicked(const QModelIndex &index);               // сохранение информации о заметке после редактирования

    void on_applyButton_clicked();                                          // сохранение информации о заметке после редактирования

    void on_editButton_clicked();                                           // отображение полной информации об заметке

    void on_addTypeApply_clicked();                                         // добавление новой группы заметок

    void on_addNoteApply_clicked();                                         // добавление новой заметки

    void on_loadPhotoButton_clicked();                                      // изменение изображения профиля

    void on_toolButton_clicked();                                           // отображение меню с функциями сортировки


    void on_registrationButton_clicked();                                   // отображение формы с регистрацией

    void on_authorizationButton_clicked();                                  // отображение формы с авторизацией

    void on_authShowPass_stateChanged(int arg1);                            // показать/скрыть пароль при авторизации

    void on_regShowPass_stateChanged(int arg1);                             // показать/скрыть пароль при регистрации

    void on_loginButton_clicked();                                          // авторизация пользователя

    void on_registerButton_clicked();                                       // регистрация нового пользователя

    void on_btnList1_clicked();                                             // отображение первой группы заметок
    
    void on_btnList2_clicked();                                             // отображение второй группы заметок

    void on_btnList3_clicked();                                             // отображение третей группы заметок

    void on_btnList4_clicked();                                             // отображение четвертой группы заметок

    void on_btnList5_clicked();                                             // отображение пятой группы заметок

    void on_btnList6_clicked();                                             // отображение шестой группы заметок

    void on_deleteType_clicked();                                           // удаление выбранной группы заметок

    void btns_click();                                                      // выбор из базы данных заметок выбранной группы

    void on_boolPlanned_stateChanged(int arg1);                             // изменение содержимого

    void on_cancelNote_clicked();                                           // отмена добавления новой заметки

    void sortByTitle();                                                     // сортировка по заголовку по убыванию

    void sortByDateOfCreate();                                              // сортировка по дате создания по возрастанию

    void sortByTitleACK();                                                  // сортировка по заголовку по возрастанию

    void sortByDateOfCreateDESC();                                          // сортировка по дате создания по убыванию

    void on_removeNote_clicked();                                           // удаление заметки

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;                        //переменная соединения с базой данной
    QSqlQuery query;                        //переменная представляющая интерфейс для выполнения операций SQL    
    int countOfButtons = 0;                 //счетчик созданных групп
    QWidget *widg = new QWidget;            //указатель на виджет для корректного отображения формы с собственными группами
    User loginedUser;                       //объект класса User, представляющий запись из таблицы 'users'
    QPushButton **listBtn;                  //список созданных кнопок (кастомных групп)
    QPushButton *currentBtn;                //текущая выбранная группа
    QString prevStr;                        //название предыдущей группы
};

#endif // MAINWINDOW_H
