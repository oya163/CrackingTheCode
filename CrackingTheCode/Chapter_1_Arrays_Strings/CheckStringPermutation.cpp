/*
	Given two strings, write a method to decide if one is a permutation of the other
	10/30/2016
	Oyashi
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isPermutation(string first, string second) {

	//Check the length of the both of strings
	if (first.length() != second.length()) {
		return false;
	}

	//data structure declaration
	map<char, int> charMap;
	map<char, int>::iterator itr;
	int charCount = 0;

	//map the characters in string and char-count
	for (int i = 0; i < first.size(); i++) {
		charMap[first[i]]++;
	}

	//match with second string
	for (int i = 0; i < second.size(); i++) {
		itr = charMap.find(second[i]);
		if (itr != charMap.end()) {
			itr->second--;
		}
		else {
			return false;
		}
	}

	//check if character count in both string are even
	for (auto& x : charMap) {
		if (x.second != 0) {
			return false;
		}
	}

	return true;

}

int main() {
	string firstString, secondString;

	cout << "Enter first string : "; cin >> firstString; cout << endl;
	cout << "Enter second string : "; cin >> secondString; cout << endl;
	
	if (isPermutation(firstString, secondString)) {
		cout << "The strings are permutation of each other" << endl;
	}
	else {
		cout << "The strings are not permutation of each other" << endl;
	}
}
