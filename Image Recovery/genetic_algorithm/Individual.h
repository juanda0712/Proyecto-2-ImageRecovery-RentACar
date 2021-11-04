#ifndef IMAGE_RECOVERY_INDIVIDUAL_H
#define IMAGE_RECOVERY_INDIVIDUAL_H

#include <vector>
#include "opencv4/opencv2/opencv.hpp"
using namespace cv;
using namespace std;

class Individual {
private:
    int genesQuantity;
    int fitness;
    vector<Vec3b> genes;
public:
    Individual(int genesQuantity, vector<Vec3b> colorsList);
    void calculateIndFitness();

    //setters
    void setFitness(int fitness);

    //getters
    vector<Vec3b> getGenes();
    int getFitness();
    int getGenesQuantity();
};
#endif //IMAGE_RECOVERY_INDIVIDUAL_H
