#include "App.h"
/*
App::App(string fileName) {
    this->running = true;
    img = imread(fileName);
    initWindow();
    initPtrs();
}

App::~App() {
    delete this->genetic_engine;
    delete this->ops;
}

void App::initWindow() {
    namedWindow("My Image Recovery App");
    putText(this->img, "My App", Point(250,10), 1,50, Scalar(0,0,0), 5);
    imshow("My Image Recovery App", this->img);
}

void App::initPtrs() {
    this->ops = new ImageOperations(this->img);
    this->genetic_engine = new Genetics(20, ops->getTotalRectanglePixels(),ops->getColors(),ops->getPercentages());
}

bool App::isRunning() {
    return this->running;
}

void App::begin() {
    this->genetic_engine->geneticAlgorithm(&this->img);
}

void App::kill() {
    destroyAllWindows();
    this->running = false;
}

void App::listen(int key) {
    if (key == 27) {
        this->kill();
    }
    else if (key == 13) {
        this->begin();
    }
    else if (key == 'd') {
        genetic_engine->updateFlag(true);
        std::cout << "Next" << std::endl;
    }
    else if (key == 'a') {
        std::cout << "Previous" << std::endl;
    }
}
*/