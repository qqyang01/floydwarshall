#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
  //TEST CASE 1
	int inf = std::numeric_limits<int>::max();
	int W[5][5] = { {0,1,inf,1,5},{9,0,3,2,inf},{inf,inf, 0,4,inf},{inf,inf,2,0,3},{3,inf,inf,inf,0} };
  
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
