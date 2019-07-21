#include "inputData.h"
#include <fstream>
#include "Graph.h"
using namespace std;

#define MAXV 300

InputData::InputData(Graph* g){
	setGraph(g);
}
string InputData::getInfoPath(int x, int y){
	return InfoPath[x][y];
}
void InputData::setInfoPath(int x, int y, string data){
	InfoPath[x][y] = data;
}

Graph* InputData::getGraph(){
	return graph;
}
void InputData::setGraph(Graph *g){
	graph = g;
}
string InputData::getExistDataCountSum(){
	return existDataCountSum;
}
void InputData::setExistDataCountSum(string data){
	existDataCountSum = data;
}

void InputData::readFileInfo(string s){
	fstream inFile;
	inFile.open(s);
	
	getline(inFile,existDataCountSum,'\n');
	for(int i =0;i< stoi(getExistDataCountSum()); i++){
		
		for(int j = 0; j<3; j++){
			getline(inFile,InfoPath[i][j],',');
		}
		getline(inFile,InfoPath[i][3],'\n');
	}
	inFile.close();
}
void InputData::inputDataToGraph(){
	Graph *g = getGraph();
	for(int i = 0; i<stoi(getExistDataCountSum());i++){
		g->insert_edge(stoi(getInfoPath(i,0)),stoi(getInfoPath(i,1)),stoi(getInfoPath(i,2)),!getInfoPath(i,3).compare("TRUE"));
	}
}
void InputData::writeFile(){
	ofstream outFile;
	remove("data.txt");
	outFile.open("data.txt");
	outFile<<getExistDataCountSum()<<endl;
	for(int i=0; i<stoi(getExistDataCountSum()); i++){
		for(int j=0; j<3; j++){
			outFile<<getInfoPath(i,j)<<',';
		}
		outFile<<getInfoPath(i,3)<<'\n';
	}
	outFile.close();
}
void InputData::addData(int x,int y, int w, string status){
	setExistDataCountSum(to_string(stoi(getExistDataCountSum())+1));
	setInfoPath(stoi(getExistDataCountSum())-1,0,to_string(x));
	setInfoPath(stoi(getExistDataCountSum())-1,1,to_string(y));
	setInfoPath(stoi(getExistDataCountSum())-1,2,to_string(w));
	setInfoPath(stoi(getExistDataCountSum())-1,3,status);
}
void InputData::deleteEdge(int x, int y){
	string temp[MAXV][4];
	int tempI=-1;
	if(stoi(getExistDataCountSum())>0){
		for(int i =0; i<stoi(getExistDataCountSum());i++){
			if(!getInfoPath(i,0).compare(to_string(x))&&!getInfoPath(i,1).compare(to_string(y))){
				tempI = i;
			}
		}
		cout<<tempI<<endl;
		if(tempI==-1){
			cout<<"Error : No Exist Edge";
			return;
		}
		for(int i = 0; i<stoi(getExistDataCountSum())-tempI-1;i++){
			for(int j=0;j<4;j++){
				temp[i][j]=getInfoPath(i+tempI+1,j);
			}
		}
		for(int i=0; i<stoi(getExistDataCountSum())-tempI-1;i++){
			for(int j =0;j<4;j++){
				setInfoPath(i,j,temp[i][j]);
			}
		}
		setExistDataCountSum(to_string(stoi(getExistDataCountSum())-1));
	}
	else{
		cout<<"Error : No Exist Edge";
		return;
	}
	
}