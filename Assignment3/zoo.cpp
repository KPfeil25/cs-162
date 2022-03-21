#include "zoo.h"
#include "functions.h"

using namespace std;

/*********************************************************************
** Function: zoo(float)
** Description: zoo constructor
** Parameters: float that sets the bank amount
** Pre-Conditions: n/a
** Post-Conditions: zoo created with money
*********************************************************************/ 
zoo::zoo(float bank) {
    this->bank = bank;
    this->num_tigers = 0;
    this->num_bears = 0;
    this->num_sea_lions = 0;

    this->tiger_arr = new tiger[num_tigers];
    this->bear_arr = new bear[num_bears];
    this->sea_lion_arr = new sea_lion[num_sea_lions];
}

/*********************************************************************
** Function: ~zoo()
** Description: zoo destructor
** Parameters: n/a
** Pre-Conditions: zoo object exists
** Post-Conditions: zoo object destroyed
*********************************************************************/ 
zoo::~zoo() {
    delete [] tiger_arr;
    delete [] bear_arr;
    delete [] sea_lion_arr;
}

/*********************************************************************
** Function: set_bank()
** Description: bank setter for the zoo class
** Parameters: amount the zoo gets
** Pre-Conditions: n/a
** Post-Conditions: zoo with that amount of money
*********************************************************************/ 
void zoo::set_bank(float bank) {
    this->bank = bank;
}

/*********************************************************************
** Function: welcome()
** Description: announces rules
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: user knows the game
*********************************************************************/ 
void zoo::welcome() {
    cout << "Welcome to zoo tycoon!" << endl;
    cout << "This will be a turn-based game where the month increases by one each turn." << endl;
    cout << "The bank starts with $100,000 and you will gain and lose money as you go!" << endl;
}

/*********************************************************************
** Function: tiger_food_costs()
** Description: calculates the amount that tigers food will cost for that month
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: tiger food for the month taken away from bank
*********************************************************************/ 
void zoo::tiger_food_costs(int choice) {
    float rand_percent = get_random_percent();

    if (choice == 2){
        float food_cost = (800 * rand_percent); //800 because tigers have a base food cost of 5x and 2x from special food
        bank -= ((static_cast <float> (num_tigers)) * food_cost);
    }
    else if (choice == 3) {
        float food_cost = (200 * rand_percent); //200 because tigers have a base food cost of 5x and a .5x from special food
        bank -= ((static_cast <float> (num_tigers)) * food_cost);
    }
    else {
        float food_cost = (400 * rand_percent); //400 because tigers have a base food cost of 5x
        bank -= ((static_cast <float> (num_tigers)) * food_cost);
    }
}

/*********************************************************************
** Function: bear_food_costs()
** Description: calculates the amount that bears food will cost for that month
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bear food for the month taken away from bank
cout << "This will take " << ((static_cast <float> (num_bears)) * food_cost) << " out in food costs for bears" << endl;
*********************************************************************/
void zoo::bear_food_costs(int choice) {
    float rand_percent = get_random_percent();
    if (choice == 2) {
        float food_cost = (480 * rand_percent); // 480 cause bears have 3x normal food and double from food choice
        bank -= ((static_cast <float> (num_bears)) * food_cost);
    }
    else if (choice == 3) {
        float food_cost = (120 * rand_percent); //120 because bears have a base food cost of 3x and .5x from choice
        bank -= ((static_cast <float> (num_bears)) * food_cost);
    }
    else {
        float food_cost = (240 * rand_percent); //240 cause bears have 3x base food cost
        bank -= ((static_cast <float> (num_bears)) * food_cost);
    }
}

/*********************************************************************
** Function: sea_lion_food_costs()
** Description: calculates the amount that sea lions food will cost for that month
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: sea lion food for the month taken away from bank
*********************************************************************/
void zoo::sea_lion_food_costs(int choice) {
    float rand_percent = get_random_percent();
    if (choice == 2) {
        float food_cost = (160 * rand_percent); //160 because sea lions have the base food cost and 2x from food choice
        bank -= ((static_cast <float> (num_sea_lions)) * food_cost);
    }
    else if (choice == 3) {
        float food_cost = (40 * rand_percent); //40 because sea lions have the base food cost and .5x from food choice
        bank -= ((static_cast <float> (num_sea_lions)) * food_cost);
    }
    else {
        float food_cost = (80 * rand_percent); //80 because sea lions have the base food cost
        bank -= ((static_cast <float> (num_sea_lions)) * food_cost);
    }
}

/*********************************************************************
** Function: total_food_costs()
** Description: calculates the amount that all food will cost for that month
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: all food for the month taken away from bank
*********************************************************************/
void zoo::total_food_costs() {
    int choice = food_choice();
    tiger_food_costs(choice);
    bear_food_costs(choice);
    sea_lion_food_costs(choice);
}

/*********************************************************************
** Function: tiger_revenue()
** Description: calculates the amount that tigers will generate for that month
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: amount tigers generate added to bank
*********************************************************************/
void zoo::tiger_revenue() {
    for (int i = 0; i < num_tigers; i++) {
        if (tiger_arr[i].get_age() < 6) {
            bank += 2400.0; 
        }
        else {
            bank += 1200.0;
        }
    }
}

/*********************************************************************
** Function: bear_revenue()
** Description: calculates the amount that bears will generate for that month
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: amount bears generate added to bank
*********************************************************************/
void zoo::bear_revenue() {
    for (int i = 0; i < num_bears; i++) {
        if (bear_arr[i].get_age() < 6) {
            bank += 1000.0;
        }
        else {
            bank += 500.0;
        }
    }
}

/*********************************************************************
** Function: sea_lion_revenue()
** Description: calculates the amount that sea lions will generate for that month
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: amount sea lions generate added to bank
*********************************************************************/
void zoo::sea_lion_revenue() {
    for (int i = 0; i < num_sea_lions; i++) {
        if (sea_lion_arr[i].get_age() < 6) {
            bank += 280.0;
        }
        else {
            bank += 140.0;
        }
    }
}

/*********************************************************************
** Function: update_revenue()
** Description: takes all money for food away from bank and adds revenue from each animal
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: bank amount updated
*********************************************************************/
void zoo::update_revenue() {
    tiger_revenue();
    bear_revenue();
    sea_lion_revenue();
    total_food_costs();
}

/*********************************************************************
** Function: choice()
** Description: asks user if they want to buy an animal or not
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: known if user wants to buy an animal or not
*********************************************************************/
int zoo::choice() {
    int choice;

    cout << "Would you like to buy animals (1) or nah (2)?" << endl;
    cin >> choice;

    if (choice == 1) {
        return 1;
    }
    else {
        return 2;
    }
}

/*********************************************************************
** Function: enter_animal_species()
** Description: asks user what species they want to buy
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: species user wants to buy is known
*********************************************************************/
int zoo::enter_animal_species() {
    int the_choice = zoo::choice();

    if (the_choice == 1) {
        int animal_choice;
        bool go_beavs = true;

        do {
            cout << "Which species do you want to buy?" << endl;
            cout << "Tiger (1), Black Bear (2), or Sea Lion (3)" << endl;
            cin >> animal_choice;

            if (animal_choice == 1 || animal_choice == 2 || animal_choice == 3) {
                go_beavs = false;
                return animal_choice;
            }
            else {
                cout << "You did not enter 1, 2, or 3 homie please try again!" << endl;
                go_beavs = true;
            }
        } while (go_beavs == true);
    }
    else {
        cout << "You won't buy any animals this turn, maybe next time!" << endl;
    }
}

/*********************************************************************
** Function: enter_num_to_buy()
** Description: asks user how many of the selected species they want to buy
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: amount of species they want to buy is known
*********************************************************************/
int zoo::enter_num_to_buy() {
    bool go_beavs2 = true;
    int num_to_buy;

    do {
        cout << "How many animals do you want to buy? Enter 1 or 2:" << endl;
        cin >> num_to_buy;

        if (num_to_buy == 1 || num_to_buy == 2) {
            return num_to_buy;
        }
        else {
            cout << "You did not enter 1 or 2, please try again." << endl;
            go_beavs2 = true;
        }
    } while (go_beavs2 == true);
}

/*********************************************************************
** Function: buy_animals()
** Description: combines all of the above functions to perform all tasks for buying an animal
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: animal arrays added to if user bought animals
*********************************************************************/
void zoo::buy_animals() {
    int species = zoo::enter_animal_species();
    int num_to_buy = zoo::enter_num_to_buy();

 
    if (species == 1) {
        resize_tiger_arr(num_to_buy);
        bank -= (12000 * num_to_buy);

        for (int i = 0; i < num_to_buy; i++) {
            tiger_arr[(num_tigers - 1)].set_age(48); //48 months is 4yrs
        }
    }
    else if (species == 2) {
        resize_bear_arr(num_to_buy);
        bank -= (5000 * num_to_buy);

        for (int i = 0; i < num_to_buy; i++) {
            bear_arr[(num_bears - 1)].set_age(48); //48 months is 4yrs
        }
    }
    else if (species == 3) {
        resize_sea_lion_arr(num_to_buy);
        bank -= (700 * num_to_buy);

        for (int i = 0; i < num_to_buy; i++) {
            sea_lion_arr[(num_sea_lions - 1)].set_age(48); //48 months is 4yrs
        }
    }
}

/*********************************************************************
** Function: check_bank()
** Description: checks if user has money left
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: if user doesnt have money then the game exits
*********************************************************************/
void zoo::check_bank() {
    if (bank <= 0) {
        cout << "You have run out of money and gone bankrupt! Oops, try again!" << endl;
    }
}

/*********************************************************************
** Function: resize_tiger_arr()
** Description: resizes tiger array based on how many they bought
** Parameters: how many they bought
** Pre-Conditions: n/a
** Post-Conditions: array of tigers added to and ages set to adults
*********************************************************************/
tiger* zoo::resize_tiger_arr(int num_to_buy) {
    num_tigers += num_to_buy;
    tiger* new_tiger_arr = new tiger[num_tigers];
    
    for (int i = 0; i < (num_tigers - num_to_buy); i++) {
        new_tiger_arr[i] = tiger_arr[i];
    }

    delete [] tiger_arr;
    tiger_arr = new_tiger_arr;
    return tiger_arr;
}

/*********************************************************************
** Function: resize_bear_arr()
** Description: resizes bear array based on how many they bought
** Parameters: how many they bought
** Pre-Conditions: n/a
** Post-Conditions: array of bears added to and ages set to adults
*********************************************************************/
bear* zoo::resize_bear_arr(int num_to_buy) {
    num_bears += num_to_buy;
    bear* new_bear_array = new bear[num_bears];

    for (int i = 0; i < (num_bears - num_to_buy); i++) {
        new_bear_array[i] = bear_arr[i];
    }

    delete [] bear_arr;
    bear_arr = new_bear_array;
    return bear_arr;
}

/*********************************************************************
** Function: resize_sea_lion_arr()
** Description: resizes sea lion array based on how many they bought
** Parameters: how many they bought
** Pre-Conditions: n/a
** Post-Conditions: array of sea lions added to and ages set to adults
*********************************************************************/
sea_lion* zoo::resize_sea_lion_arr(int num_to_buy) {
    num_sea_lions += num_to_buy;
    sea_lion* new_sea_lion_array = new sea_lion[num_sea_lions];

    for (int i = 0; i < (num_sea_lions - num_to_buy); i++) {
        new_sea_lion_array[i] = sea_lion_arr[i];
    }

    delete [] sea_lion_arr;
    sea_lion_arr = new_sea_lion_array;
    return sea_lion_arr;
}

/*********************************************************************
** Function: dead_tiger()
** Description: takes one off the end of the the tiger array
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: array of tigers decreases in length by 1
*********************************************************************/
tiger* zoo::dead_tiger() {

    if (num_tigers > 0) {
        num_tigers -= 1;
        tiger* new_tiger_arr = new tiger[num_tigers];

        for (int i = 0; i < num_tigers; i++) {
            new_tiger_arr[i] = tiger_arr[i];
        }

        delete [] tiger_arr;
        tiger_arr = new_tiger_arr;
        return tiger_arr;
    }
    else {
        cout << "There are no tigers to die!" << endl;
    }
}

/*********************************************************************
** Function: dead_bear()
** Description: takes one off the end of the the bear array
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: array of bears decreases in length by 1
*********************************************************************/
bear* zoo::dead_bear() {

    if (num_bears > 0) {
        num_bears -= 1;
        bear* new_bear_arr = new bear[num_bears];

        for (int i = 0; i < num_bears; i++) {
            new_bear_arr[i] = bear_arr[i];
        }

        delete [] bear_arr;
        bear_arr = new_bear_arr;
        return bear_arr;
    }
    else {
        cout << "There are no bears to die!" << endl;
    }
}

/*********************************************************************
** Function: dead_sea_lion()
** Description: takes one off the end of the the sea lion array
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: array of sea lions decreases in length by 1
*********************************************************************/
sea_lion* zoo::dead_sea_lion() {

    if (num_sea_lions > 0) {
        num_sea_lions -= 1;
        sea_lion* new_sea_lion_arr = new sea_lion[num_sea_lions];

        for (int i = 0; i < num_sea_lions; i++) {
            new_sea_lion_arr[i] = sea_lion_arr[i];
        }

        delete [] sea_lion_arr;
        sea_lion_arr = new_sea_lion_arr;
        return sea_lion_arr;
    }
    else {
        cout << "There are no sea lions to die!" << endl;
    }
}

/*********************************************************************
** Function: sick_tiger()
** Description: deals with sick adult and baby tigers
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: amount needed to take care of the tiger taken away from bank
*********************************************************************/
void zoo::sick_tiger() {
    srand(time(NULL));
    
    if (num_tigers > 0) {
        int rand_tiger = rand() % num_tigers;

        if (tiger_arr[rand_tiger].get_age() < 6) {
            cout << "A baby tiger got sick, this will cost $12,000 to heal them." << endl;
            bank -= 12000.0;
        }
        else {
            cout << "A tiger got sick, this will cost $6,000 to heal." << endl;
            bank -= 6000.0;
        }
    }
}

/*********************************************************************
** Function: sick_bear()
** Description: deals with sick adult and baby bears
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: amount needed to take care of the bear taken away from bank
*********************************************************************/
void zoo::sick_bear() {
    srand(time(NULL));

    if (num_bears > 0) {
        int rand_bear = rand() % num_bears;

        if (bear_arr[rand_bear].get_age() < 6) {
            cout << "A baby bear got sick, this will cost $5,000 to heal them." << endl;
            bank -= 5000.0;
        }
        else {
            cout << "A bear got sick, this will cost $2,500 to heal." << endl;
            bank -= 2500.0;
        }
    }
}

/*********************************************************************
** Function: sick_sea_lion()
** Description: deals with sick adult and baby sea lions
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: amount needed to take care of the sea lion taken away from bank
*********************************************************************/
void zoo::sick_sea_lion() {
    srand(time(NULL));

    if (num_sea_lions > 0) {
        int rand_sea_lion = rand() % num_sea_lions;

        if (tiger_arr[rand_sea_lion].get_age() < 6) {
            cout << "A baby sea lion got sick, this will cost $700 to heal them." << endl;
            bank -= 700.0;
        }
        else {
            cout << "A sea lion got sick, this will cost $350 to heal." << endl;
            bank -= 350.0;
        }
    }
}

/*********************************************************************
** Function: sick_animal()
** Description: deals with all sick animals
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: amount needed to take care of whatever sick animal is taken away from bank
*********************************************************************/
void zoo::sick_animal() {
    int species = get_random_species();
    
    if (species == 1) {
        if (bank > 0) {
            
            sick_tiger();
        }
        else {
            cout << "A tiger died cause you're broke :(" << endl;
            dead_tiger();
        }
    }
    else if (species == 2) {
        if (bank > 0) {
            sick_bear();
        }
        else {
            cout << "A bear died cause you're broke :(" << endl;
            dead_bear();
        }
    }
    else if (species == 3) {
        if (bank > 0) {
            sick_sea_lion();
        }
        else {
            cout << "A sea lion died cause you're REALLY broke :(" << endl;
            dead_sea_lion();
        }
    }
}

/*********************************************************************
** Function: tiger_babies()
** Description: lets tigers have babies if there are 2 adults
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: babies either had or not had
*********************************************************************/
void zoo::tiger_babies() {
    int adult_counter = 0;

    if (num_tigers >= 2) {
        for (int i = 0; i < num_tigers; i++) {
            if (tiger_arr[i].get_age() > 48) {
                adult_counter++;
            }
        }
    }
    else {
        cout << "You do not have enough tigers to give birth!" << endl;
    }

    if (adult_counter >= 2) {
        cout << "Your tiger gave birth to triplets!" << endl;
        resize_tiger_arr(3);
        
        for (int i = 0; i < 3; i++) {
            tiger_arr[(num_tigers - 1) - i].set_age(0);
        }
    }
    else {
        cout << "You do not have enough adult tigers to give birth!" << endl;
    }
}

/*********************************************************************
** Function: bear_babies()
** Description: lets bears have babies if there are 2 adults
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: babies either had or not had
*********************************************************************/
void zoo::bear_babies() {
    int adult_counter = 0;

    if (num_bears >= 2) {
        for (int i = 0; i < num_bears; i++) {
            if (bear_arr[i].get_age() > 48) {
                adult_counter++;
            }
        }
    }
    else {
        cout << "You do not have enough bears to give birth!" << endl;
    }

    if (adult_counter >= 2) {
        cout << "Your bear gave birth to twins!" << endl;
        resize_bear_arr(2);

        for (int i = 0; i < 2; i++) {
            bear_arr[(num_bears - 1) - i].set_age(0);
        }
    }
    else {
        cout << "You do not have enough adult bears to give birth!" << endl;
    }
}

/*********************************************************************
** Function: sea_lion_babies()
** Description: lets sea lions have babies if there are 2 adults
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: babies either had or not had
*********************************************************************/
void zoo::sea_lion_babies() {
    int adult_counter = 0;

    if (num_sea_lions >= 2) {
        for (int i = 0; i < num_sea_lions; i++) {
            if (sea_lion_arr[i].get_age() > 48) {
                adult_counter++;
            }
        }
    }
    else {
        cout << "You do not have enough sea lions to give birth!" << endl;
    }

    if (adult_counter >= 2) {
        cout << "Your sea lion gave birth to a child! Its name is Samuel." << endl;
        resize_sea_lion_arr(1);

        sea_lion_arr[(num_sea_lions - 1)].set_age(0);
    }
    else {
        cout << "You do not have enough adult sea lions to give birth!" << endl;
    }
}

/*********************************************************************
** Function: babies()
** Description: deals with all baby animal births
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: babies either had or not had
*********************************************************************/
void zoo::babies() {
    int species = get_random_species();

    if (species == 1) {
        tiger_babies();
    }
    else if (species == 2) {
        bear_babies();
    }
    else if (species == 3) {
        sea_lion_babies();
    }
}

/*********************************************************************
** Function: population_spike()
** Description: random event population spike, makes sea lions generate more revenue
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: extra amount from sea lions added to bank
*********************************************************************/
void zoo::population_spike() {
    cout << "For whatever reason, there has been a population spike." << endl;
    cout << "Even more confusingly, everyone is going to see the sea lions." << endl;
    cout << "Go see the lions or something idk" << endl;

    int extra_money = rand() % 400 + 150;
    cout << "You will recieve " << (num_sea_lions * extra_money) << " extra dollars" << endl;
    bank += (num_sea_lions * extra_money);
}

/*********************************************************************
** Function: random_events()
** Description: gets random special event and calls the associated function
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: special event occurs
*********************************************************************/
void zoo::random_events() {
    int event = get_random_event();
    int odds = rand() % 4 + 1;
    int choice = food_choice();
    // this whole chunk deals with extra odds or less less based on food types
    if (event == 1) {
        if (choice == 3) {
            if (odds == 1) {
                sick_animal();
            }
        }
        else if (choice == 2) {
            if (odds == 1 || odds == 2 || odds == 3 || odds == 4) {
                sick_animal();
            }
        }
        else {
            sick_animal();
        }
    }
    else if (event == 2) {
        babies();
    }
    else if (event == 3) {
        population_spike();
    }
    else {
        cout << "Nothing happened this month!" << endl;
    }
}

/*********************************************************************
** Function: food_choice()
** Description: asks user for which food they want to use
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: food choice known
*********************************************************************/
int zoo::food_choice() {
    int food_choice;
    bool ask_again = true;

    do {
        cout << "Which food would you like to pick?" << endl;
        cout << "1. Regular" << endl;
        cout << "2. Premium (2x cost, but 1/2 chance of being sick)" << endl;
        cout << "3. Crappy (1/2 cost, but 2x more likely to be sick)" << endl;
        
        cin >> food_choice;
        
        if (food_choice == 1 || food_choice == 2 || food_choice == 3) {
            //ask_again = false;
            return food_choice;
        }
        else {
            cout << "You did not enter 1, 2, or 3 please enter again." << endl;
            ask_again = true;
        }

    } while (ask_again == true);

}

/*********************************************************************
** Function: menu()
** Description: runs whole game
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void zoo::menu() {
    bool yerb = true;
    int choice;
    welcome();

    do {
        buy_animals();
        random_events();
        //cout << bank << " is the amount in the bank" << endl;
        cout << "Do you want to play another round? (1) yes or (2) no" << endl;
        cin >> choice;

        if (choice == 1) {
            update_revenue();
            cout << "You have $" << bank << " left!" << endl;
            if (bank <= 0) {
                cout << "You're out of money. You lose." << endl;
                yerb = true;
                continue;
            }
            yerb = false;
        }
        if (choice == 2) {
            yerb = true;
        }

    } while(yerb == false);
}

