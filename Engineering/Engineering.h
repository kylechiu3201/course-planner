#pragma once
#include <iostream>
#include <vector>
#include "../Course/Course.h"

//Class contains general courses overlapping between ECE and CS 
class Engineering{   //make class abstract??? Do we need to create this?
    protected:
    
    static const int req_hours; //interacts with Student Class
    vector <Course> geneds;
    vector <Course> language;
    vector <Course> physics; //211 and 212
    vector <Course>adv_comp;
    vector <Course> misc; //ENG 100
    
    public:
    vector<Course> get_geneds();
    
};