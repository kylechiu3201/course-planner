#include "../Course/Course.h"
#include "Semester.h"
#include "../Student/Student.h"

//8 semesters + up to 4 summer/winter semesters
//min 12 max 18 for school year, except for last semesters//max 8?? for summer
//semester - contains four courses
using namespace std;

Semester::Semester()
{
    sem_vec = {vector<Course>(), ""};
    sem_name = "";
    sem_hours = 0;
}

int Semester::get_sem_hours()
{
    return sem_hours;
}

string Semester::get_sem_name()
{
    return sem_name;
}

vector<Course> Semester::get_sem_vec()
{
    return sem_vec.first;
}
string * Semester::get_note()
{
    return &sem_vec.second;
}

void Semester::set_note() //need another set note for loading?
{
    string input;
    cout <<"Type to edit note";
    cin >> input;
    sem_vec.second = input;
    
}
void Semester::set_sem_name(string name)
{
    sem_name = name;
}

void Semester::set_sem_hours(int hour){
    sem_hours = hour;
}

bool Semester::valid_sem(Course c) //checks for valid semester (exception is last semester, can underload)
//if they add a course, and go over, this checks for it.
{
    if(get_sem_hours()+ c.get_credit_hours() >18)
    {
        return false;
    }
    return true;
}



void Semester::add_hours(int hours)
{
    sem_hours += hours;
}

void Semester::set_note_load(string note){
    sem_vec.second = note;
}
