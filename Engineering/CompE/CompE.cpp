#include "CompE.h"
#include "../Engineering.h"
#include "../../Database/Database.h"
#include "../../Course/Course.h"
#include <iostream>
#include <vector>
#include <fstream>

vector<Course> CompE::pos_foundations = {};   //possible classes to take to fulfill requirements
vector<Course> CompE::pos_core= {};
vector<Course> CompE::pos_gen_electives = {}; //includes all of tech elective list
vector<Course> CompE::pos_EE_Foundation = {};
vector<Course> CompE::pos_adv_computing = {};
vector<Course> CompE::pos_capstone = {};
const int CompE::tech_hours = 27;
CompE::CompE()
{
    //foundations = vector<Course>(10, Course()); //Math, Science core
    //core = vector<Course>(10, Course());
    //gen_electives; //not EE or adv computing or capstone
    //EE_foundation = vector<Course>(1, Course());
    //adv_computing = vector<Course>(3, Course());
    //capstone = vector<Course>(1, Course()); //445 411 496 499


    foundations = {vector<Course>(10, Course()), 0}; //math science core
    core = {vector<Course>(10, Course()), 0};
    gen_electives = {vector<Course>(), 0}; //not EE or adv comp or capstone
    EE_foundation = {vector<Course>(1, Course()), 0};
    adv_computing = {vector<Course>(3, Course()), 0};
    capstone = {vector<Course>(1, Course()), 0}; //445 411 496 499

    pos_foundations = {};   //possible classes to take to fulfill requirements
    pos_core= {};
    pos_gen_electives = {}; //includes all of tech elective list
    pos_EE_Foundation = {};
    pos_adv_computing = {};
    pos_capstone = {};


    //delete Course
    //find course you want to dleete;
    //delete = Coruse();
    //swap(deletedposition, lastnonemptyposition)
    //decrement integer

    //add cousre
}

//getters
vector<Course> CompE::get_pos_foundations()
{
    return pos_foundations;
}
vector<Course> CompE::get_pos_core()
{
    return pos_core;
}
vector<Course> CompE::get_pos_gen_electives()
{
    return pos_gen_electives;
}
vector<Course> CompE::get_pos_EE_Foundation()
{
    return pos_EE_Foundation;
}
vector<Course> CompE::get_pos_adv_computing()
{
    return pos_adv_computing;
}
vector<Course> CompE::get_pos_capstone()
{
    return pos_capstone;
}


pair<vector<Course>, int>* CompE::get_foundations()
{
    return &foundations;
}
pair<vector<Course>, int>* CompE::get_core()
{
    return &core;
}
pair<vector<Course>, int>* CompE::get_gen_electives()
{
    return &gen_electives;
}
pair<vector<Course>, int>* CompE::get_EE_foundation()
{
    return &EE_foundation;
}
pair<vector<Course>, int>* CompE::get_adv_computing()
{
    return &adv_computing;
}
pair<vector<Course>, int>* CompE::get_capstone()
{
    return &capstone;
}

string CompE::get_major_name()
{
    return "CE";
}


int CompE:: get_tech_hours(vector<Course> & EE_foundation, vector<Course> & adv_computing, vector<Course> & gen_electives, vector<Course> & capstone)
{
    int sum = 0;
    if(!EE_foundation.empty())
    {
        sum += EE_foundation[0].get_credit_hours();
    }
    for(int x = 0 ; x < 3 ; x++)
    {
        if(!adv_computing.empty())
        {
            sum += adv_computing[x].get_credit_hours();
        }
    }
    for(int x =0 ; x < gen_electives.size(); x++)
    {
        if(!gen_electives.empty())
        {
            sum += gen_electives[x].get_credit_hours();
        }
    }

    if(!capstone.empty())
    {
        sum += capstone[0].get_credit_hours();
    }

    return sum;
}
//checks if a course is part of degree
//for
bool CompE::check_degree(Course c){
    if(Engineering::search_req2(get_pos_foundations(),c)==true || Engineering::search_req2(get_pos_core(), c) == true || Engineering::search_req2(get_pos_gen_electives(), c)==true || Engineering::search_req2(get_pos_EE_Foundation(), c) ==true || Engineering::search_req2(get_pos_adv_computing(), c)==true || Engineering::search_req2(get_pos_capstone(), c)==true)
    {
        return true;
    }
    return false;

}
bool CompE:: remove_from_degree(Course &c)
{
    int index=-1;
    if(Engineering::search_req(*get_foundations(),c)){ //search for course
        pair<vector<Course>, int> temp = *get_foundations();
        index = Engineering::search_req_index(temp, c); //find index of course in degree vector
        temp.first[index] = Course();
        swap(temp.first[index], temp.first[temp.second-1]);
        temp.second--;
        cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_core(),c))
    {
        pair<vector<Course>, int> temp = *get_core();
        index = Engineering::search_req_index(temp, c);
        temp.first[index] = Course();
        swap(temp.first[index], temp.first[temp.second-1]);
        temp.second--;
        cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_gen_electives(),c))
    {
        pair<vector<Course>, int> temp = *get_gen_electives();
        index = Engineering::search_req_index(temp, c);
        temp.first[index] = Course();
        swap(temp.first[index], temp.first[temp.second-1]);
        temp.second--;
        cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_EE_foundation(),c))
    {
        pair<vector<Course>, int> temp = *get_EE_foundation();
        index = Engineering::search_req_index(temp, c);
        temp.first[index] = Course();
        swap(temp.first[index], temp.first[temp.second-1]);
        temp.second--;
        cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_adv_computing(),c))
    {
        pair<vector<Course>, int> temp = *get_adv_computing();
        index = Engineering::search_req_index(temp, c);
        temp.first[index] = Course();
        swap(temp.first[index], temp.first[temp.second-1]);
        temp.second--;
        cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_capstone(),c))
    {
        pair<vector<Course>, int> temp = *get_capstone();
        index = Engineering::search_req_index(temp, c);
        temp.first[index] = Course();
        swap(temp.first[index], temp.first[temp.second-1]);
        temp.second--;
        cout << "Succesfully removed course";
        return true;
    }

    cout << "No course to remove";
    return false;

}

void CompE::add_to_degree(Course& c)
{

    if(Engineering::search_req2(get_pos_foundations(), c))
    {
        if(!Engineering::search_req(*get_foundations(), c))
        {
            get_foundations()->first[foundations.second++] = c;
        }
    }
    else if(Engineering::search_req2(get_pos_core(), c))
    {
        if(!Engineering::search_req(*get_core(), c))
        {
            get_core()->first[core.second++] = c;
        }
    }
    else if(Engineering::search_req2(get_pos_gen_electives(), c))
    {
        if(!Engineering::search_req(*get_gen_electives(), c))
        {
            get_gen_electives()->first[gen_electives.second++] = c;
        }
    }
    else if(Engineering::search_req2(get_pos_EE_Foundation(), c))
    {
        if(!Engineering::search_req(*get_EE_foundation(), c))
        {
            get_EE_foundation()->first[EE_foundation.second++] = c;
        }
    }
    else if(Engineering::search_req2(get_pos_adv_computing(), c))
    {
        if(!Engineering::search_req(*get_adv_computing(), c))
        {
            get_adv_computing()->first[adv_computing.second++] = c;
        }

    }
    else if(Engineering::search_req2(get_pos_capstone(), c))
    {
        if(!Engineering::search_req(*get_capstone(), c))
        {
            get_capstone()->first[capstone.second++] = c;
        }

    }


}
void CompE::fill_pos_vec()
{
    ifstream file("CE_Data.txt");
    if (file.fail())
    {
        cout<< "file failed to open";
        return;
        // file is not open
    }
    int lengths[6]; //beginning of file, put lengths of vector
    for(int x= 0 ; x< 6 ; x++)
    {
        file >>lengths[x];
    }

    Course c;
    while(file.good())
    {
        for(int x = 0; x < 6 ; x++)
        {
            for(int y = 0; y < lengths[x] ; y++)
            {
                file >> c;
                if(x==0)
                {
                    get_pos_foundations().push_back(c);
                }
                if(x==1)
                {
                    get_pos_core().push_back(c);
                }
                if(x==2)
                {
                    get_pos_EE_Foundation().push_back(c);
                }
                if(x==3)
                {
                    get_pos_capstone().push_back(c);
                }
                if(x==4)
                {
                    get_pos_adv_computing().push_back(c);
                }
                if(x==5)
                {
                    get_pos_gen_electives().push_back(c);
                }
            }
        }
    }
    file.close();
}
void CompE::save_deg_vec(Engineering * major)
{
    ofstream deg_file("student_degree_data.txt", ofstream::out | ofstream::trunc); //open empty file for fresh save
    int vec = major->get_foundations()->second;
    deg_file << vec << "\n"; //save vector size of category
    for(int x = 0; x < vec; x++){ //save courses inside category
        deg_file << major->get_foundations()->first[x] << "\n";
    }
    vec = major->get_core()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file <<major->get_core()->first[x] << "\n";
    }
    vec = major->get_gen_electives()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file << major->get_gen_electives()->first[x] << "\n";
    }
    vec = major->get_EE_foundation()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file << major->get_EE_foundation()->first[x] << "\n";
    }
    vec = major->get_adv_computing()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file << major->get_adv_computing()->first[x] << "\n";
    }
    vec = major->get_capstone()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file << major->get_capstone()->first[x] << "\n";
    }
}

void CompE::load_deg_vec(Engineering * major)
{
    ifstream deg_file("student_degree_data.txt", ifstream::in);
    if(deg_file.fail())
    {
        cout << "failed to locate degree course information";
        return;
    }
    int course_sum;
    deg_file >> course_sum;
    major->get_foundations()->second = course_sum;
    for(int x = 0; x < course_sum; x++){
        Course temp;
        deg_file >> temp;
        major->get_foundations()->first[x] = temp;
    }
    deg_file >> course_sum;
    major->get_core()->second = course_sum;
    for(int x = 0; x < course_sum; x++){
        Course temp;
        deg_file >> temp;
        major->get_core()->first[x] = temp;
    }
    deg_file >> course_sum;
    major->get_gen_electives()->second = course_sum;
    for(int x = 0; x < course_sum; x++){
        Course temp;
        deg_file >> temp;
        major->get_gen_electives()->first[x] = temp;
    }
    deg_file >> course_sum;
    major->get_EE_foundation()->second = course_sum;
    for(int x = 0; x < course_sum; x++){
        Course temp;
        deg_file >> temp;
        major->get_EE_foundation()->first[x] = temp;
    }
    deg_file >> course_sum;
    major->get_adv_computing()->second = course_sum;
    for(int x = 0; x < course_sum; x++){
        Course temp;
        deg_file >> temp;
        major->get_adv_computing()->first[x] = temp;
    }
    deg_file >> course_sum;
    major->get_capstone()->second = course_sum;
    for(int x = 0; x < course_sum; x++){
        Course temp;
        deg_file >> temp;
        major->get_capstone()->first[x] = temp;
    }
}





void CompE::is_satisfied() //CHANGE BOOL LATER?
{
    cout << "Pick course requirement category : foundations, core, gen_electives, EE_foundation, Advanced Computing, Capstone";
    cout << "\n type: F, CO, GE, EE, AC, or CA";
    string input;
    cin >> input;
    while(input != "F" && input != "CO" && input != "GE" && input != "EE" && input != "AC" && input !="CA")
    {
        cout << "Please enter a valid course category";
        cin >> input;
    }
    int num_needed=0; //courses needed
    if(input =="F")
    {
        num_needed= get_foundations()->first.size() - get_foundations()->second;
        cout << "You need " << num_needed << " more courses in this category.";
        cout<< "\nDisplay courses?";
    }
    if(input =="CO")
    {
        num_needed= get_core()->first.size() - get_core()->second;
        cout << "You need " << num_needed << " more courses in this category.";
    }
    if(input =="GE")
    {
        num_needed= get_gen_electives()->first.size() - get_gen_electives()->second;
        cout << "You need " << num_needed << " more courses in this category.";
    }
    if(input =="EE")
    {
        num_needed= get_EE_foundation()->first.size() - get_EE_foundation()->second;
        cout << "You need " << num_needed << " more courses in this category.";
    }
    if(input =="AC")
    {
        num_needed= get_adv_computing()->first.size() - get_adv_computing()->second;
        cout << "You need " << num_needed << " more courses in this category.";
    }
    if(input =="CA")
    {
        num_needed= get_capstone()->first.size() - get_capstone()->second;
        cout << "You need " << num_needed << " more courses in this category.";
    }
}
    
    
    
    
    
        
  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    