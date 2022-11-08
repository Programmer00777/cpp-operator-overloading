//
// Created by Sergey Chernikov on 11/8/22.
//

#ifndef LB2_RANDOMSETGENERATOR_H
#define LB2_RANDOMSETGENERATOR_H


#include "Set.h"

class RandomSetGenerator {
public:
    RandomSetGenerator() {
        srand((unsigned) time(nullptr));
    }

    Set generateRandomSet() {
        Set set;
        for (int i = 0; i < rand() % 10; i++) {
            set + rand() % 10;
        }

        return set;
    }
};


#endif //LB2_RANDOMSETGENERATOR_H
