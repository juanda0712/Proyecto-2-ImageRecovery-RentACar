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
            if (find(this->colorsList.begin(), this->colorsList.end(), color) == this->colorsList.end()) {
                this->colorsList.push_back(color);
            }
            i++;
        }
    }
}

vector <Vec3b> ImageOperations::getColors() {
    return this->colorsList;
}