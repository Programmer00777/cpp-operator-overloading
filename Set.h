//
// Created by Sergey Chernikov on 11/8/22.
//

#ifndef LB2_SET_H
#define LB2_SET_H

#include <vector>

using namespace std;

class Set {
private:
    vector<int> set;

public:
    Set() {}

    Set(const Set &sample) {
        this->set = sample.set;
    }

    Set operator + (int value) {
        if (count(set.begin(), set.end(), value) == 0) {
            set.push_back(value);
        }
        return *this;
    }

    Set operator - (int value) {
        for (int i = 0; i < set.size(); i++) {
            if (this->set.at(i) == value) {
                vector<int>::iterator it = this->set.begin() + i;
                this->set.erase(it);
            }
        }

        return *this;
    }

    Set operator * (Set const &anotherSet) {
        Set newSet;
        for (int i = 0; i < this->set.size(); i++) {
            if (count(anotherSet.set.begin(), anotherSet.set.end(), this->set.at(i)) != 0) {
                newSet + this->set.at(i);
            }
        }
        for (int i = 0; i < anotherSet.set.size(); i++) {
            if (count(this->set.begin(), this->set.end(), anotherSet.set.at(i)) != 0) {
                newSet + anotherSet.set.at(i);
            }
        }
        return newSet;
    }

    int operator [] (int index) {
        if (index >= set.size() || index < 0) {
            cout << "Error: Index out of bound!" << endl;
            exit(0);
        }
        return set[index];
    }

    Set operator = (Set const &anotherSet) {
        this->set = anotherSet.set;
        return *this;
    }

    void toString() {
        cout << "Set:" << endl;
        for (int i = 0; i < set.size(); i++) {
            cout << " " << set.at(i);
        }
    }
};


#endif //LB2_SET_H
