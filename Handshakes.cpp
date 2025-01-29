#include <iostream>
#include <vector>
#include <queue>
#include "Graph.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    Graph g;
    int vert_id = 0;

    g.AddVertex(vert_id++, "Zheka");
    g.AddVertex(vert_id++, "Roma");
    g.AddVertex(vert_id++, "Serun");
    g.AddVertex(vert_id++, "Kasimir");
    g.AddVertex(vert_id++, "Susan");
    g.AddVertex(vert_id++, "Hubabub");

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    for(int i = 0; i < vert_id; i++)
        g.findMinDistanceDecstr(i);      

    return 0;
}