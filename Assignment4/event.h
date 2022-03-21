#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <cstdlib>

using namespace std;

class event{
    protected:
        char symbol;
        string percept;
    public:
        event();
        event(char, string);
        virtual ~event();
        virtual void print_percept() = 0;
        virtual void encounter() = 0;
        char get_symbol();
        void set_symbol(char);
};


#endif