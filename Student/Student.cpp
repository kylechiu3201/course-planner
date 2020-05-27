#include "../Course/Course.h"
#include "../Engineering/CompE/CompE.h"
#include "../Engineering/Engineering.h"
#include "../Student/Student.h"
#include "../Database/Database.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
//constructors
Student::Student(vector<Course> & cour, int syear, int gyear, Engineering maj, int tcred, int deg, string n){
    cour_taken = cour;
    strt_year = syear;
    grad_year = gyear;
   //change this to Major object instead of string
    stud_major = maj;
    GPA = calculateGPA(cour);
    tot_credit = tcred;
    degree_cred = deg;
    name = n;
}

Student::Student(Engineering maj, string n, int syear){
    int strt_year = syear;
    int grad_year = 0;
    stud_major = maj;
    name = n;
    GPA = 0;
    tot_credit = 0;
    degree_cred = 0;
    
}

double Student::calculateGPA(vector<Course> & cour) {
    double result = 0.0;
    double complete = 0.0;
    for(int i = 0; i<cour.size(); i++){
        result += cour[i].get_gpa_value();
        if(cour[i].get_grade().compare("NT") != 0 || cour[i].get_grade().compare("IP") != 0 || cour[i].get_grade().compare("PS") != 0){
            complete += 1.0;
        }
    }
    if(complete != 0.0){
        result = result/complete;
        return result;
    }
    return 0.0;
}

//getters
vector<Course> Student::get_cour_taken(){
    return cour_taken;
}

int Student::get_strt_year(){
    return strt_year;
}

int Student::get_grad_year(){
    return grad_year;
}

Engineering Student::get_stud_major(){
    return stud_major;
}

double Student::get_GPA(){
    return GPA;
}

int Student::get_tot_credit(){
    return tot_credit;
}

int Student::get_cred_needed(){
    return Engineering::get_tot_hours()-degree_cred;;
}

int Student::get_degree_cred(){
    return degree_cred;
}

string Student::get_name(){
    return name;
}

//setters
void Student::set_strt_year(int year){
    strt_year = year;
}

void Student::set_grad_year(int year){
    grad_year = year;
}

void Student::set_stud_major(Engineering maj){
    stud_major = maj;
}

void Student::set_tot_credit(int tcred){
    tot_credit = tcred;
}

void Student::set_degree_cred(int deg)
{
    degree_cred = deg;
}

void Student::set_name(string n){
    name = n;
}


void Student::addCourse(Engineering * major){
    int class_num;
    string course;
    string grade;
    
    cout << "Add Course, Format: 'Major_CourseNum'" << endl;
    cin >> course >> class_num;
    
    //add function to find corresponding course in database
    Course * c = Database::find_course(course, class_num);
    if(c==NULL)  //c is pointer lul
    {
        cout << "Course not found. Type 'add' to try again\n";
        return;
    }
    
    for(int i = 0; i<cour_taken.size(); i++){   //checks if course is already taken
        if(cour_taken[i].get_major().compare(c->get_major())==0 && cour_taken[i].get_course_num()==c->get_course_num()){ //compare courses
            cout << "Course already taken. Type 'add' to try again\n";
            return;
        }
    }
    cout << "Add a grade, ex. 'A+' \n Press ENTER if in progress or type PS for passing credit w/o grade" << "\n";
    cin >> grade;
    if(valid_grade(grade)){
        if(grade.compare("\n") == 0){
            c.set_grade("IP");
        }
        else{
            c.set_grade(grade);
        }
    }
    else{
        cout << "\nInvalid grade. Type 'add' to try again"
        return;
    }
    
     if(check_degree(&c))
     {
         degree_cred += c.get_credit_hours();
         add_to_degree(c,major);
     }
    cour_taken.push_back(c);
    tot_credit += c.get_credit_hours(); //we need to define if course is degree cred
    GPA = calculateGPA(cour_taken);
} 

void Student::removeCourse(){
    string course;
    int class_num;
    Course c;
    cout << "Remove Course, Format: 'Major_CourseNum'" << endl;
    cin >> course >> class_num ;
    
    Course c = Course(course, class_num);
    
    for(int i = 0; i<cour_taken.size(); i++){
        if(cour_taken.at(i).get_major().compare(c.get_major())==0 && cour_taken.at(i).get_course_num()==c.get_course_num()){ //compare courses
            if(CompE::check_degree(c)){
                degree_cred -= c.get_credit_hours();
            }
            tot_credit -= cour_taken.at(i).get_credit_hours(); //We need to define if course is degree cred
            cour_taken.pop_back(c);
        }
    }
    GPA = calculateGPA(cour_taken);
}
 
 
 Student * Student::create_new_student()
 {
    string user_name;
    string major;
    int start_year;
    
    std::cout << "Type your major: ";
    
    std::cin >> major ;
    Engineering * m = choose_major(major);
    while(m == NULL)
    {
        std::cout << "Type your major: ";
        m = choose_major(major);
    }
    cout << "Type your name: ";
    cin >> user_name ;
    cout << "Type enrollment year: ";
    cin >> start_year ;
    
    Student * student = new Student(m, user_name, start_year);
    
    return student;  
 }
 
 bool Student::valid_grade(string g){ //check to see if string is a valid grade
     if(grade.compare("A+") == 0){
            return true;
        }
        if(grade.compare("A") == 0){
            return true;
        }
        if(grade.compare("A-") == 0){
            return true;
        }
        if(grade.compare("B+") == 0){
            return true;
        }
        if(grade.compare("B") == 0){
            return true;
        }
        if(grade.compare("B-") == 0){
            return true;
        }
        if(grade.compare("C+") == 0){
            return true;
        }
        if(grade.compare("C") == 0){
            return true;
        }
        if(grade.compare("C-") == 0){
            return true;
        }
        if(grade.compare("D+") == 0){
            return true;
        }
        if(grade.compare("D") == 0){
            return true;
        }
        if(grade.compare("D-") == 0){
            return true;
        }
        if(grade.compare("F") == 0){
            return true;
        }
        if(grade.compare("PS") == 0){
            return true;
        }
        if(grade.compare("\n") == 0){
            return true;
        }
        return false;
    }
 

 
 
 