#include "Genetics.h"
#include "iostream"

Genetics::Genetics(int num, vector<int> p) {
    this->fittest = nullptr;
    this->secondFittest = nullptr;
    this->nextGen = nullptr;
    this->numOfGenerations = num;
    this->currentGen = new Population(p);
}

Genetics::~Genetics() {
    delete this->currentGen;
    delete this->nextGen;
    delete this->fittest;
    delete this->secondFittest;
}

void Genetics::geneticAlgorithm() {
    currentGen->calculateFitness();
    while (this->numOfGenerations > 0) {
        this->selection();
        this->crossover();
        if (1 + (rand() % 7) < 5) {
            this->mutation();
        }
        if (1 + (rand()%100) < 2) {
            this->inversion();
        }
        this->updateGeneration();
        this->currentGen = nextGen;
        this->currentGen->calculateFitness();
        this->numOfGenerations--;
    }
}

void Genetics::selection() {
    *fittest = currentGen->getFittest();
    *secondFittest = currentGen->getSecondFittest();
}

void Genetics::crossover() {
    for (int i = 0; i < fittest->getGenes()/2; i++) {
        int temp = this->fittest->getChromosome()[i];
        this->fittest->getChromosome()[i] = secondFittest->getChromosome()[i];
        this->secondFittest->getChromosome()[i] = temp;
    }
}

void Genetics::mutation() {
    int mutationPoint = rand()%fittest->getGenes();
    if (this->fittest->getChromosome()[mutationPoint] == 1) {
        this->fittest->getChromosome()[mutationPoint] = 0;
    }
    else {
        this->fittest->getChromosome()[mutationPoint] = 1;
    }
    mutationPoint = rand()%secondFittest->getGenes();
    if (this->secondFittest->getChromosome()[mutationPoint] == 1) {
        this->secondFittest->getChromosome()[mutationPoint] = 0;
    }
    else {
        this->secondFittest->getChromosome()[mutationPoint] = 1;
    }
}

void Genetics::inversion() {
    int inversionHalf = rand()%fittest->getGenes()/2;
    for (int k = inversionHalf; k < fittest->getGenes(); k++) {
        fittest->getChromosome()[k]++;
        if (fittest->getChromosome()[k] > 1) {
            fittest->getChromosome()[k] = 0;
        }
    }
    inversionHalf = rand()%secondFittest->getGenes()/2;
    for (int k = inversionHalf; k < secondFittest->getGenes(); k++) {
        secondFittest->getChromosome()[k]++;
        if (secondFittest->getChromosome()[k] > 1) {
            secondFittest->getChromosome()[k] = 0;
        }
    }
}

void Genetics::updateGeneration() {

}

Individual Genetics::getFittestChild() {
    return *fittest;
}
