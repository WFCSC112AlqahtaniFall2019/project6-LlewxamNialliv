#include <iostream>
#include <vector>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"
#include <ctime>
#include "Node.h"
#include <cassert>
using namespace std;

int main() {

    int seed, length;
    srand(seed);

    cout << "Please enter a seed:";
    cin >> seed;
    cout << "Please enter a length:";
    cin >> length;

    vector<int> v(length);
    LinkedList List = LinkedList();

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
    }

    for (int i = 0; i < length; i++) { // generate a linked list identical to the vector
        List.addNext(v[i]);
    }

    clock_t start_vector = clock();
    insertionSort(v, v.size());
    clock_t end_vector = clock(); // use insertion sort for vector and get the time
    double elapsed_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC;

    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }
    cout << "The vector is sorted" << endl;

    clock_t start_linkedList = clock();
    List.LinkedinsertionSort();
    clock_t end_linkedList = clock(); // use insertion sort for linked list and get the time
    double elapsed_linkedList = double(end_linkedList - start_linkedList) / CLOCKS_PER_SEC;

    cout << "Sorted LinkedList:  " ;
    List.print();

    cout << endl; // output the time
    cout << "Elapsed time for sorting a " << length << "-element vector or linkedlist: " << endl;
    cout << "Vector(BinaryInsertionSort): " << elapsed_vector << endl;
    cout << "Linkedlist(InsertionSort): " << elapsed_linkedList << endl;
}