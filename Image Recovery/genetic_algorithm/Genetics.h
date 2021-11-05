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
    int genesQuantity;
    vector<Vec3b> colorsList;
    vector<Individual> allFittest;

public:
    Genetics(int numOfGenerations, int genesQuantity, vector<Vec3b> colorsList,vector<double> percentages);
    ~Genetics();
    vector<Individual> geneticAlgorithm();
    void selection();
    vector<double> crossover();
    void mutation();
    void inversion();

};
#endif //IMAGE_RECOVERY_GENETICS_H
