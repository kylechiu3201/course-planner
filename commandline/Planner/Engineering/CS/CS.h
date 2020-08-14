#pragma once
#include <iostream>
#include <vector>
#include "../../Course/Course.h"
#include "../Engineering.h"

using namespace std;

class CS : public Engineering {
    
    private:    
    
    static vector<Course> pos_cs_foundations;   //possible classes to take to fulfill requirements
    static vector<Course> pos_cs_core;  //CS core + CS 210
    static vector<Course> pos_cs_adv_electives; //400-level course in any area
    static vector<Course> pos_cs_gen_electives; //Leftover electives
    static vector<Course> pos_cs_other_tech; //Leftover tech electives

    //Departmental Electives
    static vector<Course> pos_cs_team_proj;    //team project
    static vector<Course> pos_cs_software_foundation;  //software foundations
    static vector<Course> pos_cs_alg;  //Algorithms and Models of Computation:
    static vector<Course> pos_cs_data; //Intelligence and Big Data
    static vector<Course> pos_cs_social; //Human and Social Impact
    static vector<Course> pos_cs_media; //Media
    static vector<Course> pos_cs_perfcomp; //Scientific, Parallel, and High Perfomance Computing
    static vector<Course> pos_cs_sec;  //Distributed Systems, Networking, and Security
    static vector<Course> pos_cs_mach; //Machines
    
    //contains courses planned/completed
    vector<Course> foundations = vector<Course>(10); //Math and Science core
    vector<Course> core = vector<Course>(11);
    vector<Course> gen_electives; //not EE or adv computing or capstone
    vector<Course> dpt_electives = vector<Course>(3); //Pick 3 from one department
    vector<Course> cs_adv_electives = vector<Course>(2); //400-level from any area
    vector<Course> team_proj = vector<Course>(1);
    vector<Course> other_tech = vector<Course>(2); //leftover tech electives
    
    public:
    //getters
    static vector<Course> get_pos_cs_foundations();
    static vector<Course> get_pos_cs_core();
    static vector<Course> get_pos_cs_dpt_electives();
    static vector<Course> get_pos_cs_adv_electives();
    static vector<Course> get_pos_cs_gen_electives();
    static vector<Course> get_pos_cs_other_tech();

    static vector<Course> get_pos_cs_team_proj();
    static vector<Course> get_pos_cs_software_foundation();
    static vector<Course> get_pos_cs_alg();
    static vector<Course> get_pos_cs_data();
    static vector<Course> get_pos_cs_social();
    static vector<Course> get_pos_cs_media();
    static vector<Course> get_pos_cs_perfcomp();
    static vector<Course> get_pos_cs_sec();
    static vector<Course> get_pos_cs_mach();
    
    vector<Course> get_foundations();
    vector<Course> get_core();
    vector<Course> get_gen_electives();
    vector<Course> get_dpt_electives();
    vector<Course> get_cs_adv_electives();
    vector<Course> get_team_proj();
    vector<Course> get_other_tech();
    
    //sep vectors so that we can check if a category is completed or not, also make functin to return which classes left
    
    CS();
    int get_cs_tech_hours(vector<Course> & dpt_electives, vector<Course> & cs_adv_electives, vector<Course> & other_tech, vector<Course> & team_proj, vector<Course> & gen_electives);
    void add_cs_to_degree(Course c, Engineering * major); //if course degree, add to requirement vectors
    static bool check_cs_degree(Course c);
    //void fill_cs_pos_vec();  //fill the pos_vectors from text file, sort vectors in this function too, this should prob go in database
    bool check_same_dpt(); //checks if the dpt electives taken are from the same dpt
    string is_dpt(Course c); //checks if course is one of the dpts, returns the name of dpt, "none" if it is not a dpt
};