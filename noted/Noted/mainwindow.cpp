#include "mainwindow.h"
#include "ui_mainwindow.h"

// 1 - Daily Tasks
// 2 - Important Tasks
// 3 - Planned Tasks
// 4 - Completed Tasks  "dd.MM.yyyy hh:mm"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->regGroupBox->hide();
    ui->returnButton->hide();
    ui->editButton->hide();
    ui->textText->hide();
    ui->headerText->hide();
    ui->textBrowser->hide();
    ui->headerLine->hide();
    ui->boolPlanned->hide();
    ui->boolImportant->hide();
    ui->boolCompleted->hide();
    ui->datePlanned->hide();
    ui->planLabel->hide();
    ui->applyButton->hide();
    ui->addTypeApply->hide();
    ui->textBrowser->setReadOnly(false);
    ui->boolCompleted->setEnabled(false);
    ui->addNoteApply->hide();
    ui->removeNote->hide();
    ui->btnList1->hide();
    ui->btnList2->hide();
    ui->btnList3->hide();
    ui->btnList4->hide();
    ui->btnList5->hide();
    ui->btnList6->hide();

    QRegularExpression m_validator("^([a-z0-9_-]+\.)*[a-z0-9_-]+@[a-z0-9_-]+(\.[a-z0-9_-]+)*\.[a-z]{2,6}$");
    QValidator *validator = new QRegularExpressionValidator(m_validator, this);
    ui->regLoginLineEdit->setValidator(validator);
    ui->authLoginLineEdit->setValidator(validator);

//    ui->datePlanned->setMinimumDateTime(QDateTime::currentDateTime());

    this->listBtn = new QPushButton *[6]{ui->btnList1, ui->btnList2, ui->btnList3, ui->btnList4, ui->btnList5, ui->btnList6};
    ui->textBrowser->setReadOnly(false);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("note.sqlite");

    if(db.open())
        qDebug() << "OPEN";

    query = QSqlQuery(db);

    QFile styleF;

    styleF.setFileName("style.css");
    styleF.open(QFile::ReadOnly);
    QString qssStr = styleF.readAll();
    this->setStyleSheet(qssStr);

    QSize szItem(600, 30);
    ui->noteList->setGridSize(szItem);

    ui->buttonGroup->setVerticalSpacing(10);
    ui->buttonGroup->setRowMinimumHeight(1, 5);

    QMenu *menu = new QMenu;
    QAction *sortTitleAsc = menu->addAction("Sort by title ASC");
    connect(sortTitleAsc, SIGNAL(triggered()), this, SLOT(sortByTitleACK()));
    QAction *sortTitleDesc = menu->addAction("Sort by title DESC");
    connect(sortTitleDesc, SIGNAL(triggered()), this, SLOT(sortByTitle()));
    QAction *sortByDateOfCreateAsc = menu->addAction("Sort by date of create ASC");
    connect(sortByDateOfCreateAsc, SIGNAL(triggered()), this, SLOT(sortByDateOfCreate()));
    QAction *sortByDateOfCreateDesc = menu->addAction("Sort by date of create DESC");
    connect(sortByDateOfCreateDesc, SIGNAL(triggered()), this, SLOT(sortByDateOfCreateDESC()));
    ui->toolButton->setMenu(menu);
   
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addNote_clicked()
{
    ui->removeNote->hide();
    ui->textBrowser->clear();
    ui->headerLine->clear();
    ui->boolPlanned->setChecked(false);
    ui->boolCompleted->setChecked(false);
    ui->boolImportant->setChecked(false);
    ui->addNote->hide();
    ui->noteList->hide();
    ui->toolButton->hide();
    ui->textText->show();
    ui->headerText->show();
    ui->textBrowser->show();
    ui->headerLine->show();
    ui->boolPlanned->show();
    ui->boolImportant->show();
    ui->boolCompleted->show();
    ui->addNoteApply->show();
    ui->boolCompleted->setEnabled(true);
    ui->boolImportant->setEnabled(true);
    ui->boolPlanned->setEnabled(true);
    ui->textBrowser->setReadOnly(false);
    ui->headerLine->setReadOnly(false);
    ui->addType->setEnabled(false);
    ui->dayT->setEnabled(false);
    ui->impT->setEnabled(false);
    ui->complTasks->setEnabled(false);
    ui->planT->setEnabled(false);
    ui->deleteType->setEnabled(false);
    ui->cancelNote->show();
    for(int x = 0; x < 6; x++)
        this->listBtn[x]->setEnabled(false);

    if(currentBtn == ui->impT)
    {
        ui->boolImportant->setChecked(true);
    }
    if(currentBtn == ui->planT)
    {
        ui->boolPlanned->setChecked(true);
        ui->planLabel->show();
        ui->datePlanned->show();
    }
}



void MainWindow::on_returnButton_clicked()
{
    ui->returnButton->hide();
    ui->editButton->hide();
    ui->textText->hide();
    ui->headerText->hide();
    ui->textBrowser->hide();
    ui->headerLine->hide();
    ui->boolPlanned->hide();
    ui->boolCompleted->hide();
    ui->boolImportant->hide();
    ui->addNote->show();
    ui->removeNote->show();
    ui->noteList->show();
    ui->listName->show();
    ui->toolButton->show();
    ui->datePlanned->hide();
    ui->planLabel->hide();
    ui->addType->setEnabled(true);
    ui->dayT->setEnabled(true);
    ui->impT->setEnabled(true);
    ui->complTasks->setEnabled(true);
    ui->planT->setEnabled(true);
    for(int x = 0; x < 6; x++)
        this->listBtn[x]->setEnabled(true);
}

void MainWindow::on_dayT_clicked()
{
    ui->listName->setText("Daily Tasks");
    ui->noteList->show();
    ui->listName->show();
    ui->addNote->show();
    ui->removeNote->show();
    ui->toolButton->show();
    this->currentBtn = ui->dayT;
    ui->deleteType->setEnabled(false);
    ui->noteList->clear();
    query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE group_id=1 and is_completed=0;");
    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());
}

void MainWindow::on_impT_clicked()
{
    ui->listName->setText("Important");
    ui->noteList->show();
    ui->listName->show();
    ui->addNote->show();
    ui->removeNote->show();
    ui->toolButton->show();
    this->currentBtn = ui->impT;
    ui->deleteType->setEnabled(false);
    ui->noteList->clear();
    query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_important=1 and is_completed=0;");
    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());

}

void MainWindow::on_planT_clicked()
{
    ui->listName->setText("Planned Tasks");
    ui->noteList->show();
    ui->listName->show();
    ui->addNote->show();
    ui->removeNote->show();
    ui->toolButton->show();
    this->currentBtn = ui->planT;
    ui->deleteType->setEnabled(false);
    ui->noteList->clear();
    query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE planned_date_time IS NOT NULL and is_completed=0;");
    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());
}

void MainWindow::on_complTasks_clicked()
{
    ui->listName->setText("Comleted Tasks");
    ui->noteList->show();
    ui->listName->show();
    ui->addNote->hide();
    ui->removeNote->show();
    ui->toolButton->show();
    this->currentBtn = ui->complTasks;
    ui->deleteType->setEnabled(false);
    ui->noteList->clear();
    query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_completed=1;");
    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());
}


void MainWindow::on_boolPlanned_toggled(bool checked)
{
    if(checked && !ui->textBrowser->isHidden())
    {
        ui->datePlanned->show();
        ui->planLabel->show();
    }
    else
    {
        ui->datePlanned->hide();
        ui->planLabel->hide();
    }

}


void MainWindow::on_boolCompleted_toggled(bool checked)
{
//    if(checked && !ui->textBrowser->isHidden())
//    {
//        ui->dateComplete->show();
//        ui->complLabel->show();
//    }
//    else
//    {
//        ui->dateComplete->hide();
//        ui->complLabel->hide();
//    }
}

void MainWindow::on_addType_clicked()
{
    if(this->countOfButtons < 6)
    {
        ui->headerText->show();
        ui->addNote->hide();
        ui->removeNote->hide();
        ui->noteList->hide();
        ui->listName->hide();
        ui->toolButton->hide();
        ui->headerLine->show();
        ui->addTypeApply->show();
        ui->headerLine->clear();
        ui->headerLine->setReadOnly(false);
        ui->addType->setEnabled(false);
        ui->dayT->setEnabled(false);
        ui->impT->setEnabled(false);
        ui->complTasks->setEnabled(false);
        ui->planT->setEnabled(false);
        ui->deleteType->setEnabled(false);
        ui->cancelNote->hide();
        for(int x = 0; x < 6; x++)
            this->listBtn[x]->setEnabled(false);
    }
}


void MainWindow::on_noteList_doubleClicked(const QModelIndex &index)
{
    QString content = ui->noteList->currentItem()->text();
    this->prevStr = ui->noteList->currentItem()->text();
    ui->addType->setEnabled(false);
    ui->dayT->setEnabled(false);
    ui->impT->setEnabled(false);
    ui->complTasks->setEnabled(false);
    ui->planT->setEnabled(false);
    ui->addNote->hide();
    ui->removeNote->hide();
    ui->noteList->hide();
    ui->toolButton->hide();
    ui->textText->show();
    ui->headerText->show();
    ui->textBrowser->show();
    ui->headerLine->show();
    ui->headerLine->setText(content);
    ui->boolPlanned->show();
    ui->boolImportant->show();
    ui->boolCompleted->show();
    ui->returnButton->show();
    ui->editButton->show();
    ui->addType->setEnabled(false);
    if (ui->boolPlanned->isChecked())
    {
        ui->datePlanned->show();
        ui->planLabel->show();
    }
    ui->textBrowser->setReadOnly(true);
    ui->headerLine->setReadOnly(true);
    ui->boolImportant->setEnabled(false);
    ui->boolPlanned->setEnabled(false);
    ui->boolCompleted->setEnabled(false);
    ui->cancelNote->hide();
    for(int x = 0; x < 6; x++)
        this->listBtn[x]->setEnabled(false);

    query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE header='" + content + "'");
    query.next();
    ui->boolCompleted->setChecked(query.record().value("is_completed").toBool());
    ui->boolImportant->setChecked(query.record().value("is_important").toBool());
    if(!query.record().value("planned_date_time").isNull())
    {
        ui->boolPlanned->setChecked(true);
        ui->datePlanned->setEnabled(true);
        ui->datePlanned->show();
        ui->datePlanned->setDateTime(QDateTime::fromString(query.record().value("planned_date_time").toString(), "dd.MM.yyyy hh:mm"));
        qDebug() << QDateTime::fromString(query.record().value("planned_date_time").toString(), "dd.MM.yyyy hh:mm");
        ui->datePlanned->setEnabled(false);
        ui->planLabel->setEnabled(false);
    }
    else
    {
        ui->boolPlanned->setChecked(false);
        ui->datePlanned->setEnabled(false);
        ui->datePlanned->hide();
        ui->planLabel->setEnabled(false);
        ui->planLabel->hide();
    }
    ui->textBrowser->setPlainText(query.record().value("info").toString());

}

void MainWindow::on_applyButton_clicked()
{
    ui->boolImportant->setEnabled(false);
    ui->boolPlanned->setEnabled(false);
    ui->returnButton->show();
    ui->applyButton->hide();
    ui->editButton->show();
    ui->textBrowser->setReadOnly(true);
    ui->headerLine->setReadOnly(true);
    ui->noteList->currentItem()->setText(ui->headerLine->text());
    ui->boolCompleted->setEnabled(false);
    ui->datePlanned->setEnabled(false);
    ui->planLabel->setEnabled(false);

    query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE header='" + this->prevStr + "'");
    query.next();
    qDebug() << query.record().value("id").toString();
    qDebug() << query.lastQuery();
    QString head = ui->headerLine->text();
    QString note_id = query.record().value("id").toString();

    QString info = ui->textBrowser->toPlainText();
    bool planned = ui->boolPlanned->isChecked();
    bool import = ui->boolImportant->isChecked();
    bool complete = ui->boolCompleted->isChecked();
    QString dt_plan = NULL;
    QString dt_complete = NULL;
    QString queryStr = "";

    if(planned)
    {
        dt_plan = ui->datePlanned->dateTime().toString("dd.MM.yyyy hh:mm");
        queryStr = "UPDATE notes_" + loginedUser.strId +" SET header='" + head +"', info='" + info + "', planned_date_time='" + dt_plan + "', complited_date_time=NULL, is_important=" + QString::number(int(import)) + ", is_completed=0 WHERE id=" + note_id + ";";
    }
    if(complete)
    {
        dt_complete = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm");
        queryStr = "UPDATE notes_" + loginedUser.strId +" SET header='" + head +"', info='" + info + "', planned_date_time=NULL, complited_date_time='" + dt_complete + "', is_important=" + QString::number(int(import)) + ", is_completed=1 WHERE id=" + note_id + ";";
    }
    if(planned && complete)
        queryStr = "UPDATE notes_" + loginedUser.strId +" SET header='" + head +"', info='" + info + "', planned_date_time='" + dt_plan + "', complited_date_time='" + dt_complete + "', is_important=" + QString::number(int(import)) + ", is_completed=1 WHERE id=" + note_id + ";";
    if(!planned && !complete)
        queryStr = "UPDATE notes_" + loginedUser.strId +" SET header='" + head +"', info='" + info + "', planned_date_time=NULL, complited_date_time=NULL, is_important=" + QString::number(int(import)) + ", is_completed=0 WHERE id=" + note_id + ";";
    if(query.exec(queryStr))
        qDebug() << "TRUE UPDATE";
    else qDebug() << "FALSE UPDATE";
    ui->datePlanned->clear();
}

void MainWindow::on_editButton_clicked()
{
    ui->boolImportant->setEnabled(true);
    ui->boolPlanned->setEnabled(true);
    ui->returnButton->hide();
    ui->applyButton->show();
    ui->editButton->hide();
    ui->textBrowser->setReadOnly(false);
    ui->headerLine->setReadOnly(false);
    ui->boolCompleted->setEnabled(true);

    if(ui->boolPlanned->isChecked())
    {
        ui->planLabel->setEnabled(true);
        ui->datePlanned->setEnabled(true);
    }
}

void MainWindow::on_addTypeApply_clicked()
{
    ui->headerLine->hide();
    ui->headerText->hide();
    ui->addTypeApply->hide();
    ui->addType->setEnabled(true);
    ui->dayT->setEnabled(true);
    ui->impT->setEnabled(true);
    ui->complTasks->setEnabled(true);
    ui->planT->setEnabled(true);
    ui->deleteType->setEnabled(true);
    for(int x = 0; x < 6; x++)
        this->listBtn[x]->setEnabled(true);

    QString nameList = ui->headerLine->text();
    if(nameList.length() != 0)
    {
        int numb = 0;
        for(int x = 0; x < 6; x ++)
        {
            if(this->listBtn[x]->isHidden() == true)
                numb = x;
        }
        this->listBtn[numb]->setText(nameList);
        this->listBtn[numb]->show();

        this->currentBtn = this->listBtn[numb];

        this->countOfButtons++;

        query.prepare("INSERT INTO groups (name, user_id) VALUES (:name, :user_id);");
        query.bindValue(":name", nameList);
        query.bindValue(":user_id", loginedUser.id);
        query.exec();

        ui->noteList->clear();
        ui->listName->setText(this->currentBtn->text());
        ui->addNote->show();
        ui->removeNote->show();
        ui->noteList->show();
        ui->listName->show();
        ui->toolButton->show();
    }else this->currentBtn = NULL;

    ui->headerLine->clear();
}

void MainWindow::on_addNoteApply_clicked()
{
    QString head = ui->headerLine->text();
    if(head.length() != 0)
    {
        ui->returnButton->hide();
        ui->editButton->hide();
        ui->textText->hide();
        ui->headerText->hide();
        ui->textBrowser->hide();
        ui->headerLine->hide();
        ui->boolPlanned->hide();
        ui->boolCompleted->hide();
        ui->boolImportant->hide();
        ui->addNote->show();
        ui->removeNote->show();
        ui->noteList->show();
        ui->addNoteApply->hide();
        ui->listName->show();
        ui->toolButton->show();
        ui->datePlanned->hide();
        ui->planLabel->hide();
        ui->addType->setEnabled(true);
        ui->dayT->setEnabled(true);
        ui->impT->setEnabled(true);
        ui->complTasks->setEnabled(true);
        ui->planT->setEnabled(true);
        ui->cancelNote->hide();

        for(int x = 0; x < 6; x++)
            this->listBtn[x]->setEnabled(true);


        QString info = ui->textBrowser->toPlainText();
        bool planned = ui->boolPlanned->isChecked();
        bool import = ui->boolImportant->isChecked();
        QString dt_plan;
        if(planned)
            dt_plan = ui->datePlanned->dateTime().toString("dd.MM.yyyy hh:mm");
        else dt_plan = NULL;
        int gr_id;
        if(currentBtn == listBtn[0] || currentBtn == listBtn[1] || currentBtn == listBtn[2]
                || currentBtn == listBtn[3] || currentBtn == listBtn[4] || currentBtn == listBtn[5])
        {
            query.exec("SELECT * FROM groups WHERE name='" + this->currentBtn->text() +  "' and user_id=" + loginedUser.strId + ";");
            query.next();
            gr_id = query.record().value("id").toInt();
        }
        else gr_id = 1;

        if(dt_plan.isNull())
            query.exec("INSERT INTO notes_" + loginedUser.strId + " (header, info, date_time_of_create, is_important, group_id) VALUES ('" + head + "', '" + info + "', '" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") + "', " + QString::number(import) + ", " + QString::number(gr_id) + ");");
        else query.exec("INSERT INTO notes_" + loginedUser.strId + " (header, info, date_time_of_create, planned_date_time, is_important, group_id) VALUES ('" + head + "', '" + info + "', '" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm") + "', '" + dt_plan + "', " + QString::number(import) + ", " + QString::number(gr_id) + ");");

        ui->datePlanned->clear();

        ui->noteList->clear();


        if(currentBtn == ui->complTasks)
            query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_completed=1;");
        else if(currentBtn == ui->impT)
                query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_important=1 and is_completed=0;");
            else if(currentBtn == ui->planT)
                    query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE planned_date_time IS NOT NULL and is_completed=0;");
                else query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE group_id=" + QString::number(gr_id) + " and is_completed=0;");

        while(query.next())
            ui->noteList->addItem(query.record().value("header").toString());
    }
}

void MainWindow::on_loadPhotoButton_clicked()
{
    QString result = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp *.ico)"));
    if(result == "")
        result = loginedUser.image;
    QPixmap pixmap(result);
    ui->labelPhoto->setPixmap(pixmap);
    query.prepare("UPDATE users SET image='" + result + "' WHERE id='" + loginedUser.strId + "'");
    query.exec();
}

void MainWindow::on_toolButton_clicked()
{
    ui->toolButton->showMenu();
}

void MainWindow::on_registrationButton_clicked()
{
    ui->authGroupBox->hide();
    ui->authLoginLineEdit->clear();
    ui->authPassLineEdit->clear();
    ui->authWarningLabel->clear();
    ui->authShowPass->setChecked(false);
    ui->regGroupBox->show();
}


void MainWindow::on_authorizationButton_clicked()
{
    ui->authGroupBox->show();
    ui->regGroupBox->hide();
    ui->regLoginLineEdit->clear();
    ui->regPassLineEdit->clear();
    ui->regRepeatpassLineEdit->clear();
    ui->regWarningLabel->clear();
    ui->regShowPass->setChecked(false);
}


void MainWindow::on_authShowPass_stateChanged(int arg1)
{
    if(arg1 == 2)
        ui->authPassLineEdit->setEchoMode(QLineEdit::Normal);
    else ui->authPassLineEdit->setEchoMode(QLineEdit::Password);
}


void MainWindow::on_regShowPass_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        ui->regPassLineEdit->setEchoMode(QLineEdit::Normal);
        ui->regRepeatpassLineEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->regPassLineEdit->setEchoMode(QLineEdit::Password);
        ui->regRepeatpassLineEdit->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::on_loginButton_clicked()
{
    QString login = ui->authLoginLineEdit->text();
    QString password = ui->authPassLineEdit->text();
    query.prepare("SELECT * FROM users WHERE mail=:log;");
    query.bindValue(":log", login);
    query.exec();
    if(query.next())
    {
        if(query.record().value(2) == password)
        {
            loginedUser = User(query.record());
            ui->userName->setText(loginedUser.mail);
            QPixmap pixmap(loginedUser.image);
            ui->labelPhoto->setPixmap(pixmap);

            query.prepare("SELECT * FROM groups WHERE user_id=:user_id;");
            query.bindValue(":user_id", loginedUser.id);
            query.exec();

            for(int x=0; query.next(); x++)
            {
                this->listBtn[x]->setText(query.record().value("name").toString());
                this->listBtn[x]->show();
                this->countOfButtons++;
            }

            ui->screenWidget->hide();
            ui->noteList->hide();
            ui->listName->hide();
            ui->addNote->hide();
            ui->removeNote->hide();
            ui->toolButton->hide();
            ui->cancelNote->hide();
            ui->deleteType->setEnabled(false);
        }
        else ui->authWarningLabel->setText("The password is incorrect!");
    }
    else ui->authWarningLabel->setText("Account with this username does not exist!");
}


void MainWindow::on_registerButton_clicked()
{
    QString login = ui->regLoginLineEdit->text();
    QString password = ui->regPassLineEdit->text();
    QString repPassword = ui->regRepeatpassLineEdit->text();
    if(login.length() > 5)
    {
        if(password.length() >= 8)
        {
            if(password == repPassword)
            {
                query.prepare("INSERT INTO users (mail, password) VALUES (:log,:pass);");
                query.bindValue(":log", login);
                query.bindValue(":pass", password);

                if(query.exec())
                {
                    query.prepare("SELECT * FROM users WHERE mail=:log and password=:pass;");
                    query.bindValue(":log", login);
                    query.bindValue(":pass", password);
                    query.exec();

                    query.next();
                    loginedUser = User(query.record());
                    ui->userName->setText(loginedUser.mail);
                    QPixmap pixmap(loginedUser.image);
                    ui->labelPhoto->setPixmap(pixmap);

                    if(query.exec("CREATE TABLE notes_" + loginedUser.strId + " ('id'	INTEGER NOT NULL UNIQUE, 'header' TEXT NOT NULL, 'info' TEXT, 'date_time_of_create' TEXT NOT NULL, 'planned_date_time'	TEXT, 'complited_date_time'	TEXT, 'is_important' INTEGER NOT NULL DEFAULT 0, 'is_completed'	TEXT NOT NULL DEFAULT 0, 'group_id'	INTEGER NOT NULL, PRIMARY KEY('id' AUTOINCREMENT));"))
                        qDebug() << "Create table true!";
                    else qDebug() << "Create table false!";

                    ui->screenWidget->hide();
                    ui->noteList->hide();
                    ui->listName->hide();
                    ui->addNote->hide();
                    ui->removeNote->hide();
                    ui->toolButton->hide();
                    ui->cancelNote->hide();
                    ui->deleteType->setEnabled(false);
                }
                else ui->regWarningLabel->setText("This login is busy!");
            }else ui->regWarningLabel->setText("The passwords do not match!");
        }else ui->regWarningLabel->setText("Password length must be at least 8 characters!");
    }else ui->regWarningLabel->setText("Login length is too short!");
}


void MainWindow::on_btnList1_clicked()
{
    ui->listName->setText(ui->btnList1->text());
    this->currentBtn = ui->btnList1;
    ui->addNote->show();
    ui->removeNote->show();
    ui->noteList->show();
    ui->listName->show();
    ui->toolButton->show();

    ui->deleteType->setEnabled(true);
    ui->noteList->clear();
    btns_click();
}


void MainWindow::on_btnList2_clicked()
{
    ui->listName->setText(ui->btnList2->text());
    this->currentBtn = ui->btnList2;
    ui->addNote->show();
    ui->removeNote->show();
    ui->noteList->show();
    ui->listName->show();
    ui->toolButton->show();
    ui->deleteType->setEnabled(true);
    ui->noteList->clear();
    btns_click();
}


void MainWindow::on_btnList3_clicked()
{
    ui->listName->setText(ui->btnList3->text());
    this->currentBtn = ui->btnList3;
    ui->addNote->show();
    ui->removeNote->show();
    ui->noteList->show();
    ui->listName->show();
    ui->toolButton->show();
    ui->deleteType->setEnabled(true);
    ui->noteList->clear();
    btns_click();
}


void MainWindow::on_btnList4_clicked()
{
    ui->listName->setText(ui->btnList4->text());
    this->currentBtn = ui->btnList4;
    ui->addNote->show();
    ui->removeNote->show();
    ui->noteList->show();
    ui->listName->show();
    ui->toolButton->show();
    ui->deleteType->setEnabled(true);
    ui->noteList->clear();
    btns_click();
}


void MainWindow::on_btnList5_clicked()
{
    ui->listName->setText(ui->btnList5->text());
    this->currentBtn = ui->btnList5;
    ui->addNote->show();
    ui->removeNote->show();
    ui->noteList->show();
    ui->listName->show();
    ui->toolButton->show();
    ui->deleteType->setEnabled(true);
    ui->noteList->clear();
    btns_click();
}

void MainWindow::on_btnList6_clicked()
{
    ui->listName->setText(ui->btnList6->text());
    this->currentBtn = ui->btnList6;
    ui->addNote->show();
    ui->removeNote->show();
    ui->noteList->show();
    ui->listName->show();
    ui->toolButton->show();
    ui->deleteType->setEnabled(true);
    ui->noteList->clear();
    btns_click();
}

void MainWindow::on_deleteType_clicked()
{
    if(currentBtn == listBtn[0] || currentBtn == listBtn[1] || currentBtn == listBtn[2]
            || currentBtn == listBtn[3] || currentBtn == listBtn[4] || currentBtn == listBtn[5])
    {
        query.prepare("DELETE FROM groups WHERE name=:name and user_id=:id");
        query.bindValue(":name", currentBtn->text());
        query.bindValue(":id", loginedUser.id);
        query.exec();

        currentBtn->hide();
        currentBtn = NULL;

        ui->noteList->hide();
        ui->listName->hide();
        ui->addNote->hide();
        ui->removeNote->hide();
        ui->toolButton->hide();
        ui->deleteType->setEnabled(false);

        this->countOfButtons--;
    }
}

void MainWindow::btns_click()
{
    query.prepare("SELECT * FROM groups WHERE name=:name and user_id=:id");
    query.bindValue(":name", currentBtn->text());
    query.bindValue(":id", loginedUser.id);
    query.exec();
    query.next();

    QString gr_id = query.record().value("id").toString();
    query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE group_id=" + gr_id + " and is_completed=0;");

    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());
}

void MainWindow::on_boolPlanned_stateChanged(int arg1)
{
    if(arg1==2)
    {
        ui->datePlanned->setEnabled(true);
        ui->planLabel->setEnabled(true);
    }
    else
    {
        ui->datePlanned->setEnabled(false);
        ui->planLabel->setEnabled(false);
    }
}


void MainWindow::on_cancelNote_clicked()
{
    ui->returnButton->hide();
    ui->editButton->hide();
    ui->textText->hide();
    ui->headerText->hide();
    ui->textBrowser->hide();
    ui->headerLine->hide();
    ui->boolPlanned->hide();
    ui->boolCompleted->hide();
    ui->boolImportant->hide();
    ui->addNote->show();
    ui->removeNote->show();
    ui->noteList->show();
    ui->addNoteApply->hide();
    ui->listName->show();
    ui->toolButton->show();
    ui->datePlanned->hide();
    ui->planLabel->hide();
    ui->addType->setEnabled(true);
    ui->dayT->setEnabled(true);
    ui->impT->setEnabled(true);
    ui->complTasks->setEnabled(true);
    ui->planT->setEnabled(true);
    ui->cancelNote->hide();

    for(int x = 0; x < 6; x++)
        this->listBtn[x]->setEnabled(true);
}

void MainWindow::sortByTitle()
{
    ui->noteList->clear();

    QString gr_id;
    if(currentBtn == listBtn[0] || currentBtn == listBtn[1] || currentBtn == listBtn[2]
            || currentBtn == listBtn[3] || currentBtn == listBtn[4] || currentBtn == listBtn[5])
    {
        query.exec("SELECT * FROM groups WHERE name='" + this->currentBtn->text() +  "' and user_id=" + loginedUser.strId + ";");
        query.next();
        gr_id = query.record().value("id").toString();
    }
    else gr_id = "1";
    if(currentBtn == ui->complTasks)
        query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_completed=1 ORDER BY header DESC;");
    else if(currentBtn == ui->impT)
            query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_important=1 and is_completed=0 ORDER BY header DESC;");
        else if(currentBtn == ui->planT)
                query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE planned_date_time IS NOT NULL and is_completed=0 ORDER BY header DESC;");
            else query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE group_id=" + gr_id + " and is_completed=0 ORDER BY header DESC;");

    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());
}

void MainWindow::sortByDateOfCreate()
{
    ui->noteList->clear();

    QString gr_id;
    if(currentBtn == listBtn[0] || currentBtn == listBtn[1] || currentBtn == listBtn[2]
            || currentBtn == listBtn[3] || currentBtn == listBtn[4] || currentBtn == listBtn[5])
    {
        query.exec("SELECT * FROM groups WHERE name='" + this->currentBtn->text() +  "' and user_id=" + loginedUser.strId + ";");
        query.next();
        gr_id = query.record().value("id").toString();
    }
    else gr_id = "1";

    if(currentBtn == ui->complTasks)
        query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_completed=1;");
    else if(currentBtn == ui->impT)
            query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_important=1 and is_completed=0;");
        else if(currentBtn == ui->planT)
                query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE planned_date_time IS NOT NULL and is_completed=0;");
            else query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE group_id=" + gr_id + " and is_completed=0;");


    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());
}

void MainWindow::sortByTitleACK()
{
    ui->noteList->clear();

    QString gr_id;
    if(currentBtn == listBtn[0] || currentBtn == listBtn[1] || currentBtn == listBtn[2]
            || currentBtn == listBtn[3] || currentBtn == listBtn[4] || currentBtn == listBtn[5])
    {
        query.exec("SELECT * FROM groups WHERE name='" + this->currentBtn->text() +  "' and user_id=" + loginedUser.strId + ";");
        query.next();
        gr_id = query.record().value("id").toString();
    }
    else gr_id = "1";
    if(currentBtn == ui->complTasks)
        query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_completed=1 ORDER BY header ASC;");
    else if(currentBtn == ui->impT)
            query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_important=1 and is_completed=0 ORDER BY header ASC;");
        else if(currentBtn == ui->planT)
                query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE planned_date_time IS NOT NULL and is_completed=0 ORDER BY header ASC;");
            else query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE group_id=" + gr_id + " and is_completed=0 ORDER BY header ASC;");

    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());
}

void MainWindow::sortByDateOfCreateDESC()
{
    ui->noteList->clear();

    QString gr_id;
    if(currentBtn == listBtn[0] || currentBtn == listBtn[1] || currentBtn == listBtn[2]
            || currentBtn == listBtn[3] || currentBtn == listBtn[4] || currentBtn == listBtn[5])
    {
        query.exec("SELECT * FROM groups WHERE name='" + this->currentBtn->text() +  "' and user_id=" + loginedUser.strId + ";");
        query.next();
        gr_id = query.record().value("id").toString();
    }
    else gr_id = "1";

    if(currentBtn == ui->complTasks)
        query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_completed=1 ORDER BY id DESC;");
    else if(currentBtn == ui->impT)
            query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_important=1 and is_completed=0 ORDER BY id DESC;");
        else if(currentBtn == ui->planT)
                query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE planned_date_time IS NOT NULL and is_completed=0 ORDER BY id DESC;");
            else query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE group_id=" + gr_id + " and is_completed=0 ORDER BY id DESC;");


    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());
}

void MainWindow::on_removeNote_clicked()
{
    QString content = ui->noteList->currentItem()->text();

    query.exec("DELETE FROM notes_" + loginedUser.strId + " WHERE header='" + content + "';");
    query.next();

    QString gr_id;
    if(currentBtn == listBtn[0] || currentBtn == listBtn[1] || currentBtn == listBtn[2]
            || currentBtn == listBtn[3] || currentBtn == listBtn[4] || currentBtn == listBtn[5])
    {
        query.exec("SELECT * FROM groups WHERE name='" + this->currentBtn->text() +  "' and user_id=" + loginedUser.strId + ";");
        query.next();
        gr_id = query.record().value("id").toString();
    }
    else gr_id = "1";

    if(currentBtn == ui->complTasks)
        query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_completed=1;");
    else if(currentBtn == ui->impT)
            query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE is_important=1 and is_completed=0;");
        else if(currentBtn == ui->planT)
                query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE planned_date_time IS NOT NULL and is_completed=0;");
            else query.exec("SELECT * FROM notes_" + loginedUser.strId + " WHERE group_id=" + gr_id + " and is_completed=0;");


    ui->noteList->clear();

    while(query.next())
        ui->noteList->addItem(query.record().value("header").toString());
}

