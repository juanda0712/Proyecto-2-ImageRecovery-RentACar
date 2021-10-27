#ifndef IMAGE_RECOVERY_IMAGEOPERATIONS_H
#define IMAGE_RECOVERY_IMAGEOPERATIONS_H

#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>

using namespace cv;
using namespace std;

class ImageOperations {

private:
    Mat image;
    vector<Vec3b> colorsList;
    vector<int> points;
    int rows, cols, numberOfColors;
    //Mat pixels
    int numberOfDifferentColors();
    void discardRedundantPixels();
public:
    ImageOperations(Mat myImage);
    ~ImageOperations();
    void savePixels();
    void rectanglePoints();
    vector<Vec3b> getColors();
    vector<int> getPoints();
};

#endif //IMAGE_RECOVERY_IMAGEOPERATIONS_H
