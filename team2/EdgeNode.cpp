#include <iostream>
#include "EdgeNode.h"

using namespace std;

EdgeNode::EdgeNode(int key, int weight){
    this->key = key;
    this->weight = weight;
    this->next = NULL;
}