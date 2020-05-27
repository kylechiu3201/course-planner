#pragma once
#include "../Engineering/CompE/CompE.h"
#include "../Engineering/Engineering.h"
#include "../Student/Student.h"
#include "../Course/Course.h"

class Database
{
private:
    static vector<Course> list_all;
    friend class Course;
public:
    static void create_db();
    static vector<Course> get_vector();
    static void save_data();
    static void load_data();
    static void search_db();
    static vector<Course> real_search(vector<Course> vec, string key, string specific);
    static vector<Course> real_search(vector<Course> vec, double low, double up);
    static vector<Course> real_search(vector<Course> vec, string key, int num);
    static Course * find_course(string major, int c_num);
    static Course * bsearch(vector <Course> & a, Course & x);
};