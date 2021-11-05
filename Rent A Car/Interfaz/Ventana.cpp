//
// Created by deyla on 5/11/2021.
//

#include "Ventana.h"
#include "Ventana.h"
#include "Ciudad.h"
#include "Calle.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

bool ciudades = true;
sf::RenderWindow window(sf::VideoMode(900,700),"Hola");

void Ventana::inicio() {
    //arista[0] = conectarpuntos(puntos[0],puntos[1]);;
    /*arista[1] = conectarpuntos(puntos[0],puntos[2]);;
    arista[2] = conectarpuntos(puntos[0],puntos[3]);;
    arista[3] = conectarpuntos(puntos[0],puntos[4]);;
    arista[4] = conectarpuntos(puntos[0],puntos[5]);;
    arista[5] = conectarpuntos(puntos[0],puntos[6]);;
    arista[6] = conectarpuntos(puntos[0],puntos[7]);;
    arista[7] = conectarpuntos(puntos[0],puntos[8]);;
    arista[8] = conectarpuntos(puntos[0],puntos[9]);;
    arista[9] = conectarpuntos(puntos[0],puntos[10]);;
    arista[10] = conectarpuntos(puntos[0],puntos[11]);;

    arista[11] = conectarpuntos(puntos[1],puntos[2]);;
    arista[12] = conectarpuntos(puntos[1],puntos[3]);;
    arista[13] = conectarpuntos(puntos[1],puntos[4]);;
    arista[14] = conectarpuntos(puntos[1],puntos[5]);;
    arista[15] = conectarpuntos(puntos[1],puntos[6]);;
    arista[16] = conectarpuntos(puntos[1],puntos[7]);;
    arista[17] = conectarpuntos(puntos[1],puntos[8]);;
    arista[18] = conectarpuntos(puntos[1],puntos[9]);;
    arista[19] = conectarpuntos(puntos[1],puntos[10]);;
    arista[20] = conectarpuntos(puntos[1],puntos[11]);;

    arista[21] = conectarpuntos(puntos[2],puntos[3]);;
    arista[22] = conectarpuntos(puntos[2],puntos[4]);;
    arista[23] = conectarpuntos(puntos[2],puntos[5]);;
    arista[24] = conectarpuntos(puntos[2],puntos[6]);;
    arista[25] = conectarpuntos(puntos[2],puntos[7]);;
    arista[26] = conectarpuntos(puntos[2],puntos[8]);;
    arista[27] = conectarpuntos(puntos[2],puntos[9]);;
    arista[28] = conectarpuntos(puntos[2],puntos[10]);;
    arista[29] = conectarpuntos(puntos[2],puntos[11]);;

    arista[30] = conectarpuntos(puntos[3],puntos[4]);;
    arista[31] = conectarpuntos(puntos[3],puntos[5]);;
    arista[32] = conectarpuntos(puntos[3],puntos[6]);;
    arista[33] = conectarpuntos(puntos[3],puntos[7]);;
    arista[34] = conectarpuntos(puntos[3],puntos[8]);;
    arista[35] = conectarpuntos(puntos[3],puntos[9]);;
    arista[36] = conectarpuntos(puntos[3],puntos[10]);;
    arista[37] = conectarpuntos(puntos[3],puntos[11]);;

    arista[38] = conectarpuntos(puntos[4],puntos[5]);;
    arista[39] = conectarpuntos(puntos[4],puntos[6]);;
    arista[40] = conectarpuntos(puntos[4],puntos[7]);;
    arista[41] = conectarpuntos(puntos[4],puntos[8]);;
    arista[42] = conectarpuntos(puntos[4],puntos[9]);;
    arista[43] = conectarpuntos(puntos[4],puntos[10]);;
    arista[44] = conectarpuntos(puntos[4],puntos[11]);;

    arista[45] = conectarpuntos(puntos[5],puntos[6]);;
    arista[46] = conectarpuntos(puntos[5],puntos[7]);;
    arista[47] = conectarpuntos(puntos[5],puntos[8]);;
    arista[48] = conectarpuntos(puntos[5],puntos[9]);;
    arista[49] = conectarpuntos(puntos[5],puntos[10]);;
    arista[50] = conectarpuntos(puntos[5],puntos[11]);;

    arista[51] = conectarpuntos(puntos[6],puntos[7]);;
    arista[52] = conectarpuntos(puntos[6],puntos[8]);;
    arista[53] = conectarpuntos(puntos[6],puntos[9]);;
    arista[54] = conectarpuntos(puntos[6],puntos[10]);;
    arista[55] = conectarpuntos(puntos[6],puntos[11]);;

    arista[56] = conectarpuntos(puntos[7],puntos[8]);;
    arista[57] = conectarpuntos(puntos[7],puntos[9]);;
    arista[58] = conectarpuntos(puntos[7],puntos[10]);;
    arista[59] = conectarpuntos(puntos[7],puntos[11]);;

    arista[60] = conectarpuntos(puntos[8],puntos[9]);;
    arista[61] = conectarpuntos(puntos[8],puntos[10]);;
    arista[62] = conectarpuntos(puntos[8],puntos[11]);;

    arista[63] = conectarpuntos(puntos[9],puntos[10]);;
    arista[64] = conectarpuntos(puntos[9],puntos[11]);;

    arista[65] = conectarpuntos(puntos[10],puntos[11]);;*/

    //arista[0] = conectarpuntos(puntos[0],puntos[1]);;

    font.loadFromFile("../Minecrafter.ttf");




    int cuenta3 = 0;
    int cuenta = 1;
    int cuenta2 = 0;
    int contador = 0;
    bool seleccionando = true;
    while(window.isOpen()){

        int mousex =sf::Mouse::getPosition(window).x;
        int mousey = sf::Mouse::getPosition(window).y;



        sf::Event event{};
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();

            }

            if (seleccionando){
                if (contador == 2){
                    std::cout<<seleccion[0]<<seleccion[1];
                    back = true;
                    seleccionando = false;

                }
                if (300-15<mousex && mousex<300-15+30 && mousey<50-15+30 && mousey>50-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[0].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 0;
                        contador = contador +1;


                    }

                if (600-15<mousex && mousex<600-15+30 && mousey<50-15+30 && mousey>50-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[1].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 1;
                        contador = contador +1;

                    }
                if (150-15<mousex && mousex<150-15+30 && mousey<250-15+30 && mousey>250-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[2].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 2;
                        contador = contador +1;

                    }
                if (150-15<mousex && mousex<150-15+30 && mousey<450-15+30 && mousey>450-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[3].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 3;
                        contador = contador +1;

                    }
                if (300-15<mousex && mousex<300-15+30 && mousey<650-15+30 && mousey>650-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[4].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 4;
                        contador = contador +1;

                    }
                if (600-15<mousex && mousex<600-15+30 && mousey<650-15+30 && mousey>650-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[5].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 5;
                        contador = contador +1;

                    }
                if (750-15<mousex && mousex<750-15+30 && mousey<250-15+30 && mousey>250-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[6].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 6;
                        contador = contador +1;

                    }
                if (750-15<mousex && mousex<750-15+30 && mousey<450-15+30 && mousey>450-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[7].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 7;
                        contador = contador +1;

                    }
                if (450-15<mousex && mousex<450-15+30 && mousey<150-15+30 && mousey>150-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[8].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 8;
                        contador = contador +1;

                    }
                if (460-15<mousex && mousex<460-15+30 && mousey<560-15+30 && mousey>560-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[9].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 9;
                        contador = contador +1;

                    }
                if (350-15<mousex && mousex<350-15+30 && mousey<350-15+30 && mousey>350-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[10].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 10;
                        contador = contador +1;

                    }
                if (570-15<mousex && mousex<570-15+30 && mousey<350-15+30 && mousey>350-15)
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        puntos[11].circulo.setFillColor(sf::Color::Blue);
                        seleccion[contador] = 11;
                        contador = contador +1;

                    }}

        }
        window.clear();

        /*if (ciudades){


            for (int i = 0; i<=numerociudades; i++) {

                dibujaciudad(i);
            Ciudad ciudad;
            ciudad.usado = true;
            ciudad.dibujar();

            ciudad.setx( coordenadasx[i]);
            ciudad.sety( coordenadasy[i]);
            ciudad.setname(i);


            ciudad.circulo.setPosition(ciudad.x-15,ciudad.y-15);



            puntos[i] = ciudad;




        }
            for (int n = 0; n<=numeroconexiones; n++) {
            if (!puntos[n].usado){

                break;
            }


            for (int i = 0; i<=numeroconexiones; i++) {
                int conecta = 3;

                if (!puntos[i].usado)
                    break;


                if (puntos[n].revisarcalles(puntos[i].getname(),numeroconexiones)){

                    if (puntos[n].usado) {

                        if(puntos[i].getx() != 350){

                            dibujarcalle(i,n);
                            Calle calle = conectarpuntos(puntos[n],puntos[i]);


                            puntos[i].agregarcalle(calle);
                            puntos[n].agregarcalle(calle);


                           }


                    }

                }




        }


        }
        ciudades = false;}*/


        /*puntos[0].circulo.setFillColor(sf::Color::Green );*/
        for (int i = 0; i<=63; i++) {
            if(arista[i].dibuja){

                window.draw(arista[i].rectangulo);
                arista[i].text.setFont(font);
                window.draw(arista[i].text);

            }

        }
        /*for (int i = 0; i<=numeroconexiones; i++) {
            if (puntos[i].usado){
                for (int n = 0; n<=numeroconexiones; n++) {

                    if (puntos[i].calles[n].usado){

                        window.draw(puntos[i].calles[n].rectangulo);
                        puntos[i].calles[n].text.setFont(font);
                        window.draw(puntos[i].calles[n].text);




                    }

                }

                }

            else
                break;
        }*/
        for (int i = 0; i<=numerociudades; i++) {
            if (puntos[i].usado){

                window.draw(puntos[i].circulo);

                puntos[i].text.setFont(font);
                window.draw(puntos[i].text);
            }

        }


        /*if (cuenta3 == 1000){

            //puntos[cuenta].calles[0].cambiacolor(sf::Color::Blue);
            if (cuenta < 13){
                pintacalle(12,cuenta);
                cuenta += 1;
            }

            //pintacalle(3,1);

            cuenta3 = 0;

        }
        cuenta3 += 1;*/






        //
        window.display();

    }


}

Calle Ventana::conectarpuntos(Ciudad punto1, Ciudad punto2) {

    int distanciay = punto1.y - punto2.y;
    int distanciax = punto1.x - punto2.x;
    if (distanciay < 0){
        distanciay *= -1;
    }
    if (distanciax < 0){
        distanciax *= -1;
    }
    float a = pow(distanciax,2);
    float b = pow(distanciay,2);
    float c = a+b;
    float largo = sqrt(c);


    float angulo =  (acos(distanciax/largo)) * (180/3.14 );
    //std::cout<<distanciax <<"**"<<largo<<"**"<< angulo<<"##";
    int lado = 0;
    if (punto1.x > punto2.x && punto1.y >= punto2.y)
        lado = -1*(180-angulo-angulo);
    if (punto1.x >= punto2.x && punto1.y <= punto2.y)
        lado = 180-angulo-angulo;

    if (punto1.y >= punto2.y){
        angulo = -1*angulo+ lado;

    }

    else{
        angulo = 1*angulo+lado;

    }
    Calle calle;
    calle.disx = distanciax;
    calle.disy = distanciay;
    calle.creareactangulo(largo,angulo,punto1.x,punto1.y);
    calle.setconectados(punto1.getname(),punto2.getname());
    calle.usado = true;




    //window.draw(calle.rectangulo);
    return calle;



}


void Ventana::pintacalle(int ciudad1, int ciudad2,std::string valor) {
    ciudad1 += 1;
    ciudad2 += 1;
    if ((ciudad1 == 1 && ciudad2 == 2) || (ciudad1 == 2 && ciudad2 == 1)){
        arista[0].cambiacolor(sf::Color::Blue);

    }//---
    if ((ciudad1 == 1 && ciudad2 == 3) || (ciudad1 == 3 && ciudad2 == 1)){
        arista[1].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 1 && ciudad2 == 4) || (ciudad1 == 4 && ciudad2 == 1)){
        arista[2].cambiacolor(sf::Color::Blue);
    }//---
    if ((ciudad1 == 1 && ciudad2 == 5) || (ciudad1 == 5 && ciudad2 == 1)){
        arista[3].cambiacolor(sf::Color::Blue);
    }//---
    if ((ciudad1 == 1 && ciudad2 == 6) || (ciudad1 == 6 && ciudad2 == 1)){
        arista[4].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 1 && ciudad2 == 7) || (ciudad1 == 7 && ciudad2 == 1)){
        arista[5].cambiacolor(sf::Color::Blue);
    }//---
    if ((ciudad1 == 1 && ciudad2 == 8) || (ciudad1 == 8 && ciudad2 == 1)){
        arista[6].cambiacolor(sf::Color::Blue);
    }//---
    if ((ciudad1 == 1 && ciudad2 == 9) || (ciudad1 == 9 && ciudad2 == 1)){
        arista[7].cambiacolor(sf::Color::Blue);
    }//---
    if ((ciudad1 == 1 && ciudad2 == 10) || (ciudad1 == 10 && ciudad2 == 1)){
        arista[8].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 1 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 1)){
        arista[9].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 1 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 1)){
        arista[10].cambiacolor(sf::Color::Blue);
    }

    if ((ciudad1 == 2 && ciudad2 == 3) || (ciudad1 == 3 && ciudad2 == 2)){
        arista[11].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 2 && ciudad2 == 4) || (ciudad1 == 4 && ciudad2 == 2)){
        arista[12].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 2 && ciudad2 == 5) || (ciudad1 == 5 && ciudad2 == 2)){
        arista[13].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 2 && ciudad2 == 6) || (ciudad1 == 6 && ciudad2 == 2)){
        arista[14].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 2 && ciudad2 == 7) || (ciudad1 == 7 && ciudad2 == 2)){
        arista[15].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 2 && ciudad2 == 8) || (ciudad1 == 8 && ciudad2 == 2)){
        arista[16].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 2 && ciudad2 == 9) || (ciudad1 == 9 && ciudad2 == 2)){
        arista[17].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 2 && ciudad2 == 10) || (ciudad1 == 10 && ciudad2 == 2)){
        arista[18].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 2 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 2)){
        arista[19].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 2 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 2)){
        arista[20].cambiacolor(sf::Color::Blue);
    }


    if ((ciudad1 == 3 && ciudad2 == 4) || (ciudad1 == 4 && ciudad2 == 3)){
        arista[21].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 3 && ciudad2 == 5) || (ciudad1 == 5 && ciudad2 == 3)){
        arista[22].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 3 && ciudad2 == 6) || (ciudad1 == 6 && ciudad2 == 3)){
        arista[23].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 3 && ciudad2 == 7) || (ciudad1 == 7 && ciudad2 == 3)){
        arista[24].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 3 && ciudad2 == 8) || (ciudad1 == 8 && ciudad2 == 3)){
        arista[25].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 3 && ciudad2 == 9) || (ciudad1 == 9 && ciudad2 == 3)){
        arista[26].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 3 && ciudad2 == 10) || (ciudad1 == 10 && ciudad2 == 3)){
        arista[27].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 3 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 3)){
        arista[28].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 3 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 3)){
        arista[29].cambiacolor(sf::Color::Blue);
    }


    if ((ciudad1 == 4 && ciudad2 == 5) || (ciudad1 == 5 && ciudad2 == 4)){
        arista[30].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 4 && ciudad2 == 6) || (ciudad1 == 6 && ciudad2 == 4)){
        arista[31].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 4 && ciudad2 == 7) || (ciudad1 == 7 && ciudad2 == 4)){
        arista[32].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 4 && ciudad2 == 8) || (ciudad1 == 8 && ciudad2 == 4)){
        arista[33].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 4 && ciudad2 == 9) || (ciudad1 == 9 && ciudad2 == 4)){
        arista[34].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 4 && ciudad2 == 10) || (ciudad1 == 10 && ciudad2 == 4)){
        arista[35].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 4 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 4)){
        arista[36].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 4 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 4)){
        arista[37].cambiacolor(sf::Color::Blue);
    }

    if ((ciudad1 == 5 && ciudad2 == 6) || (ciudad1 == 6 && ciudad2 == 5)){
        arista[38].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 5 && ciudad2 == 7) || (ciudad1 == 7 && ciudad2 == 5)){
        arista[39].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 5 && ciudad2 == 8) || (ciudad1 == 8 && ciudad2 == 5)){
        arista[40].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 5 && ciudad2 == 9) || (ciudad1 == 9 && ciudad2 == 5)){
        arista[41].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 5 && ciudad2 == 10) || (ciudad1 == 10 && ciudad2 == 5)){
        arista[42].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 5 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 5)){
        arista[43].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 5 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 5)){
        arista[44].cambiacolor(sf::Color::Blue);
    }

    if ((ciudad1 == 6 && ciudad2 == 7) || (ciudad1 == 7 && ciudad2 == 6)){
        arista[45].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 6 && ciudad2 == 8) || (ciudad1 == 8 && ciudad2 == 6)){
        arista[46].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 6 && ciudad2 == 9) || (ciudad1 == 9 && ciudad2 == 6)){
        arista[47].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 6 && ciudad2 == 10) || (ciudad1 == 10 && ciudad2 == 6)){
        arista[48].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 6 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 6)){
        arista[49].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 6 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 6)){
        arista[50].cambiacolor(sf::Color::Blue);
    }

    if ((ciudad1 == 7 && ciudad2 == 8) || (ciudad1 == 8 && ciudad2 == 7)){
        arista[51].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 7 && ciudad2 == 9) || (ciudad1 == 9 && ciudad2 == 7)){
        arista[52].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 7 && ciudad2 == 10) || (ciudad1 == 10 && ciudad2 == 7)){
        arista[53].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 7 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 7)){
        arista[54].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 7 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 7)){
        arista[55].cambiacolor(sf::Color::Blue);
    }

    if ((ciudad1 == 8 && ciudad2 == 9) || (ciudad1 == 9 && ciudad2 == 8)){
        arista[56].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 8 && ciudad2 == 10) || (ciudad1 == 10 && ciudad2 == 8)){
        arista[57].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 8 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 8)){
        arista[58].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 8 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 8)){
        arista[59].cambiacolor(sf::Color::Blue);
    }

    /*if ((ciudad1 == 9 && ciudad2 == 10) || (ciudad1 == 10 && ciudad2 == 9)){
        arista[60].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 9 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 9)){
        arista[61].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 9 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 9)){
        arista[62].cambiacolor(sf::Color::Blue);
    }

    if ((ciudad1 == 10 && ciudad2 == 11) || (ciudad1 == 11 && ciudad2 == 10)){
        arista[63].cambiacolor(sf::Color::Blue);
    }
    if ((ciudad1 == 10 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 10)){
        arista[64].cambiacolor(sf::Color::Blue);
    }

    if ((ciudad1 == 11 && ciudad2 == 12) || (ciudad1 == 12 && ciudad2 == 11)){
        arista[65].cambiacolor(sf::Color::Blue);
    }*/


}

void Ventana::dibujaciudad(int i,std::string nombre2) {
    Ciudad ciudad;
    ciudad.usado = true;
    ciudad.dibujar();
    ciudad.nombre = nombre2;


    ciudad.setx( coordenadasx[i]);
    ciudad.sety( coordenadasy[i]);
    ciudad.setText();
    ciudad.setname(i);


    ciudad.circulo.setPosition(ciudad.x-15,ciudad.y-15);



    puntos[i] = ciudad;

}

void Ventana::dibujarcalle(int i,int n,std::string valor2) {
    //Calle calle = conectarpuntos(puntos[i],puntos[n]);;
    if ((i+1 == 1 && n+1 == 2) || (i+1 == 2 && n+1 == 1)){
        arista[0].dibuja = true;
        arista[0].setText(valor2,450,50-10);

    }//-----
    if ((i+1 == 1 && n+1 == 3) || (i+1 == 3 && n+1 == 1)){

        arista[1].dibuja = true;
        arista[1].setText(valor2,225,150-10);

    }
    if ((i+1 == 1 && n+1 == 4) || (i+1 == 4 && n+1 == 1)){
        arista[2].dibuja = true;
        arista[2].setText(valor2,225,250-10);

    }
    if ((i+1 == 1 && n+1 == 5) || (i+1 == 5 && n+1 == 1)){
        arista[3].dibuja = true;
        arista[3].setText(valor2,300-5,350-10);

    }//-----
    if ((i+1 == 1 && n+1 == 6) || (i+1 == 6 && n+1 == 1)){
        arista[4].dibuja = true;
        arista[4].setText(valor2,450,350-30);

    }
    if ((i+1 == 1 && n+1 == 7) || (i+1 == 7 && n+1 == 1)){
        arista[5].dibuja = true;
        arista[5].setText(valor2,525,150-10);

    }
    if ((i+1 == 1 && n+1 == 8) || (i+1 == 8 && n+1 == 1)){
        arista[6].dibuja = true;
        arista[6].setText(valor2,525,250-20);

    }//----
    if ((i+1 == 1 && n+1 == 9) || (i+1 == 9 && n+1 == 1)){
        arista[7].dibuja = true;
        arista[7].setText(valor2,375,100-8);

    }//----
    if ((i+1 == 1 && n+1 == 10) || (i+1 == 10 && n+1 == 1)){
        arista[8].dibuja = true;
        arista[8].setText(valor2,380,310-60);

    }
    if ((i+1 == 1 && n+1 == 11) || (i+1 == 11 && n+1 == 1)){
        arista[9].dibuja = true;
        arista[9].setText(valor2,325+25,300-100);

    }
    if ((i+1 == 1 && n+1 == 12) || (i+1 == 12 && n+1 == 1)){
        arista[10].dibuja = true;
        arista[10].setText(valor2,435,200-20);

    }

    if ((i+1 == 2 && n+1 == 3) || (i+1 == 3 && n+1 == 2)){
        arista[11].dibuja = true;
        arista[11].setText(valor2,375,150-10);

    }
    if ((i+1 == 2 && n+1 == 4) || (i+1 == 4 && n+1 == 2)){
        arista[12].dibuja = true;
        arista[12].setText(valor2,375,225+20);

    }
    if ((i+1 == 2 && n+1 == 5) || (i+1 == 5 && n+1 == 2)){
        arista[13].dibuja = true;
        arista[13].setText(valor2,450,350-10);

    }
    if ((i+1 == 2 && n+1 == 6) || (i+1 == 6 && n+1 == 2)){
        arista[14].dibuja = true;
        arista[14].setText(valor2,600,350);

    }
    if ((i+1 == 2 && n+1 == 7) || (i+1 == 7 && n+1 == 2)){
        arista[15].dibuja = true;
        arista[15].setText(valor2,675,150-20);

    }
    if ((i+1 == 2 && n+1 == 8) || (i+1 == 8 && n+1 == 2)){
        arista[16].dibuja = true;
        arista[16].setText(valor2,675,250-30);

    }
    if ((i+1 == 2 && n+1 == 9) || (i+1 == 9 && n+1 == 2)){
        arista[17].dibuja = true;
        arista[17].setText(valor2,525,100-10);

    }
    if ((i+1 == 2 && n+1 == 10) || (i+1 == 10 && n+1 == 2)){
        arista[18].dibuja = true;
        arista[18].setText(valor2,525,300-10);

    }
    if ((i+1 == 2 && n+1 == 11) || (i+1 == 11 && n+1 == 2)){
        arista[19].dibuja = true;
        arista[19].setText(valor2,475,200-10);

    }
    if ((i+1 == 2 && n+1 == 12) || (i+1 == 12 && n+1 == 2)){
        arista[20].dibuja = true;
        arista[20].setText(valor2,585,200-10);

    }


    if ((i+1 == 3 && n+1== 4) || (i+1== 4 && n+1== 3)){
        arista[21].dibuja = true;
        arista[21].setText(valor2,150,350-10);

    }
    if ((i+1 == 3 && n+1== 5) || (i+1== 5 && n+1== 3)){
        arista[22].dibuja = true;
        arista[22].setText(valor2,225,450-10);

    }
    if ((i+1 == 3 && n+1== 6) || (i+1== 6 && n+1== 3)){
        arista[23].dibuja = true;
        arista[23].setText(valor2,375,450-10);

    }
    if ((i+1 == 3 && n+1== 7) || (i+1== 7 && n+1== 3)){
        arista[24].dibuja = true;
        arista[24].setText(valor2,450,250-10);

    }
    if ((i+1 == 3 && n+1== 8) || (i+1== 8 && n+1== 3)){
        arista[25].dibuja = true;
        arista[25].setText(valor2,450,350-10);

    }
    if ((i+1== 3 && n+1== 9) || (i+1== 9 && n+1== 3)){
        arista[26].dibuja = true;
        arista[26].setText(valor2,300,200-10);

    }
    if ((i+1== 3 && n+1== 10) || (i+1== 10 && n+1== 3)){
        arista[27].dibuja = true;
        arista[27].setText(valor2,305,405-10);

    }
    if ((i+1== 3 && n+1== 11) || (i+1== 11 && n+1== 3)){
        arista[28].dibuja = true;
        arista[28].setText(valor2,300-50,300-10);

    }
    if ((i+1== 3 && n+1== 12) || (i+1== 12 && n+1== 3)){
        arista[29].dibuja = true;
        arista[29].setText(valor2,460-70,300-10);

    }


    if ((i+1== 4 && n+1== 5) || (i+1== 5 && n+1== 4)){
        arista[30].dibuja = true;
        arista[30].setText(valor2,225,550-10);

    }
    if ((i+1== 4 && n+1== 6) || (i+1== 6 && n+1== 4)){
        arista[31].dibuja = true;
        arista[31].setText(valor2,375,550-10);

    }
    if ((i+1== 4 && n+1== 7) || (i+1== 7 && n+1== 4)){
        arista[32].dibuja = true;
        arista[32].setText(valor2,450,350-10);

    }
    if ((i+1== 4 && n+1== 8) || (i+1== 8 && n+1== 4)){
        arista[33].dibuja = true;
        arista[33].setText(valor2,450,450-10);

    }
    if ((i+1== 4 && n+1== 9) || (i+1== 9 && n+1== 4)){
        arista[34].dibuja = true;
        arista[34].setText(valor2,305,300-10);

    }
    if ((i+1== 4 && n+1== 10) || (i+1== 10 && n+1== 4)){
        arista[35].dibuja = true;
        arista[35].setText(valor2,305,505-10);

    }
    if ((i+1== 4 && n+1== 11) || (i+1== 11 && n+1== 4)){
        arista[36].dibuja = true;
        arista[36].setText(valor2,250,400-10);

    }
    if ((i+1== 4 && n+1== 12) || (i+1== 12 && n+1== 4)){
        arista[37].dibuja = true;
        arista[37].setText(valor2,360,400-10);

    }

    if ((i+1== 5 && n+1== 6) || (i+1== 6 && n+1== 5)){
        arista[38].dibuja = true;
        arista[38].setText(valor2,450,650-10);

    }
    if ((i+1== 5 && n+1== 7) || (i+1== 7 && n+1== 5)){
        arista[39].dibuja = true;
        arista[39].setText(valor2,525,450-10);

    }
    if ((i+1== 5 && n+1== 8) || (i+1== 8 && n+1== 5)){
        arista[40].dibuja = true;
        arista[40].setText(valor2,525,550-10);

    }
    if ((i+1== 5 && n+1== 9) || (i+1== 9 && n+1== 5)){
        arista[41].dibuja = true;
        arista[41].setText(valor2,375,400-10);

    }
    if ((i+1== 5 && n+1== 10) || (i+1== 10 && n+1== 5)){
        arista[42].dibuja = true;
        arista[42].setText(valor2,380,605-10);

    }
    if ((i+1== 5 && n+1== 11) || (i+1== 11 && n+1== 5)){
        arista[43].dibuja = true;
        arista[43].setText(valor2,325,500-10);

    }
    if ((i+1== 5 && n+1== 12) || (i+1== 12 && n+1== 5)){
        arista[44].dibuja = true;
        arista[44].setText(valor2,435,500-10);

    }

    if ((i+1== 6 && n+1== 7) || (i+1== 7 && n+1== 6)){
        arista[45].dibuja = true;
        arista[45].setText(valor2,675,450-10);

    }
    if ((i+1== 6 && n+1== 8) || (i+1== 8 && n+1== 6)){
        arista[46].dibuja = true;
        arista[46].setText(valor2,675,550-10);

    }
    if ((i+1== 6 && n+1== 9) || (i+1== 9 && n+1== 6)){
        arista[47].dibuja = true;
        arista[47].setText(valor2,525,400-10);

    }
    if ((i+1== 6 && n+1== 10) || (i+1== 10 && n+1== 6)){
        arista[48].dibuja = true;
        arista[48].setText(valor2,530,605-10);

    }
    if ((i+1== 6 && n+1== 11) || (i+1== 11 && n+1== 6)){
        arista[49].dibuja = true;
        arista[49].setText(valor2,475,500-10);

    }
    if ((i+1== 6 && n+1== 12) || (i+1== 12 && n+1== 6)){
        arista[50].dibuja = true;
        arista[50].setText(valor2,585,500-10);

    }

    if ((i+1== 7 && n+1== 8) || (i+1== 8 && n+1== 7)){
        arista[51].dibuja = true;
        arista[51].setText(valor2,750,350-10);

    }
    if ((i+1== 7 && n+1== 9) || (i+1== 9 && n+1== 7)){
        arista[52].dibuja = true;
        arista[52].setText(valor2,600,200-10);

    }
    if ((i+1== 7 && n+1== 10) || (i+1== 10 && n+1== 7)){
        arista[53].dibuja = true;
        arista[53].setText(valor2,605,405-10);

    }
    if ((i+1== 7 && n+1== 11) || (i+1== 11 && n+1== 7)){
        arista[54].dibuja = true;
        arista[54].setText(valor2,550,300-10);

    }
    if ((i+1== 7 && n+1== 12) || (i+1== 12 && n+1== 7)){
        arista[55].dibuja = true;
        arista[55].setText(valor2,660,300-10);

    }

    if ((i+1== 8 && n+1== 9) || (i+1== 9 && n+1== 8)){
        arista[56].dibuja = true;
        arista[56].setText(valor2,600,300-10);

    }
    if ((i+1== 8 && n+1== 10) || (i+1== 10 && n+1== 8)){
        arista[57].dibuja = true;
        arista[57].setText(valor2,605,525-10);

    }
    if ((i+1== 8 && n+1== 11) || (i+1== 11 && n+1== 8)){
        arista[58].dibuja = true;
        arista[58].setText(valor2,550,400-10);

    }
    if ((i+1== 8 && n+1== 12) || (i+1== 12 && n+1== 8)){
        arista[59].dibuja = true;
        arista[59].setText(valor2,660,400-10);

    }

    /*if ((i+1== 9 && n+1== 10) || (i+1== 10 && n+1== 9)){
        arista[60].dibuja = true;
        arista[60].setText(valor2,455,355-10);

    }
    if ((i+1== 9 && n+1== 11) || (i+1== 11 && n+1== 9)){
        arista[61].dibuja = true;
        arista[61].setText(valor2,400,250-10);

    }
    if ((i+1== 9 && n+1== 12) || (i+1== 12 && n+1== 9)){
        arista[62].dibuja = true;
        arista[62].setText(valor2,510,250-10);

    }

    if ((i+1== 10 && n+1== 11) || (i+1== 11 && n+1== 10)){
        arista[63].dibuja = true;
        arista[63].setText(valor2,405,455-10);

    }
    if ((i+1== 10 && n+1== 12) || (i+1== 12 && n+1== 10)){
        arista[64].dibuja = true;
        arista[64].setText(valor2,505,455-10);

    }

    if ((i+1== 11 && n+1== 12) || (i+1== 12 && n+1== 11)){
        arista[65].dibuja = true;
        arista[65].setText(valor2,460,350-10);

    }*/





}

void Ventana::backtracking() {
    std::cout<<"ft";
    pintacalle(1,2,"1000");
    pintaciudad(0);


    std::cout<<"ft";


}

void Ventana::menu() {
    while (window.isOpen())
    {
        sf::Font font2;
        font2.loadFromFile("../Minecrafter.ttf");
        sf::Text text2;
        text2.setFont(font2);
        sf::Event event{};
        int corre = 200;
        int mousex =sf::Mouse::getPosition(window).x;
        int mousey = sf::Mouse::getPosition(window).y;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (20+corre-2<mousex && mousex<20+corre+20 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 1;
                    comienza();

                }
            if (50+corre-2<mousex && mousex<50+corre+25 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 2;
                    comienza();

                }
            if (85+corre-2<mousex && mousex<85+corre+25 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 3;
                    comienza();

                }
            if (120+corre-2<mousex && mousex<120+corre+25 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 4;
                    comienza();

                }
            if (120+corre+(35*1)-2<mousex && mousex<120+corre+(35*1)+25 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 5;
                    comienza();

                }
            if (120+corre+(35*2)-2<mousex && mousex<120+corre+(35*2)+25 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 6;
                    comienza();

                }
            if (120+corre+(35*3)-2<mousex && mousex<120+corre+(35*3)+25 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 7;
                    comienza();

                }
            if (120+corre+(35*4)-2<mousex && mousex<120+corre+(35*4)+25 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 8;
                    comienza();

                }
            if (120+corre+(35*5)-2<mousex && mousex<120+corre+(35*5)+25 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 9;
                    comienza();

                }
            if (120+corre+(35*6)-2<mousex && mousex<120+corre+(35*6)+40 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 10;
                    comienza();

                }
            if (330+corre+(50*1)-2<mousex && mousex<330+corre+(50)+35 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 11;
                    comienza();

                }
            if (330+corre+(50*2)-2<mousex && mousex<330+corre+(50*2)+40 && mousey<270+30 && mousey>270)
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    cuantos = 12;
                    comienza();

                }







        }
        window.clear();


        sf::RectangleShape marTitulo(sf::Vector2f(800.f,30.f));
        marTitulo.setPosition(50-2,200+2);
        marTitulo.setFillColor(sf::Color::Blue);
        window.draw(marTitulo);
        //boton para 1
        sf::RectangleShape n1(sf::Vector2f(20.f,30.f));
        n1.setPosition(20+corre-2,270+2);
        if (20+corre-2<mousex && mousex<20+corre+20 && mousey<270+30 && mousey>270)
            n1.setFillColor(sf::Color::Red);
        else
            n1.setFillColor(sf::Color::Blue);
        window.draw(n1);
        text2.setString("1"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(20+corre,270),window.draw(text2);

        //boton para 2
        sf::RectangleShape n2(sf::Vector2f(25.f,30.f));
        n2.setPosition(50+corre-2,270+2);
        if (50+corre-2<mousex && mousex<50+corre+25 && mousey<270+30 && mousey>270)
            n2.setFillColor(sf::Color::Red);
        else
            n2.setFillColor(sf::Color::Blue);
        window.draw(n2);
        text2.setString("2"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(50+corre,270),window.draw(text2);


        //boton para 3
        sf::RectangleShape n3(sf::Vector2f(25.f,30.f));
        n3.setPosition(85+corre-2,270+2);
        if (85+corre-2<mousex && mousex<85+corre+25 && mousey<270+30 && mousey>270)
            n3.setFillColor(sf::Color::Red);
        else
            n3.setFillColor(sf::Color::Blue);
        window.draw(n3);
        text2.setString("3"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(85+corre,270),window.draw(text2);

        //boton para 4
        sf::RectangleShape n4(sf::Vector2f(25.f,30.f));
        n4.setPosition(120+corre-2,270+2);
        if (120+corre-2<mousex && mousex<120+corre+25 && mousey<270+30 && mousey>270)
            n4.setFillColor(sf::Color::Red);
        else
            n4.setFillColor(sf::Color::Blue);
        window.draw(n4);
        text2.setString("4"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(120+corre,270),window.draw(text2);

        //boton para 5
        sf::RectangleShape n5(sf::Vector2f(25.f,30.f));
        n5.setPosition(120+corre+(35*1)-2,270+2);

        if (120+corre+(35*1)-2<mousex && mousex<120+corre+(35*1)+25 && mousey<270+30 && mousey>270)
            n5.setFillColor(sf::Color::Red);
        else
            n5.setFillColor(sf::Color::Blue);
        window.draw(n5);
        text2.setString("5"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(120+corre+(35*1),270),window.draw(text2);

        //boton para 6
        sf::RectangleShape n6(sf::Vector2f(25.f,30.f));
        n6.setPosition(120+corre+(35*2)-2,270+2);

        if (120+corre+(35*2)-2<mousex && mousex<120+corre+(35*2)+25 && mousey<270+30 && mousey>270)
            n6.setFillColor(sf::Color::Red);
        else
            n6.setFillColor(sf::Color::Blue);
        window.draw(n6);
        text2.setString("6"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(120+corre+(35*2),270),window.draw(text2);

        //boton para 7
        sf::RectangleShape n7(sf::Vector2f(25.f,30.f));
        n7.setPosition(120+corre+(35*3)-2,270+2);

        if (120+corre+(35*3)-2<mousex && mousex<120+corre+(35*3)+25 && mousey<270+30 && mousey>270)
            n7.setFillColor(sf::Color::Red);
        else
            n7.setFillColor(sf::Color::Blue);
        window.draw(n7);
        text2.setString("7"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(120+corre+(35*3),270),window.draw(text2);

        //boton para 8
        sf::RectangleShape n8(sf::Vector2f(25.f,30.f));
        n8.setPosition(120+corre+(35*4)-2,270+2);

        if (120+corre+(35*4)-2<mousex && mousex<120+corre+(35*4)+25 && mousey<270+30 && mousey>270)
            n8.setFillColor(sf::Color::Red);
        else
            n8.setFillColor(sf::Color::Blue);
        window.draw(n8);
        text2.setString("8"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(120+corre+(35*4),270),window.draw(text2);

        //boton para 9
        sf::RectangleShape n9(sf::Vector2f(25.f,30.f));
        n9.setPosition(120+corre+(35*5)-2,270+2);

        if (120+corre+(35*5)-2<mousex && mousex<120+corre+(35*5)+25 && mousey<270+30 && mousey>270)
            n9.setFillColor(sf::Color::Red);
        else
            n9.setFillColor(sf::Color::Blue);
        window.draw(n9);
        text2.setString("9"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(120+corre+(35*5),270),window.draw(text2);

        //boton para 10
        sf::RectangleShape n10(sf::Vector2f(40.f,30.f));
        n10.setPosition(120+corre+(35*6)-2,270+2);

        if (120+corre+(35*6)-2<mousex && mousex<120+corre+(35*6)+40 && mousey<270+30 && mousey>270)
            n10.setFillColor(sf::Color::Red);
        else
            n10.setFillColor(sf::Color::Blue);
        window.draw(n10);
        text2.setString("10"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(120+corre+(35*6),270),window.draw(text2);

        //boton para 11
        sf::RectangleShape n11(sf::Vector2f(35.f,30.f));
        n11.setPosition(330+corre+(50*1)-2,270+2);

        if (330+corre+(50*1)-2<mousex && mousex<330+corre+(50)+35 && mousey<270+30 && mousey>270)
            n11.setFillColor(sf::Color::Red);
        else
            n11.setFillColor(sf::Color::Blue);
        window.draw(n11);
        text2.setString("11"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(330+corre+(50*1),270),window.draw(text2);


        //boton para 12
        sf::RectangleShape n12(sf::Vector2f(40.f,30.f));
        n12.setPosition(330+corre+(50*2)-2,270+2);

        if (330+corre+(50*2)-2<mousex && mousex<330+corre+(50*2)+40 && mousey<270+30 && mousey>270)
            n12.setFillColor(sf::Color::Red);
        else
            n12.setFillColor(sf::Color::Blue);
        window.draw(n12);
        text2.setString("12"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(330+corre+(50*2),270),window.draw(text2);


        text2.setString("Seleccione cuantas ciudades quieres crear"),text2.setCharacterSize(30),text2.setFillColor(sf::Color::Green),text2.setPosition(50,200),window.draw(text2);







        window.display();
    }
}

void Ventana::comienza() {
    hilo = true;
    inicio();

}

void Ventana::pintaciudad(int ciudad) {
    puntos[ciudad].pintaciudad();

}

void Ventana::creaaristas() {
    arista[0] = conectarpuntos(puntos[0],puntos[1]);;
    arista[1] = conectarpuntos(puntos[0],puntos[2]);;
    arista[2] = conectarpuntos(puntos[0],puntos[3]);;
    arista[3] = conectarpuntos(puntos[0],puntos[4]);;
    arista[4] = conectarpuntos(puntos[0],puntos[5]);;
    arista[5] = conectarpuntos(puntos[0],puntos[6]);;
    arista[6] = conectarpuntos(puntos[0],puntos[7]);;
    arista[7] = conectarpuntos(puntos[0],puntos[8]);;
    arista[8] = conectarpuntos(puntos[0],puntos[9]);;
    arista[9] = conectarpuntos(puntos[0],puntos[10]);;
    arista[10] = conectarpuntos(puntos[0],puntos[11]);;

    arista[11] = conectarpuntos(puntos[1],puntos[2]);;
    arista[12] = conectarpuntos(puntos[1],puntos[3]);;
    arista[13] = conectarpuntos(puntos[1],puntos[4]);;
    arista[14] = conectarpuntos(puntos[1],puntos[5]);;
    arista[15] = conectarpuntos(puntos[1],puntos[6]);;
    arista[16] = conectarpuntos(puntos[1],puntos[7]);;
    arista[17] = conectarpuntos(puntos[1],puntos[8]);;
    arista[18] = conectarpuntos(puntos[1],puntos[9]);;
    arista[19] = conectarpuntos(puntos[1],puntos[10]);;
    arista[20] = conectarpuntos(puntos[1],puntos[11]);;

    arista[21] = conectarpuntos(puntos[2],puntos[3]);;
    arista[22] = conectarpuntos(puntos[2],puntos[4]);;
    arista[23] = conectarpuntos(puntos[2],puntos[5]);;
    arista[24] = conectarpuntos(puntos[2],puntos[6]);;
    arista[25] = conectarpuntos(puntos[2],puntos[7]);;
    arista[26] = conectarpuntos(puntos[2],puntos[8]);;
    arista[27] = conectarpuntos(puntos[2],puntos[9]);;
    arista[28] = conectarpuntos(puntos[2],puntos[10]);;
    arista[29] = conectarpuntos(puntos[2],puntos[11]);;

    arista[30] = conectarpuntos(puntos[3],puntos[4]);;
    arista[31] = conectarpuntos(puntos[3],puntos[5]);;
    arista[32] = conectarpuntos(puntos[3],puntos[6]);;
    arista[33] = conectarpuntos(puntos[3],puntos[7]);;
    arista[34] = conectarpuntos(puntos[3],puntos[8]);;
    arista[35] = conectarpuntos(puntos[3],puntos[9]);;
    arista[36] = conectarpuntos(puntos[3],puntos[10]);;
    arista[37] = conectarpuntos(puntos[3],puntos[11]);;

    arista[38] = conectarpuntos(puntos[4],puntos[5]);;
    arista[39] = conectarpuntos(puntos[4],puntos[6]);;
    arista[40] = conectarpuntos(puntos[4],puntos[7]);;
    arista[41] = conectarpuntos(puntos[4],puntos[8]);;
    arista[42] = conectarpuntos(puntos[4],puntos[9]);;
    arista[43] = conectarpuntos(puntos[4],puntos[10]);;
    arista[44] = conectarpuntos(puntos[4],puntos[11]);;

    arista[45] = conectarpuntos(puntos[5],puntos[6]);;
    arista[46] = conectarpuntos(puntos[5],puntos[7]);;
    arista[47] = conectarpuntos(puntos[5],puntos[8]);;
    arista[48] = conectarpuntos(puntos[5],puntos[9]);;
    arista[49] = conectarpuntos(puntos[5],puntos[10]);;
    arista[50] = conectarpuntos(puntos[5],puntos[11]);;

    arista[51] = conectarpuntos(puntos[6],puntos[7]);;
    arista[52] = conectarpuntos(puntos[6],puntos[8]);;
    arista[53] = conectarpuntos(puntos[6],puntos[9]);;
    arista[54] = conectarpuntos(puntos[6],puntos[10]);;
    arista[55] = conectarpuntos(puntos[6],puntos[11]);;

    arista[56] = conectarpuntos(puntos[7],puntos[8]);;
    arista[57] = conectarpuntos(puntos[7],puntos[9]);;
    arista[58] = conectarpuntos(puntos[7],puntos[10]);;
    arista[59] = conectarpuntos(puntos[7],puntos[11]);;

    //arista[60] = conectarpuntos(puntos[8],puntos[9]);;
    /*arista[61] = conectarpuntos(puntos[8],puntos[10]);;
    arista[62] = conectarpuntos(puntos[8],puntos[11]);;

    arista[63] = conectarpuntos(puntos[9],puntos[10]);;
    arista[64] = conectarpuntos(puntos[9],puntos[11]);;

    arista[65] = conectarpuntos(puntos[10],puntos[11]);;*/

}





