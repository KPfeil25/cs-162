#include "functions.h"

using namespace std;

/*********************************************************************
** Function: get_random_event()
** Description: gets number for random event
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: random event selected
*********************************************************************/
int get_random_event() {
    srand(time(NULL));
    int num =  rand() % 4 + 1;
    return num;
}

/*********************************************************************
** Function: get_random_species()
** Description: gets number for random species
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: random species selected
*********************************************************************/
int get_random_species() {
    srand(time(NULL));
    int num = rand() % 3 + 1;
    return num;
}

/*********************************************************************
** Function: get_random_percent()
** Description: gets number for random percent for food costs
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: random cost for food generated
*********************************************************************/
float get_random_percent() {
    srand(time(NULL));
    float num = 0.8 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/ (1.2 - 0.8)));
    //cout << num << " is the random percentage" << endl;
    return num;
}
