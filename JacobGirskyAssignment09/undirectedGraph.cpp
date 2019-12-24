// Jacob Girsky 
// CSCI 3250
// Programming Assignment 9

#include "undirectedGraph.h"
#include <iostream>

/*
* WeightedGraph() - default constructor 
* @params - int mVerticies - the number of verticies
* precondition - none
* postcondition - none
*/
UndirectedGraph::UndirectedGraph(int mVertices) : WeightedGraph(mVertices)
{
}

/*
* set(int, int, int) - sets the element in the vector
* @params - i, j, weight - the vertexes
* precondition - none
* postcondition - the element is set
*/
void UndirectedGraph::set(int i, int j, int weight)
{
	WeightedGraph::set(i, j, weight);
	WeightedGraph::set(j, i, weight);
}


/*
* set(int, int) - calls set(i, i, i)
* @params - i, j - the vertexes
* precondition - none
* postcondition - the element is set
*/
void UndirectedGraph::set(int i, int j)
{
	set(i, j, 1);
}

/*
* dijkstra(int, int) - returns the shortest path from start to finish
* @params - int start, int finish - the starting vertex and the ending vertex
* precondition - none
* postcondition - none
*/
LinkedList<int> UndirectedGraph::dijkstra(int start, int finish) const
{
	
	int numVerticies = GetNumVertices();

	int *distances = new int[numVerticies];
	int *previous = new int[numVerticies];
	bool *unreached = new bool[numVerticies];

	for (int i = 0; i < numVerticies; i++) 
	{
		distances[i] = INT_MAX;
		previous[i] = -1;
		unreached[i] = true;
	}

	distances[start] = 0;
	int unreachedCount = numVerticies;

	while (unreachedCount > 0) {
		int vertex = 0;
		int min = INT_MAX;

		for (int v = 0; v < GetNumVertices(); v++) 
		{
			if (unreached[v] == true && distances[v] < min) 
			{
				vertex = v;
				min = distances[v];
			}
		}

		unreached[vertex] = false;
		unreachedCount--;

		for (int v = 0; v < numVerticies; v++) 
		{
			if (get(vertex, v) > 0 && get(vertex, v) + distances[vertex] < distances[v]) 
			{
				distances[v] = get(vertex, v) + distances[vertex];
				previous[v] = vertex;
			}
		}
	}

	LinkedList<int> list;
	int vertex = finish;
	while (vertex != -1) 
	{
		list.push_front(vertex);
		vertex = previous[vertex];
	}

	delete[] distances, previous, unreached;

	return list;

}
