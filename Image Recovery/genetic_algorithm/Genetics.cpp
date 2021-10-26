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
    while (this->numOfGenerations > 0) {

    }
}

void Genetics::selection() {

}

void Genetics::crossover() {

}

void Genetics::mutation() {

}

Individual Genetics::getFittestChild() {

}