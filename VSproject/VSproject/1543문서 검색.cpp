#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	string word;
	int ret = 0;

	getline(cin, str); // >> str;
	getline(cin, word); // >> word;

	int strSize = str.size();
	int wordSize = word.size();

	for (int i = 0; i <= strSize - wordSize; i++) {
		if (!word.compare(str.substr(i, wordSize))) {
			ret++;
			i += wordSize - 1;
		}
	}

	cout << ret;

	return 0;
}