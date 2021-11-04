
#include "Genetics.h"
#include <utility>
#include "iostream"

Genetics::Genetics(int numOfGenerations, int genesQuantity, vector<Vec3b> colorsList , vector<double> percentajes) {
    this->percentajesRectangle = percentajes;
    this->fittest = nullptr;
    this->secondFittest = nullptr;
    this->numOfGenerations = numOfGenerations;
    this->currentGen = new Population(genesQuantity,colorsList);
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
    int lessReference=0;
    int largerReference=0;
    int diference=0;
    int sumLessers=0;
    int sumLargers=0;


    for (int i = 0; i < this->fittest->getRectanglePercentages().size() ; i++) {
        if(this->fittest->getRectanglePercentages()[i] < this->percentajesRectangle[i]){
            lessReference+=1;
        }
        if(this->fittest->getRectanglePercentages()[i] > this->percentajesRectangle[i]){
            largerReference+=1;
        }
        }

    for (int i = 0; i < this->fittest->getRectanglePercentages().size() ; i++) {
        if(this->fittest->getRectanglePercentages()[i] < this->percentajesRectangle[i]){
            diference = abs(this->fittest->getRectanglePercentages()[i] - this->percentajesRectangle[i]);
        }
    }

    for (int i = 0; i < this->fittest->getRectanglePercentages().size() ; i++) {
        if(this->fittest->getRectanglePercentages()[i] < this->percentajesRectangle[i]){

        }
        if(this->fittest->getRectanglePercentages()[i] > this->percentajesRectangle[i]){

        }
    }
}

/*
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
}*/
