/*
Find the minimum
11/04/2016
Oyashi
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Node\LinkedList.h"

using namespace std;

int solution(int X) {
	stringstream ss;
	string inputString = to_string(X);
	cout << inputString << endl;
	
	int* input = new int[sizeof(inputString)];
	int* inter = new int[sizeof(inputString)];
	vector<int> results;

	for (int i = 0; i < inputString.size(); i++) {
		input[i] = inputString[i] - '0';
	}

	for (int i = 0; i < inputString.size(); i++) {
		cout << input[i] << endl;
	}

	for (int i = 0; i < inputString.size() - 1; i++) {

		for (int j = 0; j < i; j++) {
			inter[j] = input[j];
		}

		if ((int)input[i] >= (int)input[i + 1]) {
			inter[i] = input[i];
		}
		else {
			inter[i] = input[i+1];
		}

		for (int j = i+1; j < inputString.size(); j++) {
			
			inter[j] = input[j+1];
		}

		for (int j = 0; j < inputString.size(); j++) {
			//cout << inter[j] << " ";
			ss << inter[j];
		}

		int result;
		ss >> result;
		cout << result;
		results.push_back(result);
		cout << endl;
		ss.clear();
	}

	for (auto& x : results) {
		cout << x << endl;
	}
	return 0;
	//return *min_element(results.begin(), results.end());

}

int main() {
	int min = solution(123456);
	cout << "MINIMUM element = " << min << endl;
}