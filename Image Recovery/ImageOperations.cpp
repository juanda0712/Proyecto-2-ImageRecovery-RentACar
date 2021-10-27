//
// Created by juanda on 10/26/21.
//

#include "ImageOperations.h"

ImageOperations::ImageOperations(Mat myImage) {
    this->image = myImage;
}

ImageOperations::~ImageOperations() {

}

void ImageOperations::savePixels() {
    int i = 0;
    for (int y = 0; y < this->image.rows; y++) {
        for (int x = 0; x < this->image.cols; x++) {
            Vec3b color = this->image.at<Vec3b>(Point(x,y));
            this->colorsList.insert(this->colorsList.cend(), color);
            i++;
        }
    }
    discardRedundantPixels();
}

void ImageOperations::discardRedundantPixels() {
    vector<Vec3b> backup;
    int i = 0;
    for (Vec3b color : this->colorsList) {
        if (this->colorsList[i] != color) {
            backup.insert(backup.cend(), color);
            i++;
        }
    }
    this->colorsList = backup;
}

vector <Vec3b> ImageOperations::getColors() {
    return this->colorsList;
}