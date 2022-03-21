#ifndef PIT_H
#define PIT_H

#include <iostream>
#include "event.h"

class pit : public event {
    private:

    public:
        pit();
        void print_percept();
        char get_symbol();
        void encounter();
};


#endif