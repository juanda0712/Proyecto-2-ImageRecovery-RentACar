#include <QApplication>
#include "MyApplication.h"
#include "genetic_algorithm/Genetics.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    Mat image = imread("/home/eduardo/Escritorio/Proyecto-2-ImageRecovery-RentACar/Image Recovery/images.png");
    imshow("xd", image);
    //cout << image.row(0) << endl;
    //cout << image.col(0) << endl;
    cout << image.rows << endl;
    cout << image.row(1) << endl;
    cout << image.row(0).col(0) << endl;
}
