//suhyung
#include <limits>
#include <iostream>
#include "dijkstra.h"


using namespace std;

#define MAXV 300

void dijkstra::init_vars(bool discovered[], int distance[], int parent[]){
    for(int i = 1; i < (MAXV + 1); i ++){
        discovered[i] = false;
        distance[i] = std::numeric_limits<int>::max();
        parent[i] = -1;
    }
}

void dijkstra::dijkstra_shortest_path(Graph *g, int parent[], int distance[], int start){

    bool discovered[MAXV + 1];
    EdgeNode *curr;
    int v_curr;
    int v_neighbor;
    int weight;
    int smallest_dist;

    init_vars(discovered, distance, parent);

    distance[start] = 0;
    v_curr = start;

    while(discovered[v_curr] == false){

        discovered[v_curr] = true;
        curr = g->edges[v_curr];

        while(curr != NULL){

            v_neighbor = curr->key;
            weight = curr->weight;

            if((distance[v_curr] + weight) < distance[v_neighbor]){
                distance[v_neighbor] = distance[v_curr] + weight;
                parent[v_neighbor] = v_curr;
            }
            curr = curr->next;
        }

        
        smallest_dist = std::numeric_limits<int>::max();
        for(int i = 1; i < (MAXV + 1); i ++){
            if(!discovered[i] && (distance[i] < smallest_dist)){
                v_curr = i;
                smallest_dist = distance[i];
            }
        }
    }
}

void dijkstra::print_shortest_path(int v, int parent[]){
    if(v > 0 && v < (MAXV + 1) && parent[v] != -1){
        print_shortest_path(parent[v], parent);
        cout <<parent[v] <<" -> ";
    }
}

void dijkstra::print_distances(int start,  int distance[]){
    for(int i = 1; i < (MAXV + 1); i ++){
        
        if(distance[i] != std::numeric_limits<int>::max()){
            cout << "Shortest distance from " << start << " to " << i << " is: " << distance[i] << endl;   
        }

    }
}
void dijkstra::make_and_print(Graph *g,int arrive, int parent[],int start,  int distance[]){

    dijkstra_shortest_path(g, parent, distance, start);
    cout<<endl<<"Shortest Path is : ";
    print_shortest_path(arrive,parent);
    cout<<arrive<<endl<<endl;

}