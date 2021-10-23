//
// Created by eduardo on 22/10/21.
//

#include "ImageCompleter.h"
#include "iostream"

ImageCompleter::ImageCompleter() {
    this->generations = 10;
    for (int i = 0; i < 5; i++) {
        this->individuals[i] = new Individual(i+1);
        printf("Memory address: %p\n", this->individuals[i]);
        printf("ID Value: %d\n", this->individuals[i]->getId());
    }
}

void ImageCompleter::genetic_algorithm() {
    while (this->generations > 0) {

    }
}

bool ImageCompleter::fitnessSelection() {

}

Individual ImageCompleter::getConcreteIndividual(int index) {
    for (Individual* i : this->individuals) {
        if (i->getId() == index) {
            return *i;
        }
    }
}
