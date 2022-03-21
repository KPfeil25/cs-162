#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <cstdlib>
#include "node.h"

using namespace std;

class linked_list {
    private:
        unsigned int length;
        node *head;
    public:
        linked_list();
        ~linked_list();
        linked_list& operator=(const linked_list&);
        int get_length();
        void print();
        void clear();
        unsigned int push_front(int);
        unsigned int push_back(int);
        unsigned int insert(int val, unsigned int index);
        void sort_ascending(); //merge sort
        void sort_descending(); //selection sort

        void get_primes();
        void use_insert(int);
        void get_numbers();
        void find_primes();
        void list();
        void merge_sort(node**, bool);
        node* merge(node*, node*, bool);
};


#endif