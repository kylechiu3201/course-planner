#include <iostream>
#include <vector>
#include "Engineering.h"
#include "../Course/Course.h"
using namespace std;

const int Engineering::tot_hours = 128;
vector<Course> Engineering::get_geneds()
{
    return pos_geneds;
}

int Engineering::get_tot_hours()
{
    return tot_hours;
}

 Engineering * Engineering::choose_major(string maj){
    if(maj.compare("CE") == 0)
    {
        Engineering * obj = new CE();
    }
    else if(maj.compare("CS")==0)
    {
        Engineering * obj = new CS();
    }
    else if(maj.compare("EE")==0)
    {
        Engineering * obj = new EE();
    }
    else{
        cout << "Invalid Major";
        return NULL;
    }
    return &obj;
}

    bool Engineering::search_req(vector<Course> vec, Course c)
    {
        for(int x= 0 ; x< vec.size() ; x++)
        {
            if(vec[x].get_major().compareto(c.get_major())==0 && vec[x].get_course_num() == c.get_course_num())
            {
                return true;
            }
        }
        return false;
    }
    