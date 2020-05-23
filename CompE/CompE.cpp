#include "CompE.h"
#include <iostream>
#include <vector>


    int CompE:: get_tech_hours(vector<Course> EE_foundation, vector<Course> adv_computing, vector<Course> gen_electives, vector<Course> capstone)
    {
        int sum = 0;
        if(EE_foundation.empty())
        {
            sum += EE_foundation[0].get_credit_hours();
        }
        for(int x = 0 ; x < 3 ; x++)
        {
            if(adv_computing.empty())
            {
                sum += adv_computing[x].get_credit_hours();
            }
        }
        for(int x =0 ; x < gen_electives.size(); x++)
        {
            if(gen_electives.empty())
            {
                sum += gen_electives[x].get_credit_hours();
            }
        }
        
        if(capstone.empty())
        {
            sum += capstone[0].get_credit_hours();
        }
        
        return sum;
    }