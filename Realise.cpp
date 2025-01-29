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

/*��� ��������, ���������� �� �������, ����� ���������, ���� �� �� ����� � ������� vertexes.*/
bool Graph::vertexExists(int vnumber)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == vnumber)
            return true;
    return false;
}

void Graph::findMinDistanceDecstr(int fromVert)
{
    int distances[SIZE]; // ������ �����
    for (int i = 0; i < SIZE; i++) // ������������� �����
    {
        distances[i] = VERYBIGINT;
    }
    distances[fromVert] = 0;

    bool passed[SIZE]; // �������, ��� ������� ��������
    for (int i = 0; i < SIZE; i++)
    {
        passed[i] = false; // ��� ���������� ����������
    }
    // ��������� ��������� ������� �� �������
    int currentVertexNum = fromVert;
    int min_dist = 0;
    while (min_dist != VERYBIGINT)
    {
        passed[currentVertexNum] = true; // ���������� �������

        for (int i = 0; i < SIZE; i++)
        {
            // ��� ������� ����� ������������� �����
            if (edgeExists(currentVertexNum, i)
                && distances[currentVertexNum] + matrix[currentVertexNum][i] < distances[i])
                distances[i] = distances[currentVertexNum] + matrix[currentVertexNum][i];
        }
        min_dist = VERYBIGINT;
        for (int i = 0; i < SIZE; i++)
        {
            // �������� ����� ������� �������
            if (vertexExists(i) && !passed[i] && distances[i] < min_dist) // ����� ����� �������
            {
                min_dist = distances[i];
                currentVertexNum = i;
            }
        }
    }
    std::cout << names[fromVert] << " ������ �: ";
    for (int i = 0; i < vertexCount; i++) // ����� ����������
    {
        if(distances[i] != 0 && distances[i] < 4)
            //std::cout << "V" << i << ": " << distances[vertexes[i]] << ", ";
            std::cout << names[vertexes[i]] << ", ";
    }
    std::cout << std::endl;
}