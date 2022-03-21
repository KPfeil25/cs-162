#include "event.h"

using namespace std;

/******************************************************
** Function: event()
** Description: event default constructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: event object created
******************************************************/
event::event() {}

/******************************************************
** Function: ~event()
** Description: event destructor
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: event destroyed
******************************************************/
event::~event(){}

/******************************************************
** Function: event(w/ params)
** Description: event parameterized constructor
** Parameters: char, string
** Pre-Conditions: n/a
** Post-Conditions: event created
******************************************************/
event::event(char symbol, string percept) {
    this->symbol = symbol;
    this->percept = percept;
}

/******************************************************
** Function: get_symbol()
** Description: symbol getter for event
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: symbol returned for a certain event
******************************************************/
char event::get_symbol() {
    return this->symbol;
}

/******************************************************
** Function: set_symbol()
** Description: symbol setter for event
** Parameters: char
** Pre-Conditions: n/a
** Post-Conditions: symbol set for event
******************************************************/
void event::set_symbol(char symbol) {
    this->symbol = symbol;
}
