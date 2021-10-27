//
// Created by eduardo on 22/10/21.
//

#ifndef IMAGE_RECOVERY_GENETICS_H
#define IMAGE_RECOVERY_GENETICS_H

#include "Individual.h"
#include "Population.h"

using namespace std;

class Genetics {
private:
    int numOfGenerations;
    Population* population;
    Individual fittest;
    Individual secondFittest;
public:
    Genetics(int num);
    ~Genetics();
    void geneticAlgorithm();
    void selection();
    void crossover();
    void mutation();
    Individual getFittestChild();
};


#endif //IMAGE_RECOVERY_GENETICS_H
