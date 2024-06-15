#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
#define m 7
queue<int> Q;

typedef struct {
	int mssv;
	string name;
	float cpa;
	int visited;
} Student ;
Student students[m]={
	{1, "A", 3.4, 0},
	{2, "B", 3.6, 0},
	{3, "C", 2.9, 0},
	{4, "D", 3.0, 0},
	{5, "E", 2.7, 0},
	{6, "F", 2.6, 0},
	{7, "G", 2.9, 0} };
int graph [m][m]={
	{0,1,1,1,0,0,0},
	{0,0,0,0,1,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,0,1,1,0},
	{0,0,0,0,0,1,1},
	{0,0,0,0,0,0,0},
	{0,1,0,0,0,1,0} };
	
int visited[m];
void clear() {
	for (int i=0; i<7; i++) visited[i] = 0;
	while (!Q.empty()) Q.pop();
}

void dfs (int graph[m][m], int vertex) {
	visited[vertex]=1;
		cout<<"MSSV:"<< students[vertex].mssv <<",Name: "<< students[vertex].name <<",CPA:"<< students[vertex].cpa<< endl;
	for (int i=0; i<7; i++) {
		if (graph[vertex][i] && visited[vertex]==0)
		{ dfs (graph,i);
		}
	}

}

float bfs (int graph[m][m], int vertex) {
	int count=0;
	float totalcpa=0.0;
	visited[vertex]=1;
	Q.push(vertex);
	
	while(!Q.empty()) {
		vertex=Q.front();
		Q.pop();
	cout<<"MSSV:"<< students[vertex].mssv << ",Name:"<<students[vertex].name <<",CPA:"<< students[vertex].cpa<< endl;
	totalcpa+=students[vertex].cpa;
	count++;
	for(int i=0; i<7; i++){
	if( graph[vertex][i] && visited[i]==0)
	{ Q.push(i);
	visited[i]=1;
	}
	}
}
return cout>0? (totalcpa/count) : 0.0;

}

int main() {
	dfs(graph,0);
	clear();
	cout<<endl;
	float diemtrungbinh = bfs(graph,0);
    cout<< "diem trung binh:"<<diemtrungbinh <<endl;
   return 0;
}

