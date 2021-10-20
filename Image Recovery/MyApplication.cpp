//
// Created by eduardo on 19/10/21.
//

#include "MyApplication.h"

MyApplication::MyApplication() {
    this->window = new QMainWindow(nullptr);

    QPushButton button("Show image", this->window);
    QFont f("Times", -1, -1, true);
    button.setGeometry(200, 300, 90,50);
    button.setFont(f);

    QObject::connect(&button, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

    window->resize(500,500);
    window->show();
}

MyApplication::~MyApplication() {
    delete this->window;
}