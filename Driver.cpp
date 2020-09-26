#include "Floyd.h"
#include <limits>
#include <iostream>
#include <iomanip>
#pragma once
#define N 3

int P[N][N];
int D[N][N];
using namespace std;
int main() {
	int inf = 1000000;
	int W[N][N] = { {0,4,5},{2,0,inf},{inf,-3, 0} };
	//set D=W
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			D[i][j] = W[i][j];
	//print W
	int setDist = 10;
	int setDist2 = 5;
	char fill = ' ';
	cout << "Graph: " << endl;
	cout << "     1";
	for (int i = 2; i < N + 1; i++) {
		cout << setw(setDist) << setfill(fill) << i;

	}

	cout << endl << "   ---------------------------------------" << endl;
	for (int i = 0; i < size(W); i++) {
		cout << "  ";
		cout << i + 1 << "| ";
		for (int j = 0; j < size(W[0]); j++) {
			if (W[i][j] == inf) {
				cout << left << setw(setDist2) << setfill(fill) << "inf " << "     ";
			}
			else {
				cout << left << setw(setDist2) << setfill(fill) << W[i][j] << "     ";
			}
		}
		cout << endl;
	}
	floyd(N, W, D, P);
	cout << "\n";
	printSolution(D, P);
}
