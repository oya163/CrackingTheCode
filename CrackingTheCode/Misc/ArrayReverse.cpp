/*
	Reverse array without iteration
	02/21/2017
	Oyashi
*/

#include <iostream>

using namespace std;

void reverse(int *arr, int n) {
	if (n <= 0) return;
	swap(arr[0], arr[n - 1]);
	reverse(++arr, n - 2);
}

int main(){
	int arr[6] = {5,6,3,2,1,8};
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	reverse(arr, 6);
	cout << "\nAfter reverse" << endl;
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";

}