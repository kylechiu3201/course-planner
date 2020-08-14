#include "Course.h"
#include <iostream>
#include <string>

//constructors
/**
* @brief Creates a Course object based on the given parameters
*
* @param maj The major of the course
* @param cnum The course number of the course
* @param n The name of the course
* @param chours The number of credit hours of the course
* @param gpa The average GPA of the course
* @param atr Any course attributes (e.g. technical elective, humanities, etc.)
* @param grade1 The grade received for the course (default to NT for Not Taken)
*/
Course::Course(string maj, int cnum, string n,  int chours, double gpa, string atr) //for our use to load classes from save file
{
    major = maj;
    name = n;
    course_num = cnum;
    avgGPA = gpa;
    credit_hours = chours;
    attribute = atr;
    grade = "NT";  //grade
}

/**
 * @brief Creates a Course object based on the given parameters
 *
 * @param maj The major of the course
 * @param cnum The course number of the course
 * @param n The name of the course
 * @param chours The number of credit hours of the course
 * @param gpa The average GPA of the course
 * @param atr Any course attributes (e.g. technical elective, humanities, etc.)
 * @param grade1 The grade received for the course (default to NT for Not Taken)
 */
Course::Course(string maj, int cnum, string n,  int chours, double gpa, string atr, string grade1 = "NT") //for our use to load classes from save file
{
    major = maj;
    name = n;
    course_num = cnum;
    avgGPA = gpa;
    credit_hours = chours;
    attribute = atr;
    grade = grade1;  //grade
}

/**
 * @brief creates an empty Course object with empty default values
 */
Course::Course()  //empty course
{
    major = "";
    name = "";
    course_num = 0;
    avgGPA = 0.0;
    credit_hours = 0;
    grade = "NT"; //DEFAULT setting until added from Planner Class
    attribute = "NA";
}

/**
 * @brief Creates a Course object based on the major and the course number
 *
 * @param maj The major of the course
 * @param num The course number of the course
 */
Course::Course(string maj, int num){
    major = maj;
    name = "";//maj+" "+std::to_string(num);
    course_num = num;
    avgGPA = 0.0;
    credit_hours = 0;
    grade = "NT";
    attribute = "NA";
}

//getters
/**
 * @brief Gets the major of the course
 *
 * @return The major of the course (e.g. ECE)
 */
string Course::get_major()
{
    return major;
}

/**
 * @brief Gets the name of the course
 *
 * @return The name of the course
 */
string Course::get_name()
{
    return name;
}

/**
 * @brief Gets the course number of the course
 *
 * @return The course number of the course
 */
int Course::get_course_num()
{
    return course_num;
}

/**
 * @brief Gets the average GPA of the course
 *
 * @return The average GPA of the course
 */
double Course:: get_avgGPA()
{
    return avgGPA;
}

/**
 * @brief Gets the credit hours of the course
 *
 * @return The credit hours of the course
 */
int Course::get_credit_hours()
{
    return credit_hours;
}

/**
 * @brief Gets the grade received for the course
 *
 * @return The grade received for the course
 */
string Course:: get_grade(){
    return grade;
}

/**
 * @brief Gets any course attributes of the course (e.g. technical electives, humanities, etc.)
 *
 * @return Any course attributes of the course (e.g. technical electives, humanities, etc.)
 */
string Course::get_attribute()
{
    return attribute;
}

//setters
/**
 * @brief Sets the major of the course
 *
 * @param maj The major to set to
 */
void Course:: set_major(string maj)
{
    major = maj;
}

/**
 * @brief Sets the name of the course
 *
 * @param n The name of the course to set to
 */
void Course:: set_name(string n)
{
    name = n;
}

/**
 * @brief Sets the course number of the course
 *
 * @param num The course number of the course to set to
 */
void Course:: set_course_num(int num)
{
    course_num = num;
}

/**
 * @brief Sets the average GPA of the course
 *
 * @param gpa The average GPA to set to
 */
void Course:: set_avgGPA(double gpa)
{
    avgGPA = gpa;
}

/**
 * @brief Sets the number of credit hours of the course
 *
 * @param hours The number of credit hours to set to
 */
void Course:: set_credit_hours(int hours)
{
    credit_hours = hours;
}

/**
 * @brief Sets the received grade of the course
 *
 * @param g The gade to set to
 */
void Course:: set_grade(string g)
{
    grade = g;
}

/**
 * @brief Sets the attributes of the course
 *
 * @param attr The attributes to set
 */
void Course:: set_attribute(string attr)
{
    attribute = attr;
}

//other functions
/**
 * @brief Overloads < for course comparison based on course major alphabetical order, then course number size
 *
 * @param c The course to compare to
 */
bool Course::operator< (Course & c)  //overloads < to sort courses by major and number
{
    if(major.compare(c.major) < 0)
    {
        return true;
    }
    else if(major.compare(c.major) == 0)
    {
        if(course_num<c.course_num)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Overloads > for course comparison based on course major alphabetical order, then course number size
 *
 * @param c The course to compare to
 */
bool Course::operator> (Course & c)
{
    if(major.compare(c.major) > 0)
    {
        return true;
    }
    else if(major.compare(c.major) == 0)
    {
        if(course_num>c.course_num)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Overloads == for course equality comparison based on both course major equality and course number equality
 *
 * @param c The course to compare to
 */
bool Course::operator== (Course c)
{
    if(major.compare(c.major) == 0 && course_num == c.course_num)
        return true;
    return false;
}

/**
 * @brief Gets the GPA value of the course based on the received letter grade
 *
 * @return the GPA value of the course
 */
double Course:: get_gpa_value()
{
    if(grade.compare("A+") == 0){
        return 4.0;
    }
    if(grade.compare("A") == 0){
        return 4.0;
    }
    if(grade.compare("A-") == 0){
        return 3.67;
    }
    if(grade.compare("B+") == 0){
        return 3.33;
    }
    if(grade.compare("B") == 0){
        return 3.0;
    }
    if(grade.compare("B-") == 0){
        return 2.67;
    }
    if(grade.compare("C+") == 0){
        return 2.33;
    }
    if(grade.compare("C") == 0){
        return 2.0;
    }
    if(grade.compare("C-") == 0){
        return 1.67;
    }
    if(grade.compare("D+") == 0){
        return 1.33;
    }
    if(grade.compare("D") == 0){
        return 1.0;
    }
    if(grade.compare("D-") == 0){
        return 0.67;
    }
    return 0.0;
}

//Course object overloads
/**
 * @brief Overloads << for easier saving of courses in the save file by adding a space between every private variable of the Course object
 *
 * @param out The output stream (to a save file)
 * @param obj The course to save
 */
ostream& operator <<(ostream& out, const Course& obj)  //overloads << for database class
{
  out << obj.major << " " << obj.course_num << " " << obj.name << " " << obj.credit_hours  << " " << obj.avgGPA << " " << obj.attribute << " " << obj.grade << "\n";
     return out;
}

/**
 * @brief Overloads >> for easier data reading of courses in the save file by storing each input into its respective private variable of a Course object
 *
 * @param in The input stream (from reading a file)
 * @param obj The course to read
 */
istream& operator >>(istream& in, Course& obj)   //overloads >> for database class
{
    in >> obj.major  >> obj.course_num >> obj.name >> obj.credit_hours  >> obj.avgGPA   >> obj.attribute  >> obj.grade;
    return in;
}

/**
 * @brief Displays all courses in a given Course vector along with its credit hours and average GPA
 *
 * @param vec The vector of Course objects to display
 */
void Course::display(vector<Course> &vec)
{
    cout << "Course       Credit Hours   Average GPA\n";
    cout << "----------------------------------------\n";
    for(int i = 0; i < vec.size(); ++i)
    {
        string course = vec[i].major + " " + to_string(vec[i].course_num);
        int len = course.length();
        string space = "           ";
        space = space.substr(0, 8 - len + 5);
        string comp = vec[i].credit_hours > 9 ? "" : " ";
        std::cout << course << space << vec[i].credit_hours << "            " << comp << vec[i].avgGPA << "\n";
    }
}


