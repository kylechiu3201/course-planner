#pragma once
#include <iostream>
#include <vector>
#include "../../Course/Course.h"
#include "../Engineering.h"

using namespace std;

class CompE : public Engineering {
    private:    
    const int total_hours = 128;
    vector<Course> pos_foundations;   //possible classes to take to fulfill requirements
    vector<Course> pos_core;
    vector<Course> pos_gen_electives;
    vector<Course> pos_EE_Foundation;
    vector<Course> pos_adv_computing;
    vector<Course> pos_capstone;
    
    //contains courses planned/taken
    vector<Course> foundations = vector<Course>(10); //Math and Science core
    vector<Course> core = vector<Course>(10);
    vector<Course> gen_electives; //no cap or found
    vector<Course> EE_foundation = vector<Course>(1);
    vector<Course> adv_computing = vector<Course>(3);
    vector<Course> capstone = vector<Course>(1); //445 411 496
    
    //sep vectors so that we can check if a category is completed or not, also make functin to return which classes left
    public:
    int get_tech_hours(vector<Course> EE_foundation, vector<Course> adv_computing, vector<Course> gen_electives, vector<Course> capstone);
    
};