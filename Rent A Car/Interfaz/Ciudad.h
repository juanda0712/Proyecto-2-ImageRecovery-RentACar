//
// Created by deyla on 5/11/2021.
//

#ifndef RENT_A_CAR_CIUDAD_H
#define RENT_A_CAR_CIUDAD_H
#include <SFML/Graphics.hpp>
#include "Calle.h"

/**
 * @file Ciudad.h
 * @date 25/10/2021
 * @author Deylan Sandoval
 */
class Ciudad {
public:
    sf::CircleShape circulo = sf::CircleShape(15.f);
    bool usado= false;
    int name;
    int numero = 0;
    sf::Color color = sf::Color::Magenta;
    float x = 350;
    float y = 350;
    Calle calles[21];
    std::string nombre;
    sf::Text text;

    /**
     * @brief cambia la coordenada x
     * @param x2
     */
    void setx(float x2);

    /***
     * @brief cambia la coordenada y
     * @param y2
     */
    void sety(float y2);

    /**
     * @brief cambias el color y la posicion de la ciudad
     */
    void dibujar();

    /**
     * @brief cambia el valor de numero de la ciudad
     * @param name2
     */
    void setname(int name2);
    /**
     * retorna el valor de numero de la ciudad
     * @return name
     */
    int getname();
    /**
     * @brief revisa si la ciudad nueva ya esta conectada
     * @param ciudad2
     * @param numeroconexiones
     * @return bool
     */
    bool revisarcalles(int ciudad2,int numeroconexiones);
    /**
     * @brief cambia de color la ciudad
     */
    void pintaciudad();
    /**
     * @brief retorna la coordenada x
     * @return x
     */
    int getx();

    /**
     * @brief retorna la coordenada y
     * @return y
     */
    int gety();
    /**
     * @brief agrega la calle nueva que esta conectada
     * @param calle2
     */
    void agregarcalle(Calle calle2);
    /**
     * configura el nombre de la ciudad
     */
    void setText();

};


#endif //RENT_A_CAR_CIUDAD_H
