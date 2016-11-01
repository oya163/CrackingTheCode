/*
	Write a method to replace all spaces in a string with'%20'. You may assume that
the string has sufficient space at the end of the string to hold the additional
characters, and that you are given the "true" length of the string. (Note: if implementing
in Java, please use a character array so that you can perform this operation
in place.)
EXAMPLE
Input: "Mr John Smith  "
Output: "Mr%20Dohn%20Smith"

	10/30/2016
	Oyashi
*/

#include <iostream>

using namespace std;

void replaceString(char *str, int length) {
	int numSpaces = 0, newLength;
	for (int i = 0; i < length; i++) {
		if (str[i] == ' ') {
			numSpaces++;
		}
	}

	newLength = length + numSpaces * 2;

	str[newLength] = '\0';
	for (int i = length - 1; i > -0; i--) {
		if (str[i] == ' ') {
			str[newLength - 1] = '0';
			str[newLength - 2] = '2';
			str[newLength - 3] = '%';
			newLength -= 3;
		}
		else {
			str[newLength - 1] = str[i];
			newLength -= 1;
		}
	}
	
}

int main() {
	char inputString[] = "Mr Oyesh Singh";
	int lenString = 15;
	replaceString(inputString, lenString);
	cout << inputString << endl;
}
