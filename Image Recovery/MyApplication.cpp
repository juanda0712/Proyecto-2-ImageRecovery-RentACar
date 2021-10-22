//
// Created by eduardo on 19/10/21.
//

#include "MyApplication.h"

MyApplication::MyApplication() {
    this->window = new QMainWindow(nullptr);
    initText();
    initButtons();
    this->window->setWindowTitle("Image Recovery Application");
    window->resize(800,600);
    window->show();
}

MyApplication::~MyApplication() {
    delete this->window;
    delete this->title;
    delete this->buttons;
}

void MyApplication::initText() {
    QFont font("Times", 30, -1, true);
    this->title = new QLabel("Image Recovery App", this->window);
    this->title->setFixedSize(350,150);
    this->title->setFont(font);
    this->title->setGeometry(800/3, 5, 350,150);
}

void MyApplication::initButtons() {
    this->buttons = new QPushButton("PRESS", this->window);
    this->buttons->setGeometry(400,350,buttons->width(),buttons->height());
    QObject::connect(buttons, &QPushButton::clicked, this, &MyApplication::printOnPressed);
}

void MyApplication::printOnPressed() {
    ImageLoader::loadImage("/home/eduardo/Escritorio/Proyecto-2-ImageRecovery-RentACar/Image Recovery/images.png", this->window);
}