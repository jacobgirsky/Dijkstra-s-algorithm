// Jacob Girsky 
// CSCI 3250
// Programming Assignment 9

#include "weightedGraph.h"
#include <iostream>
#include <stdexcept>

/*
* checkForVertexInRange() - throws error if vertex is out of range
* @params - value - the values being evaluated
* precondition - none
* postcondition - none
*/
void WeightedGraph::checkForVertexInRange(int value) const
{
	if (value < 0 || value >= mVertices) {
		throw std::logic_error("Vertex out of range.");
	}
}

/*
* WeightedGraph() - default constructor that sets the vector and assigns all values to 0
* @params - number of elements
* precondition - none
* postcondition - none
*/
WeightedGraph::WeightedGraph(int m)
{
	const int capacity = m * m;
	mVertices = m;
	mGraph.resize(capacity);

	for (int i = 0; i < capacity; i++)
	{
		mGraph[i] = 0;
	}
}

/*
* operator== -  Returns true if passed graph's vertices
equals this graph's vertices and if every element in passed graph equals every element in this graph
* @params - graph object
* precondition - none
* postcondition - none
*/
bool WeightedGraph::operator==(const WeightedGraph &graph) const
{
	if (graph.mVertices == mVertices) {
		for (int i = 0; i < mVertices * mVertices; i++)
			if (graph.mGraph[i] == mGraph[i])
			{
				return true;
			}
	}
	return false;
}


/*
* getNumVerticies() - returns number of verticies
* @params - none
* precondition - none
* postcondition - none
*/
int WeightedGraph::GetNumVertices() const
{
	return mVertices;
}

/*
* set(int, int, int) - sets the element in the vector
* @params - i, j, weight - the vertexes
* precondition - none
* postcondition - the element is set
*/
void WeightedGraph::set(int i, int j, int weight)
{
	checkForVertexInRange(i);
	checkForVertexInRange(j);
	mGraph[i * mVertices + j] = weight;
}

/*
* set(int, int) - calls set(i, i, i)
* @params - i, j - the vertexes
* precondition - none
* postcondition - the element is set
*/
void WeightedGraph::set(int i, int j)
{
	checkForVertexInRange(i);
	checkForVertexInRange(j);
	set(i, j, 1);
}

/*
* get(int, int) -  returns the element in the vector
* @params - i, j - the vertexes
* precondition - none
* postcondition - none
*/
int WeightedGraph::get(int i, int j) const
{
	checkForVertexInRange(i);
	checkForVertexInRange(j);
	return mGraph[i * mVertices + j];
}

/*
* isSymmetric() - returns true if the graph is symmetric
* @params - none
* precondition - none
* postcondition - none
*/
bool WeightedGraph::isSymmetric() const
{
	for (int i = 0; i < mVertices; i++)
	{
		for (int j = 0; j < mVertices; j++)
		{
			if (get(i, j) != get(j, i))
				return false;
		}
	}
	return true;
}

/*
* isAntisymmetric() - returns true if the graph is antisymmetric
* @params - none
* precondition - none
* postcondition - none
*/
bool WeightedGraph::isAntisymmetric() const
{
	for (int i = 0; i < mVertices; i++)
	{
		for (int j = i + 1; j < mVertices; j++)
		{
			if (get(i, j) == 1 && get(j, i) == 1)
				return false;
		}
	}
	return true;
}

/*
* transpose() - returns the transpose of the graph
* @params - none
* precondition - none
* postcondition - none
*/
WeightedGraph WeightedGraph::transpose() const
{
	WeightedGraph tra(mVertices);
	for (int i = 0; i < mVertices; i++)
	{
		for (int j = 0; j < mVertices; j++)
		{
			tra.set(j, i, get(i, j));
		}
	}
	return tra;
}

/*
* isSymmetric() - returns true if the graph is reflexive
* @params - none
* precondition - none
* postcondition - none
*/
bool WeightedGraph::isReflexive() const
{
	for (int i = 0; i < mVertices; i++)
	{
		if (get(i, i) == 0)
		{
			return false;
		}
	}
	return true;
}

/*
* isSymmetric() - returns true if the graph is transitive
* @params - none
* precondition - none
* postcondition - none
*/
bool WeightedGraph::isTransitive() const
{
	for (int i = 0; i < mVertices; i++)
	{
		for (int j = 0; j < mVertices; j++)
		{
			for (int k = 0; k < mVertices; k++)
			{
				if (get(i, j) == get(i, j) || (get(i, k) && get(k, i)))
					return true;
			}
		}
	}
	return false;
}

/*
* operator<< - allows us to pring out the transpose of the graph
* @params - os, g - the os stream and the graph object
* precondition - none
* postcondition - none
*/
std::ostream & operator<<(std::ostream & os, const WeightedGraph & g)
{
	for (int i = 0; i < g.mVertices; i++)
	{
		for (int j = 0; j < g.mVertices; j++)
		{
			os << g.get(i, j) << " ";
		}
		std::cout << std::endl;
	}
	return os;
}
