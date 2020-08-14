#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include "../Student/Student.h"
#include "../Course/Course.h"
#include "Database.h"
#include "../Engineering/CompE/CompE.h"
#include "../Semester/Semester.h"
#include <algorithm>
#include <QApplication>
#include <QFile>
#include <QTextStream>

//vector onto heap, return pointer
//destructor at main();

//ToDo: language requirement

//A vector that holds every single course
vector<Course> Database::list_all = vector<Course>(2468, Course());

/**
 * @brief
 */
void Database::create_db()
{
    int list_all_size=2486;
    string path = QApplication::applicationDirPath().toLocal8Bit().constData();
    ifstream load_file (path + "/course_database.txt", ifstream::in);
    if(load_file.fail())
    {
        std::cout << "Error: course_database.txt not found.";
        exit(EXIT_FAILURE);
        return;
    }
    load_file >> list_all_size; //retrieves list size from save file
    cout << list_all_size;
    for(int x = 0; x < list_all_size; ++x)
    {
        load_file >> list_all[x];  //loads courses into list_all vector
    }
    load_file.close();

    CompE::fill_pos_vec();
    Engineering::fill_pos_vec_Eng();
}

/**
 * @brief
 *
 * @return
 */
vector<Course> Database::get_vector()
{
    return list_all;
}

/**
 * @brief
 *
 * @param student
 */
void Database::save_data(Student* student)
{
    string path = QApplication::applicationDirPath().toLocal8Bit().constData();
    ofstream save_file (path + "/course_database.txt", ofstream::out);
    save_file << list_all.size() << "\n"; //saves list size into file
    for(int i = 0; i < list_all.size(); ++i)
    {
        save_file << list_all[i];  //loads database courses into save file
    }
    save_file.close();



    ofstream file;
    file.open(path + "/student_data.txt", ofstream::out | ofstream::trunc); //clear contents of file for fresh save
    //SAVE STUDENT DATA HERE
    //example:  3 (course vec size)
    //          ECE 225...(list of courses)
    //          "" (name)
    //          CE (major)
    //          2019 (start year)
    //          2023 (grad year)
    //          40 (total credit hours)
    //          12 (degree credit hours)
    //          3.6 (overall gpa)
    file << student->get_cour_taken().size() << "\n";
    for(int x = 0 ; x< student->get_cour_taken().size();x++)
    {
        file << student->get_cour_taken()[x];
    }
    file << student->get_name()<< "\n" << student->get_stud_major()->get_major_name() << "\n" << student->get_start_year() <<"\n" << student->get_grad_year() << "\n" << student->get_tot_credit() << "\n" << student->get_degree_cred() << "\n" << student->get_GPA() << "\n";

    //write semester data to student file
    //example : "" (name)
    //          15 (hours)
    //          1 (course vector size)
    //          ECE 310...... (courses)
    //          "" (note)
    for(int x = 1; x < 18; x++){
        file << student->get_sem(x)->Semester::get_sem_name() << "\n" <<student->get_sem(x)->Semester::get_sem_hours() << "\n" << student->get_sem(x)->Semester::get_sem_vec()->size() << "\n";

        for(int y = 0; y < student->get_sem(x)->Semester::get_sem_vec()->size(); y++){
            file << student->get_sem(x)->Semester::get_sem_vec()->at(y);
        }
        file << *student->get_sem(x)->Semester::get_note() << "\n";

    }

    file.close();
    //SAVE DEGREE DATA INTO STUDENT HERE
    student->get_stud_major()->save_deg_vec(student->get_stud_major());
    //SAVE ENGINEERING DATA
    student->get_stud_major()->save_gen_vec(student->get_stud_major());
}

/**
 * @brief
 *
 * @param student
 */
void Database::load_data(Student* student)
{
    int list_all_size;
    string path = QApplication::applicationDirPath().toLocal8Bit().constData();
    ifstream load_file (path + "/course_database.txt", ifstream::in); //Read course database file
    if(load_file.fail()) //Error catching
    {
        std::cout << "Error: course_database.txt not found.";
        exit(EXIT_FAILURE);
        return;
    }
    load_file >> list_all_size; //retrieves list size from save file
    for(int x = 0; x < list_all_size; ++x)
    {
        load_file >> list_all[x];  //loads courses into list_all vector
    }
    //LOAD STUDENT DATA HERE
    int vec_size; //cour_taken size
    ifstream stud_file(path + "/student_data.txt", ifstream::in); //read student data file
   /* if(stud_file.fail()) //Error catching
    {
        std::cout << "Error: student_data.txt not found.\nPress Enter to exit.";
        string temp;
        std::getline(std::cin, temp);
        exit(EXIT_FAILURE);
        return;
    }*/
    stud_file >> vec_size;
    for(int x =0; x<vec_size ; x++)
    {
        Course temp;
        stud_file >> temp;
        student->push_cour_taken(temp);

    }
    //(num_courses, courses, name, major, start, grad, total, degree)
    string maj_name, name;
    int start_year, grad_year, tot_credit, degree_cred;
    double GPA;
    stud_file >> name >> maj_name >> start_year >> grad_year >> tot_credit >> degree_cred >> GPA; //load student data from file (same order as save)
    student->set_name(name);
    student->set_start_year(start_year);
    student->set_grad_year(grad_year);
    student->set_tot_credit(tot_credit);
    student->set_degree_cred(degree_cred);
    student->set_stud_major(Engineering::choose_major(maj_name));
    student->set_GPA(GPA);

    //load semester data to student
    //example : "" (name)
    //          15 (hours)
    //          1 (course vector size)
    //          ECE 310...... (courses)
    //          "" (1 note?)
    for(int x = 1; x < student->get_plan().size()+1; x++){
        int hour;
        cout << student->get_plan().size();
        string note;
        stud_file >> name >> hour >> vec_size;

        student->get_sem(x)->Semester::set_sem_name(name);
        student->get_sem(x)->Semester::set_sem_hours(hour);

        for(int y = 0; y < vec_size; y++){
            Course temp;
            stud_file >> temp;
            student->get_sem(x)->Semester::get_sem_vec()->push_back(temp);
        }
        stud_file >> note;
        student->get_sem(x)->Semester::set_note_load(note);
    }


    //LOAD DEGREE DATA HERE
    student->get_stud_major()->load_deg_vec(student->get_stud_major());
    student->get_stud_major()->load_gen_vec(student->get_stud_major());
    stud_file.close();
}

/**
 * @brief
 */
vector<Course> Database::search_db(string s, vector<string> thing, double low, double up, int cnum, int crednum) //search for specific courses in the database
{
    std::cout << "\nEnter all attributes you wish to search by: ";
    std::cout << "\nAttributes to choose from: major, gpa, coursenum, credhours, libed, adv-comp, humanities, social, western, non-western, minority, CompEtech (technical electives).";
    std::cout << "\n  ->Default sort is by course name. Add \"sort\" as another attribute to sort from highest to lowest GPA.\n";
    vector<Course> vec = list_all;
    bool flag = false;
    if(s.find("major") != string::npos)
    {
        flag = true;
        std::cout << "\nList all course majors you wish to search for (separated by spaces), then type \"done\" when finished: \n";
        vec = real_search(vec, "maj", thing);
    }
    if(s.find("CompEtech") != string::npos)
    {
        flag = true;
        vec = real_search(vec, "atr", {"CEtech"});
    }
    if(s.find("libed") != string::npos)
    {
        flag = true;
        vec = real_search(vec, "atr", {"libed"});
    }
    if(s.find("humanities") != string::npos)
    {
        flag = true;
        vec = real_search(vec, "atr", {"HUM"});
    }
    if(s.find("social") != string::npos)
    {
        flag = true;
        vec = real_search(vec, "atr", {"SOC"});
    }
    if(s.find("western") != string::npos)
    {
        flag = true;
        vec = real_search(vec, "atr", {"WEST"});
    }
    if(s.find("non-western") != string::npos)
    {
        flag = true;
        vec = real_search(vec, "atr", {"NWST"});
    }
    if(s.find("minority") != string::npos)
    {
        flag = true;
        vec = real_search(vec, "atr", {"MIN"});
    }
    if(s.find("adv-comp") != string::npos)
    {
        flag = true;
        vec = real_search(vec, "atr", {"AC"});
    }
    if(s.find("gpa") != string::npos)
    {
        flag = true;
        std::cout << "\nEnter the lower bound for the GPA range to search by: (0.0 - 4.0)\n";
        std::cout << "\nEnter the upper bound for the GPA range to search by: (lowerbound - 4.0)\n";
        vec = real_search(vec, low, up);
    }
    if(s.find("coursenum") != string::npos)
    {
        flag = true;
        std::cout << "Enter course number: \n";
        vec = real_search(vec, "cnum", cnum);
    }
    if(s.find("credhours") != string::npos)
    {
        flag = true;
        std::cout << "Enter credit hour amount: \n";
        vec = real_search(vec, "chours", crednum);
    }
    if(s.find("sort") != string::npos)
    {
        flag = true;
        insertionsort(vec);
        reverse(vec.begin(), vec.end());
    }
    return vec;
}

/**
 * @brief
 *
 * @param vec
 * @param key
 * @param specific
 *
 * @return
 */
vector<Course> Database::real_search(vector<Course> vec, string key, vector<string> specific)
{ //helper function for search_db based on course name
    vector<Course> ret;
    if(key.compare("maj") == 0)
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            for(string ctype : specific)
            {
                if(vec[i].get_major().compare(ctype) == 0)
                    ret.push_back(vec[i]);
            }
        }
        return ret;
    }
    else if(key.compare("atr") == 0)
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            if(vec[i].get_attribute().find(specific[0]) != string::npos)
            {
                ret.push_back(vec[i]);
            }
        }
        return ret;
    }
    return ret;
}

/**
 * @brief
 *
 * @param vec
 * @param low
 * @param up
 *
 * @return
 */
vector<Course> Database::real_search(vector<Course> vec, double low, double up)
{ //helper function for search_db based on gpa
    vector<Course> ret;
    if(low < 0)
        low = 0.0;
    if(up > 4.00)
        up = 4.00;
    if(low > up)
    {
        low = up;
    }
    for(int i = 0; i < vec.size(); ++i)
    {
        if(vec[i].get_avgGPA() >= low && vec[i].get_avgGPA() <= up)
        {
            ret.push_back(vec[i]);
        }
    }
    return ret;
}

/**
 * @brief
 *
 * @param vec
 * @param key
 * @param num
 *
 * @return
 */
vector<Course> Database::real_search(vector<Course> vec, string key, int num)
{ //helper function for search_db based on credit hours
    vector<Course> ret;
    if(key.compare("cnum") == 0)
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            if(vec[i].get_course_num() == num)
            {
                ret.push_back(vec[i]);
            }
        }
        return ret;
    }
    else if(key.compare("chours") == 0)
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            if(vec[i].get_credit_hours() == num)
            {
                ret.push_back(vec[i]);
            }
        }
        return ret;
    }
    return ret;
}

/**
 * @brief
 *
 * @param major
 * @param c_num
 *
 * @return
 */
Course Database::find_course(string major, int c_num)
{
    Course c(major, c_num);
    for(int x = 0;x <list_all.size();x++){
        if(list_all[x] == c){
            return list_all[x];
        }
    }
    return Course();
}

/**
 * @brief
 *
 * @param a
 * @param x
 *
 * @return
 */
Course Database::bsearch(vector <Course> & a, Course & x)  //sorts vectors by name and course number
{
    int low = 0;
    int high = a.size() -1;

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(x < a[mid])
            high = mid - 1;

        else if(x > a[mid])
            low = mid + 1;
        else

            return a[mid];
    }

    return Course();
}

/**
 * @brief
 *
 * @param arr
 */
void Database::insertionsort(vector<Course>& arr)
{
    int i, j, n = arr.size();
    Course key;
    for(i = 1; i < n; ++i)
    {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j].get_avgGPA() > key.get_avgGPA())
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

/**
 * @brief
 *
 * @param s
 * @param repl
 */
void Database::change_char(string& s, char repl)
{
    char find = repl == '_' ? ' ' : '_';
    for(int i = 0; i < s.size(); ++i)
        if(s[i] == find)
            s[i] = repl;
}
