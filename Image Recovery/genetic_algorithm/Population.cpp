#include "Population.h"

Population::Population(int genesQuantity, vector<Vec3b> colorsList) {
    this->genesQuantity = genesQuantity;
    this->colorsList = colorsList;
    for (auto & individual : this->individuals) {
        individual = new Individual(genesQuantity,colorsList);
    }
}


void Population::calculateFitness(vector<double> percentages) {
    for (auto & individual : this->individuals) {
        individual->calculateIndFitness(percentages);
    }
}

Individual* Population::getFittest() {
    int currentFitness = this->individuals[0]->getFitness();
    int fit;
    for (int i = 0; i < individualsQuantity; i++) {
        if (this->individuals[i]->getFitness() < currentFitness) {
            currentFitness = this->individuals[i]->getFitness();
            fit = i;
        }
    }
    return this->individuals[fit];
}

Individual* Population::getSecondFittest() {
    int currentFitness = this->individuals[0]->getFitness();
    int fit1=0;
    int fit2;
    for (int i = 0; i < individualsQuantity; i++) {
        if (this->individuals[i]->getFitness() < currentFitness) {
            currentFitness = this->individuals[i]->getFitness();
            fit2 = fit1;
            fit1 = i;
        }
    }
    return this->individuals[fit2];
}

void Population::addCrossoverIndividual(Individual* crossoverIndividual){
    int lesserFitness =0;
    int fit;
    for (int i = 0; i < individualsQuantity; i++) {
        if (this->individuals[i]->getFitness() > lesserFitness) {
            lesserFitness = this->individuals[i]->getFitness();
            fit = i;
        }
    }
     this->individuals[fit] = crossoverIndividual;

}
