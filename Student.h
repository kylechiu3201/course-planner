#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Student{
    private:
    vector<Course> cour_taken;
    int cur_year;
    string major; //Major class?
    double avgGPA;
    double tot_credit;
    double cred_needed;
    
    public:
    //constructor
    Student(vector<Course> cour, int year, string maj, double tcred);
    
    //getters
    double calculateGPA(vector<Course> cour);
    vector<Course> get_cour_taken();
    
    int get_cur_year();
    
    string get_major();
    
    double get_avgGPA();
    
    double get_tot_credit();
    
    double get_cred_needed();
    
    //setters
    void set_cur_year(int year);
    
    void set_major(string maj);
    
    void set_tot_credit(double tcred);
    
    void addCourse();
    
    void removeCourse();
    
    //calculate calculateGPA
    double calculateGPA();
    
};