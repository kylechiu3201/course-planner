#include <iostream>
#include <fstream>
#include <string>
#include "Course/Course.h"
#include "Engineering/Engineering.h"
#include "Engineering/CompE/CompE.h"
#include "Student/Student.h"
#include "Database/Database.h"
#include "Command/Command.h"

using namespace std;

int main()
{
    Database::create_db();
    ifstream check;
    check.open("student_data.txt", ifstream::in);
    Student * student = NULL;
    if(check.fail())
    {
        ofstream new_file("student_data.txt", ofstream::out);
        string major_name = "";
        student = Student::create_new_student(major_name);
        new_file << "0" << "\n" << student->get_name() << "\n" << major_name << 
        "\n" <<student->get_start_year() << "\n" << student->get_start_year()+4 << "\n" << "0" << "\n" << "0" << "\n" ; //write student data to file (num_courses, courses, name, major, start, grad, total, degree)
    }
    else
    {
        student = new Student();
        load_data(student);//load student function
    }
    Command::init_student(student);

    while(true)
    {
        cout << "Enter a command:\n";
        string command;
        getline(cin, command);
        Command::get_command(command);
        cout << "\n";
    }
    //Command class will destruct and exit program
    return 0;
}