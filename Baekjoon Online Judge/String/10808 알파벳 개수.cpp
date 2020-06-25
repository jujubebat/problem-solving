#include<iostream>
#include<string>
using namespace std;

int check[26];

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		check[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << check[i] << " ";
	}

	return 0;
}