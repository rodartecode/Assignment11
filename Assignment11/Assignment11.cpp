// Assignment11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static const int COLUMNS = 6;

void dijkstra(int graph[][COLUMNS], int weights[])
{

}

int main()
{
	int weightArray[6];

	int weightMatrix[COLUMNS][COLUMNS] =
	{ 
	{ 0, 120, 150, -1, -1, 500 },
	{ 120, 0 - 1, 75, -1, 350 },
	{ 150, -1, 0, -1, 250, -1 },
	{ -1, 75, -1, 0, 150, -1 },
	{ -1, -1, 250,  150, 0, -1},
	{ 500, 350, -1, -1, -1, 0} 
	};



    return 0;
}

