#include <iostream>
#include <stdlib.h>
#include "Command.h"

using namespace std;

/*
 Interprets and executes a given command
 Input: command to execute
 Output: None
*/
void Command::get_command(string command)
{
    //Exits the program
    if(command.compare("exit") == 0)
    {
        Command::exit_prog();
        return;
    }
        //If the given command does not match, then notify user
    else
    {
        cout << "Command not recognized.\n";
    }
}

/*

*/
void Command::exit_prog()
{
    //call all destructors needed
    exit(0);
}