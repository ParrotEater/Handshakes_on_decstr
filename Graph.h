#pragma once
#define SIZE 10
#define VERYBIGINT 1000000000 // очень большое число
#include <iostream>

class Graph 
{
	public:
		Graph();
		void AddVertex(int vnumber, std::string name);
		void addEdge(int v1, int v2, int weight = 1);		
		void findMinDistanceDecstr(int fromVert);
		bool edgeExists(int v1, int v2);
		bool vertexExists(int vnumber);

private:	
	int matrix[SIZE][SIZE];
	int vertexes[SIZE];
	std::string names[SIZE];
	int vertexCount;
};
