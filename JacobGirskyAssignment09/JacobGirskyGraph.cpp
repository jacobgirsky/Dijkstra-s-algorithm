// Jacob Girsky 
// CSCI 3250
// Programming Assignment 9

#include <iostream>
#include <string>
#include "undirectedGraph.h"


int main() {

	int numVerticies, numEdges, startingVertex, endingVertex, weight;
	std::string name[25];

	std::cout << "Number of verticies in our matrix: ";
	std::cin >> numVerticies;

	UndirectedGraph graph(numVerticies);

	for (int i = 0; i < numVerticies; i++) {
		std::cout << "Enter the name of place " << i << ": ";
		std::cin >> name[i];
	}

	std::cout << "Number of edges in our matrix: ";
	std::cin >> numEdges;

	for (int i = 0; i < numEdges; i++) {
		std::cout << "Enter a starting vertex number: ";
		std::cin >> startingVertex;
		std::cout << "Enter a ending vertex number: ";
		std::cin >> endingVertex;
		std::cout << "Enter a weight: ";
		std::cin >> weight;
		graph.set(startingVertex, endingVertex, weight);
	}

	int startNum, endNum;

	std::cout << "Enter a starting location vertex number: ";
	std::cin >> startNum;

	std::cout << "Enter a ending location vertex number: ";
	std::cin >> endNum;

	std::cout << std::endl;

	std::cout << "Verticies :" << std::endl;
	for (int i = 0; i < numVerticies; i++) {
		std::cout << i << ": " << name[i] << std::endl;
	}

	std::cout << "Original Graph:\n";
	operator<<(std::cout, graph);

	std::cout << std::endl;

	std::cout << "Path from " << name[startNum] << " to " << name[endNum] << "." << std::endl;

	LinkedList<int> list = graph.dijkstra(startNum, endNum);

	for (int i = 0; i < list.size(); i++) {
		std::cout << i + 1 << ": " << name[list.at(i)] << std::endl;
	}

	int sum = 0;
	for (int i = 1; i < list.size(); i++) {
		sum += graph.get(list.at(i - 1), list.at(i));
	}

	std::cout << std::endl;

	std::cout << "Distance: " << sum << std::endl;
	std::cout << "Done: ";

	std::cin.get();
	std::system("pause");
	std::cin.ignore();
	return 0;
}