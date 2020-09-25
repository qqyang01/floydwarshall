#include "Floyd.h"
#include <limits>
#pragma once
int P[5][5];
int D[5][5];
using namespace std;
int main() {
	int inf = std::numeric_limits<int>::max();
	int W[5][5] = { {0,1,inf,1,5},{9,0,3,2,inf},{inf,inf, 0,4,inf},{inf,inf,2,0,3},{3,inf,inf,inf,0} };
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			D[i][j] = W[i][j];
	floyd(5, W, D, P);
	path(0, 0, P);
}
  
	/*for (int i = 0; i < size(W); i++) {
		cout << endl;
		for (int j = 0; j < size(W[0]); j++) {
			if (W[i][j] == inf) {
				cout << "inf ";
			}
			else {
				cout << W[i][j] << " ";
			}

		}
	}*/





};
