#include "gold.h"
#include "event.h"

using namespace std;

/******************************************************
** Function: gold()
** Description: gold default constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: gold object created
******************************************************/
gold::gold() : event('G', "You see a glimmer nearby.") {}

/******************************************************
** Function: print_percept()
** Description: percept printed for gold
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: percerpt printed for correct object
******************************************************/
void gold::print_percept() {
    cout << "You see a glimmer nearby." << endl;
}

/******************************************************
** Function: get_symbol()
** Description: symbol getter for gold
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: symbol returned for gold
******************************************************/
char gold::get_symbol() {
    return this->symbol;
}

/******************************************************
** Function: encounter()
** Description: not sure
** Parameters: nah
** Pre-Conditions: n/a
** Post-Conditions: not much
******************************************************/
void gold::encounter() {

}