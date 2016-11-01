/*
	Write an algorithm such that if an element in an MxN matrix is 0, its entire row
	and column are set to 0.
	10/31/2016
	Oyashi
*/

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void zeroMatrix(int** matrix, int m, int n) {
	vector<int, int> newMatrix;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 0) {
				newMatrix.push_back(make_pair(i, j));
			}
		}
	}
}

int main() {
		int n = 7;
		//Dynamic 2D array allocation
		int **image = new int*[n];
		for (int i = 0; i < n; i++) {
			image[i] = new int[n];
		}
	
		//Random value initialization
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				image[i][j] = rand() % 10;
			}
		}

		zeroMatrix(image, n, n)
}