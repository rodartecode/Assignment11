# Assignment11
Dijksta's algorithm
CS 110C Assignment 11: CS Air

City College of San Francisco

Instructor: Max Luttrell

Spring 2018


For this assignment, you will implement Dijkstra’s algorithm in order to determine the cheapest flights from San Francisco to other cities for a fictitious airline, CS Airlines.


Consider the following map of available flights on CS Airlines.  Each vertex has a name and an index, e.g. SFO has index 0, LAX has vertex 1, etc.  Each edge has a weight which is the cost of a ticket between the two cities.


MISSING PICTURE


We can represent this map as an adjacency matrix:

  { 
	{ 0, 120, 150, -1, -1, 500 },
	{ 120, 0 - 1, 75, -1, 350 },
	{ 150, -1, 0, -1, 250, -1 },
	{ -1, 75, -1, 0, 150, -1 },
	{ -1, -1, 250,  150, 0, -1},
	{ 500, 350, -1, -1, -1, 0} 
	}



Design and implement a C++ class to represent this graph using an adjacency matrix.  In addition to storing the adjacency matrix, your class should include a method which uses Dijkstra’s algorithm in order to compute and print out the cheapest cost from San Francisco (vertex 0) to each other city.  It may help you debug to print out the weight array, v, and vertex set for each iteration of the algorithm.


You do not need to provide methods for the standard graph operations, e.g. to add/remove vertices and edges.  You may use any work you’ve done on previous assignments, e.g. your List, you may modify your List to fit this problem, or you may come up with your own solution from scratch.
