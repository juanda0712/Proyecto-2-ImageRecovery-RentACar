
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

    Mat image = imread("/home/juanda/CLionProjects/Proyecto-2-ImageRecovery-RentACar/Image Recovery/imgsPrueba/2.png");

    ImageOperations op(image);

    namedWindow("Image Recovery",WINDOW_GUI_EXPANDED);

    imshow("Image Recovery", image);

    Genetics gen1(10,op.getTotalRectanglePixels(),op.getColors(),op.getPercentages());

    vector<Individual> allFitest= gen1.geneticAlgorithm();

    int key;
    int i= 0;
    int pixelPos;
    while(true){
        key = waitKey();
        vector<Vec3b> totalGenes = allFitest[i].getGenes();
        pixelPos=0;
        if(key ==13 && i<allFitest.size()){

                for (int r = op.getPoints()[1]; r <= op.getPoints()[3]; r++) {
                    for (int c = op.getPoints()[0]; c <= op.getPoints()[2]; c++) {
                        image.at<Vec3b>(Point(c,r))[0] = totalGenes[pixelPos][0];
                        image.at<Vec3b>(Point(c,r))[1] = totalGenes[pixelPos][1];
                        image.at<Vec3b>(Point(c,r))[2] = totalGenes[pixelPos][2];
                        pixelPos++;
                    }
                }


            //namedWindow("individual", WINDOW_FREERATIO);
            imshow("Image Recovery", image);
            i++;
        }else if(key == 27){
            destroyAllWindows();
            break;
        }
    }
    return 0;
}