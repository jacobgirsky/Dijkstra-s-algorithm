// Jacob Girsky 
// CSCI 3250
// Programming Assignment 9

#pragma once
#include <stdexcept>
#include <fstream>
#include <vector> 

class WeightedGraph
{
private:
	int mVertices;                           // Number of vertices
	std::vector<int> mGraph;                      // 1D vector of integers,
												  // mVertices * mVertices elements long

	void checkForVertexInRange(int) const;   // Checks for a vertex in range. Throws
											 // error if out of range.

public:
	WeightedGraph(int);                      // Builds a blank matrix that is m * m
											 // Set mVertices = m
											 // Sets all elements of mGraph to 0.

	bool operator==(const WeightedGraph&) const;
	// Returns true if passed graph's vertices
	// equals this graph's vertices AND
	// if every element in passed graph equals
	// every element in this graph. False otherwise.
	// Requires a loop.

	int GetNumVertices() const;              // Returns mVertices

	virtual void set(int, int, int);                 // Sets index i,j to weight
											 // First param: i
											 // Second param: j
											 // Third param: weight
											 // Check to make sure that i and j are a vertex in range

	virtual void set(int, int);                      // Calls "set(i,j,weight)" with weight=1
	int get(int, int) const;                 // Returns mGraph at cell (i,j)
											 // Check to make sure that i and j are a vertex in range

											 // This method can be written with for-loops (or without if you are clever).
	bool isSymmetric() const;                // Returns true if every elements at (i,j) is identical to (j,i)
	bool isAntisymmetric() const;            // Returns true if element at (i,j) is 1 and element (j,i)
											 // is 0 (provided that i != j)

											 // Each of these methods require a for loop
	WeightedGraph transpose() const;         // Builds a new matrix which is transpose of this matrix
	bool isReflexive() const;                // Returns true if all elements along the diagonal are > 0
	bool isTransitive() const;               // Returns true if graph is transitive. Three for loops!
	friend std::ostream& operator<<(std::ostream& os, const WeightedGraph& g); // Visualizes the graph
};


