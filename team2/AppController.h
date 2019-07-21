#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H
#include<iostream>
#include "AppController.h"
#include "AppView.h"
#include "dijkstra.h"
#include "inputData.h"
#include "flo.h"




using namespace std;

class AppController{

    public:
    void setGraph(Graph* g);
    Graph* getGraph();
    void setDijkstra (dijkstra dij);
    dijkstra getDijkstra();
    void run();
    void setFlo(flo f);
    flo getFlo();
    AppController();
    void fileuse(string s);
    void nofileuse();
    int inputStart();
    int inputArrive();
    void inputAndMake();
   void supprot_print_flo(Matrix<int> n,int start,int arrive);
    private:
    Graph* graph;
    dijkstra dij;
    flo fl;
   

};
#endif