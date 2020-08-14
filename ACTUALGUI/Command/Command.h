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
    static void get_command(std::string command, std::string s = "", std::string course = "", int class_num = 0, std::string grade = "", std::string sgroup = "", std::string gened = "", std::string semester = "", std::string note = "");
    static void exit_prog(Student* student);
    static void list_commands();
    static void create_student();
    static Student * get_student();
};
