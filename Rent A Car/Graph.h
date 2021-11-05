//
// Created by Diego on 10/23/2021.
//

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
    void start();
    bool empty();
    int size();
    vertice *getVertice(string name);
    void setArista(vertice *start, vertice *end, int Km);
    void setVertice(string name, int value);
    void adyList();
    void createGraph(int num);
    void backtracking(vertice* start, vertice* end);

private:
    vertice *h;
};


#endif //RENT_A_CAR_GRAPH_H
