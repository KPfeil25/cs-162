#ifndef BEAR_H
#define BEAR_H
#include "animal.h"

using namespace std;

class bear: public animal {
    public:
        bear();
        bear(int, int, int, float, float);
};
#endif