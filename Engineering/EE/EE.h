#pragma once
#include <iostream>
#include <vector>
#include "../../Course/Course.h"
#include "../Engineering.h"

using namespace std;

class EE: public Engineering
{
private:
    static vector<Course> pos_foundations;
    static vector<Course> pos_core;
    static vector<Course> pos_gen_electives;
    static vector<Course> pos_adv_ECE;
    static vector<Course> pos_ECE_labs;
    
    vector<Course> foundations = Vector<Course>(10);
    vector<Course> core = vector<Course>(9);
    vector<Course> gen_electives;
    vector<Course> adv_ECE = vector<Course>(3);
    vector<Course> ECE_labs = vector<Course>(3);
public:
    static vector<Course> get_pos_foundations();
    static vector<Course> get_pos_core();
    static vector<Course> get_pos_gen_electives();
    static vector<Course> get_pos_adv_ECE();
    static vector<Course> get_pos_ECE_labs();
    
    vector<Course> get_foundations();
    vector<Course> get_core();
    vector<Course> get_gen_electives();
    vector<Course> get_adv_ECE();
    vector<Course> get_ECE_labs();
    
    //32 tech hours needed
    
    int get_tech_hours(vector<Course> & adv_ECE, vector<Course> & adv_computing, vector<Course> & gen_electives, vector<Course> & ECE_labs);  //gets tech elective hours
    static bool check_degree(Course c);
    void add_to_degree(Course c, Engineering * major);  //if course degree, add to requirement vectors
    static void fill_pos_vec();  //fill the pos_vectors from text file, sort vectors in this function too, this should prob go in database
}

