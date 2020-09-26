#include "Floyd.h"
#include <iostream>
#include <iomanip>
using namespace std;
#pragma once
void floyd(int n, int W[5][5], int D[5][5], int P[5][5])
{
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if (i == j)
				P[i][j] = 0;
			D[i][j] = W[i][j];
		}

	for (k = 0; k < n; k++)
		for (j = 0; j < n; j++)
			for (i = 0; i < n; i++) {
				if (D[i][k] + D[k][j] < D[i][j] && D[i][k] != 1000000 && D[k][j] != 1000000) {
					P[i][j] = k + 1;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
}


void printSolution(int D[5][5], int P[5][5])
{
	int setDist = 7;
	int setDist2 = 2;
	char fill = ' ';
	cout << "Final Distances" << endl;
	cout << "     ";
	for (int i = 1; i < 6; i++) {
		
		cout << setw(setDist) << setfill(fill) << i;
	}
	cout <<endl << "   -------------------------------" <<endl;
	
	for (int i = 0; i < 5; i++)
	{
		cout << "  ";
		cout << i + 1 << "| ";
		for (int j = 0; j < 5; j++)
		{
			if (D[i][j] == 1000000)
				cout <<setw(setDist2)<< setfill(fill)<<"inf" << "     ";
			else
				cout <<setw(setDist2) << setfill(fill) << D[i][j] << "     ";
		}
		cout << endl;

	}
	cout << "Final Paths " << endl;
	cout << "     ";
	for (int i = 1; i < 6; i++) {
		
		cout << setw(setDist) << setfill(fill) << i;
	}
	cout << endl << "   -------------------------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "  ";
		cout << i + 1 << "| ";
		for (int j = 0; j < 5; j++)
		{
			if (P[i][j] == 1000000)
				cout << setw(setDist2) << setfill(fill) << "inf" << "     ";
			else
				cout <<setw(setDist2) << setfill(fill)<< P[i][j] << "     ";
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
				cout <<  i + 1 << " to " << j + 1 << ": " << i + 1 << " ";
				path(P, i, j);
				cout << j + 1 << endl;
			}
		}
	}
}

void path(int P[5][5], int i, int j)
{
	if (P[i][j] == 0)
		return;

	path(P, P[i][j]-1, j);
	cout << P[i][j] << " ";
}
