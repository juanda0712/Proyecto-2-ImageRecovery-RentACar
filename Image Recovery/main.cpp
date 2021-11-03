#include "App.h"
#include "genetic_algorithm/Genetics.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "ImageOperations.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {

    Mat image = imread("/home/juanda/CLionProjects/Proyecto-2-ImageRecovery-RentACar/Image Recovery/images/patron.png");

    ImageOperations op(image);
    vector<int> points =op.getPoints();

    cout << op.getTotalRectanglePixels()<< endl;
    cout << points[0]<< endl;
    cout << points[1]<< endl;
    cout << points[2]<< endl;
    cout << points[3]<< endl;
    cout << op.getTotalImagePixels()<< endl;


    //Genetics genetics(15, op.getPoints());
    return 0;
}