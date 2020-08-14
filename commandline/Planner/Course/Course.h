#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Course class that holds all course information and associated methods
 */
class Course{
    //friend overload functions for Database class
    friend ostream& operator <<(ostream& out, const Course& obj);
    friend istream& operator >>(istream& in, Course& obj);
    
    private:
    string major;  //ECE or CS   
    string name;
    int course_num;
    //string isCrossListed; not sure if we are doing this
    double avgGPA;  //add more GPA values? technical/college etc.
    int credit_hours;
    string grade; 
    string attribute;
    public:
    //constructors
    Course(string maj, int cnum, string n,  int chours, double gpa, string atr);
    Course(string maj, int cnum, string n, int chours, double gpa, string atr, string grade1);
    Course();
    Course(string maj, int num);
    
     //getters
    string get_major();
    string get_name();
    int get_course_num();
    double get_avgGPA();
    int get_credit_hours();
    string get_grade();
    string get_attribute();
    
    //setters
    void set_major(string maj);
    void set_name(string n);
    void set_course_num(int num);
    void set_avgGPA(double gpa);
    void set_credit_hours(int hours);
    void set_grade(string g);
    void set_attribute(string attr);
    
    //other functions
    bool operator< (Course & c);
    bool operator >(Course & c);
    bool operator== (Course c);
    double get_gpa_value();
    static void display(vector<Course> &vec);
};

