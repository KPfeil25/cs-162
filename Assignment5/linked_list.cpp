#include "linked_list.h"

using namespace std;

/******************************************************
** Function: is_int
** Description: checks if an inputted number is an integer
** Parameters: string
** Pre-conditions: n/a 
** Post-conditions: known if input was an integer
******************************************************/
bool is_int(string a) {
    
    for (int i = 0; i < a.length(); i++) {
        if (a[0] == '-') { i = 1; }
        if (a[i] > '9' || a[i] < '0') {
            //cout << "not a num" << endl;
            return false;
        }
        //cout << "a num" << endl;
        return true;
    }
}

/******************************************************
** Function: linked_list()
** Description: default constructor for linked list
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: linked list object created
******************************************************/
linked_list::linked_list() {
    this->length = 0;
    this->head = NULL;
}

/******************************************************
** Function: ~linked_list()
** Description: linked list destructor
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: linked list destroyed
******************************************************/
linked_list::~linked_list() {
    clear();
}

/******************************************************
** Function: assignment operator overload
** Description: overlaods the assignment operator for the linked list class
** Parameters: linked list reference
** Pre-conditions: n/a 
** Post-conditions: lists copied correctly
******************************************************/
linked_list& linked_list::operator=(const linked_list &list) {
    
    while (head != NULL) {
        clear();
    }

    node* curr = list.head;
    while (curr != NULL) {
        push_front(curr->val);
        curr = curr->next;
    }
    head = curr;
    return *this;
}

/******************************************************
** Function: use_insert()
** Description: Allows the user to use the insert function
** Parameters: int num
** Pre-conditions: n/a 
** Post-conditions: num inserted at a selected position
******************************************************/
void linked_list::use_insert(int num) {
    int position;
    bool go_again = true;

    do {
        //cout << "Length is " << length << endl;
        cout << "What position would you like to insert at?" << endl;
        cin >> position;

        if (is_int(to_string(position)) == false || position <= 0 || position > length) {
            cout << "Not a valid postion, try again." << endl;
            go_again = true;
        }
        else {
            insert(num, position);
            go_again = false;
        }
    } while (go_again == true);

}

/******************************************************
** Function: get_numbers()
** Description: gets all the numbers the user wants for the list
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: all numbers for the list gotten
******************************************************/
void linked_list::get_numbers() {
    bool go_again = true;
    string choice;
    string num;

    do {
       cout << "Would you like to use push_front(1), push_back(2), or insert(3) to add to the linked list?" << endl;
       cin >> choice;
       cout << "What number would you like to add?" << endl;
       cin >> num;

       if (stoi(choice) != 1 && stoi(choice) != 2 && stoi(choice) != 3) { //makes sure they select one of the choices
           cout << "Not a valid choice, try again." << endl;
           go_again = true;
       }
       if (is_int(num) == false) {
           cout << "Not a valid number, try again." << endl;
           go_again = true;
       }
       else {
           if (stoi(choice) == 1) {
               push_front(stoi(num));
           }
           else if (stoi(choice) == 2) {
               push_back(stoi(num));
           }
           else {
               use_insert(stoi(num));
           }
           go_again = false;
       }

    } while (go_again == true);
}

/******************************************************
** Function: get_primes
** Description: finds all prime numbers in the list
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: all primes in the list found
******************************************************/
void linked_list::get_primes() {
    node *curr = head;
    int prime_counter = 0;

    while(curr != NULL) {
        bool is_prime = true;

        for (int j = 2; j <= curr->val / 2; ++j) {
            if (curr->val % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (curr->val <= 1) { //negative numbers cannot be prime
                is_prime = false;
        }
        if (is_prime) {
            prime_counter++;
            //cout << curr->val << " is a prime number!" << endl;
        }
        curr = curr->next;
    }
    cout << "There is(are) " << prime_counter << " prime number(s) in this linked list (repeats included)!" << endl;
}

/******************************************************
** Function: list()
** Description: runs everything, basically main
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: all things needed to be done to the list are done
**** over 20 lines (barely) becuase this runs everything and also error checks
******************************************************/
void linked_list::list() {
    bool go_again = true;
    char choice;

    do {
        cout << "Add node to the list? (y or n)" << endl;
        cin >> choice;

        if (choice == 'y') {
            get_numbers();
            go_again = true;
        }
        else {
            go_again = false;
        }
    } while (go_again == true);

    cout << "Sort by ascending or descending? (a or d)" << endl;
    cin >> choice;

    if (choice == 'a') {
        sort_ascending();
        cout << "Your sorted linked list is: " << endl;
        print();
    }
    else {
        sort_descending();
        cout << "Your sorted linked list is: " << endl;
        print();
    }
    get_primes();
}

/******************************************************
** Function: get_length()
** Description: gets the length of the list
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: length of list is gotten
******************************************************/
int linked_list::get_length() {
    return this->length;
}

/******************************************************
** Function: print()
** Description: prints the whole linked list
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: list printed
******************************************************/
void linked_list::print() {
    node *curr = head;

    while(curr != NULL) {
        cout << curr->val << endl;
        curr = curr->next;
    }

}

/******************************************************
** Function: clear
** Description: clears the list, basically my destructor
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: list cleared
******************************************************/
void linked_list::clear() {
    node* temp = head;

    while(temp != NULL) {
        head = head->next;
        delete temp;
        temp = head;
    }
    length = 0;
}

/******************************************************
** Function: push_front()
** Description: adds value to the front of the list
** Parameters: int
** Pre-conditions: n/a 
** Post-conditions: value added to the front of the list
******************************************************/
unsigned int linked_list::push_front(int data) {
    node* temp = new node;

    temp->val = data;
    temp->next = head;

    head = temp;
    //cout << length << endl;

    return length++;
}

/******************************************************
** Function: push_back()
** Description: adds value to the back of the list
** Parameters: int
** Pre-conditions: n/a 
** Post-conditions: value added to the back of the list
******************************************************/
unsigned int linked_list::push_back(int data) {
    node* temp = new node;
    
    node* curr = head;

    if (length == 0) {
        push_front(data);
    }
    else {
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = temp;

        temp->val = data;
        temp->next = NULL;
    }
    return length++;
}

/******************************************************
** Function: insert()
** Description: adds value to the specified position
** Parameters: int, unsigned int
** Pre-conditions: n/a 
** Post-conditions: value added to the specified position
******************************************************/
unsigned int linked_list::insert(int value, unsigned int index) {
    node* old;
    node* new_node = new node;

    node* curr = head;

    if (length == 0) {
        push_front(value);
    }
    else {
        for (int i = 0; i < index - 1; i++) {
            old = curr;
            curr = curr->next;
        }
        old->next = new_node;
        new_node->val = value;
        new_node->next = curr;
    }

    return length++;
}

/******************************************************
** Function: merge_sort()
** Description: uses merge sort to sort the list
** Parameters: node**, bool
** Pre-conditions: n/a 
** Post-conditions: list is sorted
******************************************************/
void linked_list::merge_sort(node** head, bool ascending) {
    node* head_1;
    node* head_2;
    //cout << "Sorting" << endl;
    if (((*head) == NULL) || ((*head)->next == NULL)) {
        return;
    }

    head_1 = *head;
    head_2 = *head;

    while((head_2->next != NULL) && (head_2->next->next != NULL)) {
        head_1 = head_1->next;
        head_2 = head_2->next->next;
    }

    head_2 = head_1->next;
    node *start = *head;
    head_1->next = NULL;
    
    if (ascending == true) {
        merge_sort(&start, true);
        merge_sort(&head_2, true);
        *head = merge(start, head_2, true);
    }
    else {
        merge_sort(&start, false);
        merge_sort(&head_2, false);
        *head = merge(start, head_2, false);
    }
}

/******************************************************
** Function: merge()
** Description: performs the merging part of the merge sort process
** Parameters: node*, node*, bool
** Pre-conditions: n/a 
** Post-conditions: merging done for the list
******************************************************/
node* linked_list::merge(node* head1, node* head2, bool ascending) {
    //cout << "Merging" << endl;
    node* head3;
    node* tmp;

    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    if (ascending == true) {
        if (head1->val <= head2->val) {
            head3 = head1;
            head3->next = merge(head1->next, head2, true);
        }
        else {
            head3 = head2;
            head3->next = merge(head1, head2->next, true);
        }
        return head3;
    }
    else {
        if (head1->val >= head2->val) {
            head3 = head1;
            head3->next = merge(head1->next, head2, false);
        }
        else {
            head3 = head2;
            head3->next = merge(head1, head2->next, false);
        }
        return head3;
    }
}

/******************************************************
** Function: sort_ascending()
** Description: sorts the list in ascending order
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: list sorted in ascending order
******************************************************/
void linked_list::sort_ascending() {
    merge_sort(&head, true);
}

/******************************************************
** Function: sort_descending()
** Description: sorts the list in descending order
** Parameters: n/a
** Pre-conditions: n/a 
** Post-conditions: list sorted in desceinding order
******************************************************/
void linked_list::sort_descending() {
    merge_sort(&head, false);
}


