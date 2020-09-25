#include "Floyd.h"
#include <iostream>
using namespace std;
#pragma once
void floyd(int n, int W[5][5], int D[5][5], int P[5][5])
{
	int i, j, k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			P[i][j] = 0;
	for (int u = 0; u < 5; u++)
		for (int t = 0; t < 5; t++)
			D[u][t] = W[u][t];

	for(k = 1; k<=n; k++)
		for(j = 1; j<=n; j++)
			for(i = 1; i<=n; i++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
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
