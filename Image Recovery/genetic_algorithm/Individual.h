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
    vector<Vec3b> colorsList;
    vector<double> RectanglePercentages;
    vector<int>  quantityOfEachGen;

public:
    Individual(int genesQuantity, vector<Vec3b> colorsList);
    void calculateIndFitness();
    void  pixelsPercentage();
    void quantities();

    //setters
    void setFitness(int fitness);

    //getters
    vector<double> getRectanglePercentages();
    vector<int> getQuantityOfEachGen();
    vector<Vec3b> getGenes();
    vector<Vec3b> getColors();
    int getFitness();
    int getGenesQuantity();
};
#endif //IMAGE_RECOVERY_INDIVIDUAL_H
