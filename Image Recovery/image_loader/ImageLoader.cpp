//
// Created by eduardo on 19/10/21.
//

#include "ImageLoader.h"

void ImageLoader::loadImage(QString filepath, QMainWindow *parent) {
    QPixmap img;
    QLabel* label = new QLabel(parent);
    img.load(filepath);
    label->setPixmap(img);
    label->setGeometry(200, 100, 264,191);
    label->show();
}