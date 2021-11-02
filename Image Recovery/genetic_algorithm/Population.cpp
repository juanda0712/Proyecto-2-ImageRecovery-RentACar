//
// Created by eduardo on 25/10/21.
//

#include "Population.h"

Population::Population(vector<int> p) {
    int totalPixels = (p[3]-p[1])*(p[4]-p[2]);
    initializePopulation(totalPixels);
}

void Population::initializePopulation(int imagePixels) {
    for (auto & individual : this->individuals) {
        individual = new Individual(imagePixels);
    }
}

int Population::calculateFitness() {
    /*for (int & fitnessPoint : this->fitnessPoints) {
        for (auto & individual : this->individuals) {
            fitnessPoint = individual->getFitness();
        }
    }*/
}

Individual Population::getFittest() {
    /*int fitness;
    for (int i = 0; i < 10; i++) {
        if (this->fitnessPoints[i] > this->fitnessPoints[i+1]) {
            fitness = fitnessPoints[i];
        }
        else {
            fitness = fitnessPoints[i+1];
        }
    }
    return fitness;*/
}

Individual Population::getSecondFittest() {
    for (auto & individual : this->individuals) {

    }
}