#ifndef IMAGE_RECOVERY_GENETICS_H
#define IMAGE_RECOVERY_GENETICS_H

#include "Individual.h"
#include "Population.h"

using namespace std;

class Genetics {
private:
    int numOfGenerations;
    Population* currentGen;
    Individual* fittest;
    Individual* secondFittest;
    vector<double> percentajesRectangle;
public:
    Genetics(int numOfGenerations, int genesQuantity, vector<Vec3b> colorsList,vector<double> percentajes);
    ~Genetics();
    void geneticAlgorithm();
    void selection();
    void crossover();
    void mutation();
    void inversion();
};
#endif //IMAGE_RECOVERY_GENETICS_H
