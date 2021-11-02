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
    vector<int> pixels;
    Population* currentGen;
    Population* nextGen;
    Individual* fittest;
    Individual* secondFittest;
public:
    Genetics(int num, vector<int> p);
    ~Genetics();
    void geneticAlgorithm();
    void selection();
    void crossover();
    void mutation();
    void inversion();
};


#endif //IMAGE_RECOVERY_GENETICS_H
