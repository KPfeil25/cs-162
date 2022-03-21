#ifndef ZOO_H
#define ZOO_H
#include "bear.h"
#include "sea_lion.h"
#include "tiger.h"

using namespace std;

class zoo {
    private:
        float bank;
        int num_tigers;
        int num_bears;
        int num_sea_lions;
        tiger* tiger_arr;
        bear* bear_arr;
        sea_lion* sea_lion_arr;

    public:
        zoo(float);
        ~zoo();

        void set_bank(float);

        void welcome();
        void tiger_food_costs(int);
        void bear_food_costs(int);
        void sea_lion_food_costs(int);
        void total_food_costs();
        void tiger_revenue();
        void bear_revenue();
        void sea_lion_revenue();
        void update_revenue();
        int choice();
        int enter_animal_species();
        int enter_num_to_buy();
        void buy_animals();
        void check_bank();
        tiger* resize_tiger_arr(int);
        bear* resize_bear_arr(int);
        sea_lion* resize_sea_lion_arr(int);
        tiger* dead_tiger();
        bear* dead_bear();
        sea_lion* dead_sea_lion();

        void sick_tiger();
        void sick_bear();
        void sick_sea_lion();
        void sick_animal();
        void tiger_babies();
        void bear_babies();
        void sea_lion_babies();
        void babies();
        void population_spike();
        int food_choice();
        void random_events();

        void menu();     
};
#endif