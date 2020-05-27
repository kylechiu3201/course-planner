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
void Command::get_command(string command)
{
    //Exits the program
    if(COMP("exit"))
    {
        Command::exit_prog();
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
         Database::save_data();
    }
    else if(COMP("load"))
    {
         Database::load_data();
    }
    else if(COMP("ANS"))
    {
        
    }
    
    
    
    
    //If the given command does not match, then notify user
    else
    {
        cout << "Command not recognized.\n";
    }
}

/*
 Destructs and exits the program
 Input: None
 Output: None
*/
void Command::exit_prog(Student * student)
{
    //call all destructors needed
    Database::save_data();
    delete student;  //deletes student on heap
    exit(0); 
}


void Command::list_commands()
{
    cout << "search -> searches database for class of a specified attribute\n";
    cout << "exit -> saves data and closes program" << "\n";
    cout << "save -> saves data\n" ; 
    cout << "load -> loads data\n" ;
    cout << "ANS -> add new student, WARNING : overwrites current student data \n";
}

void Command::firstAdd(Student * student){
    cout << "Add courses, to leave type 'exit'\n";
    while(true) {
        string exit;
        student->addCourse();
        if(cin >> exit)
        {
            if(exit.compare("exit")==0)
            {
                return;
            } else {
                cout << "Invalid input";
            }

        }

    }
}












