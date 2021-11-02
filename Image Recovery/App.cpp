//
// Created by eduardo on 19/10/21.
//

#include "App.h"

App::App(string imageName) {
    this->running = true;
    img = imread("/home/eduardo/Escritorio/Proyecto-2-ImageRecovery-RentACar/Image Recovery/"+imageName+".png");
    this->ops = new ImageOperations(img);
    initWindow();
}

App::~App() {
    delete this->engine;
    delete this->ops;
}

void App::initWindow() {
    namedWindow("My Image Recovery App", WINDOW_AUTOSIZE);
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
        imshow("My Image Recovery App", this->img);
        std::cout << "Next" << std::endl;
    }
    else if (key == 'a') {
        std::cout << "Previous" << std::endl;
    }
}