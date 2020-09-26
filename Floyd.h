#pragma once
#define N 3
void floyd(int n, int W[N][N], int D[N][N], int P[N][N]);
void printSolution(int D[N][N], int P[N][N]);
void path(int P[N][N], int i, int j);
