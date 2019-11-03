#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
#include "Node.h"
#include <iostream>

class LinkedList {

public:

    friend class Node;

    LinkedList();

    LinkedList(const LinkedList &list);  // copy constructor

    LinkedList& operator= (const LinkedList &list); // copy operator

    ~ LinkedList(); // destructor

    void LinkedinsertionSort();  // sort function

    void addNext(int newNode); // add node function

    void print();  // print function


private:

    Node* head;

};


#endif //BINARYINSERTIONSORT_LINKEDLIST_H