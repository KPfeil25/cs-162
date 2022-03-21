/******************************************************
** Program: driver.cpp
** Author: Kevin Pfeil
** Date: 11/22/2019
** Description: Hunt the Wumpus game
** Input: Game board size and if you want debug mode or nah
** Output: A good frickin time
******************************************************/

#include <iostream>
#include "player.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    bool debug = true;
    int game_size = 0;
    if (argc != 3) {
        cout << "You did not enter the correct number of arguments!" << endl;
        return 1;
    }
    else {
        cout << argv[1] << " is the game size" << endl;
        cout << argv[2] << " is the debug bool" << endl;
        game_size = atoi(argv[1]);
        string debug_choice(argv[2]);

        if (debug_choice == "True" || debug_choice == "true" || debug_choice == "T") {
            debug = true;
        }
        else if (debug_choice == "False" || debug_choice == "false" || debug_choice == "F") {
            debug = false;
        }
        else {
            int choice = 0;

            cout << "You did not specify anything about debug mode, choose debug(1) or normal(2)" << endl;
            cin >> choice;
            if (choice == 1) {
                debug = true;
            }
            else {
                debug = false;
            }
        }
    }
    // whole game
    player p1(game_size);
    p1.play_game(game_size, debug);

}