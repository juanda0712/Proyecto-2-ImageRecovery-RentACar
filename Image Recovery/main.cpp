#include <QApplication>
#include "MyApplication.h"
#include "genetic_algorithm/Genetics.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "ImageOperations.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    Mat image = imread("/home/eduardo/Escritorio/Proyecto-2-ImageRecovery-RentACar/Image Recovery/images.png");

    ImageOperations op(image);
    op.savePixels();
    int i = 0;
    while (i < op.getColors().size()) {
        cout << op.getColors()[i] << endl;
        i++;
    }
    return 0;
}