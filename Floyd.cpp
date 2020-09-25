#include "Floyd.h"
#pragma once
void floyd(int n, int W[][100], int D[][100], int P[][100])
{
	int i, j, k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			P[i][j] = 0;
	D = W;

	for(k = 1; k<=n; k++)
		for(j = 1; j<=n; j++)
			for(i = 1; i<=n; i++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
}
