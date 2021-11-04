
#include "Genetics.h"
#include <utility>
#include "iostream"

Genetics::Genetics(int num, vector<int> p) {
    this->fittest = nullptr;
    this->secondFittest = nullptr;
    this->numOfGenerations = num;
    this->pixels = p;
    this->currentGen = new Population(p);
}

Genetics::~Genetics() {
    delete this->currentGen;
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
        currentGen->calculateFitness();
        this->numOfGenerations--;
    }
}

void Genetics::selection() {
    cout << "Selecting" << endl;
    this->fittest = currentGen->getFittest();
    this->secondFittest = currentGen->getSecondFittest();
}

void Genetics::crossover() {
    cout << "Crossing" << endl;
    for (int i = 0; i < fittest->getGenes()/2; i++) {
        int temp = this->fittest->getChromosome()[i];
        this->fittest->getChromosome()[i] = secondFittest->getChromosome()[i];
        this->secondFittest->getChromosome()[i] = temp;
    }
}

void Genetics::mutation() {
    cout << "Mutating" << endl;
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
    cout << "Inverting" << endl;
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
