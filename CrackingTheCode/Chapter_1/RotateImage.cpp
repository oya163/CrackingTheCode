/*
	Given an image represented by an NxN matrix, where each pixel in the image is 4
	bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

	10/31/2015
	Oyashi
*/

#include <iostream>
#include <time.h>

using namespace std;

void rotateImage(int** matrix, int m) {
	for (int layer = 0; layer < m / 2; layer++) {
		int first = layer;
		int last = m - 1 - first;
		for (int i = first; i < last; i++) {
			int offset = i - first;

			//save the top element
			int top = matrix[first][i];

			//left bottom to top left
			matrix[first][i] = matrix[last - offset][first];

			//right bottom to left bottom
			matrix[last - offset][first] = matrix[last][last - offset];

			//top right to right bottom
			matrix[last][last - offset] = matrix[i][last];

			//top to top right
			matrix[i][last] = top;
		}
	}

	cout << "After rotation" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
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

	//Display image before rotation
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << image[i][j] << " ";
		}
		cout << endl;
	}

	rotateImage(image, n);
}
