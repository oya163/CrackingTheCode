///*
//	Implement a method to perform basic string compression using the counts
//	of repeated characters. For example, the string aabcccccaaa would become
//	a2blc5a3. If the "compressed" string would not become smaller than the original
//	string, your method should return the original string.
//
//	10/31/2016
//	Oyashi
//*/
//
//#include <iostream>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
////Check the size of resulting string
//int countCompression(string str) {
//	if (str == "\0" || str.empty()) return 0;
//	char last = str[0];
//	int size = 0, count = 1;
//	for (int i = 1; i < str.length(); i++) {
//		if (str[i] == last) {
//			count++;
//		}
//		else {
//			last = str[i];
//			size += 1 + to_string(count).length();
//			count = 1;
//		}
//	}
//	size += 1 + to_string(count).length();
//	return size;
//}
//
//
////Method to compress the string
//string compressString(string str) {
//	string newString = "";
//
//	int size = countCompression(str);
//	if (size >= str.length()) {
//		return str;
//	}
//	
//	char last = str[0];
//	int count = 1;
//	for (int i = 1; i < str.length(); i++) {
//		stringstream ss;
//		ss << last;
//		string temp;
//		ss >> temp;
//		if (str[i] == last) {
//			count++;
//		}
//		else {
//			last = str[i];
//			ss << last;
//			ss >> temp;
//			newString.append(temp);
//			newString.append(to_string(count));
//			count = 1;
//		}
//	}
//	stringstream ss;
//	ss << last;
//	string temp;
//	ss >> temp;
//	newString.append(temp);
//	newString.append(to_string(count));
//	return newString;
//}
//
//int main() {
//	string inputStr = "abcde";
//	string outputStr = compressString(inputStr);
//	cout << outputStr << endl;
//}