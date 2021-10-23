//
// Created by eduardo on 22/10/21.
//

#include "Individual.h"
#include <iostream>

Individual::Individual(int id1) {
    this->id = id1;
    cout << "Individual created" << endl;
}

int Individual::getId() const {
    return this->id;
}