//
// Created by eduardo on 25/10/21.
//

#ifndef IMAGE_RECOVERY_POPULATION_H
#define IMAGE_RECOVERY_POPULATION_H

#include "Individual.h"
#include "iostream"

/**
 * @brief  Encaargado de almacenar a los individuos y aplicarles la Funcion de fitness
 *@file Population.h
 * @date 4/11/21
 * @author JuanRM EduardoBM
 */
class Population {
private:
    int num; //numero de poblacion
    int individualsQuantity = 10;
    Individual* individuals[10]; //cantidad de individuos
    int genesQuantity;
    vector<Vec3b> colorsList;


public:
    Population(int genesQuantity, vector<Vec3b> colorsList);
    /**
     * @brief Calcula el fitness de todos los individuos de la poblacion
     * @param percentages
     */
    void calculateFitness(vector<double> percentages);
    /**
     * @brief Agrega un nuevo individuo al vector de genes
     * @param crossoverIndividual
     */
    void addCrossoverIndividual(Individual* crossoverIndividual);

    //GETTERS
    Individual* getFittest();
    Individual* getSecondFittest();
};


#endif //IMAGE_RECOVERY_POPULATION_H
