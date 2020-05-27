#include "CS.h"
#include "../Engineering.h"
#include "../../Database.h"
#include <iostream>
#include <vector>

    CS(){
    }
    
    //getters
    vector<Course> CS::get_pos_cs_foundations(){
        return pos_cs_foundations;
    }
    vector<Course> CS::get_pos_cs_core(){
        return pos_cs_core;
    }
    vector<Course> CS::get_pos_cs_adv_electives(){
        return pos_cs_adv_electives;
    }
    vector<Course> CS::get_pos_cs_gen_electives(){
        return pos_cs_gen_electives;
    }
    vector<Course> CS::get_pos_cs_other_tech(){
        return pos_cs_other_tech;
    }

    //Departmental getters
    vector<Course> CS::get_pos_cs_team_proj(){
        return pos_cs_team_proj;
    }
    vector<Course> CS::get_pos_cs_software_foundation(){
        return pos_cs_software_foundation;
    }
    vector<Course> CS::get_pos_cs_alg(){
        return pos_cs_alg;
    }
    vector<Course> CS::get_pos_cs_data(){
        return pos_cs_data;
    }
    vector<Course> CS::get_pos_cs_social(){
        return pos_cs_social;
    }
    vector<Course> CS::get_pos_cs_media(){
        return pos_cs_media;
    }
    vector<Course> CS::get_pos_cs_perfcomp(){
        return pos_cs_perfcomp;
    }
    vector<Course> CS::get_pos_cs_sec(){
        return pos_cs_sec;
    }
    vector<Course> CS::get_pos_cs_mach(){
        return pos_cs_mach;
    }
    
    vector<Course> CS::get_foundations(){
        return foundations;
    }
    vector<Course> CS::get_core(){
        return core;
    }
    vector<Course> CS::get_gen_electives(){
        return gen_electives;
    }
    vector<Course> CS::get_dpt_electives(){
        return dpt_electives;
    }
    vector<Course> CS::get_cs_adv_electives(){
        return cs_adv_electives;
    }
    vector<Course> CS::get_team_proj(){
        return team_proj;
    }
    vector<Course> CS::get_other_tech(){
        return other_tech;
    }

    int CS::get_cs_tech_hours(vector<Course> & dpt_electives, vector<Course> & cs_adv_electives, vector<Course> & other_tech, vector<Course> & team_proj, vector<Course> & gen_electives)
    {
        int sum = 0;
        for(int x = 0 ; x < 3 ; x++)
        {
            if(!dep_electives.empty())
            {
                sum += dep_electives[x].get_credit_hours();
            }
        }
        for(int x = 0 ; x < 2 ; x++)
        {
            if(!cs_adv_electives.empty())
            {
                sum += cs_adv_electives[x].get_credit_hours();
            }
        }
        for(int x =0 ; x < gen_electives.size(); x++)
        {
            if(!gen_electives.empty())
            {
                sum += gen_electives[x].get_credit_hours();
            }
        }
        for(int x = 0 ; x < 2 ; x++)
        {
            if(!other_tech.empty())
            {
                sum += other_tech[x].get_credit_hours();
            }
        }
        
        if(!team_proj.empty())
        {
            sum += team_proj[0].get_credit_hours();
        }
        
        return sum;
    }
    //checks if a course is part of degree 
        bool CS::check_cs_degree(Course c){
        /*std::vector<Course> All;
        //if this doesn't work, need to make getters to get size of each vector.
        All.reserve(pos_cs_team_proj.size()+pos_cs_software_foundation.size()+pos_cs_alg.size()+pos_cs_data.size()+pos_cs_social.size()+pos_cs_media.size()+pos_cs_perfcomp.size()+pos_cs_sec.size()+pos_cs_mach.size()+pos_cs_foundations.size()+pos_cs_core.size()+pos_cs_adv_electives.size()+pos_cs_gen_electives.size()+pos_cs_other_tech.size()+Engineering::pos_geneds.size()+Engineering::pos_lang.size()+Engineering::pos_compos.size());
        All.insert(All.end(), pos_cs_foundations.begin(), pos_cs_foundations.end());
        All.insert(All.end(), pos_cs_core.begin(), pos_cs_core.end());
        All.insert(All.end(), pos_cs_team_proj.begin(), pos_cs_team_proj.end());
        All.insert(All.end(), pos_cs_software_foundation.begin(), pos_cs_software_foundation.end());
        All.insert(All.end(), pos_cs_alg.begin(), pos_cs_alg.end());
        All.insert(All.end(), pos_cs_data.begin(), pos_cs_data.end());
        All.insert(All.end(), pos_cs_social.begin(), pos_cs_social.end());
        All.insert(All.end(), pos_cs_media.begin(), pos_cs_media.end());
        All.insert(All.end(), pos_cs_perfcomp.begin(), pos_cs_perfcomp.end());
        All.insert(All.end(), pos_cs_sec.begin(), pos_cs_sec.end());
        All.insert(All.end(), pos_cs_mach.begin(), pos_cs_mach.end());
        All.insert(All.end(), pos_cs_adv_electives.begin(), pos_cs_adv_electives.end());
        All.insert(All.end(), pos_cs_gen_electives.begin(), pos_cs_gen_electives.end());
        All.insert(All.end(), pos_cs_other_tech.begin(), pos_cs_other_tech.end());
        All.insert(All.end(), pos_geneds.begin(), pos_geneds.end());
        All.insert(All.end(), pos_lang.begin(), pos_lang.end());
        All.insert(All.end(), pos_compos.begin(), pos_compos.end());
        
        for(int x =0; x< All.size(); x++)
        {
            if(All[x].get_major()==c.get_major() && All[x].get_course_num()==c.get_course_num())
            {
                return true;
            }
        }
        return false;
        */
        if(Engineering::searchreq(pos_cs_foundations(),c)==true || Engineering::searchreq(pos_cs_core(), c) == true || Engineering::searchreq(pos_cs_team_proj(), c)==true || Engineering::searchreq(pos_cs_software_foundation(), c) ==true || Engineering::searchreq(pos_cs_alg(), c)==true || Engineering::searchreq(pos_cs_data(), c)==true || Engineering::searchreq(pos_cs_social(), c)==true || Engineering::searchreq(pos_cs_media(), c)==true || Engineering::searchreq(pos_cs_perfcomp(), c)==true || Engineering::searchreq(pos_cs_sec(), c)==true || Engineering::searchreq(pos_cs_mach(), c)==true || Engineering::searchreq(pos_cs_adv_electives(), c)==true || Engineering::searchreq(pos_cs_gen_electives(), c)==true || Engineering::searchreq(pos_cs_other_tech(), c)==true || Engineering::searchreq(pos_geneds(), c)==true || Engineering::searchreq(pos_lang(), c)==true || Engineering::searchreq(pos_compos(), c)==true)
        {
            return true;
        }
        return false;
        
    }
    
    void CS::add_cs_to_degree(Course c, Engineering * major){
        
    }
    
        