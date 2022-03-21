#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "event.h"
#include "bats.h"
#include "gold.h"
#include "wumpus.h"
#include "pit.h"

using namespace std;

class room{
    private:
        event* e1;
    public:
        room();
        void clear_board();

        void set_bats();
        void set_gold();
        void set_pit();
        void set_wumpus();
        void set_event_to_blank();
        char get_symbol();
        event* get_event();
};

#endif