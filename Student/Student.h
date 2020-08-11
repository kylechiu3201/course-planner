#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "../Course/Course.h"
#include "../Engineering/Engineering.h"
#include "../Semester/Semester.h"

using namespace std;

class Student {
private:
    vector<Course> cour_taken;
    vector<Semester> plan;
    int start_year;
    int grad_year;
    Engineering * stud_major; //Engineering class?
    double GPA;
    int tot_credit;
    int degree_cred;
    string name;

public:
    //constructor
    Student (vector<Semester> my_plan, vector<Course> & cour, int syear, int gyear, Engineering* maj, int tcred, int deg, string n);
    Student(Engineering* maj, string n, int syear);
    Student();

    //getters
    double calculateGPA(vector<Course> & cour);
    
    vector<Course> get_cour_taken();

    int get_start_year();
    
    int get_grad_year();

    Engineering * get_stud_major();

    double get_GPA();

    int get_tot_credit();

    int get_degree_cred();
    
    string get_name();
    
    Semester get_sem(int num);
    vector<Semester> get_sem_vec();
    
    //setters
    void set_start_year(int year);
    
    void set_grad_year(int year);

    void set_stud_major(Engineering *  maj);

    void set_tot_credit(int tcred);
    
    void set_degree_cred(int deg);
    
    void set_name(string n);

    //Other Functions
    void addCourse();

    void removeCourse();
    
    static Student* create_new_student(string & name);
    
    int get_cred_needed();
    
    bool valid_grade(string g);
    
    static void display_sem_names(vector<Semester> vec);
    
    int pick_semester(vector<Semester> vec); //returns index of semester

    void stud_sem_name(Student *student);
};