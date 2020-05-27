#pragma once
#include <string>
#include <Student.h>
class Command
{
public:
    static void get_command(std::string command);
    static void exit_prog(Student * student);
    static void list_commands();
    static void firstAdd(Student * student);
};