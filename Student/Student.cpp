#include "../Course/Course.h"
#include "../Engineering/CompE/CompE.h"
#include "../Engineering/Engineering.h"
#include "../Student/Student.h"
#include "../Database/Database.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../Semester/Semester.h"

using namespace std;
//constructors
Student::Student(vector<Semester> my_plan, vector<Course> & cour, int syear, int gyear, Engineering * maj, int tcred, int deg, string n){
    plan = my_plan;
    cour_taken = cour;
    start_year = syear;
    grad_year = gyear;
   //change this to Major object instead of string
    stud_major = maj;
    GPA = calculateGPA(cour);
    tot_credit = tcred;
    degree_cred = deg; //credit earned towards degree
    name = n;
}

Student::Student(Engineering * maj, string n, int syear){
    plan = {vector<Semester>(16, Semester())};
    cour_taken = vector<Course>();
    start_year = syear;
    grad_year = 0;
    stud_major = maj;
    name = n;
    GPA = 0;
    tot_credit = 0;
    degree_cred = 0;
    
}

Student::Student(){
    plan = vector<Semester>(16, Semester());
    cour_taken = vector<Course>();
    start_year = 0;
    grad_year = 0;
    stud_major = NULL; //need to make a default major or something
    name = "";
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

int Student::get_start_year(){
    return start_year;
}

int Student::get_grad_year(){
    return grad_year;
}

Engineering * Student::get_stud_major(){
    return stud_major;
}

double Student::get_GPA(){
    return 0; //Does this function do anything GPA;
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

Semester Student::get_sem(int num){
    return plan[num-1];
}

vector<Semester> Student::get_sem_vec(){
    return plan;
}

//setters
void Student::set_start_year(int year){
    start_year = year;
}

void Student::set_grad_year(int year){
    grad_year = year;
}

void Student::set_stud_major(Engineering * maj){
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


void Student::addCourse(){
    int class_num;
    string course;
    string grade;
    
    //user picks semester to add course to
    cout << "Which semester would you like to add the course to?\n";
    display_sem_names(plan);
    int index = pick_semester(plan);

    //retrieve input for course
    cout << "Add Course, Format: 'Major_CourseNum'" << endl;
    cin >> course >> class_num;
    
    //add function to find corresponding course in database
    Course c = Database::find_course(course, class_num); //find_course returns Course() object
    if(c.get_name()=="") 
    {
        cout << "Course not found. Type 'add' to try again\n"; //NEED TO ADD OPTION TO ADD COURSE TO DATABASE
        return;
    }
    
    /*for(int i = 0; i<cour_taken.size(); i++){   //checks if course is already taken
        if(cour_taken[i].get_major().compare(c->get_major())==0 && cour_taken[i].get_course_num()==c->get_course_num()){ //compare courses
            cout << "Course already taken. Type 'add' to try again\n";
            return;
        }
    }*/
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
        cout << "\nInvalid grade. Type 'add' to try again";
        return;
    }
    if(plan[index].valid_sem(c)) //checks if adding course goes over 18 hours
    {
        if(CompE::check_degree(c))
        {
            degree_cred += c.get_credit_hours();
            stud_major->add_to_degree(c);  //adds course to degree
        }
        cour_taken.push_back(c); //adds course to general student course vector
        plan[index].get_sem_vec().push_back(c); //adds course to correct semester
        
        plan[index].add_hours(c.get_credit_hours()); //QUESTION:: should i go  get_plan()[index]....instead?
        //does ...plan[index].get_hours()++ work
        tot_credit += c.get_credit_hours(); 
        GPA = calculateGPA(cour_taken);
    }
} 

void Student::removeCourse(){
    
    cout << "Pick semester to remove from";
    int index = pick_semester(plan);
    
    string course;
    int class_num;
    cout << "Remove Course, Format: 'Major_CourseNum'" << endl;
    cin >> course >> class_num ;
    
    Course c = Course(course, class_num);
    
    for(int i = 0; i<cour_taken.size(); i++){
        //if(cour_taken[i]==c){ //compare courses using overloaded operator
        if(cour_taken.at(i).get_major().compare(c.get_major())==0 && cour_taken.at(i).get_course_num()==c.get_course_num())
        {
            if(stud_major->remove_from_degree(c)){  //removes from degree
                degree_cred -= c.get_credit_hours();
            }
            tot_credit -= cour_taken[i].get_credit_hours(); 
            cour_taken.erase(find(cour_taken.begin(), cour_taken.end(), c));  //remove from general course vector
            plan[index].get_sem_vec().erase(find(plan[index].get_sem_vec().begin(), plan[index].get_sem_vec().end(),c)); //remove from semester
            GPA = calculateGPA(cour_taken);
            return;
        }
    }
    cout << "Course not found";
    
}
 
 
 Student * Student::create_new_student(string & name)
 {
    string user_name;
    int start_year;
    
    std::cout << "Type your major: ";
    
    std::cin >> name ;

    Engineering * m = Engineering::choose_major(name);
    while(m == NULL)
    {
        std::cout << "Type your major: ";
        cin >> name;
        m = Engineering::choose_major(name);
    }
    cout << "Type your name: ";
    cin >> user_name ;
    cout << "Type enrollment year: ";
    cin >> start_year ;
    
    Student * student = new Student(m, user_name, start_year);
    
    return student;  
 }
 
 bool Student::valid_grade(string g){ //check to see if string is a valid grade
     if(g.compare("A+") == 0){
            return true;
        }
        if(g.compare("A") == 0){
            return true;
        }
        if(g.compare("A-") == 0){
            return true;
        }
        if(g.compare("B+") == 0){
            return true;
        }
        if(g.compare("B") == 0){
            return true;
        }
        if(g.compare("B-") == 0){
            return true;
        }
        if(g.compare("C+") == 0){
            return true;
        }
        if(g.compare("C") == 0){
            return true;
        }
        if(g.compare("C-") == 0){
            return true;
        }
        if(g.compare("D+") == 0){
            return true;
        }
        if(g.compare("D") == 0){
            return true;
        }
        if(g.compare("D-") == 0){
            return true;
        }
        if(g.compare("F") == 0){
            return true;
        }
        if(g.compare("PS") == 0){
            return true;
        }
        if(g.compare("\n") == 0){
            return true;
        }
        return false;
    }
    //Displays all semester names
    void Student::display_sem_names(vector<Semester> vec)  
    {
        for(int x=0 ; x< vec.size() ; x++)
        {
            cout << vec[x].get_sem_name()  << "\n";
        }
    }
    
    
    
    int Student::pick_semester(vector<Semester> vec)
    {
        string input;
        getline(cin, input);
        int index = 0;
        while(input != vec[index].get_sem_name() && index < vec.size())
        {
            index++;
        }
        if(index == vec.size())
        {
            cout << "Invalid Semester. Type 'add' to try again";
        }
        
        return index;
    }

void Student::stud_sem_name(Student *student) //sets semester names according to start year
{
    int year = student->get_start_year();
    string set = "";
    for(int x = 3 ; x< student->get_sem_vec().size()+2 ; x++)
    {
        if(x % 4 == 1)
        {
            set = "Spring";
            set+= to_string(year);
            student->get_sem(x-2).set_sem_name(set);
        }
        if(x % 4 == 2)
        {
            set = "Summer";
            set+= to_string(year);
            student->get_sem(x-2).set_sem_name(set);
        }
        if(x % 4 ==3)
        {
            set = "Fall";
            set+= to_string(year);
            student->get_sem(x-2).set_sem_name(set);
        }
        if(x % 4 ==0)
        {
            set = "Winter";
            set+= to_string(year);
            student->get_sem(x-2).set_sem_name(set);
            year++; //update year every 4 semesters
        }
        set = "";
    }
}