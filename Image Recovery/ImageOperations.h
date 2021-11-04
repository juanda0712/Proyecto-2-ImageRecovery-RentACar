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

    vector<int>  quantityOfEachPixel; // basado en colorsList , la primera posicion de colorsList esta relacionada con la primera posicion de este vector
    vector<double> percentages;  //porcentajes de cada color basado en la posicion de colorList osea la primera posicion de colorsList esta relacionada con la primera posicion de este vector

    int totalImagePixels;
    int totalRectanglePixels;

public:
    ImageOperations(Mat myImage);
    ~ImageOperations();
    void savePixels(Mat myImage);
    void rectanglePoints(Mat myImage);
    void quantities(Mat myImage); // averigua la cantidad que hay de cada pixel (usa el vector quantityOfEachPixel para guardar los datos
    void pixelsPercentage();

    vector<Vec3b> getColors();
    vector<int> getPoints();
    vector<int> getQuantityOfEachPixel();
    vector<double> getPercentages();

    int getTotalImagePixels();
    int getTotalRectanglePixels();
};

#endif //IMAGE_RECOVERY_IMAGEOPERATIONS_H
