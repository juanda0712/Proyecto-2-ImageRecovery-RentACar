
#include "Individual.h"
#include <iostream>

Individual::Individual(int genesQuantity, vector<Vec3b> colorsList) {
    this->genesQuantity = genesQuantity;
    this->fitness = 0;
    int flag;
    for (int p = 0; p < genesQuantity; p++) {
        flag = rand() % colorsList.size();
        this->genes.insert(genes.cend(), colorsList[flag]);
        }
    }
void Individual::calculateIndFitness(){} //falta hacer el fitness

void Individual::setFitness(int indFitness) {
    this->fitness = indFitness;
}
vector<Vec3b> Individual::getGenes() {
    return this->genes;
}

int Individual::getFitness() {
    return this->fitness;
}

int Individual::getGenesQuantity() {
    return this->genesQuantity;
}