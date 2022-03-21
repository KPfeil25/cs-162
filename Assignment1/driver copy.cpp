/* 
Program: driver.cpp
Author: Kevin Pfeil
Date: 10/14/2019
Description: Takes in text file, parses through them, outputs sorted info
Input: text files
Output: sorted information about the text files
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "encyclopedia.h"

int main(int argc, char* argv[]) {
    // variables
    int numHunters = 0;
    int numMonsters = 0;
    ifstream finH(argv[1]);
    ifstream finM(argv[2]);
    int sizeH;
    int sizeM;
    finH >> numHunters;
    cout << "main:" << numHunters << endl;
    finM >> numMonsters;
    attack* attack_arr = new attack;
    int option;
    string userexperience;
    bool go_again;
    int looooop;
    
    hunter hunter_arr[numHunters];
    create_hunters(numHunters, hunter_arr, finH);
    monster monster_arr[numMonsters];
    get_monster_data(monster_arr, numMonsters, finM);
    idAndPasswordMatch(numHunters, hunter_arr, userexperience);
    
    do {
        option=menuchoice();
        if (option == 1) {
            Sortmonsters(monster_arr, numMonsters);
        }
        else if (option == 2) {
            sortAttacks(monster_arr, numMonsters);
        }
        else if (option == 3) {
            getAttackEffectiveness(monster_arr, numMonsters);
            bubbleSortForEffectiveness(monster_arr, numMonsters, hunter_arr, userexperience);
        }
        else if (option == 4) {
            quitprogram();
        }
        cout << "Do you want to run this again? Enter 1 for yes and 2 for no." << endl;
        cin >> looooop;
        if (looooop == 1) {
            go_again = true;
        }
        else {
            go_again = false;
        }
    } while (go_again == true); 
    
}