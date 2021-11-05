//
// Created by deyla on 5/11/2021.
//

#include "Ciudad.h"
void Ciudad::setx(float x2) {
    this->x = x2;

}

void Ciudad::sety(float y2) {
    this->y = y2;

}

int Ciudad::getx() {
    return x;
}
int Ciudad::gety() {
    return y;
}

void Ciudad::dibujar() {
    circulo.setPosition(x-15,y-15);
    circulo.setFillColor(color);


}

void Ciudad::setname(int name2) {
    this->name = name2;

}

int Ciudad::getname() {
    return name;
}

bool Ciudad::revisarcalles(int ciudadnueva,int numeroconexiones) {
    bool respuesta = true;


    for (int n = 0; n<=numeroconexiones; n++) {

        if(calles[n].usado){
            //std::cout<<calles[0].conectado[0]<<"**";
            if (calles[n].conectado[0] == ciudadnueva)
                respuesta = false;
            if(calles[n].conectado[1] == ciudadnueva)
                respuesta = false;
        }



    }
    return respuesta;
}

void Ciudad::agregarcalle(Calle calle2) {
    this->calles[numero] = calle2;
    numero = numero + 1;

}

void Ciudad::setText() {
    text.setString(nombre);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);
    text.setPosition(x-10,y-15);

}

void Ciudad::pintaciudad() {
    if (color == sf::Color::Magenta){
        color = sf::Color::Blue;
        circulo.setFillColor(color);

    }
    else{
        color = sf::Color::Magenta;
        circulo.setFillColor(color);

    }

}