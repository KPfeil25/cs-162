#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <fstream>
#include "TeachersAndSchedule.h"

using namespace std;

class Course{
  private:
    string name;
    string teacher;
    int current_enrollment;
    string* roster;
    int num_courses;
    schedule* course_time;
  public:
    Course();//1
    Course(string, string, int, string*, schedule*);//2
    ~Course();//3
    Course(const Course&);//4
    Course& operator=(const Course&);//5
    void set_name(string);//6
    string get_name();//7
    void set_teacher(string);//8
    string get_teacher();//9
    void set_current_enrollment(int);//10
    int get_current_enrollment();//11
    void set_roster(string*);//12
    string get_roster(int);//13
    void set_num_courses(int);//14
    int get_num_courses();//15
    void set_course_time(schedule*);//16
    schedule* get_course_time();//17
    void change_course_time(schedule* course_time);//18
    void enroll_student(string new_student);//19
    void get_course_info(Course*);//20
    void info_into_courses(fstream&);//21
};
#endif