#include "Graph.h"
#include <iostream>


Graph::Graph()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = 0;
	vertexCount = 0;	
}
void Graph::AddVertex(int vnumber, std::string name)
{
	vertexes[vertexCount] = vnumber;
	names[vertexCount] = name;
    vertexCount++;
}
void Graph::addEdge(int v1, int v2, int weight)
{
	matrix[v1][v2] = weight;
	matrix[v2][v1] = weight;
}

bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] != 0;
}

/*Для проверки, существует ли вершина, нужно проверить, есть ли ее номер в массиве vertexes.*/
bool Graph::vertexExists(int vnumber)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == vnumber)
            return true;
    return false;
}

void Graph::findMinDistanceDecstr(int fromVert)
{
    int distances[SIZE]; // массив меток
    for (int i = 0; i < SIZE; i++) // инициализация меток
    {
        distances[i] = VERYBIGINT;
    }
    distances[fromVert] = 0;

    bool passed[SIZE]; // признак, что вершина окрашена
    for (int i = 0; i < SIZE; i++)
    {
        passed[i] = false; // все неокрашены изначально
    }
    // принимаем стартовую вершину за текущую
    int currentVertexNum = fromVert;
    int min_dist = 0;
    while (min_dist != VERYBIGINT)
    {
        passed[currentVertexNum] = true; // окрашиваем текущую

        for (int i = 0; i < SIZE; i++)
        {
            // для смежных ребер пересчитываем метки
            if (edgeExists(currentVertexNum, i)
                && distances[currentVertexNum] + matrix[currentVertexNum][i] < distances[i])
                distances[i] = distances[currentVertexNum] + matrix[currentVertexNum][i];
        }
        min_dist = VERYBIGINT;
        for (int i = 0; i < SIZE; i++)
        {
            // выбираем новую текущую вершину
            if (vertexExists(i) && !passed[i] && distances[i] < min_dist) // выбор новой вершины
            {
                min_dist = distances[i];
                currentVertexNum = i;
            }
        }
    }
    std::cout << names[fromVert] << " знаком с: ";
    for (int i = 0; i < vertexCount; i++) // вывод результата
    {
        if(distances[i] != 0 && distances[i] < 4)
            //std::cout << "V" << i << ": " << distances[vertexes[i]] << ", ";
            std::cout << names[vertexes[i]] << ", ";
    }
    std::cout << std::endl;
}