#include<iostream>
#include<string>
#include "AppView.h"

using namespace std;

void AppView::output(string aString){
    cout << aString << endl;
}

void AppView::outputLine(string aString){
    cout << aString << endl;
}

int AppView::inputHeadVertex(){
    int headVertex;
    int scannedToken;
    while(true){
        this->output("? input head vertex : ");
        scanf("%d", &scannedToken);
        
        headVertex = scannedToken;
        return headVertex;
    }
    return 0;
}

int AppView::inputTailVertex(){
    int tailVertex;
    int scannedToken;
    while(true){
        this->output("? input tail vertex : ");
        scanf("%d", &scannedToken);

        tailVertex = scannedToken;
        return tailVertex;
    }
}



   
    
  
