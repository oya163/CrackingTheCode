#include <iostream>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	unordered_set<char> charSet;
	bool uniqueString = true;
	std::pair<unordered_set<char>::iterator, bool> retPair;
	string inputString;
	cout << "Please input the string: ";
	cin >> inputString;
	for (int i = 0; i < inputString.size(); i++) {
		retPair = charSet.insert(inputString[i]);
		if (retPair.second == false) {
			uniqueString = false;
			break;
		}
	}
	if (uniqueString) {
		cout << "Give input string has unique characters." << endl;
	}
	else {
		cout << "Given input string has duplicate characters." << endl;
	}
}