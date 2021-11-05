#include "App.h"

App::App(vector<Individual> allFitest, Mat img, ImageOperations ops) {
    this->ops = &ops;
    this->running = true;
    this->allFitest = allFitest;
    this->img = img;
    initWindow();
}

App::~App() {
    delete this->ops;
}

void App::initWindow() { //imagen inicial
    namedWindow("My Image Recovery App", WINDOW_FREERATIO);
    imshow("My Image Recovery App", this->img);
}

bool App::isRunning() const {
    return this->running;
}

void App::kill() {
    destroyAllWindows();
    this->running = false;
}

void App::next() {

    int fittestColor=0;
    for (Vec3b genes : allFitest[1].getGenes()) {
        for (int r = ops->getPoints()[1]; r <= ops->getPoints()[3]; r++) {
            for (int c = ops->getPoints()[0]; c <= ops->getPoints()[2]; c++) {
                this->img.at<Vec3b>(Point(c,r)) = genes;
            }
        }
    }
    imshow("My Image Recovery App", this->img);
}

void App::listen(int key) {
    if (key == 27) {
        this->kill();
    }
    else if (key == 13) {
        std::cout << "Antes de next" << std::endl;
        this->next();
        std::cout << "Despues de next" << std::endl;
    }
}