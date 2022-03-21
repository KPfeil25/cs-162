#include "animal.h"

using namespace std;

/*********************************************************************
** Function: animal()
** Description: default constructor for animal class
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: animal object created
*********************************************************************/
animal::animal() {
    this->age = 0;
    this->cost = 0;
    this->babies = 0;
    this->food_cost = 0;
    this->revenue = 0;
}

/*********************************************************************
** Function: animal(w/ parameters)
** Description: parameterized constructor for animal class
** Parameters: int age, int cost, int babies, float food_cost, float revenue
** Pre-Conditions: n/a
** Post-Conditions: animal object created
*********************************************************************/
animal::animal(int age, int cost, int babies, float food_cost, float revenue) {
    this->age = age;
    this->cost = cost;
    this->babies = babies;
    this->food_cost = food_cost;
    this->revenue = revenue;
}

/*********************************************************************
** Function: set_age()
** Description: setter for animal ages
** Parameters: age you want to set
** Pre-Conditions: n/a
** Post-Conditions: age set for specific animal
*********************************************************************/
void animal::set_age(int age) {
    this->age = age;
}

/*********************************************************************
** Function: set_cost()
** Description: setter for animal cost
** Parameters: cost you want to set
** Pre-Conditions: n/a
** Post-Conditions: cost set for specific animal
*********************************************************************/
void animal::set_cost(int cost) {
    this->cost = cost;
}

/*********************************************************************
** Function: set_babies()
** Description: setter for animal number of babies
** Parameters: babies you want them to have
** Pre-Conditions: n/a
** Post-Conditions: number of babies set for specific animal
*********************************************************************/
void animal::set_babies(int babies) {
    this->babies = babies;
}

/*********************************************************************
** Function: set_food_cost()
** Description: setter for animal food costs
** Parameters: food cost you want to set
** Pre-Conditions: n/a
** Post-Conditions: food cost set for specific animal
*********************************************************************/
void animal::set_food_cost(float food_cost) {
    this->food_cost = food_cost;
}

/*********************************************************************
** Function: set_revenue())
** Description: setter for animal revenue
** Parameters: revenue you want set for certain animal
** Pre-Conditions: n/a
** Post-Conditions: revenue set for specific animal
*********************************************************************/
void animal::set_revenue(float revenue) {
    this->revenue = revenue;
}

/*********************************************************************
** Function: get_age()
** Description: getter for animal ages
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: access to age for animal
*********************************************************************/
int animal::get_age() const {
    return this->age;
}

/*********************************************************************
** Function: get_cost()
** Description: getter for animal cost
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: access to cost for animal
*********************************************************************/
int animal::get_cost() const{
    return this->cost;
}

/*********************************************************************
** Function: get_babies()
** Description: getter for animal number of babies
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: access to number of babies for animal
*********************************************************************/
int animal::get_babies() const{
    return this->babies;
}

/*********************************************************************
** Function: get_food_cost()
** Description: getter for animal food cost
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: access to food cost for animal
*********************************************************************/
float animal::get_food_cost() const{
    return this->food_cost;
}

/*********************************************************************
** Function: get_revenue()
** Description: getter for animal revenue
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: access to revenue for animal
*********************************************************************/
float animal::get_revenue() const{
    return this->revenue;
}

/*********************************************************************
** Function: update_age()
** Description: adds one month animal ages
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: animal one month older
*********************************************************************/
void animal::update_age() {
    this->age++;
}

