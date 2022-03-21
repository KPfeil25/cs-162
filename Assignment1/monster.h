#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
using namespace std;

struct monster {
    string name;
    string type;
    int level;
    int num_attacks;
    float avg_effectiveness;
    struct attack *a;
};
#endif