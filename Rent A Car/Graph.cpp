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
        aux = aux->sig;
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
                       "K", "L"};
    string aux [num];
    int backup;
    string auxName;
    srand(time(NULL));
    int i = 0;
    int j = 0;
    if(num <= 0 or num > 12){
        num = (rand()%25) + 1;
        cout<<"El numero que eligio no entra en los parametros por lo que se decidio el numero: "<<num<<endl;
    }
    while (i != num){
        auxName = names[(rand()%26)];
        aux->append(auxName);
        setVertice(auxName);
        backup = (rand()%99) + 1;
        //cout<<backup<<endl;
        i++;
    }
    //cout<<"*"<<num<<"*"<<endl;
}

void Graph::tracking(vertice *start, vertice *end) {

    vertice* Vnow, *Endnow;
    int band, band2, band3 = 0;
    arista *aux;
    typedef pair<vertice*, vertice*> VerticeVertice;
    queue<vertice*>cola;
    stack<VerticeVertice>pila;
    list<vertice*>listaV;
    list<vertice*>::iterator i;

    cola.push(start);
    while(!cola.empty()){
        band = 0;
        Vnow = cola.front();
        cola.pop();
        for(i=listaV.begin(); i != listaV.end(); i++){
            if(Vnow == *i){
                band = 1;
            }
        }
        if (band == 0){
            if(Vnow == end){
                band3 = 1;
                Endnow = end;

                while(!pila.empty()){
                    cout<<Endnow->name <<"<-";

                    while(!pila.empty() && pila.top().second != Endnow){
                        pila.pop();
                    }
                    if(!pila.empty()){
                        Endnow = pila.top().first;
                    }
                }
            }
            listaV.push_back(Vnow);
            aux = Vnow->ady;
            while(aux != NULL){
                band2= 0;
                for(i = listaV.begin();i != listaV.end();i++){
                    if(aux->ady == *i){
                        band2 = 1;
                    }
                }
                if (band2 == 0){
                    cola.push(aux->ady);
                    pila.push(VerticeVertice(Vnow,aux->ady));
                }
                aux = aux->sig;
            }
        }

    }
    if (band3 == 0){
        cout<<"No se encontro ruta"<<endl;
    }
}

bool compare(pair<vertice *, int> a, pair<vertice *, int> b) {
    return a.second < b.second;
}

void Graph::realTrack(vertice *start, vertice *end) {

    int totalCost = 0, band, band2= 0;
    vertice *Vnow, *Endnow;
    arista *aux;
    typedef pair<vertice*, int>Vcost;
    typedef pair<vertice*, vertice*> VerticeVertice;
    list<Vcost>listCost;
    list<Vcost>listArray;
    list<Vcost>::iterator i, j;
    stack<VerticeVertice>pila;

    listCost.push_back(Vcost(start, 0));
    listArray.push_back(Vcost(start, 0));

    while(!listArray.empty()){

        Vnow = listArray.front().first;
        totalCost = listArray.front().second;
        listArray.pop_front();

        if(Vnow == end){

            cout<<"Costo total: "<<totalCost<<endl;
            band2 = 1;
            Endnow = end;

            while(!pila.empty()){
                cout<<Endnow->name<<"<-";

                while(!pila.empty() && pila.top().second !=Endnow ){
                    pila.pop();
                }
                if(!pila.empty()){
                    Endnow = pila.top().first;
                }
            }
            break;
        }

        aux = Vnow->ady;
        while(aux != NULL){

            band = 0;
            totalCost = totalCost + aux->Gas;
            for(i = listCost.begin();i != listCost.end(); i++){
                if(aux->ady == i->first){

                    band = 1;
                    if(totalCost < i->second){
                        (*i).second = totalCost;
                        for(j = listArray.begin(); j != listArray.end(); j++){
                            if(j->first == aux->ady){
                                (*j).second = totalCost;
                            }
                        }
                        listArray.sort(compare);
                        pila.push(VerticeVertice(Vnow, aux->ady));
                        cout<<"Ruta actual "<<totalCost<<endl;
                        totalCost = totalCost - aux->Gas;
                    }

                }
            }
            if (band == 0){
                listCost.push_back(Vcost(aux->ady, totalCost));
                listArray.push_back(Vcost(aux->ady, totalCost));
                listArray.sort(compare);
                pila.push(VerticeVertice(Vnow, aux->ady));
                cout<<"Ruta actual "<<totalCost<<endl;
                totalCost = totalCost - aux->Gas;
            }
            aux = aux->sig;

        }
    }
    if(band2 == 0){
        cout<<"No hay rutas compatibles"<<endl;
    }
}
