#pragma once
#include "../Engineering/CompE/CompE.h"
#include "../Engineering/Engineering.h"
#include "../Student/Student.h"
#include "../Course/Course.h"

/**
 * @brief
 */
class Database
{
private:
    static vector<Course> list_all;
    static void insertionsort(vector<Course>& arr);
    friend class Course;
public:
    static void change_char(string& s, char repl);
    static void create_db();
    static vector<Course> get_vector();
    static void save_data(Student* student);
    static void load_data(Student* student);
    static vector<Course> search_db(string s, vector<string> thing = {}, double low = 0, double up = 0, int cnum = 0, int crednum = 0);
    static vector<Course> real_search(vector<Course> vec, string key, vector<string> specific);
    static vector<Course> real_search(vector<Course> vec, double low, double up);
    static vector<Course> real_search(vector<Course> vec, string key, int num);
    static Course  find_course(string major, int c_num);
    static Course  bsearch(vector <Course> & a, Course & x);
};
