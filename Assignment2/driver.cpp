/*********************************************************************
** Program Filename: driver.cpp
** Author: Kevin Pfeil
** Date: 10/26/2019
** Description: Driver for university catalog
** Input: n/a
** Output: the university catalog
*********************************************************************/

#include "functions.h"

int main() {
    University U1;
    U1.get_all_info();
    all_actions(U1);
    U1.print_new_courses();

    return 0;
}