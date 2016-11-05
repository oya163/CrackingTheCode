/*
	Write an algorithm such that if an element in an MxN matrix is 0, its entire row
	and column are set to 0.
	using bit vector
	10/31/2016
	Oyashi
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <bitset>


using namespace std;

void setZeros(int **matrix, int m, int n) {
	bitset<7> checkRow;
	bitset<7> checkCol;

	//Store the location where zeros are present
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 0) {
				checkRow[i] = 1;
				checkCol[j] = 1;
				cout << i << " " << j << endl;
			}
		}
	}

	//Zero out the row and column.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (checkRow[i] || checkCol[i]) {
				matrix[i][j] = 0;
			}
		}
	}
}

int main() {
	//7*7 matrix is created
	//If you change this, change, the size of bitset vector
	//in the setZero function, as well.
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

	cout << "Display before zero matrix operation " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << image[i][j] << " ";
		}
		cout << endl;
	}

	//Call setZero operation
	setZeros(image, n, n);

	cout << "Display after zero matrix operation " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << image[i][j] << " ";
		}
		cout << endl;
	}

}