#include "App.h"
#include "genetic_algorithm/Genetics.h"
#include "genetic_algorithm/Individual.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "ImageOperations.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {

    Mat image = imread("/home/juanda/CLionProjects/Proyecto-2-ImageRecovery-RentACar/Image Recovery/imgsPrueba/1.png");

    ImageOperations op(image);
    vector<int> points =op.getPoints();

    cout << op.getTotalImagePixels()<< endl;
    cout << op.getTotalRectanglePixels()<< endl;
    cout << points[0]<< endl;
    cout << points[1]<< endl;
    cout << points[2]<< endl;
    cout << points[3]<< endl;

    for (int i = 0; i < op.getColors().size() ; ++i) {
        cout << "PIxel: " <<op.getColors()[i] << " Cantidad: " << op.getQuantityOfEachPixel()[i] << " Porcentaje: " << op.getPercentages()[i]<< "%"<<endl;
    }

    Individual ind(op.getTotalRectanglePixels(),op.getColors());
    for (int i = 0; i <ind.getGenes().size() ; ++i) {
        cout << ind.getGenes()[i] << endl;
    }
    for (int i = 0; i < ind.getRectanglePercentages().size() ; ++i) {
        cout << "PIxel: " <<ind.getColors()[i] << " Cantidad: " << ind.getQuantityOfEachGen()[i] << " Porcentaje: " << ind.getRectanglePercentages()[i]<< "%"<<endl;
    }



    //Genetics genetics(15, op.getPoints());
    return 0;
}