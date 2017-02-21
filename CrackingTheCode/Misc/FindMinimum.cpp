/*
	Integer X is given. You must choose two adjacent digits and replace
	them with the larger of these two digits.
	For example, if X = 233614.
	Possible values are:-
	33614 (by replacing 23 with 3)
	23614 (by replacing 33 with 3 or 36 with 6)
	23364 (by replacing 61 with 6 or 14 with 4)

	The MINIMUM number will be 23364.

	11/04/2016
	Oyashi
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/*
Excludes the index having smaller digit
and returns the whole integer without
the smaller digit
*/
int exclude(int index, string inputString) {
	stringstream ss;
	int result = 0;
	
	//Save digits from starting index to excluding index
	for (int i = 0; i < index; i++) {
		ss << inputString[i];
	}

	//Save digits from one step ahead from excluding index
	//to last digit
	for (int i = index+1; i < inputString.size(); i++) {
		ss << inputString[i];
	}

	//Convert stringstream into integer
	ss >> result;
	cout << result << endl;
	ss.clear();
	return result;
}

int solution(int X) {
	
	string inputString = to_string(X);
	cout << "Input digits = " << inputString << endl;
	
	int* input = new int[sizeof(inputString)];
	vector<int> results;

	//Convert string to integer
	for (int i = 0; i < inputString.size(); i++) {
		input[i] = inputString[i] - '0';
	}

	cout << "\nList of possible maximum numbers" << endl;
	//Go through each number and check the
	//greatest among two adjacent digits
	for (int i = 0; i < inputString.size() - 1; i++) {
		//accumulate the results excluded with smaller index
		//in vector container
		if (input[i] > input[i+1]) {
			results.push_back(exclude(i+1, inputString));
		}
		else {
			results.push_back(exclude(i, inputString));
		}
	}

	return *min_element(results.begin(), results.end());
}

int main() {
	int min = solution(233614);
	cout << "\nMINIMUM element = " << min << endl;
}