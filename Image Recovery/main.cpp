#include "App.h"
#include "genetic_algorithm/Genetics.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "ImageOperations.h"

using namespace std;
using namespace cv;

int main() {
    string name;
    cin >> name;
    App* application = new App(name);
    int key;
    while (application->isRunning()) {
        key = waitKey();
        application->listen(key);
    }
    delete application;
    return 0;
}