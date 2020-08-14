#include <iostream>
#include <bits/ios_base.h>
#include <fstream>
#include "Command.h"
#include "../Database/Database.h"
#include "../Student/Student.h"
#define COMP(comm) command.compare(comm) == 0

using namespace std;

//A static Student object pointer that points to the Student object being used so that Command has access to that Student object
Student* Command::student = NULL;

/**
 * @brief Sets the static Student object pointer to the given parameter so that the Command class has access to the Student object being used
 *
 * @param stud A pointer to the Student object that's currently being used
 */
void Command::init_student(Student* stud)
{
    student = stud;
}

/**
 * @brief Reads a command from the user and executes it
 *
 * @param command The command to execute
 */
void Command::get_command(string command)
{
    //Exits the program
    if(COMP("exit"))
    {
        Command::exit_prog(student);
        return;
    }
    else if(COMP("help") || COMP("list"))
    {
        Command::list_commands();
        return;
    }
    else if(COMP("search"))
    {
        Database::search_db();
        return;
    }
    else if(COMP("save"))
    {
         Database::save_data(student);
    }
    else if(COMP("add"))
    {
        student->addCourse();
        getchar();
    }
    else if(COMP("plan"))
    {
        Student::display_plan(student->get_plan());
    }
    else if(COMP("info"))  //display student info
    {
        student->display_info();
    }
    else if(COMP("possible")) //course options not taken
    {
        string input;
        input = CompE::select_group();
        ((CompE*)student->get_stud_major())->is_satisfied(input);
        getchar();
    }
    else if(COMP("degree fulfilled")) //fulfilled course categories
    {
        string input;
        input = CompE::select_group();
        ((CompE*)student->get_stud_major())->satisfied(input);
        getchar();
    }
    else if(COMP("degree course group")) //displays both fulfilled and not taken courses in same group
    {
        string input;
        input = CompE::select_group();
        ((CompE*)student->get_stud_major())->satisfied(input);
        cout << "\n";
        ((CompE*)student->get_stud_major())->is_satisfied(input);
        getchar();
    }
    else if(COMP("ENG fulfilled"))
    {
        string input;
        input = Engineering::select_group();
        getchar();
        string gened = "";
        if(input == "G")
        {
            cout << "\nPick a general education category: libed, humanities, social, western, non-western, minority:\n";
            getline(cin, gened);
        }
        cout << "\n";
        student->get_stud_major()->Engineering::satisfied(input, gened);
    }
    else if(COMP("ENG possible"))
    {
        string input;
        input = Engineering::select_group();
        getchar();
        string gened = "";
        if(input == "G")
        {
            cout << "\nPick a general education category: libed, humanities, social, western, non-western, minority:\n";
            getline(cin, gened);
        }
        cout << "\n";
        student->get_stud_major()->Engineering::is_satisfied(input, gened);
    }
    else if (COMP("ENG course group"))
    {
        string input;
        input = Engineering::select_group();
        getchar();
        string gened = "";
        if(input == "G")
        {
            cout << "\nPick a general education category: libed, humanities, social, western, non-western, minority:\n";
            getline(cin, gened);
        }
        cout << "\n";
        student->get_stud_major()->Engineering::satisfied(input, gened);
        cout << "\n";
        student->get_stud_major()->Engineering::is_satisfied(input, gened);
    }
    else if(COMP("add note"))
    {
        cout << "\nWhich semester would you like to add the note to?\n";
        student->display_sem_names(student->get_plan());
        cout << "\n";
        int index = student->pick_semester(student->get_plan());
        student->get_sem(index+1)->set_note();
    }
    else if(COMP("display note"))
    {
        cout << "\nWhich semester would you like to display the note from?\n";
        student->display_sem_names(student->get_plan());
        cout << "\n";
        int index = student->pick_semester(student->get_plan());
        student->get_sem(index+1)->display_note();
    }
    else if(COMP("reset"))
    {
        cout << "\nAre you sure you want to reset student info? (y/n): ";
        string s;
        getline(cin, s);
        if(tolower(s[0]) == 'y')
        {
            ifstream file1("student_data.txt", ifstream::in|ifstream::trunc);
            ifstream file2("student_degree_data.txt", ifstream::in|ifstream::trunc);
            ifstream file3("student_eng_data.txt", ifstream::in|ifstream::trunc);
            file1.close();
            file2.close();
            file3.close();
            ofstream new_file("student_data.txt", ofstream::out);
            string major_name;
            cout << "\n";
            Student* stud = Student::create_new_student(major_name);
            new_file << "0" << "\n" << stud->get_name() << "\n" << major_name <<
                     "\n" <<stud->get_start_year() << "\n" << stud->get_start_year()+4 << "\n" << "0" << "\n" << "0" << "\n" ; //write student data to file (num_courses, courses, name, major, start, grad, total, degree)
            init_student(stud);
        }
    }
    else if(COMP("change grade"))
    {
        int class_num;
        string course;
        string grade;
        //FUNCTION TO DISPLAY COUR_TAKEN
        cout << "\nChoose course to change grade , Format: 'Major CourseNum'" << endl;
        cin >> course >> class_num;

        //add function to find corresponding course in database
        Course c = Database::find_course(course, class_num); //find_course returns Course() object
        while(c.get_name()== "")
        {
            cout << "Course not found. Please try again";
            cout << "\nChoose course to change grade , Format: 'Major CourseNum'" << endl;
            cin >> course >> class_num;
            c = Database::find_course(course, class_num);
        }

        cout << "Change grade, ex. 'A+' \n Type IP if in progress, PS for passing credit w/o grade, or NT if not taken yet" << "\n";
        cin >> grade;
        if(student->valid_grade(grade))
        {
            c.set_grade(grade);
            student->change_grade(c, grade);
        }
        while(!student->valid_grade(grade)) 
        {
            cout << "Please enter a valid grade";
            cin >> grade;
            if(student->valid_grade(grade))
            {
                c.set_grade(grade);
                student->change_grade(c, grade);
            }
        }
    }
    else if (COMP("remove"))
    {
        student->removeCourse();
        getchar();
    }



    //If the given command does not match, then notify user
    else if(command != "")
    {
        cout << "Command not recognized.\n";
    }
}

/**
 * @brief Saves and exits the program
 *
 * @param student A pointer to the Student object that's being saved
 */
void Command::exit_prog(Student* student)
{
    //TODO: destructors?
    //call all destructors needed
    Database::save_data(student);
    //deletes student on heap
    exit(0); 
}

//TODO: change list stuff
/**
 * @brief Displays a list of possible commands to choose from 
 */
void Command::list_commands()
{
    cout << "\n";
    cout << "search               ->  searches database for class of a specified attribute\n";
    cout << "exit                 ->  saves data and closes program" << "\n";
    cout << "save                 ->  saves data\n" ;
    cout << "load                 ->  loads data\n" ;
    cout << "new                  ->  add new student, WARNING : overwrites current student data \n"; //NOT IMPLEMENTED YET
    cout << "add                  ->  adds courses to a student's profile\n";
    cout << "plan                 ->  display courses information for each semester\n";
    cout << "possible             ->  displays courses that have not yet been taken that can be taken to fulfill a requirement\n";
    cout << "degree fulfilled     ->  displays courses that have been added that fulfill a DEGREE specific requirement\n";
    cout << "degree course group  ->  displays both courses taken and courses that can be taken that fulfill a DEGREE specific requirement\n";
    cout << "ENG fulfilled        ->  displays courses that have been added that fulfill a general Engineering requirement\n";
    cout << "ENG course group     ->  displays both courses taken and courses that can be taken that fulfill a general Engineering requirement\n";
    cout << "info                 ->  view student information, displays: Name, Major, Year, Total Credit Hours, Degree Credit Hours, Overall GPA\n";
    cout << "add note             ->  add note to semester\n";
    cout << "display note         ->  display note from semester\n";
    cout << "change grade         -> change course grade";
}