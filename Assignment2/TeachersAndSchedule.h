#ifndef TEACHERSANDSCHEDULE_H
#define TEACHERSANDSCHEDULE_H
#include <iostream>

using namespace std;

struct teacher{
  int id;
  string password;
  string first_name;
  string last_name;
};
struct schedule{
  string days;
  string start_time;
  string end_time;
  string term;
  string location;
};
#endif