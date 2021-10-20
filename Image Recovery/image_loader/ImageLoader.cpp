//
// Created by eduardo on 19/10/21.
//

#include "ImageLoader.h"

void ImageLoader::loadImage(QString filepath, QMainWindow *parent) {
    QPixmap img;
    img.load(filepath);
    QLabel *label1 = new QLabel(parent);
    label1->setPixmap(img);
    label1->setGeometry(100, 50, 264,191);
    label1->show();
}