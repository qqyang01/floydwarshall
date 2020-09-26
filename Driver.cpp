#include "Floyd.h"
#include <limits>
#include <iostream>
#include <iomanip>
#pragma once

int P[5][5];
int D[5][5];
using namespace std;
int main() {
	int inf = 1000000;
	int W[5][5] = { {0,1, inf,1,5},{9,0,3,2,inf},{inf, inf, 0,4,inf},{inf,inf,2,0,3},{3,inf,inf,inf, 0} };
	//set D=W
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			D[i][j] = W[i][j];
	//print W
	int setDist = 7;
	int setDist2 = 5;
	char fill = ' ';
	cout << "Graph: " << endl;
	cout << "     1         2         3         4         5";

	cout << endl << "   ---------------------------------------" << endl;
	for (int i = 0; i < size(W); i++) {
		cout << "  ";
		cout << i + 1 << "| ";
		for (int j = 0; j < size(W[0]); j++) {
			if (W[i][j] == inf) {
				cout <<left << setw(setDist2) << setfill(fill) << "inf " << "     ";
			}
			else {
				cout << left <<setw(setDist2) << setfill(fill) << W[i][j] << "     ";
			}
		}
		cout << endl;
	}
	floyd(5, W, D, P);
	cout << "\n";
	printSolution(D, P);
}
