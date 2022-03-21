#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include "event.h"

using namespace std;

class wumpus : public event{
    private:

    public:
        wumpus();
        void print_percept();
        char get_symbol();
        void encounter();
};

#endif