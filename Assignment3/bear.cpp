#include "animal.h"
#include "bear.h"

using namespace std;

/*********************************************************************
** Function: bear()
** Description: default constructor for bear
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bear object created
*********************************************************************/
bear::bear() {
    animal();
}

/*********************************************************************
** Function: bear(w/ parameters)
** Description: parameterized constructor for bear
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bear object created
*********************************************************************/
bear::bear(int age, int cost, int babies, float food_cost, float revenue) {
    animal(age, cost, babies, food_cost, revenue);
}