//
// Created by eduardo on 22/10/21.
//

#ifndef IMAGE_RECOVERY_INDIVIDUAL_H
#define IMAGE_RECOVERY_INDIVIDUAL_H

#include <vector>

using namespace std;

class Individual {
private:
    int genes;
    int fitness;
    vector<int> chromosome;
public:
    Individual(int genes);
    vector<int> getChromosome();
    int calculateIndFitness();
    int getFitness();
    int getGenes();
};


#endif //IMAGE_RECOVERY_INDIVIDUAL_H
