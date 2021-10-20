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

class MyApplication {
public:
    QMainWindow *window;
    MyApplication();
    ~MyApplication();
};


#endif //IMAGE_RECOVERY_MYAPPLICATION_H
