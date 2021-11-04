//
// Created by eduardo on 25/10/21.
//

#ifndef IMAGE_RECOVERY_POPULATION_H
#define IMAGE_RECOVERY_POPULATION_H


#include "Individual.h"
#include "iostream"

class Population {
private:
    int num; //numero de poblacion
    int individualsQuantity = 10;
    Individual* individuals[10]; //cantidad de individuos

public:
    Population(int genesQuantity, vector<Vec3b> colorsList);
    void calculateFitness();

    //setters
    void setNum();

    //getters especiales
    Individual* getFittest();
    Individual* getSecondFittest();
};


#endif //IMAGE_RECOVERY_POPULATION_H
