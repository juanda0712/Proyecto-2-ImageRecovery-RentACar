//
// Created by eduardo on 22/10/21.
//

#ifndef IMAGE_RECOVERY_INDIVIDUAL_H
#define IMAGE_RECOVERY_INDIVIDUAL_H

#include <QColor>

using namespace std;

class Individual {
private:
    int fitness;
    int id;
    QColor* color;
public:
    int genes[5];
    Individual();
    int getFitness();
};


#endif //IMAGE_RECOVERY_INDIVIDUAL_H
