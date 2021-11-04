#include "Population.h"

Population::Population(int genesQuantity, vector<Vec3b> colorsList) {
    for (auto & individual : this->individuals) {
        individual = new Individual(genesQuantity,colorsList);
    }
}

void Population::calculateFitness() {
    for (auto & individual : this->individuals) {
        individual->calculateIndFitness();
    }
}

Individual* Population::getFittest() {
    int currentFitness = 0;
    int fit;
    for (int i = 0; i < individualsQuantity; i++) {
        if (this->individuals[i]->getFitness() > currentFitness) {
            currentFitness = this->individuals[i]->getFitness();
            fit = i;
        }
    }
    return this->individuals[fit];
}

Individual* Population::getSecondFittest() {
    int currentFitness = 0;
    int fit1=0;
    int fit2;
    for (int i = 0; i < individualsQuantity; i++) {

        if (this->individuals[i]->getFitness() > currentFitness) {
            currentFitness = this->individuals[i]->getFitness();
            fit2 = fit1;
            fit1 = i;
        }
    }
    return this->individuals[fit2];
}
