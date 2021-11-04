#include <iostream>
#include "Graph.h"


int main() {
    string list[] = {"1", "2", "3", "4"};
    Graph G;
    G.start();
    //g.createGraph(2);

    //g.removeItem("4", list);

    G.setVertice("TIJ");
    G.setVertice("MTY");
    G.setVertice("MZT");
    G.setVertice("BJX");
    G.setVertice("GDL");
    G.setVertice("SAN");
    G.setVertice("TAM");
    G.setVertice("MEX");
    G.setVertice("CUN");
    G.setVertice("MID");

    G.setArista(G.getVertice("TIJ"), G.getVertice("MTY"), 800);
    G.setArista(G.getVertice("MZT"), G.getVertice("TIJ"), 400);
    G.setArista(G.getVertice("MZT"), G.getVertice("BJX"), 300);
    G.setArista(G.getVertice("MTY"), G.getVertice("BJX"), 700);
    G.setArista(G.getVertice("BJX"), G.getVertice("SAN"), 900);
    G.setArista(G.getVertice("BJX"), G.getVertice("TAM"), 450);
    G.setArista(G.getVertice("BJX"), G.getVertice("MEX"), 350);
    G.setArista(G.getVertice("GDL"), G.getVertice("MZT"), 500);
    G.setArista(G.getVertice("GDL"), G.getVertice("MTY"), 450);
    G.setArista(G.getVertice("GDL"), G.getVertice("BJX"), 250);
    G.setArista(G.getVertice("GDL"), G.getVertice("MEX"), 500);
    G.setArista(G.getVertice("SAN"), G.getVertice("MID"), 1200);
    G.setArista(G.getVertice("TAM"), G.getVertice("MID"), 450);
    G.setArista(G.getVertice("MEX"), G.getVertice("MID"), 450);
    G.setArista(G.getVertice("MEX"), G.getVertice("CUN"), 650);
    G.setArista(G.getVertice("CUN"), G.getVertice("GDL"), 650);

    //cout<<G.empty()<<endl;
    //G.adyList();

    G.realTrack(G.getVertice("TIJ"), G.getVertice("MID"));


    return 0;
}
