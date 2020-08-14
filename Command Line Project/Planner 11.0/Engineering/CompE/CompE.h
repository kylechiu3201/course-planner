#pragma once
#include <iostream>
#include <vector>
#include "../../Course/Course.h"
#include "../Engineering.h"
#include "../../Student/Student.h"

using namespace std;

/**
 * @brief 
 */
class CompE : public Engineering {
private:
    static const int tech_hours;
    static vector<Course>  pos_foundations;   //possible classes to take to fulfill requirements
    static vector<Course>  pos_core;
    static vector<Course>  pos_gen_electives; //includes all of tech elective list
    static vector<Course>  pos_EE_Foundation;
    static vector<Course>  pos_adv_computing;
    static vector<Course>  pos_capstone;

    //contains courses planned/completed
    pair<vector<Course>, int>  foundations; //Math and Science core
    pair<vector<Course>, int>  core;
    pair<vector<Course>, int>  gen_electives; //not EE or adv computing or capstone
    pair<vector<Course>, int>  EE_foundation;
    pair<vector<Course>, int>  adv_computing;
    pair<vector<Course>, int>  capstone; //445 411 496 499

    //sep vectors so that we can check if a category is completed or not, also make functin to return which classes left
public:
    //constructors
    CompE();

    //getters
    static vector<Course> get_pos_foundations();
    static vector<Course> get_pos_core();
    static vector<Course> get_pos_gen_electives();
    static vector<Course> get_pos_EE_Foundation();
    static vector<Course> get_pos_adv_computing();
    static vector<Course> get_pos_capstone();

    pair<vector<Course>, int>* get_foundations();
    pair<vector<Course>, int>* get_core();
    pair<vector<Course>, int>* get_gen_electives();
    pair<vector<Course>, int>* get_EE_foundation();
    pair<vector<Course>, int>* get_adv_computing();
    pair<vector<Course>, int>* get_capstone();

    string get_major_name();

    static void set_pos_foundations(Course c);
    static void set_pos_core(Course c);
    static void set_pos_gen_electives(Course c);
    static void set_pos_EE_Foundation(Course c);
    static void set_pos_adv_computing(Course c);
    static void set_pos_capstone(Course c);

    //other functions
    int get_tech_hours(vector<Course> & EE_foundation, vector<Course> & adv_computing, vector<Course> & gen_electives, vector<Course> & capstone);  //gets tech elective hours
    static bool check_degree(Course c);
    void add_to_degree(Course c);  //if course degree, add to requirement vectors
    bool remove_from_degree(Course c); // remove a course from a category
    static void fill_pos_vec(); //fill the pos_vectors from text file, sort vectors in this function too, this should prob go in database
    void save_deg_vec(Engineering * major); //save the updated degree vectors
    void load_deg_vec(Engineering * major);
    void display_courses(vector<Course> & vec); //displays courses in that category
    static string select_group();
    void is_satisfied(string input);
    void satisfied(string input);
};
