#include "animal.h"
#include "tiger.h"

using namespace std;

/*********************************************************************
** Function: sea_lion()
** Description: default constructor for sea lion
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: sea lion object created
*********************************************************************/
tiger::tiger() {
     animal();
}

/*********************************************************************
** Function: tiger(w/ parameters)
** Description: parameterized constructor for tigers
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: tiger object created
*********************************************************************/
tiger::tiger(int age, int cost, int babies, float food_cost, float revenue) {
     animal(age, cost, babies, food_cost, revenue);
}