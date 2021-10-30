//
// Created by Diego on 10/23/2021.
//

#include "Graph.h"

void Graph::start() {

    h = NULL;

}

bool Graph::empty() {

    if(h == NULL){
        return true;
    }
    return false;

}

int Graph::size(){

    int cont;
    vertice *aux;
    aux = h;

    while (aux != NULL){

        aux =  aux -> sig;
        cont++;

    }
    return cont;
};

vertice *Graph::getVertice(string name) {

    vertice *aux;
    aux = h;

    while (aux != NULL){

        if (aux->name == name){
            return aux;
        }
    }
    return NULL;
}

void Graph::setVertice(string name) {

    vertice *newCity = new vertice;
    newCity -> name = name;
    newCity->sig = NULL;
    newCity->ady = NULL;

    if (empty()){

        h = newCity;

    }
    else{

        vertice *aux;
        aux = h;

        while (aux->sig != NULL){

            aux = aux->sig;

        }
        aux-> sig = newCity;
    }
}

void Graph::setArista(vertice *start, vertice *end, int gas) {

    arista *tNew = new arista;
    tNew -> Gas = gas;
    tNew -> sig = NULL;
    tNew -> ady = NULL;
    arista *aux;

    aux = start->ady;

    if(aux == NULL){

        start->ady = tNew;
        tNew->ady = end;

    }
    else{
        while(aux->sig != NULL){

            aux = aux->sig;

        }
        aux->sig = tNew;
        tNew->ady = end;
    }
}

void Graph::adyList() {

    vertice *verAux;
    arista *arisAux;

    verAux = h;

    while(verAux != NULL){

        cout<<verAux->name<<"->";

        arisAux = verAux->ady;
        while(arisAux != NULL){

            cout<<arisAux->ady->name<<"->";
            arisAux = arisAux->sig;
        }
        verAux = verAux->sig;
        cout<<endl;
    }
}

string Graph::removeItem(string item, string *list) {
    int x = list->length();
    string aux [x];
    for (int i = 0; i <= x; i++){
        if(list[i] != item){
            //aux->insert;
        }
    }
    cout<<aux[1]<<endl;
    return aux[0];
}

void Graph::createGraph(int num) {

    string names [] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
                       "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
                       "U", "V", "W", "X", "Y", "Z"};
    string aux [num];
    int backup;
    string auxName;
    srand(time(NULL));
    int i = 0;
    int j = 0;
    if(num <= 0 or num > 26){
        num = (rand()%25) + 1;
        cout<<"El numero que eligio no entra en los parametros por lo que se decidio el numero: "<<num<<endl;
    }
    while (i != num){
        auxName = names[(rand()%25)+1];
        aux->append(auxName);
        setVertice(auxName);
        //backup = (rand()%99) + 1;
        //cout<<backup<<endl;
        i++;
    }
    //cout<<"*"<<num<<"*"<<endl;
}

void Graph::tracking(vertice *start, vertice *end) {

    vertice* Vnow, *Endnow;
    bool band, band2, band3 = true;
    arista *aux;
    typedef pair<vertice*, vertice*> VerticeVertice;
    queue<vertice *>cola;
    stack<VerticeVertice>pila;
    list<vertice*>lista;
    list<vertice*>::iterator i;

    cola.push(start);

    while(!cola.empty()){

        Vnow = cola.front();
        cola.pop();
        for(i=lista.begin(); i != lista.end(); i++){
            if(Vnow == *i){
                band = false;
            }
        }
        if (band){
            if(Vnow == end){
                band = false;
                Endnow = end;

                while(!pila.empty()){
                    cout<<Endnow->name<<"<-";

                    while(!pila.empty() && pila.top().second != Endnow){
                        pila.pop();
                    }
                    if(!pila.empty()){
                        Endnow = pila.top().first;
                    }
                }
            }
            lista.push_back(Vnow);
            aux = Vnow->ady;
            while(aux != NULL){
                for(i = lista.begin();i != lista.end();i++){
                    if(aux->ady == *i){
                        band2 = false;
                    }
                }
                if (band2){
                    cola.push(aux->ady);
                    pila.push(VerticeVertice(Vnow,aux->ady));
                }
                aux = aux->sig;
            }
        }

    }
    if (band3){
        cout<<"No se encontró ruta"<<endl;
    }
}
