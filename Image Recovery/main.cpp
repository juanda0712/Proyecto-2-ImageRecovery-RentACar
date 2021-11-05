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
    App* imageRecovery = new App("/home/eduardo/Escritorio/Proyecto-2-ImageRecovery-RentACar/Image Recovery/imgsPrueba/1.png");
    int key;
    while (imageRecovery->isRunning()) {
        key = waitKey(0);
        imageRecovery->listen(key);
    }
    delete imageRecovery;

    /*Mat image = imread("/home/eduardo/Escritorio/Proyecto-2-ImageRecovery-RentACar/Image Recovery/imgsPrueba/1.png");
    ImageOperations op(image);
    imshow("original", image);
    Genetics gen1(10,op.getTotalRectanglePixels(),op.getColors(),op.getPercentages());
    vector<Individual> allFitest= gen1.geneticAlgorithm();
    for (Vec3b genes : allFitest[1].getGenes()) {
        for (int r = op.getPoints()[1]; r <= op.getPoints()[3]; r++) {
            for (int c = op.getPoints()[0]; c <= op.getPoints()[2]; c++) {
                image.at<Vec3b>(Point(c,r)) = genes;
            }
        }
    }
    namedWindow("individual", WINDOW_FREERATIO);
    imshow("individual", image);
    waitKey();*/

    /*
    Population pop(op.getTotalRectanglePixels(), op.getColors());
    pop.calculateFitness(op.getPercentages());
    Individual* ind;
    Individual* ind3;
    ind = pop.getFittest();
    cout << ind->getFitness()<<endl;
    ind3 = pop.getSecondFittest();
    cout << ind3->getFitness()<<endl;


    Individual ind2(op.getTotalRectanglePixels(),op.getColors());
    ind2.calculateIndFitness(op.getPercentages());
    cout << ind2.getFitness() << endl;*/


    /*App* application = new App("/home/juanda/CLionProjects/Proyecto-2-ImageRecovery-RentACar/Image Recovery/imgsPrueba/2.png");
    int key;
    while(application->isRunning()){
        key = waitKey();
        application->listen(key);
    }
    delete(application);*/
/*
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
    }*/

    //Genetics genetics(15, op.getPoints());
    return 0;
}