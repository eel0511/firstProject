#include <iostream>
#include <stack>
#include "flo.h"
#include "inputData.h"
#include "Matrix.h"
using namespace std;

#define MAXV 300
#define MAX_INT 100000000


Matrix<int> flo::make_flo( Graph *g,int start,int distance){
   
    EdgeNode *curr;
    stack<int> s;
  int cont = MAXV;
  int v_curr;
  int v_neighbor;
  Matrix<int> dist(MAXV,MAXV);
  Matrix<int> n(MAXV,MAXV);
  int v;

  for(int a=0;a<MAXV;a++){
      for(int b=0;b<MAXV;b++){
          dist[a][b] = MAX_INT;
      }
  }
   
  
    g->Array(curr,dist);
   
    

 for(int k=1; k<cont; k++){
        for(int i=1; i<cont; i++){
            for(int j=1; j<cont; j++){

                
                if(dist[i][j] > min(dist[i][j], dist[i][k]+dist[k][j])){
            
                   n[i][j]=k;
      
                }
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
               
            }
             
        }
       
    }
    return n;
   /* for(int i=1; i<cont; i++){    for debug
            cout<<endl;
            cout<<"start ";
            for(int j=1; j<cont; j++){
               
                cout<<"\t"<<n[i][j];
                }
            }
     */
}
    

