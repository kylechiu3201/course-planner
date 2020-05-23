#include "../Course/Course.h"
#include "../Engineering/CompE/CompE.h"
#include "../Engineering/Engineering.h"
#include "../Student/Student.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//constructors
Student::Student(vector<Course> cour, int year, string maj, double tcred){
    cour_taken = cour;
    cur_year = year;
    major = maj;
    avgGPA = calculateGPA(cour);
    tot_credit = tcred;
    cred_needed = 128-tcred;
}

double Student::calculateGPA(vector<Course> cour){
    double result = 0.0;
    double complete = 0.0;
    for(int i = 0; i<cour.size(); i++){
        result += cour.at(i).get_grade_value();
        if(cour.at(i).get_grade().compare("NT") != 0 || cour.at(i).get_grade().compare("IP") != 0 || cour.at(i).get_grade().compare("PS") != 0){
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
    
int Student::get_cur_year(){
    return cur_year;
}
    
string Student::get_major(){
    return major;
}
    
double Student::get_avgGPA(){
    return avgGPA;
}
    
double Student::get_tot_credit(){
    return tot_credit;
}
    
double Student::get_cred_needed(){
    return cred_needed;
}
    
//setters
void Student::set_cur_year(int year){
    cur_year = year;
}
    
void Student::set_major(string maj){
    major = maj;
}
    
void Student::set_tot_credit(double tcred){
    tot_credit = tcred;
    cred_needed = 128-tcred;
}
    
/*void Student::addCourse(){
    string major;
    int class_num;
    Course c;
    cout << "Add Course" << endl << "Type 'Major CourseNum'" ;
    cin >> major >> class_num ;
    //add function to find corresponding course in database
    for(int i = 0; i<cour_taken.size(); i++){
        if(cour_taken.at(i) == c){
            return;
        }
    }
    cour_taken.push_back(c);
    tot_credit += c.get_credit_hours();
    cred_needed -= c.get_credit_hours();
    avgGPA = calculateGPA(cour_taken);
} */
    
/*void Student::removeCourse(){
    string major;
    int class_num;
    Course c;
    cout << "Remove Course" << endl << "Type 'Major CourseNum'" ;
    cin >> major >> class_num ;
    //add function to find corresponding course in database
    for(int i = 0; i<cour_taken.size(); i++){
        if(cour_taken[i] == c){
            tot_credit -= cour_taken.at(i).get_credit_hours();
            cred_needed += cour_taken.at(i).get_credit_hours();
            cour_taken.pop_back(c);
        }
    }
    avgGPA = calculateGPA(cour_taken);
}
 */