/*
	Assume you have a method isSubstring which checks if one word is a substring
	of another. Given two strings, si and s2, write code to check Ifs2 is a rotation of si
	using only onecalltoisSubstring (e.g., "waterbottLe" is a rotation of "erbottLewat").

	11/1/2016
	Oyashi
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



bool isSubstring(string s1, string s2) {
	string origS1 = s1;
	string origS2 = s2;

	//Check if the string has same length
	if (s1.length() != s2.length()) {
		return false;
	}

	//Sort the string, to check the rotation, short way
	stable_sort(origS1.begin(), origS1.end());
	stable_sort(origS2.begin(), origS2.end());

	if (origS2 == origS2) {
		return true;
	}
	else {
		//ooyeshmannooyeshmann = ooyeshmann + ooyeshmann
		//second string will be found somewhere in
		//large version of first string
		s1 = s1 + s1;
		for (int i = 0; i < s2.length(); i++) {
			for (int j = 0; j < s1.length(); j++) {
				if (s2[i] == s1[j]) {
					string newSubString = string(&s1[j],s2.length());
					if (newSubString == s2) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	string first = "ooyeshmann";
	string second = "mannooyesh";

	if (isSubstring(first, second)) {
		cout << "Second string is rotation of first string" << endl;
	}
	else {
		cout << "Second string is not rotation of first string" << endl;
	}
}