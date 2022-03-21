#include "pit.h"

using namespace std;

/******************************************************
** Function: pit()
** Description: pit default constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: pit object created
******************************************************/
pit::pit() : event('P', "You feel a breeze.") {}

/******************************************************
** Function: print_percept()
** Description: percept printed for pit
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: percerpt printed for correct object
******************************************************/
void pit::print_percept() {
    cout << "You feel a breeze." << endl;
}

/******************************************************
** Function: get_symbol()
** Description: symbol getter for pit
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: symbol returned for pit
******************************************************/
char pit::get_symbol() {
    return this->symbol;
}

/******************************************************
** Function: encounter()
** Description: not sure
** Parameters: nah
** Pre-Conditions: n/a
** Post-Conditions: not much
******************************************************/
void pit::encounter() {
    
}