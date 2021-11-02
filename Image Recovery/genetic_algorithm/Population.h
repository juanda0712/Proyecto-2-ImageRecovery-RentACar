//
// Created by eduardo on 25/10/21.
//

#ifndef IMAGE_RECOVERY_POPULATION_H
#define IMAGE_RECOVERY_POPULATION_H


#include "Individual.h"
#include "iostream"

class Population {
private:
    int num;
    Individual* individuals[10];
public:
    Population(vector<int> p);
    void initializePopulation(int imagePixels);
    void calculateFitness();
    Individual* getFittest(int currentFitness, int i);
    Individual* getSecondFittest(int currentFitness, int i);
};


#endif //IMAGE_RECOVERY_POPULATION_H
