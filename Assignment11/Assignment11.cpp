// Assignment11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <limits>
#include <iostream>

using namespace std;

static const int COLUMNS = 6;
static const int INF = numeric_limits<int>::max();

int smallestVector(LinkedList<int>* vectors, int weights[])
{
	bool found = false;
	int smallestIndex = 0;
	while (found == false)
	{
		if (!vectors->contains(smallestIndex))
			found = true;
		else
			smallestIndex++;
	}

	for (int i = smallestIndex; i < COLUMNS; i++)
	{
		if (weights[i] < weights[smallestIndex] && !vectors->contains(i))
		{
			smallestIndex = i;
		}
	}

	return smallestIndex;
}

void dijkstra(int matrix[][COLUMNS], int weights[])
{
	LinkedList<int>* vectors = new LinkedList<int>();

	vectors->insert(0);

	for (int v = 0; v < COLUMNS; v++)
	{
		weights[v] = matrix[0][v];
	}
	for (int i = 0; i < COLUMNS; i++)
	{
		cout << weights[i] << "\t";
	}

	cout << endl << endl;

	for (int step = 1; step < COLUMNS; step++)
	{
		int v = smallestVector(vectors, weights);
		vectors->insert(v);

		for(int u = 0; u < COLUMNS; u++)
			if (!vectors->contains(u))
			{
				if (weights[u] > weights[v] + matrix[v][u])
					weights[u] = weights[v] + matrix[v][u];
			}
	}

	for (int i = 0; i < COLUMNS; i++)
	{
		cout << weights[i] << "\t";
	}

	cout << endl << endl;
}

int main()
{
	int weightArray[COLUMNS];

	int weightMatrix[COLUMNS][COLUMNS] =
	{ 
	{ INF, 120, 150, INF, INF, 500 },
	{ 120, INF, INF, 75, INF, 350 },
	{ 150, INF, INF, INF, 250, INF },
	{ INF, 75, INF, INF, 150, INF },
	{ INF, INF, 250,  150, INF, INF},
	{ 500, 350, INF, INF, INF, INF} 
	};

	dijkstra(weightMatrix, weightArray);

    return 0;
}

