#include "../Course/Course.h"
#include "Database.h"
#include <fstream>
#include <string>
#include <stdlib.h>

//vector onto heap, return pointer
//destructor at main();
Database::Database()
{
    list_all = new vector<Course>;
}

void Database::create_db()
{
    ifstream file;
    file.open("course_database.txt", ios::in);

    if(file.fail())
    {
        std::cout << "Error: course_database.txt not found.";
        exit(EXIT_FAILURE);
        return;
    }

    while(file.good())
    {
        //Major CourseNum avgGPA creditHours AttributeString
        Course temp;
        file >> temp;
        list_all->push_back(temp);
    }
    file.close();
}

vector<Course> * Database::get_vec_ptr()
{
    return list_all;
}


void Database::save_data()
{
    //ofstream save_file ("course_data_save.txt", ofstream::out);
    //save_file << courseobj
}

void Database::load_data()
{
    /*string maj, int cnum, int gpa, int chours, string atr, int grade1*/
    //ifstream load_file ("course_data_save.txt", ifstream::in);   
}