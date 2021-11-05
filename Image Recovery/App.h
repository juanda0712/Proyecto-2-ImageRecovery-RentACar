//
// Created by eduardo on 19/10/21.
//

#ifndef IMAGE_RECOVERY_APP_H
#define IMAGE_RECOVERY_APP_H

#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "genetic_algorithm/Genetics.h"
#include "genetic_algorithm/Population.h"
#include "genetic_algorithm/Individual.h"
#include "ImageOperations.h"

using namespace cv;

class App {
private:
    Mat img;
    vector<Individual> allFitest;
    ImageOperations* ops;
    vector<Individual> genFittests;
    int index;
    bool running;
    void initWindow();
public:
    App(vector<Individual> allFitest, Mat img,ImageOperations ops);
    ~App();
    void kill();
    void listen(int key);
    bool isRunning() const;
    void next();
};


#endif //IMAGE_RECOVERY_APP_H