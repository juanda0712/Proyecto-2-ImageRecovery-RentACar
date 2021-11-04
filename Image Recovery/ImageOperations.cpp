#include "ImageOperations.h"

ImageOperations::ImageOperations(Mat myImage) {
    this->image = myImage;
    this->totalImagePixels = myImage.rows * myImage.cols;
    this->rectanglePoints(myImage);
    this->totalRectanglePixels = (this->points[2]-this->points[0])*(this->points[3]-this->points[1]);
    //guada los colores de la img
    this->savePixels(myImage);

    //llena de ceros el vector con el mismo tamano del vector colorLIst
    for(int i = 0;  i < this->colorsList.size(); i++){
        this->quantityOfEachPixel.insert(quantityOfEachPixel.cend(),0);
    }
    this->quantities(myImage);
    this->pixelsPercentage();
}

ImageOperations::~ImageOperations() {

}

void ImageOperations::savePixels(Mat myImage) {
    for (int row = 0; row < myImage.rows; row++) {
        for (int col = 0; col < myImage.cols; col++) {
            Vec3b color = myImage.at<Vec3b>(Point(col,row));
            if(!(color[0]==255 & color[1]==255 & color[2]==255)){
                if (find(this->colorsList.begin(), this->colorsList.end(), color) == this->colorsList.end()) {
                    this->colorsList.push_back(color);
                }
            }
        }
    }
}

void ImageOperations::rectanglePoints(Mat myImage) {
    bool  flag =false;
    for (int row = 0; row < myImage.rows  & flag== false; row++) {
        for (int col = 0; col < myImage.cols; col++) {
            Vec3b pixel = myImage.at<Vec3b>(Point(col,row));
            if (pixel[0] == 255 & pixel[1] == 255 & pixel[2] == 255 ){
                this->points.insert(points.cend(),col);
                this->points.insert(points.cend(),row);
                flag = true;
                break;
            }
        }
    }
    flag = false;
    for (int row =  myImage.rows-1; row  > 0 & flag== false; row--) {
        for (int col = myImage.cols-1; col  > 0 ; col--) {
            Vec3b pixel = myImage.at<Vec3b>(Point(col,row));
            if (pixel[0] == 255 & pixel[1] == 255 & pixel[2] == 255 ){
                this->points.insert(points.cend(),col);
                this->points.insert(points.cend(),row);
                flag = true;
                break;
            }
        }
    }
}

void ImageOperations::quantities(Mat myImage){

    for (int row = 0; row < myImage.rows; row++) {
        for (int col = 0; col < myImage.cols; col++) {
            Vec3b pixel = myImage.at<Vec3b>(Point(col,row));
            for(int i = 0; i < this->colorsList.size(); i++){
                Vec3b color = this->colorsList[i];
                if (pixel[0] == color[0] & pixel[1] == color[1]  & pixel[2] == color[2]  ){
                    this->quantityOfEachPixel[i] += 1;
                    break;
                }
            }
        }
    }
}

void ImageOperations::pixelsPercentage(){
    double percentage;
    for (int i = 0; i < this->quantityOfEachPixel.size() ; i++) {
        percentage = ((double)this->quantityOfEachPixel[i]/((double)this->totalImagePixels-(double)this->totalRectanglePixels))*100;
        this->percentages.insert(percentages.cend(),percentage);
    }
}

vector<int> ImageOperations::getPoints(){
    return  this->points;
}
int ImageOperations::getTotalImagePixels(){
    return this->totalImagePixels;
}
int ImageOperations::getTotalRectanglePixels(){
    return this->totalRectanglePixels;
}

vector<int> ImageOperations::getQuantityOfEachPixel() {
    return this->quantityOfEachPixel;
}
vector<double> ImageOperations::getPercentages() {
    return this->percentages;
}
vector <Vec3b> ImageOperations::getColors() {
    return this->colorsList;
}

