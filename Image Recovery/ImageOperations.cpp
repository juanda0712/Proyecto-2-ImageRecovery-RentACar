#include "ImageOperations.h"

ImageOperations::ImageOperations(Mat myImage) {
    this->image = myImage;
    this->totalImagePixels = myImage.rows * myImage.cols;
    this->rectanglePoints(myImage);
    this->totalRectanglePixels = (this->points[2]-this->points[0])*(this->points[3]-this->points[1]);
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

void ImageOperations::rectanglePoints(Mat myImage) {
    for (int row = 0; row < myImage.rows; row++) {
        for (int col = 0; col < myImage.cols; col++) {
            Vec3b color = myImage.at<Vec3b>(Point(col,row));
            if (color[0] == 255 & color[1] == 255 & color[2] == 255 ){
                this->points.insert(points.cend(),col);
                this->points.insert(points.cend(),row);
                break;
            }
        }
    }
    for (int row =  myImage.rows-1; row  > 0 ; row--) {
        for (int col = myImage.cols-1; col  > 0 ; col--) {
            Vec3b color = myImage.at<Vec3b>(Point(col,row));
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

