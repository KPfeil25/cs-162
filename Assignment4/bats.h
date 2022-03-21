#ifndef BATS_H
#define BATS_H

#include <iostream>
#include "event.h"

using namespace std;

class bats : public event{
    public:
        bats();
        ~bats();
        
        void print_percept();
        char get_symbol();
        void encounter();
};

#endif
