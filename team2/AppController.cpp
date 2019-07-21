#include <iostream>
#include <string>
#include "AppController.h"


#define MAXV 300

using namespace std;


void AppController::setGraph(Graph *g){
    graph = g;
}
Graph* AppController::getGraph(){
    return graph;
}
void AppController::setDijkstra(dijkstra d){
    dij = d;
}
dijkstra AppController::getDijkstra(){
    return dij;
}
void AppController::setFlo(flo f){
    fl = f;
}
flo AppController::getFlo(){
    return fl;
}
void AppController::run(){
    AppView view;
   int x;
    view.outputLine("<< want use txt file? yes :1 No : 2 >>");
    cin>>x;
    
    
    if(x == 1){
        this->fileuse("");
        
    }
    else{
       this->nofileuse();
    }

    
    
    view.outputLine("<<End of shortest path algorithms>>");
}

void AppController::inputAndMake(){
    int parent[MAXV + 1];
    int distance[MAXV + 1];
     Matrix<int> n(MAXV,MAXV);
     Matrix<int> dist(MAXV,MAXV);
    int start;
    int arrive;

    start=this->inputStart();
    arrive=this->inputArrive();
    
     cout<<endl<<"floyd Shortest Path is : "<<start;
            
        this->supprot_print_flo(getFlo().make_flo(getGraph(),start,arrive),start,arrive);

            cout<<" -> "<<arrive<<endl;
            dij.make_and_print(getGraph(),arrive,parent,start,distance);

            setGraph(NULL);
}
void AppController::supprot_print_flo(Matrix<int> n,int start,int arrive){


    if(n[start][arrive]!=0){
        this->supprot_print_flo(n,start,n[start][arrive]);
        cout<<" -> "<<n[start][arrive];
        this->supprot_print_flo(n,n[start][arrive],arrive);
    }
}

    

AppController::AppController(){
    dijkstra dij;
    flo flo;
    setGraph(new Graph(false));
    setDijkstra(dij);
    setFlo(flo);
}
void AppController::fileuse(string s){
   
    
    cout<<"Input Filename"<<endl;
    cin>>s;
    InputData *inp = new InputData(getGraph());
    

    
    inp->readFileInfo(s);
    inp->inputDataToGraph();
    
    
   
    this->inputAndMake();
   
   
}
void AppController::nofileuse(){
    int parent[MAXV + 1];
    int distance[MAXV + 1];
    int start;
    int arrive;

    getGraph()->insert_edge(1, 2, 110, false);
    getGraph()->insert_edge(2, 3, 115, false);
    getGraph()->insert_edge(3, 4, 74, false);
    getGraph()->insert_edge(4, 5, 121, false);
    getGraph()->insert_edge(5, 6, 39, false);
    getGraph()->insert_edge(6, 7, 103, false);
    getGraph()->insert_edge(6, 8, 67, false);
    getGraph()->insert_edge(8, 1, 222, false);

    cout<<"I have this graph"<<endl;
    getGraph()->print();
    

    
 
    this->inputAndMake();

    setGraph(NULL);

    
}
int AppController::inputStart(){
    AppView view;

    int start = view.inputHeadVertex();
    return start;
}
int AppController::inputArrive(){
    AppView view;
    int arrive = view.inputTailVertex();
    return arrive;
}