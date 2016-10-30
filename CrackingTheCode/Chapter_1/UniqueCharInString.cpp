/*
	Implement an algorithm to determine if a string has all unique characters.
	10/29/2016
	Oyashi
*/

#include <iostream>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	//Define required data structure
	unordered_set<char> charSet;
	bool uniqueString = true;
	std::pair<unordered_set<char>::iterator, bool> retPair;
	string inputString;

	//Input string
	cout << "Please input the string: ";
	cin >> inputString;

	//Check for the duplicate characters
	for (int i = 0; i < inputString.size(); i++) {
		retPair = charSet.insert(inputString[i]);
		if (retPair.second == false) {
			uniqueString = false;
			break;
		}
	}

	//Display the results accordingly
	if (uniqueString) {
		cout << "Give input string has unique characters." << endl;
	}
	else {
		cout << "Given input string has duplicate characters." << endl;
	}
}