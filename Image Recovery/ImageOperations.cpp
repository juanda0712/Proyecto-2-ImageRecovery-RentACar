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

void ImageOperations::rectanglePoints() {
    for (int row = 0; row < this->image.rows; row++) {
        for (int col = 0; col < this->image.cols; col++) {
            Vec3b color = this->image.at<Vec3b>(Point(col,row));
            if (color[0] == 255 & color[1] == 255 & color[2] == 255 ){
                this->points.insert(points.cend(),col);
                this->points.insert(points.cend(),row);
                break;
            }
        }
    }
    for (int row =  this->image.rows-1; row  > 0 ; row--) {
        for (int col = this->image.cols-1; col  > 0 ; col--) {
            Vec3b color = this->image.at<Vec3b>(Point(col,row));
            if (color[0] == 255 & color[1] == 255 & color[2] == 255 ){
                this->points.insert(points.cend(),col);
                this->points.insert(points.cend(),row);
                break;
            }
        }
    }
}

vector<int> ImageOperations::getPoints(){
    return  this->points;
}

