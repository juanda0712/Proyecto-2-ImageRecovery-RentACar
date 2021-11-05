#ifndef IMAGE_RECOVERY_IMAGEOPERATIONS_H
#define IMAGE_RECOVERY_IMAGEOPERATIONS_H

#include "opencv4/opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <vector>

using namespace cv;
using namespace std;

/**
 * @brief Realiza todas las operaciones a la imagen representada como una matriz a la cual se le aplican operaciones matriciales para sacar su datos
 *@file ImageOperations.h
 * @date 4/11/21
 * @author JuanRm EduardoBM
 */
class ImageOperations {
private:
    Mat image;
    vector<Vec3b> colorsList;
    vector<int> points;

    vector<int>  quantityOfEachPixel; // basado en colorsList , la primera posicion de colorsList esta relacionada con la primera posicion de este vector
    vector<double> percentages;  //porcentajes de cada color basado en la posicion de colorList osea la primera posicion de colorsList esta relacionada con la primera posicion de este vector

    int totalImagePixels;
    int totalRectanglePixels;

public:
    ImageOperations(Mat myImage);
    ~ImageOperations();
    /**
     * @brief Saca los colores de una imagen descartando el blanco
     * @param myImage
     */
    void savePixels(Mat myImage);
    /**
     * @brief Saca las coordenadas del rectangulo faltante
     * @param myImage
     */
    void rectanglePoints(Mat myImage);
    /**
     * @brief averigua la cantidad que hay de cada pixel (usa el vector quantityOfEachPixel para guardar los datos
     * @param myImage
     */
    void quantities(Mat myImage);
    /**
     * @brief Saca los porcentajes que hay de cada pixel en la imagen completa
     */
    void pixelsPercentage();

    //GETTERS
    vector<Vec3b> getColors();
    vector<int> getPoints();
    vector<int> getQuantityOfEachPixel();
    vector<double> getPercentages();
    int getTotalImagePixels();
    int getTotalRectanglePixels();
};

#endif //IMAGE_RECOVERY_IMAGEOPERATIONS_H
