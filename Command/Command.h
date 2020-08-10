#pragma once
#include <string>
#include "../Student/Student.h"
class Command
{
    static Student* student;
public:
    static void init_student(Student* stud);
    static void get_command(std::string command);
    static void exit_prog();
    static void list_commands();
    static void create_student();
};