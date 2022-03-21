#ifndef SEA_LION_H
#define SEA_LION_H
#include "animal.h"

using namespace std;

class sea_lion: public animal {
    public:
        sea_lion();
        sea_lion(int, int, int, float, float);
};
#endif