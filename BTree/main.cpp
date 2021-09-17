#include <iostream>
#include "btree.h"

using namespace std;

int main() {
    BTree t(3);
    t.insert(8);
    t.insert(9);
    t.insert(10);
    t.insert(11);
    t.insert(15);
    t.insert(16);
    t.insert(17);
    t.insert(18);
    t.insert(20);
    t.insert(23);

    cout << "The B-tree is: ";
    t.traverse();

    int k = 10;
    (t.search(k) != NULL) ? cout << endl
        << k << " is found"
        : cout << endl
        << k << " is not Found";

    k = 2;
    (t.search(k) != NULL) ? cout << endl
        << k << " is found"
        : cout << endl
        << k << " is not Found\n";
}