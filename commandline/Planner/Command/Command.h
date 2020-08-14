#pragma once
#include <string>
#include "../Student/Student.h"

/**
 * @brief Displays a list of possible commands to choose from 
 */
class Command
{
private:
    static Student* student;
public:
    static void init_student(Student* stud);
    static void get_command(std::string command);
    static void exit_prog(Student* student);
    static void list_commands();
    static void create_student();
};