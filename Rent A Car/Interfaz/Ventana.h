//
// Created by deyla on 5/11/2021.
//

#ifndef RENT_A_CAR_VENTANA_H
#define RENT_A_CAR_VENTANA_H

#include "Ciudad.h"
#include "Calle.h"

#include <math.h>
#include <thread>
#include <thread>
/**
 * @file Ventana.h
 * @date 25/10/2021
 * @author Deylan Sandoval
 */
class Ventana {
public:
    int numerociudades = 11;
    int numeroconexiones = 11;
    Ciudad puntos[19];
    int cuantos = 0;
    int coordenadasx[19];
    int coordenadasy[19];
    bool hilo =false;
    bool back = false;
    sf::Font font;
    sf::Text text;
    int seleccion[2];
    Calle arista[70];





    /**
     * @brief abre la ventana del grafo
     */
    void inicio();

    /**
     *
     * @param punto1
     * @param punto2
     * @return
     */
    Calle conectarpuntos(Ciudad punto1, Ciudad punto2);

    /**
     * @brief cambia de color la calle
     * @param ciudad1
     * @param ciudad2
     * @param valor
     */
    void pintacalle(int ciudad1,int ciudad2,std::string valor);

    /**
     * @brief cambia de color la ciudad
     * @param ciudad1
     */
    void pintaciudad(int ciudad1);

    /**
     * @brief crea una ciudad
     * @param i
     * @param nombre2
     */
    void dibujaciudad(int i,std::string nombre2);

    /**
     * @brief crea una calle nueva entre las ciudades
     * @param i
     * @param n
     * @param valor2
     */
    void dibujarcalle(int i,int n,std::string valor2);

    /**
     * @brief Hilo para probar funcionalidad
     */
    void backtracking();

    /**
     * @brief abre la ventana con el menu inicial
     */
    void menu();

    /**
     * @brief inicia el hilo de los grafos e inicia la ventana del grafo
     */
    void comienza();

    void creaaristas();


};


#endif //RENT_A_CAR_VENTANA_H
