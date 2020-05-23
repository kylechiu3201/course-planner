#include <iostream>
#include "Course/Course.h"
#include "Engineering/Engineering.h"
#include "Engineering/CompE/CompE.h"
#include "Student/Student.h"
#include "Database/Database.h"
#include "Command/Command.h"
#include <string>

using namespace std;

int main()
{
    cout << "Enter a command:\n";
    //add courses in here?
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    Course temp;
    Database * data = new Database();
    data->create_db();
        cout << "Enter a command:\n";
        string command;
        getline(cin, command);
        Command::get_command(command);
    //Command class will destruct and exit program
    return 0;
}