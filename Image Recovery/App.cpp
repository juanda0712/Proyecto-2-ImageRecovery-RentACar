//
// Created by eduardo on 19/10/21.
//

#include "App.h"

App::App() {
    this->running = true;
    img = imread("/home/eduardo/Escritorio/Proyecto-2-ImageRecovery-RentACar/Image Recovery/images/patron.png");
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
    this->genetic_engine = new Genetics(20, ops->getPoints());
}

bool App::isRunning() {
    return this->running;
}

void App::kill() {
    destroyAllWindows();
    this->running = false;
}

void App::listen(int key) {
    if (key == 27) {
        this->kill();
    }
    else if (key == 'd') {
        std::cout << "Next" << std::endl;
    }
    else if (key == 'a') {
        std::cout << "Previous" << std::endl;
    }
}