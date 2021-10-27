#include <QApplication>
#include "MyApplication.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "ImageOperations.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {

    ImageOperations op(image);
    op.savePixels();
    int i = 0;
    while (i < op.getColors().size()) {
        cout << op.getColors()[i] << endl;
        i++;
    }
    return 0;
}
