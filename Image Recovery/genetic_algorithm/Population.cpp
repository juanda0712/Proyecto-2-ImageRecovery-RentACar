//
// Created by eduardo on 25/10/21.
//

#include "Population.h"

Population::Population(int size) {
    initializePopulation();
}

void Population::initializePopulation(int imagePixels) {
    for (auto & individual : this->individuals) {
        individual = new Individual(imagePixels);
    }
}

Individual Population::getFittest() {

}

Individual Population::getSecondFittest() {

}