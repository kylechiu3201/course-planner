#include "CompE.h"
#include "../Engineering.h"
#include "../../Database/Database.h"
#include "../../Course/Course.h"
#include <iostream>
#include <vector>
#include <fstream>

vector<Course> CompE::pos_foundations;   //possible classes to take to fulfill requirements
vector<Course> CompE::pos_core;
vector<Course> CompE::pos_gen_electives ; //includes all of tech elective list
vector<Course> CompE::pos_EE_Foundation;
vector<Course> CompE::pos_adv_computing;
vector<Course> CompE::pos_capstone;
const int CompE::tech_hours = 27;

/**
 * @brief 
 */
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
    
    
    west = {vector<Course>(2, Course()), 0};
    non_west= {vector<Course>(2, Course()), 0};
    US_min= {vector<Course>(2, Course()), 0};
    hum_and_arts={vector<Course>(2, Course()), 0};
    soc_and_behav={vector<Course>(2, Course()), 0};
    libed={vector<Course>(2, Course()), 0};
    //language={vector<Course>(3, Course()), 0};
    compos={vector<Course>(2, Course()), 0};
    


    //delete Course
    //find course you want to dleete;
    //delete = Coruse();
    //swap(deletedposition, lastnonemptyposition)
    //decrement integer

    //add cousre
}

//getters
/**
 * @brief 
 *
 * @return 
 */
vector<Course> CompE::get_pos_foundations()
{
    return pos_foundations;
}

/**
 * @brief 
 *
 * @return 
 */
vector<Course> CompE::get_pos_core()
{
    return pos_core;
}

/**
 * @brief 
 *
 * @return 
 */
vector<Course> CompE::get_pos_gen_electives()
{
    return pos_gen_electives;
}

/**
 * @brief 
 *
 * @return 
 */
vector<Course> CompE::get_pos_EE_Foundation()
{
    return pos_EE_Foundation;
}

/**
 * @brief 
 *
 * @return 
 */
vector<Course> CompE::get_pos_adv_computing()
{
    return pos_adv_computing;
}

/**
 * @brief 
 *
 * @return 
 */
vector<Course> CompE::get_pos_capstone()
{
    return pos_capstone;
}

/**
 * @brief 
 *
 * @return 
 */
pair<vector<Course>, int>* CompE::get_foundations()
{
    return &foundations;
}

/**
 * @brief 
 *
 * @return 
 */
pair<vector<Course>, int>* CompE::get_core()
{
    return &core;
}

/**
 * @brief 
 *
 * @return 
 */
pair<vector<Course>, int>* CompE::get_gen_electives()
{
    return &gen_electives;
}

/**
 * @brief 
 *
 * @return 
 */
pair<vector<Course>, int>* CompE::get_EE_foundation()
{
    return &EE_foundation;
}

/**
 * @brief 
 *
 * @return 
 */
pair<vector<Course>, int>* CompE::get_adv_computing()
{
    return &adv_computing;
}

/**
 * @brief 
 *
 * @return 
 */
pair<vector<Course>, int>* CompE::get_capstone()
{
    return &capstone;
}

/**
 * @brief 
 *
 * @return 
 */
string CompE::get_major_name()
{
    return "CE";
}

//setters
/**
 * @brief 
 *
 * @param c
 */
void CompE::set_pos_foundations(Course c)
{
    pos_foundations.push_back(c);
}
    
/**
 * @brief 
 *
 * @param c
 */
void CompE::set_pos_core(Course c)
{
    pos_core.push_back(c);
}  
    
/**
 * @brief 
 *
 * @param c
 */
void CompE::set_pos_gen_electives(Course c)
{
    pos_gen_electives.push_back(c);
}

/**
 * @brief 
 *
 * @param c
 */
void CompE::set_pos_EE_Foundation(Course c)
{
    pos_EE_Foundation.push_back(c);
}

/**
 * @brief 
 *
 * @param c
 */
void CompE::set_pos_adv_computing(Course c)
{
    pos_adv_computing.push_back(c);
}

/**
 * @brief 
 *
 * @param c
 */
void CompE::set_pos_capstone(Course c)
{
    pos_capstone.push_back(c);
}

/**
 * @brief 
 *
 * @param EE_foundation
 * @param adv_computing
 * @param gen_electives
 * @param capstone
 *
 * @return 
 */
int CompE:: get_tech_hours(vector<Course> & EE_foundation, vector<Course> & adv_computing, vector<Course> & gen_electives, vector<Course> & capstone) //returns total credit hours from the personal category vectors
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
/**
 * @brief 
 *
 * @param c
 *
 * @return 
 */
bool CompE::check_degree(Course c){
    if(Engineering::search_req2(get_pos_foundations(),c)==true || Engineering::search_req2(get_pos_core(), c) == true || Engineering::search_req2(get_pos_gen_electives(), c)==true || Engineering::search_req2(get_pos_EE_Foundation(), c) ==true || Engineering::search_req2(get_pos_adv_computing(), c)==true || Engineering::search_req2(get_pos_capstone(), c)==true)
    {
        return true;
    }
    return false;

}

/**
 * @brief 
 *
 * @param c
 *
 * @return 
 */
bool CompE:: remove_from_degree(Course c)
{
    int index=-1;
    if(Engineering::search_req(*get_foundations(),c)){ //search for course

        index = Engineering::search_req_index(*get_foundations(), c); //find index of course in degree vector
        get_foundations()->first[index] = Course();
        swap(get_foundations()->first[index], get_foundations()->first[get_foundations()->second-1]);
        get_foundations()->second--;
        //cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_core(),c))
    {
        cout << "check";

        index = Engineering::search_req_index(*get_core(), c);
        get_core()->first[index] = Course();
        swap( get_core()->first[index], get_core()->first[ get_core()->second-1]);
        get_core()->second--;
        //cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_gen_electives(),c))
    {

        index = Engineering::search_req_index(*get_gen_electives(), c);
        get_gen_electives()->first[index] = Course();
        swap(  get_gen_electives()->first[index],  get_gen_electives()->first[  get_gen_electives()->second-1]);
        get_gen_electives()->second--;
        //cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_EE_foundation(),c))
    {

        index = Engineering::search_req_index(*get_EE_foundation(), c);
        get_EE_foundation()->first[index] = Course();
        swap(get_EE_foundation()->first[index], get_EE_foundation()->first[get_EE_foundation()->second-1]);
        get_EE_foundation()->second--;
        //cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_adv_computing(),c))
    {

        index = Engineering::search_req_index(*get_adv_computing(), c);
        get_adv_computing()->first[index] = Course();
        swap(get_adv_computing()->first[index], get_adv_computing()->first[get_adv_computing()->second-1]);
        get_adv_computing()->second--;
       // cout << "Succesfully removed course";
        return true;
    }
    else if(Engineering::search_req(*get_capstone(),c))
    {

        index = Engineering::search_req_index(*get_capstone(), c);
        get_capstone()->first[index] = Course();
        swap(get_capstone()->first[index], get_capstone()->first[get_capstone()->second-1]);
        get_capstone()->second--;
        //cout << "Succesfully removed course";
        return true;
    }

    //cout << "No course to remove";
    return false;

}

/**
 * @brief 
 *
 * @param c
 */
void CompE::add_to_degree(Course c) //checks to see if the course belongs to a category and adds it to the vector
{

    if(Engineering::search_req2(get_pos_foundations(), c))//checks the possible courses in category if it matches with c
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

/**
 * @brief 
 */
void CompE::fill_pos_vec() //puts the courses from the text file in to the possible course vectors
{
    ifstream file("CE_Data.txt");
    if (file.fail())
    {
        cout<< "file failed to open\n";
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
                    pos_foundations.push_back(c);
                }
                if(x==1)
                {
                    pos_core.push_back(c);
                }
                if(x==2)
                {
                    pos_EE_Foundation.push_back(c);
                }
                if(x==3)
                {
                    pos_capstone.push_back(c);
                }
                if(x==4)
                {
                    pos_adv_computing.push_back(c);
                }
                if(x==5)
                {
                    pos_gen_electives.push_back(c);
                }
            }
        }
    }
    file.close();
}



/**
 * @brief 
 *
 * @param major
 */
void CompE::save_deg_vec(Engineering * major)
{
    ofstream deg_file("student_degree_data.txt", ofstream::out | ofstream::trunc); //open empty file for fresh save
    int vec = major->get_foundations()->second;
    deg_file << vec << "\n"; //save vector size of category
    for(int x = 0; x < vec; x++){ //save courses inside category
        deg_file << major->get_foundations()->first[x];
    }
    vec = major->get_core()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file <<major->get_core()->first[x];
    }
    vec = major->get_gen_electives()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file << major->get_gen_electives()->first[x];
    }
    vec = major->get_EE_foundation()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file << major->get_EE_foundation()->first[x];
    }
    vec = major->get_adv_computing()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file << major->get_adv_computing()->first[x];
    }
    vec = major->get_capstone()->second;
    deg_file << vec << "\n";
    for(int x = 0; x < vec; x++){
        deg_file << major->get_capstone()->first[x];
    }
}

/**
 * @brief 
 *
 * @param major
 */
void CompE::load_deg_vec(Engineering * major)
{
    ifstream deg_file("student_degree_data.txt", ifstream::in);
    if(deg_file.fail())
    {
        cout << "failed to locate degree course information\n";
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

/**
 * @brief 
 *
 * @param input
 */
void CompE::is_satisfied(string input) //courses that you still have left to take
{
    int num_needed=0; //courses needed
    vector<Course> temp;
    vector<Course> all;
    //ToDo: add a way to select multiple/all of the categories
    if(input =="F")
    {
        num_needed= get_foundations()->first.size() - get_foundations()->second;
        temp = get_foundations()->first;
        all = get_pos_foundations();
    }
    if(input =="CO")
    {
        num_needed= get_core()->first.size() - get_core()->second;
        temp = get_core()->first;
        all = get_pos_core();
    }
    if(input =="GE")
    {
        num_needed= get_gen_electives()->first.size() - get_gen_electives()->second;
        temp = get_gen_electives()->first;
        all = get_pos_gen_electives();
    }
    if(input =="EE")
    {
        num_needed= get_EE_foundation()->first.size() - get_EE_foundation()->second;
        temp = get_EE_foundation()->first;
        all = get_pos_EE_Foundation();
    }
    if(input =="AC")
    {
        num_needed= get_adv_computing()->first.size() - get_adv_computing()->second;
        temp = get_adv_computing()->first;
        all = get_pos_adv_computing();
    }
    if(input =="CA")
    {
        num_needed= get_capstone()->first.size() - get_capstone()->second;
        temp = get_capstone()->first;
        all = get_pos_capstone();
    }
    vector<Course> disp;
    for(Course a : all)
    {
        bool flag = false;
        for(Course t : temp)
        {
            if(a == t)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            disp.push_back(a);
    }
    cout << "\nYou need " << num_needed << " more course(s) in this category.\n";
    if(!disp.empty())
        disp_course_vec(disp);
    else
        cout << "\nNo courses left for this category.\n";
}

/**
 * @brief 
 *
 * @param input
 */
void CompE::satisfied(string input)  //displays courses taken
{
    int num_needed=0; //courses needed
    vector<Course> temp;
    //ToDo: add a way to select multiple/all of the categories
    if(input =="F")
    {
        num_needed= get_foundations()->second;
        temp = get_foundations()->first;
    }
    if(input =="CO")
    {
        num_needed= get_core()->second;
        temp = get_core()->first;
    }
    if(input =="GE")
    {
        num_needed= get_gen_electives()->second;
        temp = get_gen_electives()->first;
    }
    if(input =="EE")
    {
        num_needed= get_EE_foundation()->second;
        temp = get_EE_foundation()->first;
    }
    if(input =="AC")
    {
        num_needed= get_adv_computing()->second;
        temp = get_adv_computing()->first;
    }
    if(input =="CA")
    {
        num_needed= get_capstone()->first.size() - get_capstone()->second;
        temp = get_capstone()->first;
    }
    cout << "\nYou have taken " << num_needed << " course(s) in this category.\n";
    if(!temp.empty())
            disp_course_vec(temp);
        else
            cout << "\nYou have not taken any courses in this category.\n";
}
    
/**
 * @brief 
 *
 * @return 
 */
string CompE::select_group() //picks out a certain category
{
    cout << "\nPick course requirement category : foundations, core, gen_electives, EE_foundation, Advanced Computing, Capstone";
    cout << "\n type: F, CO, GE, EE, AC, or CA\n";
    string input;
    cin >> input;
    while(input != "F" && input != "CO" && input != "GE" && input != "EE" && input != "AC" && input !="CA")
    {
        cout << "Please enter a valid course category: ";
        cin >> input;
    }
    return input;
}
