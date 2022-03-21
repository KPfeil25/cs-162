#include "animal.h"
#include "sea_lion.h"

using namespace std;

/*********************************************************************
** Function: sea_lion()
** Description: default constructor for sea lion
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: sea lion object created
*********************************************************************/
sea_lion::sea_lion() {
     animal();
}

/*********************************************************************
** Function: sea_lion(w/ parameters)
** Description: parameterized constructor for sea lion
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: sea lion object created
*********************************************************************/
sea_lion::sea_lion(int age, int cost, int babies, float food_cost, float revenue) {
     animal(age, cost, babies, food_cost, revenue);
}