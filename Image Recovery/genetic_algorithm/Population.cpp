//
// Created by eduardo on 25/10/21.
//

#include "Population.h"

Population::Population(vector<int> p) {
    this->populationSize = 10;
    int totalPixels = (p[3]-p[1])*(p[4]-p[2]);
    initializePopulation(totalPixels);
}

void Population::initializePopulation(int imagePixels) {
    for (auto & individual : this->individuals) {
        individual = new Individual(imagePixels);
    }
}

int Population::calculateFitness() {

}

Individual Population::getFittest() {

}

Individual Population::getSecondFittest() {

}