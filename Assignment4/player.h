#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "room.h"
#include "event.h"

using namespace std;

class player {
    private:
        int initial_x_pos;
        int initial_y_pos;
        int x_pos;
        int y_pos;
        bool has_gold;
        bool wump_dead;
        int num_arrows;
        vector<vector<room>> grid;
    
    public:
        player(int);

        int get_x_pos();
        int get_y_pos();
        bool get_has_gold();
        bool is_wumpy_dead();
        void set_initial_coords(int);
        void print_grid(int);
        void print_grid_wout_locations(int);

        void set_bats(int);
        void set_pits(int);
        void set_wumpus(int);
        void move_wumpy_wump_wumpman_wummmmp(int);
        void set_gold(int);
        void set_all_events(int);

        void move_or_shoot(int);
        void move_player(int, char);
        void move_wumpy_wump_wumpster(int);
        void shoot_left(int);
        void shoot_up(int);
        void shoot_right(int);
        void shoot_down(int);
        void shoot_arrow(int, char);
        bool check_for_event(int);
        void new_rand_position(int);
        void check_for_wumpus(int);
        void check_for_bats(int);
        void check_for_pits(int);
        void check_for_gold(int);
        void check_percepts(int);

        void play_game(int, bool);
        void delete_wumpus(int);
        void delete_it_all(int);
        void play_again(int, bool);
        void debug_game(int, bool);
        void normal_game(int, bool);
        void game(int, bool);
};

#endif