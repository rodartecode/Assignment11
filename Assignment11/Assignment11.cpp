// Assignment11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <limits>
#include <iostream>

using namespace std;

static const int COLUMNS = 6;
static const int INF = numeric_limits<int>::max();






class Graph
{
private:
	int adjArray[COLUMNS][COLUMNS];
	int weightArray[COLUMNS];

public:
	Graph()
	{
	}

	Graph(int newAdjArray[COLUMNS][COLUMNS], int newWeightArray[COLUMNS])
	{
		for (int i = 0; i < COLUMNS; i++)
		{
			for (int j = 0; j < COLUMNS; j++)
			{
				adjArray[i][j] = newAdjArray[i][j];
			}
		}

		for (int k = 0; k < COLUMNS; k++)
		{
			weightArray[k] = newWeightArray[k];
		}
	}

	~Graph()
	{
	}

	int sum(int left, int right)
	{
		int result = left + right;
		if (result < 0)
			result = INF;
		return result;
	}

	void dijkstra()
	{
		LinkedList<int>* vectors = new LinkedList<int>();

		vectors->insert(0);

		for (int v = 0; v < COLUMNS; v++)
		{
			weightArray[v] = adjArray[0][v];
		}
		cout << "INITIALLY: \n\n";
		for (int i = 0; i < COLUMNS; i++)
		{
			cout << weightArray[i] << "\t";
		}
		cout << endl << endl;

		cout << "THEN: \n\n";

		for (int step = 1; step < COLUMNS; step++)
		{
			int v = smallestVector(vectors, weightArray);
			vectors->insert(v);

			for (int u = 0; u < COLUMNS; u++)
			{
				if (!vectors->contains(u))
				{
					if (weightArray[u] > sum(weightArray[v], adjArray[v][u]))
						weightArray[u] = sum(weightArray[v], adjArray[v][u]);
				}
			}

			for (int i = 0; i < COLUMNS; i++)
			{
				cout << weightArray[i] << "\t";
			}
			cout << endl << endl;
		}

		cout << "FINALLY: \n\n";
		for (int i = 0; i < COLUMNS; i++)
		{
			cout << weightArray[i] << "\t";
		}
		cout << endl << endl;
	}

	int smallestVector(LinkedList<int>* vectors, int weightArray[])
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
			if (weightArray[i] < weightArray[smallestIndex] && !vectors->contains(i))
			{
				smallestIndex = i;
			}
		}

		return smallestIndex;
	}
};

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

	Graph aGraph(weightMatrix, weightArray);

	aGraph.dijkstra();

    return 0;
}


/*

EXPECTED OUTPUT:

INITIALLY:

2147483647      120     150     2147483647      2147483647      500

THEN:

2147483647      120     150     195     2147483647      470

2147483647      120     150     195     400     470

2147483647      120     150     195     345     470

2147483647      120     150     195     345     470

2147483647      120     150     195     345     470

FINALLY:

2147483647      120     150     195     345     470

*/

