//
// Created by eduardo on 25/10/21.
//

#include "Population.h"

Population::Population(vector<int> p) {
    this->num = 10;
    int totalPixels = (p[3]-p[1])*(p[4]-p[2]);
    initializePopulation(p);
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

Individual* Population::getFittest() {
    cout << "Getting fittest" << endl;
    int currentFitness = 0;
    int fit;
    for (int i = 0; i < this->num; i++) {
        if (this->individuals[i]->getFitness() > currentFitness) {
            currentFitness = this->individuals[i]->getFitness();
            fit = i;
        }
    }
    return this->individuals[fit];
}

Individual* Population::getSecondFittest() {
    cout << "Getting secondFittest" << endl;
}