#include "CompE.h"
#include "../Engineering.h"
#include "../../Database.h"
#include "../../Course/Course.h"
#include <iostream>
#include <vector>
#include <fstream>

    int CompE::tech_hours = 27;
    CompE()
    {
        foundations = vector<Course>(10); //Math, Science core
        core = vector<Course>(10);
        gen_electives; //not EE or adv computing or capstone
        EE_foundation = vector<Course>(1);
        adv_computing = vector<Course>(3);
        capstone = vector<Course>(1); //445 411 496 499
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
    
    vector<Course> CompE::get_foundations()
    {
        return foundations;
    }
    vector<Course> CompE::get_core()
    {
        return get_core;
    }
    vector<Course> CompE::get_gen_electives()
    {
        return gen_electives;
    }
    vector<Course> CompE::get_EE_foundation()
    {
        return EE_foundation;
    }
    vector<Course> CompE::get_adv_computing();
    {
        return adv_computing;
    }
    vector<Course> CompE::get_capstone()
    {
        return capstone;
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
        //if this doesn't work, need to make getters to get size of each vector.
        /*All.reserve(CompE::pos_foundations.size()+pos_core.size()+pos_gen_electives.size()+pos_EE_Foundation.size()+pos_adv_computing.size()+pos_capstone.size()+Engineering::pos_geneds.size()+Engineering::pos_lang.size()+Engineering::pos_compos.size());
        All.insert(All.end(), CompE::pos_foundations.begin(), pos_foundations.end());
        All.insert(All.end(), pos_core.begin(), pos_core.end());
        All.insert(All.end(), pos_gen_electives.begin(), pos_gen_electives.end());
        All.insert(All.end(), pos_EE_Foundation.begin(), pos_EE_Foundation.end());
        All.insert(All.end(), pos_adv_computing.begin(), pos_adv_computing.end());
        All.insert(All.end(), pos_capstone.begin(), pos_capstone.end());
        All.insert(All.end(), pos_geneds.begin(), pos_geneds.end());
        All.insert(All.end(), pos_lang.begin(), pos_lang.end());
        All.insert(All.end(), pos_compos.begin(), pos_compos.end());*/
        if(Engineering::searchreq(get_pos_foundations(),c)==true || Engineering::searchreq(get_pos_core(), c) == true || Engineering::searchreq(get_pos_gen_electives(), c)==true || Engineering::searchreq(get_pos_EE_Foundation(), c) ==true || Engineering::searchreq(get_pos_adv_computing(), c)==true || Engineering::searchreq(get_pos_capstone(), c)==true)
        {
            return true;
        }
        return false;
      
    }
    //command to add course, student class calls this? 
    
    void CompE::add_to_degree(Course c, Engineering major)
    {
        int size;
        
        /*if(CompE::check_degree(c)==false)
        {
            return;
        }*/
        if(Engineering::searchreq(get_pos_foundations(), c))
        {
            if(!Engineering::searchreq(major.get_foundations(), c))
            {
                 major.get_foundations().push_back(c);
            }
        }
        else if(Engineering::searchreq(get_pos_core(), c))
        {
            if(!Engineering::searchreq(major.get_core(), c))
            {
                major.get_core().push_back(c);
            }
        }
        else if(Engineering::searchreq(get_pos_gen_electives(), c))
        {
            if(!Engineering::searchreq(major.get_gen_electives(), c))
            {
                major.get_core().push_back(c);
            }
        }
        else if(Engineering::searchreq(get_pos_EE_Foundation(), c))
        {
            if(!Engineering::searchreq(major.get_EE_foundation(), c))
            {
                major.get_EE_foundation().push_back(c);
            }
        }
        else if(Engineering::searchreq(get_pos_adv_computing(), c))
        {
            if(!Engineering::searchreq(major.get_adv_computing(), c))
            {
                 major.get_adv_computing().push_back(c);
            }
          
        }
        else if(Engineering::searchreq(get_pos_capstone(), c))
        {
            if(!Engineering::searchreq(major.get_capstone(), c))
            {
                 major.get_capstone().push_back(c);
            }
          
        }
        
        
    }
    void fill_pos_vec()
    {
        ifstream file("CE_Data.txt");
        if (file.fail())
        {
            cout<< "file failed to open"
            return;
            // file is not open
        }
        int lengths[6]; 
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
    int is_satisfied(vector<Course> vec)
    {
        
    }
    
    
        
  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    