#include "changepop.h"
#include "ui_changepop.h"
#include "Command/Command.h"
#include "Database/Database.h"
#include <QDebug>

ChangePop::ChangePop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePop)
{
    ui->setupUi(this);
    ui->comboBox->addItem("A+");
    ui->comboBox->addItem("A");
    ui->comboBox->addItem("A-");
    ui->comboBox->addItem("B+");
    ui->comboBox->addItem("B");
    ui->comboBox->addItem("B-");
    ui->comboBox->addItem("C+");
    ui->comboBox->addItem("C");
    ui->comboBox->addItem("C-");
    ui->comboBox->addItem("D+");
    ui->comboBox->addItem("D");
    ui->comboBox->addItem("D-");
    ui->comboBox->addItem("F");
    ui->comboBox->addItem("Not Taken Yet");
    ui->comboBox->addItem("In Progress");
    ui->comboBox->addItem("Pass");

    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_8->setVisible(false);

}

ChangePop::~ChangePop()
{
    delete ui;
}



void ChangePop::on_pushButton_clicked()
{
    std::string cour_name = ui->lineEdit->text().toLocal8Bit().constData();
    string numcheck = ui->lineEdit_2->text().toLocal8Bit().constData();
    bool start = false;
    string numtemp = "";
    for(int i = 0; i < numcheck.size(); ++i)
    {
        if(numcheck[i] == ' ' && !start)
            continue;
        if(numcheck[i] == ' ' && start)
            break;
        if(numcheck[i] != ' ')
            start = true;
        numtemp += numcheck[i];
    }
    numcheck = numtemp;
    bool flag = false;
    for(int x = 0; x < numcheck.size(); x++){
        if(!isdigit(numcheck[x])){
            flag = true;
        }
    }
    if(flag){
        ui->label_8->setVisible(true);
        return;
    }
    ui->label_8->setVisible(false);
    int class_num = stoi(numcheck); ///read this as a string and first remove all spaces before and after, then check for only digits

    std::string grade = ui->comboBox->currentText().toLocal8Bit().constData();
    string real_maj = "";
    start = false;
    for(int i = 0; i < cour_name.size(); ++i)
    {
        if(cour_name[i] == ' ' && !start)
            continue;
        if(cour_name[i] == ' ' && start)
            break;
        if(cour_name[i] != ' ')
            start = true;
        real_maj += cour_name[i];
    }
    cour_name = real_maj;
    if(grade=="Not Taken Yet")
    {
        grade = "NT";
    }
    else if(grade =="In Progress")
    {
        grade = "IP";
    }
    else if(grade =="Pass")
    {
        grade = "PS";
    }

       Course c = Database::find_course(cour_name, class_num); //find_course returns Course object
       if(c.get_name()=="")
       {
           return;
           ui->label_7->setVisible(true);
           ui->label_6->setVisible(false);
       }

       if(Command::get_student()->valid_grade(grade))
       {
           QString g = QString::fromStdString(grade);
           qDebug() << g << "\n";
                       c.set_grade(grade);
           Command::get_student()->change_grade(c, grade);
           ui->label_7->setVisible(false);
           ui->label_6->setVisible(true);
           Database::save_data(Command::get_student());
       }
       else
       {
       ui->label_6->setVisible(false);
       ui->label_7->setVisible(true);
       }
}
