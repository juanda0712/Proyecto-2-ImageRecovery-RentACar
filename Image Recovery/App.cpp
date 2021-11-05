#include "App.h"

App::App(string fileName) {
    this->index = 0;
    this->running = true;
    this->img = imread(fileName);
    initWindow();
    initPtrs();
}

App::~App() {
    delete this->genetic_engine;
    delete this->ops;
}

void App::initWindow() {
    namedWindow("My Image Recovery App", WINDOW_FREERATIO);
    imshow("My Image Recovery App", this->img);
}

void App::initPtrs() {
    this->ops = new ImageOperations(this->img);
    this->genetic_engine = new Genetics(20, ops->getTotalRectanglePixels(),ops->getColors(),ops->getPercentages());
}

bool App::isRunning() const {
    return this->running;
}

void App::begin() {
    this->genFittests = this->genetic_engine->geneticAlgorithm();
    //this->next();
}

void App::kill() {
    destroyAllWindows();
    this->running = false;
}

void App::next() {
    Mat individual(ops->getPoints()[3]-ops->getPoints()[1], ops->getPoints()[2] - ops->getPoints()[0], CV_8UC3, Scalar(0,0,0));
    for (Vec3b genes : this->genFittests[index].getGenes()) {
        for (int r = ops->getPoints()[1]; r <= ops->getPoints()[3]; r++) {
            for (int c = ops->getPoints()[0]; c <= ops->getPoints()[2]; c++) {
                individual.at<Vec3b>(Point(c,r)) = genes;
            }
        }
    }
    imshow("My Image Recovery App", individual);
}

void App::listen(int key) {
    if (key == 27) {
        this->kill();
    }
    else if (key == 13) {
        this->begin();
    }
    else if (key == 'd') {
        this->index++;
        this->next();
        std::cout << "Next" << std::endl;
    }
}