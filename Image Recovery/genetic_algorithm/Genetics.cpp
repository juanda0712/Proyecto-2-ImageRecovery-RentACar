
#include "Genetics.h"
#include <utility>
#include "iostream"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

Genetics::Genetics(int numOfGenerations, int genesQuantity, vector<Vec3b> colorsList , vector<double> percentages) {
    this->percentajesRectangle = percentages;
    this->fittest = nullptr;
    this->secondFittest = nullptr;
    this->numOfGenerations = numOfGenerations;
    this->currentGen = new Population(genesQuantity,colorsList);
    this->genesQuantity = genesQuantity;
    this->colorsList = colorsList;
}

Genetics::~Genetics() {
    delete this->currentGen;
    delete this->fittest;
    delete this->secondFittest;
}

vector<Individual> Genetics::geneticAlgorithm() {
    vector<double> crossoverIndPercentajes;

    while (this->numOfGenerations > 0) {
        currentGen->calculateFitness(percentajesRectangle);
        this->selection();
        this->allFittest.insert(allFittest.cend(), *fittest);
        crossoverIndPercentajes = this->crossover();

        /*
        if (1 + (rand() % 7) < 5) {
            this->mutation();
        }
        if (1 + (rand()%50) < 5) {
            this->inversion();
        }*/

        currentGen = new Population(this->genesQuantity,this->colorsList);
        currentGen->calculateFitness(percentajesRectangle);
        //Individual crossoverIndividual(this->genesQuantity,this->colorsList,crossoverIndPercentajes);
        //currentGen->addCrossoverIndividual(&crossoverIndividual);
        this->numOfGenerations--;
    }
    return this->allFittest;
}

void Genetics::selection() {
    this->fittest = currentGen->getFittest();
    this->secondFittest = currentGen->getSecondFittest();
}

vector<double> Genetics::crossover() {
    int lessReference=0;
    int largerReference=0;
    double diference=0;
    vector<double> IndPercentajes = this->fittest->getRectanglePercentages();

    for (int i = 0; i < this->fittest->getRectanglePercentages().size() ; i++) {  // saca la cantidad de menores y mayores al de referencia
        if(this->fittest->getRectanglePercentages()[i] < this->percentajesRectangle[i]){
            lessReference+=1;
        }
        if(this->fittest->getRectanglePercentages()[i] > this->percentajesRectangle[i]){
            largerReference+=1;
        }
        }

    for (int i = 0; i < this->fittest->getRectanglePercentages().size() ; i++) {  //saca la diferencia
        if(this->fittest->getRectanglePercentages()[i] < this->percentajesRectangle[i]){
            diference = abs(this->fittest->getRectanglePercentages()[i] - this->percentajesRectangle[i]);
        }
    }

    for (int i = 0; i < this->fittest->getRectanglePercentages().size() ; i++) {
        if(this->fittest->getRectanglePercentages()[i] < this->percentajesRectangle[i]){
            if(fittest->getRectanglePercentages().size() == 2){
                IndPercentajes[i] += diference / (double)3;
            } else{
                IndPercentajes[i] += diference / (double)lessReference;
            }

        }
        if(this->fittest->getRectanglePercentages()[i] > this->percentajesRectangle[i]){
            if(fittest->getRectanglePercentages().size() == 2){
                IndPercentajes[i] -= diference / (double)3;
            }else{
                IndPercentajes[i] -= diference / (double)largerReference;
            }
        }
    }
    return IndPercentajes;
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

