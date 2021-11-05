//
// Created by Diego on 10/23/2021.
//

#include "Graph.h"

void Graph::start() { //inicializa el grafo en NULL.

    h = NULL;

}

bool Graph::empty() { //si el primer vector es vacio retorna true

    if(h == NULL){
        return true;
    }
    return false;

}

int Graph::size(){ //retorna el size del grafo

    int cont;
    vertice *aux;
    aux = h;

    while (aux != NULL){

        aux =  aux -> sig;
        cont++;

    }
    return cont;
};

vertice *Graph::getVertice(string name) { //retorna el vertice buscado

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

void Graph::setVertice(string name, int value) { // dado un nombre crea un vertice

    vertice *newCity = new vertice; //crea un vertice
    newCity -> name = name; //se le asigna el nombre dado en los parametros al vertice
    newCity->sig = NULL;
    newCity->ady = NULL;

    if (empty()){

        h = newCity; //si no se ha inicializado el grafo se crea con el vertice

    }
    else{

        vertice *aux;
        aux = h;

        while (aux->sig != NULL){
                                    //busca el ultimo vertice creado
            aux = aux->sig;

        }
        aux-> sig = newCity; //agrega el vertice al grafo
    }
}

void Graph::setArista(vertice *start, vertice *end, int gas) { //basaddo en 2 vertices crea la arista entre ellas

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

void Graph::adyList() { //imprime en consola la lista de los vectores y a quines esta conectado junto con su valor

    vertice *verAux;
    arista *arisAux;

    verAux = h;

    while(verAux != NULL){

        cout<<verAux->name<<"->";

        arisAux = verAux->ady;
        while(arisAux != NULL){

            cout<<" :: " <<arisAux->Gas<< " " <<arisAux->ady->name<<"->";
            arisAux = arisAux->sig;
        }
        verAux = verAux->sig;
        cout<<endl;
    }
}

bool repeat(string name, int i, string* lista){ //retorna si un string se repite en una lista
    for (int x = 0; x != i; x++){
        if(name == lista[x]){
            return true;
        }
    }
    return false;
}

void Graph::createGraph(int num) { //crea el grafo con el numero de vertices indicado por el usuario

    bool band;
    string names[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
    string aux[num];
    int i = 0, j = 0, k;
    string auxName, auxName2, destino;
    srand(time(NULL));

    if(num <= 0 or num > 12){
        num = (rand()%11) + 1;
        cout<<"El numero que eligio no entra en los parametros por lo que se decidio el numero: "<<num<<endl;
    }
    while (i != num){
        band = true;
        auxName = names[(rand()%11)];
        while (band){
            if (!repeat(auxName, 12, aux)){
                aux[i] = auxName;
                setVertice(auxName, i);
                band = false;
                i++;
            }
            else{
                auxName = names[(rand()%11)];
            }
        }
    }
    for (int z = 0; z != num; z++){
    }
    while (j != num){
        k = 0;
        while (k != 4){
            auxName2 = aux[rand()%(num - 1)];
            if (aux[j] != auxName2){
                setArista(getVertice(aux[j]), getVertice(auxName2), (rand()%99) + 1 );
                k++;
            }
        }
        j++;
    }
    adyList();
    cout<<"Usted se encuentra en la ciudad: "<<aux[0]<<endl;
    cout<<"Ingrese el nombre del destino "<<endl;
    cin >>destino ;
    cout<<destino<<endl;
    backtracking(getVertice(aux[0]), getVertice(destino));
}

bool compare(pair<vertice *, int> a, pair<vertice *, int> b) { //compara 2 pares de numeros
    return a.second < b.second;
}

void Graph::backtracking(vertice *start, vertice *end) { //encuentra la ruta mas rapida indagando en todas las rutas posibles

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
                        cout<<" "<<endl;
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
                cout<<" "<<endl;
                totalCost = totalCost - aux->Gas;
            }
            aux = aux->sig;

        }
    }
    if(band2 == 0){
        cout<<"No hay rutas compatibles"<<endl;
    }
}