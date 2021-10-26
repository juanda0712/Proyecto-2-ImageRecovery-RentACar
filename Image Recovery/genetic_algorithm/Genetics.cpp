//
// Created by eduardo on 22/10/21.
//

#include "Genetics.h"
#include "iostream"

Genetics::Genetics(int num) {
    this->numOfGenerations = num;
    this->population = new Population(10);
}

Genetics::~Genetics() {
    delete this->population;
}

void Genetics::geneticAlgorithm() {
    population.calculateFitness();
    while (this->numOfGenerations > 0) {
        this->selection();
        this->crossover();
        if ((rand() + 1) % 6 < 5)) {
            this->mutation();
        }
        this->addFittestChild();
        population.calculateFitness();
    }
}

void Genetics::selection() {
    this->fittest = population->getFittest();
    this->secondFittest = population->getSecondFittest();
}

void Genetics::crossover() {
    for (int i = 0; i < genes/2; i++) {
        int temp = this->fittest.genes[i];
        this->fittest.genes[i] = secondFittest.genes[i];
        this->secondFittest.genes[i] = temp;
    }
}

void Genetics::mutation() {
    int mutationPoint;
    if (this->fittest.genes[mutationPoint] == 1) {
        this->fittest.genes[mutationPoint] = 0;
    }
    else {
        this->fittest.genes[mutationPoint] = 1;
    }
    if (this->secondFittest.genes[mutationPoint] == 1) {
        this->secondFittest.genes[mutationPoint] = 0;
    }
    else {
        this->secondFittest.genes[mutationPoint] = 1;
    }
}

Individual Genetics::getFittestChild() {
    return this->fittest;
}