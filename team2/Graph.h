#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <limits>
#include "EdgeNode.h"
#include "Matrix.h"
using namespace std;

#define MAXV 300

class Graph{
    bool directed;
    public:
        EdgeNode *edges[MAXV + 1];
        Graph(bool);
        ~Graph();
        void insert_edge(int, int, int, bool);
        void print();
        void Array(EdgeNode *,Matrix<int>);
};
#endif

