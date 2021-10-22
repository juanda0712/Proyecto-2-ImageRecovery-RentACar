//
// Created by eduardo on 19/10/21.
//

#include "ImageLoader.h"

void ImageLoader::loadImage(QString filepath, QMainWindow *parent) {
    QPixmap img;
    img.load(filepath);
    QLabel label1(parent);
    label1.setPixmap(img);
    label1.setGeometry(parent->width()/2 - label1.width()/2, 50, 264,191);
    parent->createPopupMenu();
}