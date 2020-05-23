#pragma once
#include "../Engineering/CompE/CompE.h"
#include "../Engineering/Engineering.h"
#include "../Student/Student.h"
#include "../Course/Course.h"

class Database
{
private:
    vector<Course> * list_all;
    friend class Course;
public:
    Database();
    void create_db();
    vector<Course> * get_vec_ptr();
    int search_db(Course look);
    void save_data();
    void load_data();
};