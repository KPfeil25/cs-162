#ifndef encyclopedia_h
#define encyclopedia_h
#include <iostream>

using namespace std;

struct attack {
    string name;
    float effectiveness;
    string element;
};

struct hunter {
    string name;
    int id;
    string password;
    string experience;
    float encounters;
};

struct monster {
    string name;
    string type;
    int level;
    int num_attacks;
    float avg_effectiveness;
    struct attack *a;
};

monster * create_monsters(int);
void get_monster_data(monster *, int, ifstream &);
attack * create_attacks(int);
void get_attack_data(attack *, int, ifstream &);
void delete_info(hunter **, int, monster **, int);

bool idAndPasswordMatch(int, hunter*, string);
bool is_int(string);
void swap(monster*, monster*);
void bubblesort(monster*, int);
void create_hunters(int, hunter*, ifstream&);
void sortAttacks(monster*, int);
int menuchoice();
void Sortmonsters(monster*, int);
void quitprogram();
void getAttackEffectiveness(monster*, int);
void bubbleSortForEffectiveness(monster*, int, hunter*, string);
#endif