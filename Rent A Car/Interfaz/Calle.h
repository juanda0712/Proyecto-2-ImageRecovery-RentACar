//
// Created by deyla on 5/11/2021.
//

#ifndef RENT_A_CAR_CALLE_H
#define RENT_A_CAR_CALLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
/**
 * @file Calle.h
 * @date 25/10/2021
 * @author Deylan Sandoval
 */
class Calle {
public:
    sf::RectangleShape rectangulo;
    float largo = 0;
    float angulo = 0;
    bool usado = false;
    float x = 0;
    float y = 0;
    int conectado[2];
    int disx = 0;
    int disy= 0;
    sf::Text text;
    sf::Color color = sf::Color::Red;
    bool dibuja = false;

    /**
     * @brief crea el rectangulo para simular la calle
     * @param largo2
     * @param angulo2
     * @param x2
     * @param y2
     */
    void creareactangulo(float largo2, float angulo2,float x2,float y2);
    /**
     * @brief cambia las ciudades a la que esta conectada
     * @param punto1
     * @param punto2
     */
    void setconectados(int punto1,int punto2);

    /**
     * @brief cambia el color de la calle
     * @param color2
     */
    void cambiacolor(sf::Color color2);

    /**
     * @brief cambia la posicion y el valor de la calle
     * @param valor
     * @param posx
     * @param posy
     */
    void setText(std::string valor,int posx,int posy);

};


#endif //RENT_A_CAR_CALLE_H
