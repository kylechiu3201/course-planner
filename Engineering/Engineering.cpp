#include <iostream>
#include <vector>
#include <string>
#include "Engineering.h"
#include "CompE/CompE.h"
using namespace std;

const int Engineering::tot_hours = 128;
vector<Course> Engineering::pos_geneds = vector<Course>();
vector<Course> Engineering::get_geneds()
{
    return pos_geneds;
}

static void fill_pos_vec()
{
    return;
}

int Engineering::get_tot_hours()
{
    return tot_hours;
}



 Engineering * Engineering::choose_major(string maj){
    Engineering * obj;
    if(maj.compare("CE") == 0)
    {
         obj = new CompE();
    }
    /*else if(maj.compare("CS")==0)
    {
        Engineering * obj = new CS();
    }
    else if(maj.compare("EE")==0)
    {
        Engineering * obj = new EE();
    } */
    else{
        cout << "Invalid Major \n";
        return NULL;
    }
    return obj;
}


    bool Engineering::search_req(pair<vector<Course>, int> vec, Course c)
    {
        for(int x= 0 ; x< vec.first.size() ; x++)
        {
            if(vec.first[x] == c)
            {
                return true;
            }
        }
        return false;
    }
    int Engineering:: search_req_index(pair<vector<Course>, int> vec, Course c)
    {
        for(int x= 0 ; x< vec.first.size() ; x++)
        {
            if(vec.first[x] == c)
            {
                return x;
            }
        }
        return -1;
    }

    int Engineering::search_req2(vector<Course> vec, Course c)
    {
        for(int x= 0 ; x< vec.size() ; x++)
        {
            if(vec[x] == c)
            {
                return true;
            }
        }
        return false;
    }

