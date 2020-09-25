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
				if (D[i][k] + D[k][j] < D[i][j]&& D[i][k] != 100 && D[k][j] !=1000000) {
					P[i][k] = P[k][j];
					D[i][j] = D[i][k] + D[k][j];
				}
			}
}

void path(int q, int r, int P[5][5])
{
	if (P[q][r] != 0) {
		path(q, P[q][r], P);
		cout << "v" << P[q][r];
		path(P[q][r], r, P);

	}
}

void printSolution(int D[5][5])
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (D[i][j] == 1000000)
					cout << "inf" << "     ";
				else
					cout << D[i][j] << "     ";
			}
			cout << endl;
		}
	}

