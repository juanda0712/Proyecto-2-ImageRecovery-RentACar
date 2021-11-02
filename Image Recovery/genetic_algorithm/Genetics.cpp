#include "Genetics.h"

#include <utility>
#include "iostream"

Genetics::Genetics(int num, vector<int> p) {
    this->fittest = nullptr;
    this->secondFittest = nullptr;
    this->nextGen = nullptr;
    this->numOfGenerations = num;
    this->pixels = p;
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
        if (1 + (rand()%50) < 5) {
            this->inversion();
        }
        currentGen = new Population(this->pixels);
        this->numOfGenerations--;
    }
}

void Genetics::selection() {
    this->fittest = currentGen->getFittest(0,0);
    this->secondFittest = currentGen->getSecondFittest(0,0);
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
