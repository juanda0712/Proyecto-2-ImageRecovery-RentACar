//
// Created by eduardo on 22/10/21.
//

#include "Individual.h"
#include <iostream>

Individual::Individual() {
    cout << "Individual created" << endl;
}

int Individual::getFitness() {
    return this->fitness;
}