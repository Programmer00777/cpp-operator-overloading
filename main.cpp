#include <iostream>
#include <set>
#include "Set.h"

using namespace std;

Set getUniqueSet(Set sets[], int size);
Set getUniqueSetFromTwoSets(Set sets[]);

int main() {

    return 0;
}

/**
 * Accepts an array of sets, creates a new set that contain only unique elements and returns it.
 *
 * @param sets Array of sets.
 * @return Set that contains all the unique elements from the passed sets.
 */
Set getUniqueSet(Set sets[], int size) {
    if (size < 3) {
        cout << "Error: Array size should be greater than 2!" << endl;
        exit(0);
    }

    vector<int> dumpOfItems;
    Set uniqueItems;

    for (int i = 0; i < size; i++) {
        for (int k = 0; k < sets[i].getSize(); k++) {
            dumpOfItems.push_back(sets[i].get(k));
        }
    }
    const size_t len = dumpOfItems.size();

    int items[len];
    for (int i = 0; i < len; i++) {
        items[i] = dumpOfItems[i];
    }

    set<int> sa(items, items + len);

    set<int>::iterator itr;
    for (itr = sa.begin(); itr != sa.end(); itr++)
    {
        uniqueItems + *itr;
    }

    return uniqueItems;
}

Set getUniqueSetFromTwoSets(Set sets[]) {
    Set nonUniqueSet = sets[0] * sets[1];
    Set uniqueSet;
    int size = sets[0].getSize() > sets[1].getSize() ? sets[0].getSize() : sets[1].getSize();
    for (int i = 0; i < size; i++) {
        if (i < sets[0].getSize()) {
            if (count(nonUniqueSet.getSet().begin(), nonUniqueSet.getSet().end(), sets[0].get(i)) == 0) {
                uniqueSet + sets[0].get(i);
            }
        }
        if (i < sets[1].getSize()) {
            if (count(nonUniqueSet.getSet().begin(), nonUniqueSet.getSet().end(), sets[1].get(i)) == 0) {
                uniqueSet + sets[1].get(i);
            }
        }
    }

    return uniqueSet;
}