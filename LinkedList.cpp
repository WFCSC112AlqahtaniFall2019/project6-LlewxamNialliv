#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList :: LinkedList(){
    head = 0; // initialize the linked list with a head pointing to null pointer
}

LinkedList::LinkedList(const LinkedList &list){

    Node* current = list.head; // temporary pointer to indicate current position
    Node* temp = head;

    while (current -> next != 0){ // copy traversing from the head
        temp -> next = new Node(current -> next -> value);
        temp = temp -> next;
        current = current -> next;
    }
}

LinkedList& LinkedList:: operator = (const LinkedList &list){

    LinkedList temp;
    swap(temp.head, head);
    return *this;
}

LinkedList :: ~LinkedList() {

    Node* current = head;
    Node* next = current -> next;

    while(current -> next != 0){
        delete(current);
        current = next;
        next = next -> next;
    }
}

void LinkedList :: addNext(int newNode) {

    if (head == 0){ // case for empty set
        head = new Node(newNode);
    }

    else { // general case
        Node* add = head;
        while (add -> next != 0){
            add = add -> next;
        }
        add -> next = new Node (newNode);
    }
}

void LinkedList::print() {

    Node* current = head; //

    if (!current) {
        cout << "Empty list." << endl;
    }
    else{
        while(current){
            cout << current -> value << " ";
            current = current -> next;
        }
    }
    cout << endl;
}

void LinkedList::LinkedinsertionSort() {

    Node* temp = head; // temporary node for swap
    Node* previous = head; // track previous node
    Node* next = head -> next;

    if ( head == 0){ // empty list
        return;
    }

    if ( head -> next == 0){ // list of one element
        return;
    }

    while (next != 0){

        if (next -> value < previous -> value) { // compare next with previous

            if(next -> value < head -> value){ // case that next is smaller than head

                previous -> next = next -> next;
                next -> next = 0;
                next -> next = head;
                head = next; // put next to the head of the list
            }

            else{ // general case

                while ((temp -> next -> value) < (next -> value) && (temp -> next) != 0){
                    temp = temp -> next;
                }

                previous->next = next->next;
                next->next = 0;

                next->next = temp->next;
                temp->next = next;
            }
        }
        else{
            previous = previous -> next;
        }
        next = previous -> next;
    }
}