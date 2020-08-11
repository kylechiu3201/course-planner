#include <iostream>
#include "Command.h"
#include "../Database/Database.h"
#include "../Student/Student.h"
#define COMP(comm) command.compare(comm) == 0

using namespace std;

/*
 Interprets and executes a given command
 Input: command to execute
 Output: None
*/
Student* Command::student = NULL;

void Command::init_student(Student* stud)
{
    student = stud;
}

void Command::get_command(string command)
{
    //Exits the program
    if(COMP("exit"))
    {
        Command::exit_prog(student);
        return;
    }
    else if(COMP("list"))
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
    else if(COMP("load"))
    {
         Database::load_data(student);
         CompE::fill_pos_vec();
    }
    else if(COMP("add"))
    {

    }
    else if(COMP("list plans"))
    {

    }
    else if(COMP("open plan"))
    {

    }
    else if(COMP("close plan"))
    {

    }
    
    
    
    //If the given command does not match, then notify user
    else if(command != "")
    {
        cout << "Command not recognized.\n";
    }
}

/*
 Destructs and exits the program
 Input: None
 Output: None
*/
void Command::exit_prog(Student* student)
{
    //call all destructors needed
    Database::save_data(student);
    //deletes student on heap
    exit(0); 
}


void Command::list_commands()
{
    cout << "search ->  searches database for class of a specified attribute\n";
    cout << "exit   ->  saves data and closes program" << "\n";
    cout << "save   ->  saves data\n" ; 
    cout << "load   ->  loads data\n" ;
    cout << "new    ->  add new student, WARNING : overwrites current student data \n";
    cout << "new    ->  adds courses to a student's profile \n";
}


