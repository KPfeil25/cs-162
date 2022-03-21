#include "encyclopedia.h"
#include <fstream>
#include <string>

bool is_int(string test) {
    int length=test.length();
    for (int i = 0; i < length; i++) {
        if (test[i] < '0' || test[i] > '9') {
            return false;
        }
    }
    return true;
}

void swap(monster *xp, monster *yp)  {
    monster temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
} 
    
void bubbleSort(monster* monster_arr, int numMonsters)  {
    int i, j;  

    for (i = 0; i < numMonsters-1; i++) {       
        for (j = 0; j < numMonsters-i-1; j++) {
            if (monster_arr[j].level > monster_arr[j+1].level) {
                swap(&monster_arr[j], &monster_arr[j+1]);
            }
        }
    }
}  

void create_hunters(int numHunters, hunter hunter_arr[], ifstream &finH) {
    string test;
    while (getline(finH, test)) {
        for (int i = 0; i < numHunters; i++) {
            finH >> hunter_arr[i].name;
            finH >> hunter_arr[i].id;
            finH >> hunter_arr[i].password;
            finH >> hunter_arr[i].experience;
            finH >> hunter_arr[i].encounters;
        }
    }
}

attack* create_attacks(int numAttacks) {
    attack* attack_arr = new attack[numAttacks];
    return attack_arr;
}

void get_attack_data(attack attack_arr[], int sizeM, ifstream &finM) {

    for (int i = 0; i < sizeM; i++) {
        finM >> attack_arr[i].name;
        finM >> attack_arr[i].effectiveness;
        finM >> attack_arr[i].element;
    }
}

void sortAttacks(monster* monster_arr, int numMonsters) {
    cout << "Fire attacks: " << endl;
    for (int i = 0; i < numMonsters; i++) {
        for (int j = 0; j < monster_arr[i].num_attacks; j++) { 
            if (monster_arr[i].a[j].element == "fire") {
                cout << monster_arr[i].a[j].name << endl;
            }
        }
    }

    cout << "\nAir attacks: " << endl;
    for (int i = 0; i < numMonsters; i++) {
        for (int j = 0; j < monster_arr[i].num_attacks; j++) { 
            if (monster_arr[i].a[j].element == "air") {
                cout << monster_arr[i].a[j].name << endl;
            }
        }
    }

    cout << "\nWater attacks: " << endl;
    for (int i = 0; i < numMonsters; i++) {
        for (int j = 0; j < monster_arr[i].num_attacks; j++) { 
            if (monster_arr[i].a[j].element == "water") {
                cout << monster_arr[i].a[j].name << endl;
            }
        }
    }

    cout << "\nEarth attacks: " << endl;    
    for (int i = 0; i < numMonsters; i++) {
        for (int j = 0; j < monster_arr[i].num_attacks; j++) { 
            if (monster_arr[i].a[j].element == "earth") {
                cout << monster_arr[i].a[j].name << endl;
            }
        }
    }
    
}

void get_monster_data(monster monster_arr[], int numMonsters, ifstream &finM) {
    string test;

    while (getline(finM, test)) {
            
        for (int i = 0; i < numMonsters; i++) {
            finM >> monster_arr[i].name;
            finM >> monster_arr[i].type;
            finM >> monster_arr[i].level;
            finM >> monster_arr[i].num_attacks;
    
            monster_arr[i].a = create_attacks(monster_arr[i].num_attacks);
            get_attack_data(monster_arr[i].a, monster_arr[i].num_attacks, finM);           
        }
    }
}

bool idAndPasswordMatch(int numHunters, hunter hunter_arr[], string userexperience) {
    //variables
    string attemptID;
    string attemptPassword;
    int tries = 3;

    do {
        cout << "Enter your ID: " << endl;
        cin >> attemptID;

        cout << "Enter your password: " << endl;
        cin >> attemptPassword;

        if (is_int(attemptID) == true) {
            for (int i = 0; i < numHunters; i++) {
                if (stoi(attemptID) != hunter_arr[i].id || attemptPassword != hunter_arr[i].password) {        
                    cout << "hi";          
                }
                else {
                    for (int i = 0; i < numHunters; i++) {
                        if (stoi(attemptID) == hunter_arr[i].id) {
                            userexperience = hunter_arr[i].experience;
                        }
                    }
                    return true;
                }
            }
            tries--;
            cout << "ID and/or password did not match, you have " << tries << " attempts remaining." << endl;
        }
        if (is_int(attemptID) == false) {

            cout << "The entered ID was not all integers, please try again." << endl;    
        }

    } while (tries > 0);
    
    exit(0);
}

int menuchoice() {
    int option;
    bool do_again;

    cout << "Welcome to the Monster Hunter Encyclopedia!" << endl;

    do {
        cout << "1. Sort monsters by level, in ascending order" << endl;
        cout << "2. Sort attacks by element" << endl;
        cout << "3. Sort monsters by average attack effectiveness" << endl;
        cout << "4. Exit the program" << endl;

        cout << "Please enter 1,2,3, or 4 to select what you want to see." << endl;
        cin >> option;

        if (option == 1 || option == 2 || option == 3 || option == 4) {
            return option;
            cout << option << endl;
            do_again = false;
        }
        else {
            cout << "You did not enter 1,2,3, or 4. Please try again." << endl;
            do_again = true;
        }

    } while (do_again == true);
}

void Sortmonsters(monster* monster_arr, int numMonsters) {
    int choicebro;
    bubbleSort(monster_arr, numMonsters);

    cout << "Do you want this printed to the screen or to an output file? Enter 1 for screen and 2 for file." << endl;
    cin >> choicebro;
    if (choicebro == 1) {
        for (int i = 0; i < numMonsters; i++) {
            cout << monster_arr[i].name << " " << monster_arr[i].level << endl;
        }
    }
    else if (choicebro == 2) {
        ofstream fout;
        fout.open("monsterssorted.txt");
        for (int i = 0; i < numMonsters; i++) {
            fout << monster_arr[i].name << " " << monster_arr[i].level << endl;
        }
    }
}

void quitprogram() {
    
    cout << "exiting program..." << endl;
    exit(0);
}

void getAttackEffectiveness(monster* monster_arr, int numMonsters) {

    for (int i = 0; i < numMonsters; i++) {
        for (int j = 0; j < monster_arr[i].num_attacks; j++) {
            monster_arr[i].avg_effectiveness += monster_arr[i].a[j].effectiveness;
        }
        monster_arr[i].avg_effectiveness /= monster_arr[i].num_attacks;
    }
}

void bubbleSortForEffectiveness(monster* monster_arr, int numMonsters, hunter* hunter_arr, string userexperience) {
    int chooooose;
    int i, j;  
    for (i = 0; i < numMonsters-1; i++) {     
        for (j = 0; j < numMonsters-i-1; j++) { 
            if (monster_arr[j].avg_effectiveness > monster_arr[j+1].avg_effectiveness)  {
                swap(&monster_arr[j], &monster_arr[j+1]);
            }
        }
    }
    cout << "Do you want to print this info to the screen or to a file? Enter 1 for screen and 2 for file" << endl;
    cin >> chooooose;
    if (chooooose == 1) {
        for (int i = 0; i < numMonsters; i++) {
            cout << monster_arr[i].name << " " << monster_arr[i].avg_effectiveness << endl;
        }
    }
    else if (chooooose == 2) {
        ofstream fout;
        fout.open("effectiveness.txt");
        for (int i = 0; i < numMonsters; i++) {
            fout << monster_arr[i].name << " " << monster_arr[i].avg_effectiveness << endl;
        }
    }
}

void deleteattack(monster* monster_arr) {
    
}