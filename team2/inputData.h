#ifndef INPUTDATA_H
#define INPUTDATA_H
#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

#define MAXV 300
class InputData{

	protected:
		string InfoPath[MAXV][4];//파일을 읽어 임시적으로 데이터를 저장할 배열
        Graph *graph;
        string existDataCountSum;
	public:
        InputData(Graph *g);
        Graph* getGraph();
        void setGraph(Graph *g);
		string getInfoPath(int x,int y);
        void setInfoPath(int x, int y, string data);
        string getExistDataCountSum();
        void setExistDataCountSum(string data);
		void readFileInfo(string s);//외부 파일을 읽어옴
		void inputDataToGraph();//외부에서 읽어온 데이터를 이용해 graph의 insertEdge를 호출
        void writeFile();
        void addData(int x, int y, int w, string status);
        void deleteEdge(int x, int y);
};
#endif
