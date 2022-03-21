#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include "event.h"

class gold : public event {
    private:

    public:
        gold();
        void print_percept();
        char get_symbol();
        void encounter();
};


#endif