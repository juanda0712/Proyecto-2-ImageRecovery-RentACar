//
// Created by eduardo on 19/10/21.
//

#ifndef IMAGE_RECOVERY_MYAPPLICATION_H
#define IMAGE_RECOVERY_MYAPPLICATION_H

#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include <QInputDialog>
#include <QPushButton>
#include "image_loader/ImageLoader.h"

class MyApplication:public QMainWindow {
private:
    QPushButton* buttons;
    QLabel* title;
    void initText();
    void initButtons();
public:
    QMainWindow* window;
    MyApplication();
    ~MyApplication();
public slots:
    void printOnPressed();
};


#endif //IMAGE_RECOVERY_MYAPPLICATION_H
