#ifndef TIGER_H
#define TIGER_H
#include "animal.h"

using namespace std;

class tiger: public animal {
    public:
        tiger();
        tiger(int, int, int, float, float);
};
#endif

