#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "course.h"
#include "university.h"

int welcome();
void teacher_login();
int find_num_courses();
int find_num_teachers();
int print_teacher_options();
void view_or_remove_students(University&);
void add_or_remove_course(University&);
void all_actions(University&);

#endif