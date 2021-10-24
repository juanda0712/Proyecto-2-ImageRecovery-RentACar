#include <QApplication>
#include "MyApplication.h"
#include "genetic_algorithm/ImageCompleter.h"
#include "opencv4/opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char **argv) {
    /*QApplication a(argc, argv);
    MyApplication app;
    ImageCompleter genetics;
    printf("ULTIMO ID: %d\n", genetics.getConcreteIndividual(5).getId());
    return QApplication::exec();*/

    Mat image = imread("D:/My OpenCV Website/Eagle.jpg");
    return 0;

}
