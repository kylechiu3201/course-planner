cmake_minimum_required(VERSION 3.15)
project(Planner_11_0)

set(CMAKE_CXX_STANDARD 14)

include_directories(Command)
include_directories(Course)
include_directories(Database)
include_directories(Engineering)
include_directories(Engineering/CompE)
include_directories(Semester)
include_directories(Student)

add_executable(Planner_11_0
        Command/Command.cpp
        Command/Command.h
        Course/Course.cpp
        Course/Course.h
        Database/Database.cpp
        Database/Database.h
        Engineering/CompE/CompE.cpp
        Engineering/CompE/CompE.h
        Engineering/Engineering.cpp
        Engineering/Engineering.h
        Semester/Semester.cpp
        Semester/Semester.h
        Student/Student.cpp
        Student/Student.h
        "txt files/CE_Data.txt"
        "txt files/cecourses.txt"
        "txt files/CEreq.txt"
        "txt files/CEtech.txt"
        "txt files/compi.txt"
        "txt files/compilecommand.txt"
        "txt files/course_database.txt"
        "txt files/cscourses.txt"
        "txt files/ececscourses.txt"
        "txt files/eecourses.txt"
        "txt files/gened.txt"
        "txt files/makefile"
        main.cpp)
