#ifndef IMAGE_RECOVERY_IMAGEOPERATIONS_H
#define IMAGE_RECOVERY_IMAGEOPERATIONS_H

#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "array"
using namespace cv;

class ImageOperations {

private:
    Mat image;
    int rows, cols, numberOfColors;
    int numberOfDifferentColors();


public:
    ImageOperations();
    ~ImageOperations();

};


#endif //IMAGE_RECOVERY_IMAGEOPERATIONS_H
