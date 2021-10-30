#include <iostream>
#include "Graph.h"


int main() {
    string list[] = {"1", "2", "3", "4"};
    Graph g;
    g.start();
    //g.createGraph(2);

    g.removeItem("4", list);
    return 0;
}
