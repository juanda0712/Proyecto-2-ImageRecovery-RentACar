//
// Created by deyla on 5/11/2021.
//
#include <iostream>
#include "Calle.h"
void Calle::creareactangulo(float largo2, float angulo2,float x2,float y2) {

    largo = largo2;
    angulo = angulo2;
    x= x2;
    y = y2;
    rectangulo =  sf::RectangleShape(sf::Vector2f(largo, 2));

    rectangulo.setPosition(x2+5,y2+5);
    rectangulo.setFillColor(color);
    rectangulo.rotate(angulo2);


}

void Calle::setconectados(int punto1,int punto2) {
    conectado[0] = punto1;
    conectado[1] = punto2;

}

void Calle::cambiacolor(sf::Color color2) {
    if (color == sf::Color::Red){
        color = sf::Color::Blue;
        rectangulo.setFillColor(color);

    }
    else{
        color = sf::Color::Red;
        rectangulo.setFillColor(color);

    }

}




void Calle::setText(std::string valor2,int posx,int posy) {
    text.setString(valor2);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);
    text.setPosition(posx,posy);


}