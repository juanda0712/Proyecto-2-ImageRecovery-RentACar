//
// Created by eduardo on 25/10/21.
//

#include "Population.h"

Population::Population(vector<int> p) {
    this->num = 10;
    int totalPixels = (p[3]-p[1])*(p[4]-p[2]);
    initializePopulation(totalPixels);
}

void Population::initializePopulation(int imagePixels) {
    for (auto & individual : this->individuals) {
        individual = new Individual(imagePixels);
    }
}

void Population::calculateFitness() {
    for (auto & individual : this->individuals) {
        individual->calculateIndFitness();
    }
}

Individual* Population::getFittest(int currentFitness, int i) {
    if (i >= this->num) {
        return this->individuals[i];
    }
    else if (this->individuals[i]->getFitness() > currentFitness) {
        return this->getFittest(this->individuals[i]->getFitness(), ++i);
    }
    else {
        return this->getFittest(currentFitness, ++i);
    }
}

Individual* Population::getSecondFittest(int currentFitness, int i) {
    if (i >= this->num - 1) {
        return this->individuals[i];
    }
    else if (this->individuals[i]->getFitness() > currentFitness) {
        return this->getFittest(this->individuals[i]->getFitness(), ++i);
    }
    else {
        return this->getFittest(currentFitness, ++i);
    }
}