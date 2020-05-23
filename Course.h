#pragma once
#include <algorithm>
#include <iostream>

using namespace std;
class Course{
    friend ostream& operator <<(ostream& out, const Course& obj);
    friend istream& operator >>(istream& in, Course& obj);
    private:
    string major;  //ECE or CS     change this to object??
    int course_num;
    //string isCrossListed; not sure if we are doing this
    double avgGPA;  //add more GPA values? technical/college etc.
    int credit_hours;
    string grade; 
    string attribute;
    public:
    //constructors
    Course(string maj, int cnum, int gpa, int chours);
    Course(string maj, int cnum, int gpa, int chours, string atr);
    Course(string maj, int cnum, int gpa, int chours, string atr, int grade1);
    Course();
    
     //getters
    string get_major();
   
    int get_course_num();
   
    double get_avgGPA();
   
    int get_credit_hours();
    
    string get_grade();
    
    double get_grade_value();
    
    double get_attribute();
    
    //setters
    void set_major(string maj);
  
    void set_course_num(int num);
    
    void set_avgGPA(double gpa);
   
    void set_credit_hours(int hours);
   
    void set_grade(string g);
    
    void set_attribute();
    
    bool operator< (Course & c);
};