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
	vector<pair<int, int>> newMatrix;

	//Store the location where zeros are present
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 0) {
				newMatrix.push_back(make_pair(i, j));
			}
		}
	}

	for (vector<pair<int, int>>::iterator itr = newMatrix.begin(); itr != newMatrix.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
		for (int row = 0; row < m; row++) {
			matrix[row][itr->second] = 0;
		}
		for (int col = 0; col < n; col++) {
			matrix[itr->first][col] = 0;
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

		//Display before zero matrix operation
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << image[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;
		
		//Apply zero matrix operation
		zeroMatrix(image, n, n);

		//Display after zero matrix operation
		cout << "After the zero matrix operation " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << image[i][j] << " ";
			}
			cout << endl;
		}
}