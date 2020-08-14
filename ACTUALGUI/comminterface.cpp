#include "comminterface.h"
#include "ui_comminterface.h"
#include "Database/Database.h"
#include "Command/Command.h"
#include "Engineering/CompE/CompE.h"
#include "save_pop_up.h"
#include "addpopup.h"
#include "removepopup.h"
#include "mainwindow.h"
#include "Student/Student.h"
#include "changepop.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QHeaderView>
#include <QMessageBox>
#include <QTableWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDebug>

CommInterface::CommInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommInterface)
{
    ui->setupUi(this);
    save_pop_up * pop1 = new save_pop_up();
    connect(ui->pushButton_6, SIGNAL(clicked()), pop1, SLOT(exec()));

    addpop = new AddPopUp();

    connect(ui->pushButton_3, SIGNAL(clicked()), addpop, SLOT(show()));

    removepop = new RemovePopUp();
    connect(ui->pushButton_2, SIGNAL(clicked()), removepop, SLOT(show()));
      ui->stackedWidget->setCurrentIndex(0);
      ui->tableWidget->show();

    changepop = new ChangePop();
    connect(ui->pushButton, SIGNAL(clicked()), changepop, SLOT(show()));

    notepop = new NotePopUp();
    connect(ui->pushButton_4, SIGNAL(clicked()), notepop, SLOT(show()));

    //DEGREE POPUPS


}

AddPopUp* CommInterface::get_pop()
{
    return addpop;
}

RemovePopUp* CommInterface::get_remove_pop()
{
    return removepop;
}

ChangePop * CommInterface::get_change_pop()
{
    return changepop;
}

NotePopUp * CommInterface::get_note_pop()
{
    return notepop;
}

void CommInterface::set_item()
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    newItem = new QTableWidgetItem(QString::fromStdString(Command::get_student()->get_name()).arg(pow(1, 1)));
    ui->tableWidget->setItem(0, 1, newItem);
    newItem = new QTableWidgetItem(QString::fromStdString(Command::get_student()->get_stud_major()->get_major_name()).arg(pow(1, 1)));
    ui->tableWidget->setItem(0, 2, newItem);
    int temp = Command::get_student()->get_start_year();
    int temp1 = Command::get_student()->get_grad_year();
    string year = std::to_string(temp) + "-" + std::to_string(temp1);
    newItem = new QTableWidgetItem(QString::fromStdString(year).arg(pow(1, 1)));
    ui->tableWidget->setItem(0, 3, newItem);
    int tot = Command::get_student()->get_tot_credit();
    string tot1 = std::to_string(tot);
    newItem = new QTableWidgetItem(QString::fromStdString(tot1).arg(pow(1, 1)));
    ui->tableWidget->setItem(0, 4, newItem);
    int cred = Command::get_student()->get_degree_cred();
    string cred1 = std::to_string(cred);
    newItem = new QTableWidgetItem(QString::fromStdString(cred1).arg(pow(1, 1)));
    ui->tableWidget->setItem(0, 5, newItem);
    double gpa = Command::get_student()->get_GPA();
    string gpa1 = std::to_string(gpa);
    newItem = new QTableWidgetItem(QString::fromStdString(gpa1).arg(pow(1, 1)));
    ui->tableWidget->setItem(0, 6, newItem);
}


CommInterface::~CommInterface()
{
    delete ui;
}


void CommInterface::on_pushButton_8_clicked()  //page 0->1
{
    tree_destr();
    tree_load();
    set_item();
    set_eng_table();
    set_deg_table();
    ui->stackedWidget->setCurrentIndex(1);
}

void CommInterface::on_pushButton_7_clicked()  //page 0->2
{
    set_item();
    set_eng_table();
    set_deg_table();
    ui->stackedWidget->setCurrentIndex(2);
}

void CommInterface::on_pushButton_5_clicked()  //save
{
    Database::save_data(Command::get_student());
}



void CommInterface::on_pushButton_9_clicked() //1->0
{
    set_item();
    set_eng_table();
    set_deg_table();
    ui->stackedWidget->setCurrentIndex(0);
}

void CommInterface::on_pushButton_10_clicked() //1=>2
{
    set_item();
    set_eng_table();
    set_deg_table();
    ui->stackedWidget->setCurrentIndex(2);
}


void CommInterface::on_pushButton_11_clicked() //2->1
{
    tree_destr();
    tree_load();
    ui->stackedWidget->setCurrentIndex(1);
}


void CommInterface::on_pushButton_12_clicked() //2->0
{
    ui->stackedWidget->setCurrentIndex(0);
}

void CommInterface::showPopUp(save_pop_up * popup)
{
    popup->show();
}

void CommInterface::tree_destr()
{
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i)
    {
        QTreeWidgetItem* temp = ui->treeWidget->topLevelItem(i);
        while(temp->childCount() > 0)
        {
            QTreeWidgetItem* child = temp->child(0);
            temp->removeChild(child);
            delete(child);
        }
        delete(temp);
    }
    ui->treeWidget->clear();
}

void CommInterface::tree_load()
{
    Student* stud = Command::get_student();
    vector<Semester> vec = stud->get_plan();

    for(int i = 0; i < vec.size(); ++i)
    {
        if(vec[i].get_sem_vec()->size() != 0 || *vec[i].get_note()!="empty_note")
        {
            string semname = vec[i].get_sem_name();
            Database::change_char(semname, ' ');
            QTreeWidgetItem* parent = new QTreeWidgetItem(ui->treeWidget, QStringList() << QString::fromStdString(semname));

            for(int j = 0; j < vec[i].get_sem_vec()->size(); ++j)
            {
                Course temp = vec[i].get_sem_vec()->at(j);
                string course = temp.get_major() + " " + to_string(temp.get_course_num());
                string grade = "Grade: " + temp.get_grade();
                string creds = "Credit Hours: " + to_string(temp.get_credit_hours());
                QTreeWidgetItem* child = new QTreeWidgetItem(parent, QStringList() << QString::fromStdString(course));
                QTreeWidgetItem* gradep = new QTreeWidgetItem(child, QStringList() << QString::fromStdString(grade));
                QTreeWidgetItem* credp = new QTreeWidgetItem(child, QStringList() << QString::fromStdString(creds));
                //child->setExpanded(true);
            }
            if(*vec[i].get_note()!="empty_note")
            {
                string nte = "Notes: " + *(vec[i].get_note());
                QTreeWidgetItem* cnote = new QTreeWidgetItem(parent, QStringList() << QString::fromStdString(nte));
            }
            string tothours = "Total Hours: " + to_string(vec[i].Semester::get_sem_hours());
            QTreeWidgetItem* thour = new QTreeWidgetItem(parent, QStringList() << QString::fromStdString(tothours));
            parent->setExpanded(true);
        }
    }
}

void CommInterface::enterEvent(QEvent* event)
{
    QWidget::enterEvent(event);
    tree_destr();
    tree_load();
}



void CommInterface::set_deg_table()
{
  //set buttons

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vector<string> vec = {"F", "CO", "GE", "EE", "AC", "CA"};
    int cour = -1;
    for(int x = 0 ; x< 2 ; x++) //columns
    {
        for(int y = 0 ; y < vec.size() ; y++)  //rows
        {
            if(x==0) //num needed
            {
                cour = ((CompE*)Command::get_student()->get_stud_major())->satisfied(vec[y]);
            }
            else{  //num left
                cour = ((CompE*)Command::get_student()->get_stud_major())->is_satisfied(vec[y]);
            }
            QString appt = " Courses";
            if(y == 2)
                appt = " Hours";
            newItem = new QTableWidgetItem(QString::number(cour) + appt);
            ui->tableWidget_2->setItem(y, x, newItem);

        }
    }

}
void CommInterface::set_eng_table()
{
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vector<string> vec = {"libed", "humanities", "social", "western", "non-western", "minority", "C"};
    int cour = -1;
    for(int x = 0 ; x< 2 ; x++) //columns
    {
        for(int y = 0 ; y < vec.size() ; y++)  //rows
        {
            if(x==0) //num needed
            {
                if(y==6)
                {
                    cour = ((Engineering*)Command::get_student()->get_stud_major())->satisfied("C");
                }
                else
                {
                cour = ((Engineering*)Command::get_student()->get_stud_major())->satisfied("G",vec[y]);
                }
            }
            else{  //num left
                if(y==6)
                {
                   cour = ((Engineering*)Command::get_student()->get_stud_major())->is_satisfied("C");
                }
                else
                {
                cour = ((Engineering*)Command::get_student()->get_stud_major())->is_satisfied("G",vec[y]);
                }
            }
            QString appt = " Courses";
        if(x == 0 && y == 6)
        {
            if(cour == 0)
                appt = "Not Fulfilled";
            else
                appt = "Fulfilled";
         }
        else if(x == 1 && y == 6)
        {
            if(cour == 0)
                appt = "";
            else
                appt= "";
        }
        if(y == 6)
            newItem = new QTableWidgetItem(appt);
        else
            newItem = new QTableWidgetItem(QString::number(cour) + appt);
            ui->tableWidget_3->setItem(y, x, newItem);

        }
    }

}

