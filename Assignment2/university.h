#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "course.h"
#include <iostream>

using namespace std;

class University{
  private:
    string name;
    string address;
    string current_term;
    int num_teachers;
    teacher* teachers;
    int num_courses;
    Course* courses;
  public:
    University();//1
    University(string name, string address, string current_term, teacher* teachers, int num_courses, Course* courses);//2
    ~University();//3
    University(const University&);//4
    University& operator=(const University&);//5
    void set_Uni_name(string);//6
    string get_uni_name();//7
    void set_address(string);//8
    string get_address();//9
    void set_current_term(string);//10
    string get_current_term();//11
    void set_teachers(teacher*);//12
    teacher* get_teachers();//13
    void set_num_teachers(int);//14
    int get_num_teachers();//15
    void set_num_courses(int);//16
    void get_num_courses();//17
    void set_courses(Course*);//18
    Course* get_courses();//19
    void search_courses_by_term(string term);//20
    void search_courses_by_times(string* times, int num_times);//21
    void add_to_catalog(Course course_to_add);//22
    void remove_from_catalog();//23
    void get_uni_info();//24
    teacher* create_teacher_arr();//25
    void create_course_arr();//26
    void get_teacher_info(teacher*);//27
    void populate_courses(fstream&);//28
    void get_all_info();//29
    void teacher_login();//30
    void all_student_options(int);
    void change_course_name();
    void change_teacher_name();
    void change_course_term();
    void change_course_days();
    void change_course_start_time();
    void change_course_end_time();
    void change_course_location();
    void change_course_enrollment();
    void all_teacher_options(int);
    void print_new_courses();
    void view_students();
    void add_to_catalog();
    Course get_new_course_info();
    void remove_student();
    void view_enrollment_and_address(University&);
};
#endif
