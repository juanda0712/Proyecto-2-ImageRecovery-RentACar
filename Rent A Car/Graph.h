//
// Created by Diego on 10/23/2021.
//
/**
 *  @file Graph.h
 *  @date 4/11/21
 *  @author Diego Vega Mora
 */
#ifndef RENT_A_CAR_GRAPH_H
#define RENT_A_CAR_GRAPH_H

#include <iostream>
#include <ctime>
#include <queue>
#include <list>
#include <stack>
#include <string>
using namespace std;

class arista;

class vertice{

    vertice *sig;
    arista *ady;
    friend class Graph;

private:
    string name;

};

class arista{

    arista *sig;
    vertice *ady;
    friend class Graph;

private:
    int Gas;

};


class Graph {

public:
    /**
     * @brief inicializa el grafo
     */
    void start();
    /**
     * @brief retorna si el grafo esta vacio o no
     * @return un bool
     */
    bool empty();
    /**
     * @brief retorna el numero de vectores del grafo
     * @return cuanto mide el grafo
     */
    int size();
    /**
     * @brief busca y retorna el vectopr buscado
     * @param name un string con el nombre del vector
     * @return el vector buscado
     */
    vertice *getVertice(string name);
    /**
     * @brief crea una arista
     * @param start un vector inicial
     * @param end el vector final
     * @param Km el valor requeriodo para pasar de un vertice a otro
     */
    void setArista(vertice *start, vertice *end, int Km);
    /**
     * @brief crea un vertice
     * @param name el nombre del vertice
     * @param value un identificador unico
     */
    void setVertice(string name, int value);
    /**
     * @brief imprime en consola la lista de adyacencia de cada vector
     */
    void adyList();
    /**
     * @brief crea el grafo de forma aleatoria con el numero de vectores brindado
     * @param num el numero de vectores a crear
     */
    void createGraph(int num);
    /**
     * @brief da la ruta mas rapida utilizando el algoritmo backtracking
     * @param start el vertice donde inicia
     * @param end el vertice al que se quiere llegar
     */
    void backtracking(vertice* start, vertice* end);

private:
    vertice *h;
};


#endif //RENT_A_CAR_GRAPH_H
