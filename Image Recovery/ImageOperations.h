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
    int rows, cols, numberOfColors;
public:
    ImageOperations(Mat myImage);
    ~ImageOperations();
    void savePixels();
    vector<Vec3b> getColors();
};


#endif //IMAGE_RECOVERY_IMAGEOPERATIONS_H
