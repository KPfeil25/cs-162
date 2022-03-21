#include "wumpus.h"

using namespace std;

/******************************************************
** Function: wumpus()
** Description: wumpus default constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: wumpus object created
******************************************************/
wumpus::wumpus() : event('W', "You smell a terrible stench.") {}

/******************************************************
** Function: print_percept()
** Description: percept printed for wumpus
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: percerpt printed for correct object
******************************************************/
void wumpus::print_percept() {
    cout << "You smell a terrible stench." << endl;
}

/******************************************************
** Function: get_symbol()
** Description: symbol getter for bats
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: symbol returned for bats
******************************************************/
char wumpus::get_symbol() {
    return this->symbol;
}

/******************************************************
** Function: encounter()
** Description: not sure
** Parameters: nah
** Pre-Conditions: n/a
** Post-Conditions: not much
******************************************************/
void wumpus::encounter() {
    
}