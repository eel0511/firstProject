#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <limits>
#include <iostream>
#include "Graph.h"

using namespace std;

#define MAXV 300

class dijkstra{

public:
   void init_vars(bool discovered[], int distance[], int parent[]);
   void dijkstra_shortest_path(Graph *g, int parent[], int distance[], int start);
   void print_shortest_path(int v, int parent[]);
   void print_distances(int start,  int distance[]);
   void make_and_print(Graph *g,int arrive, int parent[],int start,  int distance[]);

    
};
#endif