//
// Created by Diego on 10/23/2021.
//


#include "Graph.h"
#include "Interfaz/Ventana.h"

Ventana ventana;
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

vertice *Graph::getVertice(std::string name) { //retorna el vertice buscado

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

void Graph::setVertice(std::string name,int value2) { // dado un nombre crea un vertice

    vertice *newCity = new vertice; //crea un vertice
    newCity -> name = name; //se le asigna el nombre dado en los parametros al vertice
    newCity->sig = NULL;
    newCity->ady = NULL;
    newCity->value = value2;

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

        std::cout<<verAux->name<<"->";

        arisAux = verAux->ady;
        while(arisAux != NULL){

            std::cout<<" :: " <<arisAux->Gas<< " " <<arisAux->ady->name<<"->";
            arisAux = arisAux->sig;
        }
        verAux = verAux->sig;
        std::cout<<std::endl;
    }
}

bool repeat(std::string name, int i, std::string* lista){ //retorna si un string se repite en una lista
    for (int x = 0; x != i; x++){
        if(name == lista[x]){
            return true;
        }
    }
    return false;
}

void Graph::createGraph(int num) { //crea el grafo con el numero de vertices indicado por el usuario

    bool band;
    std::string names[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
    std::string aux[num];
    int i = 0, j = 0, k;
    std::string auxName, auxName2, destino;
    srand(time(NULL));

    if(num <= 0 or num > 12){
        num = (rand()%11) + 1;
        std::cout<<"El numero que eligio no entra en los parametros por lo que se decidio el numero: "<<num<<std::endl;
    }
    int num2 = 0;
    while (i != num){
        band = true;
        auxName = names[(rand()%11)];
        while (band){
            if (!repeat(auxName, 12, aux)){
                aux[i] = auxName;
                setVertice(auxName,num2);
                ventana.dibujaciudad(num2,auxName);
                band = false;
                num2 = num2 +1;
                i++;
            }
            else{
                auxName = names[(rand()%11)];
            }
        }
    }
    ventana.creaaristas();
    for (int z = 0; z != num; z++){
    }
    while (j != num){
        k = 0;
        while (k != 4){
            auxName2 = aux[rand()%(num - 1)];
            if (aux[j] != auxName2){
                vertice *start2 = getVertice(aux[j]);
                vertice *end2 = getVertice(auxName2);
                int gas = (rand() % 99) + 1;
                arista *arisAux;
                arisAux = start2->ady;
                bool esta = true;
                while(arisAux != NULL){

                    if(arisAux->ady->name == end2->name){
                        esta = false;
                    }
                    arisAux = arisAux->sig;
                }
                arisAux = end2->ady;
                while(arisAux != NULL){

                    if(arisAux->ady->name == start2->name){
                        esta = false;
                    }
                    arisAux = arisAux->sig;
                }
                if (esta){
                    setArista(start2,end2 ,gas) ;
                    setArista(end2 ,start2 ,gas) ;
                    ventana.dibujarcalle(start2->value,end2->value, std::to_string(gas));
                }



                k++;
            }
        }
        j++;
    }
    adyList();
    //std::cout<<"Usted se encuentra en la ciudad: "<<aux[0]<<std::endl;
    //std::cout<<"Ingrese el nombre del destino "<<std::endl;
    //std::cin >>destino ;
    //std::cout<<destino<<std::endl;
    while (!ventana.back){

    }
    std::cout<<"mama";
    backtracking(getVertice(ventana.puntos[ventana.seleccion[0]].text.getString()), getVertice(ventana.puntos[ventana.seleccion[1]].text.getString()));
}

bool compare(std::pair<vertice *, int> a, std::pair<vertice *, int> b) { //compara 2 pares de numeros
    return a.second < b.second;
}

void Graph::backtracking(vertice *start, vertice *end) { //encuentra la ruta mas rapida indagando en todas las rutas posibles

    int totalCost = 0, band, band2= 0;
    vertice *Vnow, *Endnow;
    arista *aux;
    typedef std::pair<vertice*, int>Vcost;
    typedef std::pair<vertice*, vertice*> VerticeVertice;
    std::list<Vcost>listCost;
    std::list<Vcost>listArray;
    std::list<Vcost>::iterator i, j;
    std::stack<VerticeVertice>pila;

    listCost.push_back(Vcost(start, 0));
    listArray.push_back(Vcost(start, 0));

    while(!listArray.empty()){

        Vnow = listArray.front().first;
        totalCost = listArray.front().second;
        listArray.pop_front();

        if(Vnow == end){

            std::cout<<"Costo total: "<<totalCost<<std::endl;
            band2 = 1;
            Endnow = end;

            while(!pila.empty()){
                std::cout<<Endnow->name<<"<-";

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
                        std::cout<<"Ruta actual "<<totalCost<<std::endl;
                        std::cout<<" "<<std::endl;
                        totalCost = totalCost - aux->Gas;
                    }

                }
            }
            if (band == 0){
                listCost.push_back(Vcost(aux->ady, totalCost));
                listArray.push_back(Vcost(aux->ady, totalCost));
                listArray.sort(compare);
                pila.push(VerticeVertice(Vnow, aux->ady));
                std::cout<<Vnow->name<<":"<<Vnow->value<<" -> "<<aux->ady->name<<":"<<aux->ady->value <<std::endl;
                std::cout<<"Ruta actual "<<totalCost<<std::endl;
                ventana.pintacalle(Vnow->value,aux->ady->value,"90");
                sf::sleep(sf::milliseconds(5000));

                std::cout<<" "<<std::endl;
                totalCost = totalCost - aux->Gas;
            }
            aux = aux->sig;

        }
    }
    if(band2 == 0){
        std::cout<<"No hay rutas compatibles"<<std::endl;
    }
}


void func2(){
    while (!ventana.hilo){

    }
    std::cout<<"hola";
    Graph G;
    G.start();
    G.createGraph(ventana.cuantos);
    //sf::sleep(sf::milliseconds(1000));

    //ventana.backtracking();

}
void func(){
    func2();
}

int main() {

    ventana.coordenadasx[0]= 300;
    ventana.coordenadasy[0] =50;//3
    ventana.coordenadasx[1]= 600;
    ventana.coordenadasy[1] =50;//5
    ventana.coordenadasx[2]= 150;
    ventana.coordenadasy[2] =250;//7
    ventana.coordenadasx[3]= 150;
    ventana.coordenadasy[3] =450;//9
    ventana.coordenadasx[4]= 300;
    ventana.coordenadasy[4] =650;
    ventana.coordenadasx[5]= 600;
    ventana.coordenadasy[5] =650;
    ventana.coordenadasx[6]= 750;
    ventana.coordenadasy[6] =250;
    ventana.coordenadasx[7]= 750;
    ventana.coordenadasy[7] =450;
    ventana.coordenadasx[8]= 450;
    ventana.coordenadasy[8] =150;
    ventana.coordenadasx[9]= 460;
    ventana.coordenadasy[9] =560;
    ventana.coordenadasx[10]= 350;
    ventana.coordenadasy[10] =350;
    ventana.coordenadasx[11]= 570;
    ventana.coordenadasy[11] =350;

    /*ventana.dibujaciudad(0,"tgh");
    ventana.dibujaciudad(1,"lkj");
    ventana.dibujaciudad(2,"yuh");
    ventana.dibujaciudad(3,"tgh");
    ventana.dibujaciudad(4,"lkj");
    ventana.dibujaciudad(5,"yuh");
    ventana.dibujaciudad(6,"tgh");
    ventana.dibujaciudad(7,"lkj");
    ventana.dibujaciudad(8,"yuh");
    ventana.dibujaciudad(9,"tgh");
    ventana.dibujaciudad(10,"lkj");
    ventana.dibujaciudad(11,"yuh");
    ventana.dibujaciudad(12,"yuh");






    ventana.dibujarcalle(10,11,"11");*/



    std::thread th(func);

    ventana.menu();











    return 0;
}
