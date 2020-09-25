#include "Floyd.h"
#include <iostream>
using namespace std;
#pragma once
void floyd(int n, int W[5][5], int D[5][5], int P[5][5])
{
	int i, j, k;
	for (i = 0; i <n; i++)
		for (j = 0; j < n; j++) {
			if (i == j)
				P[i][j] = 0;
			D[i][j] = W[i][j];
		}

	for(k = 0; k<n; k++)
		for(j = 0; j<n; j++)
			for (i = 0; i < n; i++) {
				if (D[i][k] + D[k][j] < D[i][j]&& D[i][k] != 1000000 && D[k][j] !=1000000) {
					P[i][j] = k+1;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
}


void printSolution(int D[5][5], int P[5][5])
	{
	cout << "Final Distances" << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (D[i][j] == 1000000)
					cout  <<"inf" << "     ";
				else
					cout << D[i][j] << "     ";
			}
			cout << endl;
			
		}
		cout << "Final Paths " << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (P[i][j] == 1000000)
					cout << "inf" << "     ";
				else
					cout << P[i][j] << "     ";
			}
			cout << endl;
		}
		cout << "Shortest Paths: Decoded " << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (j != i && P[i][j] != -1)
				{
					cout << "From vertex " << i + 1 << " to vertex " << j + 1 << ": " << i + 1 << " ";
					path(P, i, j);
					cout << j + 1 << endl;
				}
			}
		}
	}

void path(int P[5][5], int i, int j)
{
	if (P[i][j] != 0) {
		path(P, i, P[i][j]);
		cout << "v " << P[i][j];
		path(P, P[i][j], j);
	}
}

