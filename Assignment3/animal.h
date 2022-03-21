#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class animal {

    private:
        int age;
        int cost;
        int babies;
        float food_cost;
        float revenue;

    public:
        animal();
        animal(int, int, int, float, float);
        void set_age(int);
        void set_cost(int);
        void set_babies(int);
        void set_food_cost(float);
        void set_revenue(float);

        int get_age() const;
        int get_cost() const;
        int get_babies() const;
        float get_food_cost() const;
        float get_revenue() const;

        void update_age();
};
#endif