#ifndef EDGENODE_H
#define EDGENODE_H
#include <iostream>

using namespace std;

class EdgeNode{
    public:
        int key;
        int weight;
        EdgeNode *next;
        EdgeNode(int, int);
};
#endif
