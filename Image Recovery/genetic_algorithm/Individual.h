#ifndef IMAGE_RECOVERY_INDIVIDUAL_H
#define IMAGE_RECOVERY_INDIVIDUAL_H

#include <vector>
#include "opencv4/opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/**
 * @brief Son todas las posibles soluciones del algoritmo, tiene un vector de genes que representa los pixeles de la imagen faltante
 *@file Individual.h
 * @date 4/11/21
 * @author JuanRm EduardoBM
 */
class Individual {
private:
    int genesQuantity;
    int fitness;
    vector<Vec3b> genes;
    vector<Vec3b> colorsList;
    vector<double> IndividualPercentages;
    vector<int>  quantityOfEachGen;

public:
    Individual(int genesQuantity, vector<Vec3b> colorsList);
    Individual(int genesQuantity, vector<Vec3b> colorsList, vector<double> crossoverIndPercentajes);
    /**
     * @brief Calcula el fitness
     * @param percentages
     */
    void calculateIndFitness(vector<double> percentages);
    /**
     *  @brief saca los porcentajes de cada individuo
     */
    void  pixelsPercentage();
    /**
     * @brief Saca las cantidades de cada color de un individuo
     */
    void quantities();

   //GETTERS
    vector<double> getRectanglePercentages();
    vector<int> getQuantityOfEachGen();
    vector<Vec3b> getGenes();
    vector<Vec3b> getColors();
    int getFitness();
    int getGenesQuantity();
};
#endif //IMAGE_RECOVERY_INDIVIDUAL_H
