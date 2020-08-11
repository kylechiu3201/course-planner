#pragma once
#include "../Course/Course.h"
#include <vector>

class Semester
{
private:
    int sem_hours;
    string sem_name;
    pair<vector<Course>, string> sem_vec;



public:

    //Constructor(s)
    Semester();

    //getters
    int get_sem_hours();
    string get_sem_name();
    vector<Course> get_sem_vec();
    string * get_note();


    //setters
    void set_note();
    void set_sem_hours(int hour);
    void set_note_load(string note);
    void set_sem_name(string name);

    bool valid_sem(Course c); //checks if semester has correct hours or not
    static void set_sem();
    void add_sem();
    void add_hours(int hours);
    

};