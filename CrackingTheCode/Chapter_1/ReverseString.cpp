/*
	Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated string.
	Solution from the book
	10/29/2016
	Oyashi
*/

#include <iostream>
 
using namespace std;

void reverse(char *str) {
	char* end = str;
	char tmp;
	if (str) {
		while (*end) {
			++end;
		}
		--end;

		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

int main() {
	
	char inputString[] = "oyesh";
	reverse(inputString);
	cout << inputString << endl;

}