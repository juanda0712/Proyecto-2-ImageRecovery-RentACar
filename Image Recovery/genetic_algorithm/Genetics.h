#ifndef IMAGE_RECOVERY_GENETICS_H
#define IMAGE_RECOVERY_GENETICS_H

#include "Individual.h"
#include "Population.h"

using namespace std;
/**
 * @brief Se encarga de aplicar los algoritmos geneticos a las generaciones de individuos
 *@file Genetic.h
 * @date 4/11/21
 * @author JuanRm EduardoBM
 */
class Genetics {
private:
    int numOfGenerations;
    Population* currentGen;
    Individual* fittest;
    Individual* secondFittest;
    vector<double> percentajesRectangle;
    int genesQuantity;
    vector<Vec3b> colorsList;
    vector<Individual> allFittest;

public:
    Genetics(int numOfGenerations, int genesQuantity, vector<Vec3b> colorsList,vector<double> percentages);
    ~Genetics();
    /**
     *@brief Crea las poblaciones iniciales y aplica algoritmos
     * @return vector<Individual>
     */
    vector<Individual> geneticAlgorithm();
    /**
     * @brief Selecciona el primer y segundo fitness de una poblacion
     */
    void selection();
    /**
     *@brief cruza los individuos con mayor fitness
     * @return vector<double>
     */
    vector<double> crossover();

};
#endif //IMAGE_RECOVERY_GENETICS_H
