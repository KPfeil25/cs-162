#include "player.h"
#include <cstring>

using namespace std;

/******************************************************
** Function: player(int size)
** Description: player constuctor
** Parameters: int size
** Pre-Conditions: n/a
** Post-Conditions: Player object created
******************************************************/
player::player(int size) {
    this->x_pos = 0;
    this->y_pos = 0;
    this->has_gold = false;
    this->wump_dead = false;
    this->num_arrows = 3;
    grid.resize(size, vector<room>(size));
}

/******************************************************
** Function: get_x_pos()
** Description: getter for the players x position
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: Players x position has been gotten
******************************************************/
int player::get_x_pos() {
    return this->x_pos;
}

/******************************************************
** Function: get_y_pos()
** Description: getter for the players y position
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: Players y position has been gotten
******************************************************/
int player::get_y_pos() {
    return this->y_pos;
}

/******************************************************
** Function: get_has_gold()
** Description: getter for has gold
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: Players y position has been gotten
******************************************************/
bool player::get_has_gold() {
    return this->has_gold;
}

bool player::is_wumpy_dead() {
    return this->wump_dead;
} 

/******************************************************
** Function: set_initial_coords(int)
** Description: gives the player random starting coordinates
** Parameters: int size
** Pre-Conditions: player object must be made
** Post-Conditions: Players initial position has been set
******************************************************/
void player::set_initial_coords(int size) {
    int temp1, temp2;
    srand(time(NULL));
    this->x_pos = rand() % size;
    this->y_pos = rand() % size;

    //cout << "Before transfer: (x,y): " << "(" << x_pos << "," << y_pos << ")" << endl; 
    temp1 = x_pos;
    temp2 = y_pos;
    //cout << "After transfer: (x,y): " << "(" << x_pos << "," << y_pos << ")" << endl;

    this->initial_x_pos = temp1;
    this->initial_y_pos = temp2;
}

/******************************************************
** Function: print_grid(int size)
** Description: prints the game board with any potential events in rooms
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: grid has been printed
******************************************************/
void player::print_grid(int size) {
    //cout << size << endl;
    //cout << "X pos = " << x_pos << endl;
    //cout << "Y pos = " << y_pos << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "+" << "-" << "-" << "-";
        }
        cout << "+";
        cout << endl;
        for (int m = 0; m < 1; m++) {
            for (int k = 0; k < size; k++) {
                if (i == x_pos && k == y_pos) {
                    cout << "|" << " " << "*" << " ";
                }
                else {
                    cout << "|" << " " << grid[i][k].get_symbol() << " ";
                }
            }
            cout << "|";
            cout << endl;
        }
    }
    for (int i = 0; i < size; i++) {
        cout << "+" << "-" << "-" << "-";
    }
    cout << "+" << endl;
}

/******************************************************
** Function: print_grid_w_out_locations(int size)
** Description: prints the game board without any potential events in rooms
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: grid has been printed
******************************************************/
void player::print_grid_wout_locations(int size) {
    //cout << size << endl;
    //cout << "X pos = " << x_pos << endl;
    //cout << "Y pos = " << y_pos << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "+" << "-" << "-" << "-";
        }
        cout << "+";
        cout << endl;
        for (int m = 0; m < 1; m++) {
            for (int k = 0; k < size; k++) {
                if (i == x_pos && k == y_pos) {
                    cout << "|" << " " << "*" << " ";
                }
                else {
                    cout << "|" << " " << " " << " ";
                }
            }
            cout << "|";
            cout << endl;
        }
    }
    for (int i = 0; i < size; i++) {
        cout << "+" << "-" << "-" << "-";
    }
    cout << "+" << endl;
}
/******************************************************
** Function: set_bats(int)
** Description: sets a random room to have bats in it
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: grid has two rooms in it with bats
******************************************************/
void player::set_bats(int size) {
    int x, y;

    for (int i = 0; i < 2; i++) {
        do {
            x = rand() % size;
            y = rand() % size;
        } while (grid[x][y].get_symbol() != ' ' || (x == x_pos && y == y_pos));

        //cout << "setting bats at " << x << ", " << y << endl;
        grid[x][y].set_bats();
    }
}

/******************************************************
** Function: set_pits(int)
** Description: sets a random room to have pits in it
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: grid has two rooms in it with pits
******************************************************/
void player::set_pits(int size) {
    int x, y;

    for (int i = 0; i < 2; i++) {
        do {
            x = rand() % size;
            y = rand() % size;
        } while (grid[x][y].get_symbol() != ' ' || (x == x_pos && y == y_pos));
    

        //cout << "setting pits at " << x << ", " << y << endl;
        grid[x][y].set_pit();
    }
}

/******************************************************
** Function: set_wumpus(int)
** Description: sets a random room to have the wumpus in it
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: grid has a room with the wumpus in it
******************************************************/
void player::set_wumpus(int size) {
    int x, y;

    do {
        x = rand() % size;
        y = rand() % size;
    } while (grid[x][y].get_symbol() != ' ' || (x == x_pos && y == y_pos));
    
    //cout << "putting the wumpus at " << x << ", " << y << endl;
    grid[x][y].set_wumpus();
}

/******************************************************
** Function: set_gold(int)
** Description: sets a random room to have the gold in it
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: grid has a room with gold in it
******************************************************/
void player::set_gold(int size) {
    int x, y;

    do {
        x = rand() % size;
        y = rand() % size;
    } while (grid[x][y].get_symbol() != ' ' || (x == x_pos && y == y_pos));

    //cout << "setting gold at " << x << ", " << y << endl;
    grid[x][y].set_gold();
}

/******************************************************
** Function: set_all_events(int)
** Description: calls all of the functions that set the needed events in rooms
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: grid contains 2 rooms with bats, 2 rooms with pits, 1 room with the wumpus, and onw room with the gold
******************************************************/
void player::set_all_events(int size) {
    set_bats(size);
    set_pits(size);
    set_wumpus(size);
    set_gold(size);
}

/******************************************************
** Function: move_or_shoot(int size)
** Description: asks the user to move or shoot
** Parameters: int size
** Pre-Conditions: n/a
** Post-Conditions: user moves or shoots
******************************************************/
void player::move_or_shoot(int size) {
    string input;
    char direction;
    bool go_again = true;

    do {
        cout << "Enter w, a, s, or d to move in that direction!" << endl;
        cout << "Enter space followed by w, a, s, or d to shoot an arrow in that direction!" << endl;

        getline(cin, input);
        
        if (input[0] == 'w' || input[0] == 'a' || input[0] == 's' || input[0] == 'd') {
            direction = input[0];
            go_again = false;
            move_player(size, direction);
        }
        else if (input[0] == ' ') {
            //cout << "Enters shoot function" << endl;
            if (input[1] == 'w' || input[1] == 'a' || input[1] == 's' || input[1] == 'd') {
                direction = input[1];
                shoot_arrow(size, direction);
                go_again = false;
            }
            else {
                cout << "You did not enter a valid direction to shoot the arrow, try again!" << endl;
                go_again = true;
            }
        }
        else {
            cout << "You did not enter valid input, try again." << endl;
            go_again = true;
        }
    } while (go_again == true);
}

/******************************************************
** Function: move_player(int size)
** Description: moves player
** Parameters: int size, char
** Pre-Conditions: grid must be initialized
** Post-Conditions: player moves
******************************************************/
void player::move_player(int size, char direction) {
    if (direction == 'a') {
        if ((y_pos - 1) >= 0) {
            y_pos -= 1;
            return;
            //cout << "moving player left 1 space" << endl;
            //print_grid(size);
        }
    }
    if (direction == 'w') {
        if ((x_pos - 1) >= 0) {
            x_pos -= 1;
            return;
            //cout << "moving player up 1 space" << endl;
            //print_grid(size);
        }
    }
    if (direction == 's') {
        if ((x_pos + 1) <= (size - 1)) {
            x_pos += 1;
            return;
            //cout << "moving player down one space" << endl;
            //print_grid(size);
        }
    }
    if (direction == 'd') {
        if ((y_pos + 1) <= (size - 1)) {
            y_pos += 1;
            return;
            //cout << "moving player right one space" << endl;
            //print_grid(size);
        }
    }
    else {
        cout << "You cant go there bucko" << endl;
    }
}

/******************************************************
** Function: move_wumpy_wump_wumpster(int size)
** Description: moves wump man
** Parameters: int size
** Pre-Conditions: must be a wumpus
** Post-Conditions: wumpus moves
******************************************************/
void player::move_wumpy_wump_wumpster(int size) {
int move_wumpy = rand() % 4 + 1;

    cout << "You missed!" << endl;
    if (move_wumpy != 2) {
        delete_wumpus(size);
        //cout << "deletes wumpus" << endl;
        set_wumpus(size);
    } 
}

/******************************************************
** Function: shoot_left(int size)
** Description: lets the user shoot left
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: user shoots an arrow
******************************************************/
void player::shoot_left(int size) {

    if (num_arrows > 0) {
        for (int i = 1; i <= 3; i++) {
            if ((y_pos - i) > 0) {
                if (grid[x_pos][y_pos - i].get_symbol() == 'W') {
                    grid[x_pos][y_pos - i].set_event_to_blank();
                    cout << "You killed the wumpus! Im calling PETA." << endl;
                    wump_dead = true;
                }
            }
        }
    }
    if (wump_dead == false && num_arrows > 0) {
        move_wumpy_wump_wumpster(size);
        num_arrows--;
    }
    if (num_arrows <= 0) {
        cout << "You do not have enough arrows!" << endl;
    }
}

/******************************************************
** Function: shoot_up(int size) lmaooooooooooooooooooooooooooooooooooooooooooooooooooooo
** Description: lets the user shoot up heroine
** Parameters: int size
** Pre-Conditions: heroine must be obtained
** Post-Conditions: sense of  euphoria, elevated mood
******************************************************/
void player::shoot_up(int size) {

    if (num_arrows > 0) {
        for (int i = 1; i <= 3; i++) {
            if ((x_pos - i) > 0) {
                if (grid[x_pos - i][y_pos].get_symbol() == 'W') {
                    grid[x_pos - i][y_pos].set_event_to_blank();
                    cout << "You killed the wumpus! Im calling PETA." << endl;
                    wump_dead = true;
                }
            }
        }
    }
    if(wump_dead == false && num_arrows > 0) {
        move_wumpy_wump_wumpster(size);
        num_arrows--;
    }
    if (num_arrows <= 0) {
        cout << "You do not have enough arrows!" << endl;
    }
}

/******************************************************
** Function: shoot_right(int size)
** Description: lets the user shoot right
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: user shoots an arrow
******************************************************/
void player::shoot_right(int size) {
    if (num_arrows > 0) {
        for (int i = 1; i <= 3; i++) {
            if ((y_pos + i) < size) {
                if (grid[x_pos][y_pos + i].get_symbol() == 'W') {
                    grid[x_pos][y_pos + i].set_event_to_blank();
                    cout << "You killed the wumpus! Im calling PETA." << endl;
                    wump_dead = true;
                }
            }
        }
    }
    if (wump_dead == false && num_arrows > 0) {
        move_wumpy_wump_wumpster(size);
        num_arrows--;
    }
    if (num_arrows <= 0) {
        cout << "You do not have enough arrows!" << endl;
    }
}

/******************************************************
** Function: shoot_down(int size)
** Description: lets the user shoot down
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: user shoots an arrow
******************************************************/
void player::shoot_down(int size) {
    bool missed = true;
    if (num_arrows > 0) {
        for (int i = 1; i <= 3; i++) {
            if ((x_pos + i) < size) {
                if (grid[x_pos + i][y_pos].get_symbol() == 'W') {
                    grid[x_pos + i][y_pos].set_event_to_blank();
                    cout << "You killed the wumpus! Im calling PETA." << endl;
                    wump_dead = true;
                    missed = false;
                }
            }
        }
    }
    if (missed == true && num_arrows > 0) {
        move_wumpy_wump_wumpster(size);
        num_arrows--;
    }
    if (num_arrows <= 0) {
        cout << "You do not have enough arrows!" << endl;
    }
}

/******************************************************
** Function: shoot_arrow(int size)
** Description: user shoots arrow
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: grid has been printed
******************************************************/
void player::shoot_arrow(int size, char direction) {
    //cout << "Enters shoot function" << endl;
    if (direction == 'a') {
        shoot_left(size);
    }
    else if (direction == 'w') {
        shoot_up(size);//lmao
    }
    else if (direction == 's') {
        shoot_down(size);
    }
    else if (direction == 'd') {
        shoot_right(size);
    }
}

/******************************************************
** Function: check_for_event(int size)
** Description: checks if the user is in a room with an event
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: events have been checked
******************************************************/
bool player::check_for_event(int size) {
    
    if (grid[x_pos][y_pos].get_symbol() == 'B') {
        cout << "Entered a room with bats, uh oh!" << endl;
        new_rand_position(size);
        return true;
    }
    else if (grid[x_pos][y_pos].get_symbol() == 'W') {
        cout << "In wumpus room, you dead :(" << endl;
        return false;
    }
    else if (grid[x_pos][y_pos].get_symbol() == 'P'){
        cout << "in a pit, you fell to your death. ouch." << endl;
        return false;
    }
    else if (grid[x_pos][y_pos].get_symbol() == 'G') {
        cout << "found the gold!" << endl;
        has_gold = true;
        return true;
    }
    else {
        return true;
    }
}

/******************************************************
** Function: new_rand_position(int size)
** Description: moves user to a random spot
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: user has been randomly moved
******************************************************/
void player::new_rand_position(int size) {
    int x, y;

    do {
        x = rand() % size;
        y = rand() % size;
    } while (grid[x][y].get_symbol() != ' ' || (x == x_pos && y == y_pos));
    
    x_pos = x;
    y_pos = y;

    //cout << "new position is " << x << ", " << y << endl;
    //print_grid(size);
}

/******************************************************
** Function: check_for_wumpus(int size)
** Description: checks for event
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: event has been checked for
******************************************************/
void player::check_for_wumpus(int size) {
    if (x_pos + 1 < size) {
        if (grid[x_pos + 1][y_pos].get_symbol() == 'W') {
            grid[x_pos + 1][y_pos].get_event()->print_percept();
            return;
        }
    }
    if (x_pos - 1 >= 0) {
        if (grid[x_pos - 1][y_pos].get_symbol() == 'W') {
            grid[x_pos - 1][y_pos].get_event()->print_percept();
            return;
        }
    }
    if (y_pos + 1 < size) {
        if (grid[x_pos][y_pos + 1].get_symbol() == 'W') {
            grid[x_pos][y_pos + 1].get_event()->print_percept();
            return;
        }
    }
    if (y_pos - 1 >= 0) {
        if (grid[x_pos][y_pos - 1].get_symbol() == 'W') {
            grid[x_pos][y_pos - 1].get_event()->print_percept();
            return;
        }
    }
}

/******************************************************
** Function: check_for_bats(int size)
** Description: checks for event
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: event has been checked for
******************************************************/
void player::check_for_bats(int size) {
    if (x_pos + 1 < size) {
        if (grid[x_pos + 1][y_pos].get_symbol() == 'B') {
            grid[x_pos + 1][y_pos].get_event()->print_percept();
            return;
        }
    }
    if (x_pos - 1 >= 0) {
        if (grid[x_pos - 1][y_pos].get_symbol() == 'B') {
            grid[x_pos - 1][y_pos].get_event()->print_percept();
            return;
        }
    }
    if (y_pos + 1 < size) {
        if (grid[x_pos][y_pos + 1].get_symbol() == 'B') {
            grid[x_pos][y_pos + 1].get_event()->print_percept();
            return;
        }
    }
    if (y_pos - 1 >= 0) {
        if (grid[x_pos][y_pos - 1].get_symbol() == 'B') {
            grid[x_pos][y_pos - 1].get_event()->print_percept();
            return;
        }
    }
}

/******************************************************
** Function: check_for_pits(int size)
** Description: checks for event
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: event has been checked for
******************************************************/
void player::check_for_pits(int size) {
    if (x_pos + 1 < size) {
        if (grid[x_pos + 1][y_pos].get_symbol() == 'P') {
            grid[x_pos + 1][y_pos].get_event()->print_percept();
            return;
        }
    }
    if (x_pos - 1 >= 0) {
        if (grid[x_pos - 1][y_pos].get_symbol() == 'P') {
            grid[x_pos - 1][y_pos].get_event()->print_percept();
            return;
        }
    }
    if (y_pos + 1 < size) {
        if (grid[x_pos][y_pos + 1].get_symbol() == 'P') {
            grid[x_pos][y_pos + 1].get_event()->print_percept();
            return;
        }
    }
    if (y_pos - 1 >= 0) {
        if (grid[x_pos][y_pos - 1].get_symbol() == 'P') {
            grid[x_pos][y_pos - 1].get_event()->print_percept();
            return;
        }
    }
}

/******************************************************
** Function: check_for_gold(int size)
** Description: checks for event
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: event has been checked for
******************************************************/
void player::check_for_gold(int size) {
    if (x_pos + 1 < size) {
        if (grid[x_pos + 1][y_pos].get_symbol() == 'G') {
            grid[x_pos + 1][y_pos].get_event()->print_percept();
            return;
        }
    }
    if (x_pos - 1 >= 0) {
        if (grid[x_pos - 1][y_pos].get_symbol() == 'G') {
            grid[x_pos - 1][y_pos].get_event()->print_percept();
            return;
        }
    }
    if (y_pos + 1 < size) {
        if (grid[x_pos][y_pos + 1].get_symbol() == 'G') {
            grid[x_pos][y_pos + 1].get_event()->print_percept();
            return;
        }
    }
    if (y_pos - 1 >= 0) {
        if (grid[x_pos][y_pos - 1].get_symbol() == 'G') {
            grid[x_pos][y_pos - 1].get_event()->print_percept();
            return;
        }
    }
}

/******************************************************
** Function: check_percepts(int size)
** Description: chceks if percepts need to be printed
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: appropriate percepts have been printed
******************************************************/
void player::check_percepts(int size) {
    check_for_wumpus(size);
    check_for_bats(size);
    check_for_pits(size);
    check_for_gold(size);
}

/******************************************************
** Function: delete_it_all(int size)
** Description: basically a grid destroyer
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: grid has been DESTROYED AHHHHHHH
******************************************************/
void player::delete_it_all(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j].get_event() != NULL) {
                grid[i][j].clear_board();
            }
        }
    }
}

/******************************************************
** Function: delete_wumpus(int size)
** Description: deletes wumpus so it can move
** Parameters: int size
** Pre-Conditions: grid must be initialized
** Post-Conditions: wumpy moved
******************************************************/
void player::delete_wumpus(int size) {
    //cout << "enters delete function" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j].get_symbol() == 'W') {
                grid[i][j].get_event()->set_symbol(' ');
            }
        }
    }
}

/******************************************************
** Function: play_game(int size)
** Description: literally everything
** Parameters: int size, bool
** Pre-Conditions: grid must be initialized
** Post-Conditions: the whole friggin game
******************************************************/
void player::play_game(int size, bool debug) {
    //bool go_again = true;
    //int choice = 0;
    //do{
        set_initial_coords(size);
        set_all_events(size);
        if (debug == 1) {
            debug_game(size, debug);
        }
        else {
            normal_game(size, debug);
        }
        delete_it_all(size);
        /*
        cout << "Enter 1 to play the same board, enter 2 to play a new board, enter 3 to exit" << endl;
        cin >> choice;

        if (choice == 1) {
            player p2(size);
            p2.play_game(size, debug);

        }
        else if (choice == 2) {
            play_again(size, debug);
        }
        else {
            cout << "you entered 3 or the wrong thing, youre gonna exit" << endl;
            exit(1);
        }
        */
    //} while (go_again == true); 
}

/******************************************************
** Function: debug_game()
** Description: runs game in debug mode
** Parameters: int, bool
** Pre-Conditions: n/a
** Post-Conditions: debug mode game is run
******************************************************/
void player::debug_game(int size, bool another_turn) {
    print_grid(size);
    do {
        move_or_shoot(size);
        print_grid(size);
        another_turn = check_for_event(size);
        check_percepts(size);
        cout << "initial coords are " << initial_x_pos << initial_y_pos << endl;
        cout << "current coords are " << x_pos << y_pos << endl;
        if (wump_dead == true && has_gold == true && x_pos == initial_x_pos && y_pos == initial_y_pos) {
            cout << "You won!" << endl;
            another_turn = false;
        }
    } while (another_turn == true);
    if (wump_dead == false || has_gold == false || x_pos != initial_x_pos || y_pos != initial_y_pos) {
        cout << "You lost nerd" << endl;
    }
}

/******************************************************
** Function: normal_game()
** Description: runs game with no symbols
** Parameters: int, bool
** Pre-Conditions: n/a
** Post-Conditions: normal game is run
******************************************************/
void player::normal_game(int size, bool another_turn) {
    print_grid_wout_locations(size);
    do {
        move_or_shoot(size);
        print_grid_wout_locations(size);
        another_turn = check_for_event(size);
        check_percepts(size);
        if (wump_dead == true && has_gold == true && x_pos == initial_x_pos && y_pos == initial_y_pos) {
            cout << "You won!" << endl;
            another_turn = false;
        }
    } while (another_turn == true);
    if (wump_dead == false || has_gold == false || x_pos != initial_x_pos || y_pos != initial_y_pos) {
        cout << "You lost nerd" << endl;
    }
}

/******************************************************
** Function: play_again(int size)
** Description: semi-broken function for playing again
** Parameters: int size, bool
** Pre-Conditions: grid must be initialized
** Post-Conditions: you get to play again
******************************************************/
/* 
void player::play_again(int size, bool debug) {
    int sizee;
    string deez;
    bool deeznuts;
    player p3(size);
    cout << "Enter size then true(nutz) or false(nuts)" << endl;

    cin >> sizee;
    cin >> deez;

    if (deez == "nutz") {
        deeznuts = true;
        p3.play_game(sizee, deeznuts);
    }
    else {
        deeznuts = false;
        p3.play_game(sizee, deeznuts);
    }
    delete_it_all(size);
}
*/
