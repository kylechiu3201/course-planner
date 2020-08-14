#include "addpopup.h"
#include "ui_addpopup.h"
#include <QLineEdit>
#include "Course/Course.h"
#include "Database/Database.h"
#include "Student/Student.h"
#include "Command/Command.h"
#include "PopSearch.h"

AddPopUp::AddPopUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPopUp)
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

    sch = new PopSearch();
    connect(ui->pushButton_3, SIGNAL(clicked()), sch, SLOT(show()));
}

AddPopUp::~AddPopUp()
{
    delete ui;
}

void AddPopUp::set_up()
{
    for(int x = 0 ; x< (int)Command::get_student()->get_plan().size() ; x++)
    {
        string temp = Command::get_student()->get_plan().at(x).get_sem_name();
        Database::change_char(temp, ' ');
        ui->comboBox_2->addItem(QString::fromStdString(temp));
    }
}


void AddPopUp::on_pushButton_clicked()
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
     //I put in code earlier where basically I used a bool to keep track of things, so I iterate through the string until .   oh my bad yeh go ahead copy
     std::string grade = ui->comboBox->currentText().toLocal8Bit().constData();
     std::string semester = ui->comboBox_2->currentText().toLocal8Bit().constData();
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

    if(Command::get_student()->addCourse(cour_name, class_num, grade, semester))
    {
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

void AddPopUp::on_pushButton_2_clicked()
{
    this->close();
}
