//
// Created by eduardo on 25/10/21.
//

#ifndef IMAGE_RECOVERY_POPULATION_H
#define IMAGE_RECOVERY_POPULATION_H


#include "Individual.h"

class Population {
private:
    int populationSize;
    Individual* individuals[10];
public:
    Population(int size);
    void initializePopulation(int imagePixels);
    int calculateFitness();
    Individual getFittest();
    Individual getSecondFittest();
};


#endif //IMAGE_RECOVERY_POPULATION_H
