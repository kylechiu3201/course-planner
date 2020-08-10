#include "Course.h"
#include <iostream>
#include <string>


    //constructors
    Course::Course(string maj, int cnum, string n,  int chours, double gpa, string atr)  //for our use to hardcode classes
    {
        major = maj;
        name = n;
        course_num = cnum; 
        avgGPA = gpa;
        credit_hours = chours;
        grade = "NT"; //DEFAULT setting until added from Planner Class
        attribute = atr;
    }
    Course::Course(string maj, int cnum, string n,  int chours, double gpa, string atr, string grade1) //for our use to load classes from save file
    {
        major = maj;
        name = n;
        course_num = cnum; 
        avgGPA = gpa;
        credit_hours = chours;
        attribute = atr;
        grade = grade1;  //grade 
    }
    
    Course::Course()  //empty course
    {
        major = "";
        name = "";
        course_num = 0; 
        avgGPA = 0.0;
        credit_hours = 0;
        grade = "NT"; //DEFAULT setting until added from Planner Class
        attribute = "not";
    }
    
    Course::Course(string maj, int num){
        major = maj;
        name = maj+"_"+std::to_string(num);
        course_num = num;
        avgGPA = 0.0;
        credit_hours = 0.0;
        grade = "NT";
        attribute = "not";
    }
    
    //getters 
    string Course::get_major()
    {
        return major;
    }
    string Course::get_name()
    {
        return name;
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
    string Course::get_attribute()
    {
        return attribute;
    }
    //setters
    void Course:: set_major(string maj)
    {
        major = maj;
    }
    void Course:: set_name(string n)
    {
        name = n;
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
    void Course:: set_attribute(string attr)
    {
        attribute = attr;
    }
    
    //other functions
    
    
    bool Course::operator< (Course & c)  //overloads < to sort courses by major and number
    {
        if(major.compare(c.major) < 0)
        {
            return true;
        }
        else if(major.compare(c.major) == 0)
        {
            if(course_num<c.course_num)
            {
                return true;
            }
        }
        return false;
    }
    bool Course::operator> (Course & c)
    {
        if(major.compare(c.major) > 0)
        {
            return true;
        }
        else if(major.compare(c.major) == 0)
        {
            if(course_num>c.course_num)
            {
                return true;
            }
        }
        return false;
    }
    bool Course::operator== (Course c)
    {
        if(major.compare(c.major) == 0 && course_num == c.course_num)
            return true;
        return false;
    }

    double Course:: get_gpa_value()
    {
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

    //Course object overloads
    ostream& operator <<(ostream& out, const Course& obj)  //overloads << for database class 
    {
      out << obj.major << " " << obj.course_num << " " << obj.name << " " << obj.credit_hours  << " " << obj.avgGPA << " " << obj.attribute << " " << obj.grade << "\n";
         return out;
    }

    istream& operator >>(istream& in, Course& obj)   //overloads >> for database class
    {
        in >> obj.major  >> obj.course_num >> obj.name >> obj.credit_hours  >> obj.avgGPA   >> obj.attribute  >> obj.grade;
        return in;
    }
    
void Course::display(vector<Course> &vec)
{
    for(int i = 0; i < vec.size(); ++i)
    {
        string course = vec[i].major + " " + to_string(vec[i].course_num);
        int len = course.length();
        string space = "           ";
        space = space.substr(0, 8 - len + 5);
        std::cout << course << space << vec[i].name /*<< "\n"*/;
        std::cout << vec[i].credit_hours << " "/*temp*/ << vec[i].avgGPA << "\n";
    }
}