//
// Created by eduardo on 22/10/21.
//

#include "Individual.h"
#include <iostream>

Individual::Individual(int genes) {
    this->genes = genes;
    this->fitness = 0;
    int flag = 1 + (rand() % 2);
    for (int p = 0; p < genes; p++) {
        if (flag == 1) {
            this->chromosome.insert(chromosome.cend(), 1);
        }
        else {
            this->chromosome.insert(chromosome.cend(), 0);
        }
    }
}

vector<int> Individual::getChromosome() {
    return this->chromosome;
}

int Individual::getFitness() {
    return this->fitness;
}

int Individual::getGenes() {
    return 0;
}