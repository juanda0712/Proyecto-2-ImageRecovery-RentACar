//
// Created by eduardo on 22/10/21.
//

#ifndef IMAGE_RECOVERY_IMAGECOMPLETER_H
#define IMAGE_RECOVERY_IMAGECOMPLETER_H

#include "Individual.h"
#include <vector>

using namespace std;

class ImageCompleter {
private:
    int generations;
    Individual* individuals[10];
public:
    ImageCompleter();
    void genetic_algorithm();
    bool fitnessSelection();
    Individual getConcreteIndividual(int index);
};


#endif //IMAGE_RECOVERY_IMAGECOMPLETER_H
