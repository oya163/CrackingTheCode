///*
//	Implement an algorithm to determine if a string has all unique characters
//	10/29/2016
//	Oyashi
//*/
//
//#include <iostream>
//#include <map>
//#include <string>
//
//using namespace std;
//
//int main() {
//	//Define data structure
//	map<char, int> charMap;
//	map<char, int>::iterator itr;
//	pair<char, int> makePair;
//	string inputString;
//	int charCount = 0;
//
//	cout << "Please enter the input string "; cin >> inputString;
//
//	//Insert the map if new value else increase their previous count
//	for (int i = 0; i < inputString.size(); i++) {
//		charCount = 0;
//		itr = charMap.find(inputString[i]);
//		if (itr != charMap.end()) {
//			itr->second++;		}
//		else {
//			charCount++;
//		}
//		charMap.insert(pair<char, int>(inputString[i],charCount));
//	}
//
//	//Check if any of the key has more counts
//	for (auto& x : charMap) {
//		if (x.second > 1) {
//			cout << "Your string contains duplicate characters." << endl;
//			return 0;
//		}
//	}
//	cout << "Your string has unique characters only." << endl;
//}