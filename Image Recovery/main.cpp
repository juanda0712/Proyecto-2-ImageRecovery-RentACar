#include "App.h"
#include "genetic_algorithm/Genetics.h"
#include "genetic_algorithm/Individual.h"
#include "genetic_algorithm/Population.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "ImageOperations.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    /*Mat image = imread("/home/juanda/CLionProjects/Proyecto-2-ImageRecovery-RentACar/Image Recovery/imgsPrueba/2.png");
    ImageOperations op(image);
    Genetics gen1(10,op.getTotalRectanglePixels(),op.getColors(),op.getPercentages());
    vector<Individual> allFitest = gen1.geneticAlgorithm();

    App* imageRecovery = new App(allFitest, image, op);
    int key;
    while (imageRecovery->isRunning()) {
        key = waitKey(0);
        imageRecovery->listen(key);
    }
    delete imageRecovery;*/



    Mat image = imread("/home/juanda/CLionProjects/Proyecto-2-ImageRecovery-RentACar/Image Recovery/imgsPrueba/2.png");
    ImageOperations op(image);
    imshow("original", image);
    Genetics gen1(10,op.getTotalRectanglePixels(),op.getColors(),op.getPercentages());
    vector<Individual> allFitest= gen1.geneticAlgorithm();
    for (Vec3b genes : allFitest[9].getGenes()) {
        for (int r = op.getPoints()[1]; r <= op.getPoints()[3]; r++) {
            for (int c = op.getPoints()[0]; c <= op.getPoints()[2]; c++) {
                image.at<Vec3b>(Point(c,r)) = genes;
            }
        }
    }
    namedWindow("individual", WINDOW_FREERATIO);
    imshow("individual", image);
    waitKey();

    return 0;
}