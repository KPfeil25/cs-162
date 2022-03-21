#include "room.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

using namespace std;

/******************************************************
** Function: room()
** Description: room default constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: room created
******************************************************/
room::room() {
    this->e1 = NULL;
}

/******************************************************
** Function: clear_board()
** Description: essentially a destructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: room destroyed
******************************************************/
void room::clear_board() {
    //cout << "room destructor" << endl;
    delete e1;
}

/******************************************************
** Function: set_bats()
** Description: sets a room to have bats
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: room has bats
******************************************************/
void room::set_bats() {
    this->e1 = new bats();
}

/******************************************************
** Function: set_gold()
** Description: sets a room to have gold
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: room has gold
******************************************************/
void room::set_gold() {
    this->e1 = new gold();
}

/******************************************************
** Function: set_pit()
** Description: sets a room to have a pit
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: room has a pit
******************************************************/
void room::set_pit() {
    this->e1 = new pit();
}

/******************************************************
** Function: set_wumpus()
** Description: sets a room to have the wumpus
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: room has the wumpus
******************************************************/
void room::set_wumpus() {
    this->e1 = new wumpus();
}

/******************************************************
** Function: set_event_for_blank()
** Description: for when the wumpus dies
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: wumpus symbol is " "
******************************************************/
void room::set_event_to_blank() {
    this->e1->set_symbol(' ');
}

/******************************************************
** Function: get_symbol()
** Description: gets a symbol for a room if it has onw
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: returns the rooms symbol
******************************************************/
char room::get_symbol() {
    if (this->e1 == NULL) {
        return ' ';
    }
    return this->e1->get_symbol();
}

/******************************************************
** Function: get_event()
** Description: gets an event
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: event gets gotten
******************************************************/
event* room::get_event() {
    return this->e1;
}


