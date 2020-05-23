#include "Course.h"
#include <iostream>
#include <string>


    //constructors
    Course::Course(string maj, int cnum, int gpa, int chours, string atr)  //for our use to hardcode classes
    {
        major = maj;
        course_num = cnum; 
        avgGPA = gpa;
        credit_hours = chours;
        grade = "NT"; //DEFAULT setting until added from Planner Class
        attribute = atr;
    }
    Course::Course(string maj, int cnum, int gpa, int chours, string atr, int grade1) //for our use to load classes from save file
    {
        major = maj;
        course_num = cnum; 
        avgGPA = gpa;
        credit_hours = chours;
        attribute = atr;
        grade = grade1;  //grade 
    }
    
    Course::Course()  //empty course
    {
        major = "";
        course_num = 0; 
        avgGPA = 0.0;
        credit_hours = 0;
        grade = "NT"; //DEFAULT setting until added from Planner Class
        attribute = "not";
    }
    
    //getters 
   string Course::get_major()
    {
        return major;
    }

    int Course::get_course_num()
    {
        return course_num;
    }
    double Course:: get_avgGPA()
    {
        return avgGPA;
    }
int Course::get_credit_hours()
    {
        return credit_hours;
    }
    string Course:: get_grade(){
        return grade;
    }
    double Course:: get_grade_value(){
        if(grade.compare("A+") == 0){
            return 4.0;
        }
        if(grade.compare("A") == 0){
            return 4.0;
        }
        if(grade.compare("A-") == 0){
            return 3.67;
        }
        if(grade.compare("B+") == 0){
            return 3.33;
        }
        if(grade.compare("B") == 0){
            return 3.0;
        }
        if(grade.compare("B-") == 0){
            return 2.67;
        }
        if(grade.compare("C+") == 0){
            return 2.33;
        }
        if(grade.compare("C") == 0){
            return 2.0;
        }
        if(grade.compare("C-") == 0){
            return 1.67;
        }
        if(grade.compare("D+") == 0){
            return 1.33;
        }
        if(grade.compare("D") == 0){
            return 1.0;
        }
        if(grade.compare("D-") == 0){
            return 0.67;
        }
        return 0.0;
    }
    //setters
    void Course:: set_major(string maj)
    {
        major = maj;
    }
    void Course:: set_course_num(int num)
    {
        course_num = num;
    }
    void Course:: set_avgGPA(double gpa)
    {
        avgGPA = gpa;
    }
    void Course:: set_credit_hours(int hours)
    {
        credit_hours = hours;
    }
    void Course:: set_grade(string g)
    {
        grade = g;
    }
    bool Course:: operator< (Course & c)
    {
        if(major.compare(c.major) <0)
        {
            return true;
        }
        else if(major.compare(c.major) ==0)
        {
            if(course_num<c.course_num)
            {
                return true;
            }
        }
        return false;
    }



ostream& operator <<(ostream& out, const Course& obj)
{
    out << obj.major << " " << obj.course_num << " " << obj.avgGPA << " " << obj.credit_hours << " " << obj.attribute << " " << obj.grade ;
    return out;
}

istream& operator >>(istream& in, Course& obj)
{
    in >> obj.major  >> obj.course_num  >> obj.avgGPA  >> obj.credit_hours  >> obj.attribute  >> obj.grade ;
    return in;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    