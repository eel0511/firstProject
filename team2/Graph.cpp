#include "Graph.h"
#include "Matrix.h"
#include <iostream>
#include <limits>
using namespace std;

#define MAXV 300

int dist[MAXV][MAXV];

Graph::Graph(bool directed){
    this->directed = directed;
    for(int i = 1; i < (MAXV + 1); i ++){
        this->edges[i] = NULL;
    }
}
void Graph::Array(EdgeNode *curr,Matrix<int> dist){
    for(int v = 1; v < (MAXV + 1); v ++){
        if(this->edges[v] != NULL){
            
            curr = this->edges[v];
            while(curr != NULL){
                
                dist[v][curr->key] = curr->weight;
                curr = curr->next;
            }
            
           
        }
        
    }
}

Graph::~Graph(){
   
}

void Graph::insert_edge(int x, int y, int weight, bool directed){
    if(x > 0 && x < (MAXV + 1) && y > 0 && y < (MAXV + 1)){
        EdgeNode *edge = new EdgeNode(y, weight);
        edge->next = this->edges[x];
        this->edges[x] = edge;
        if(!directed){
            insert_edge(y, x, weight, true);
        }
    }
}

void Graph::print(){
    for(int v = 1; v < (MAXV + 1); v ++){
        if(this->edges[v] != NULL){
            cout << "Vertex " << v << " has neighbors: ";
            EdgeNode *curr = this->edges[v];
            while(curr != NULL){
                cout << curr->key<<" ";
                curr = curr->next;
            }
            cout<<endl;
           
        }
        
    }
}