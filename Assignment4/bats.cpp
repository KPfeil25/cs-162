#include "bats.h"
#include "event.h"

using namespace std;

/******************************************************
** Function: bats()
** Description: bats default constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bats object created
******************************************************/
bats::bats() : event('B', "You hear wings flapping.") {}

/******************************************************
** Function: ~bats()
** Description: bats destructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bat destroyed
******************************************************/
bats::~bats(){}

/******************************************************
** Function: print_percept()
** Description: percept printed for bats
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: percerpt printed for correct object
******************************************************/
void bats::print_percept() {
    cout << "You hear wings flapping." << endl;
}

/******************************************************
** Function: get_symbol()
** Description: symbol getter for bats
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: symbol returned for bats
******************************************************/
char bats::get_symbol() {
    return this->symbol;
}

/******************************************************
** Function: encounter()
** Description: not sure
** Parameters: nah
** Pre-Conditions: n/a
** Post-Conditions: not much
******************************************************/
void bats::encounter() {
    
}

