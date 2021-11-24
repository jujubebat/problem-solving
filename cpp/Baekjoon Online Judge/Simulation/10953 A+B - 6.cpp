#include<iostream>
#include<string>
using namespace std;

int main() {
	int t;
	string s;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> s;
		cout << s[0] - '0' + s[2] - '0' << endl;
	}

	return 0;
}