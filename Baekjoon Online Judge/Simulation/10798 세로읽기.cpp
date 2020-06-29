#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string> arr;

	for (int i = 0; i < 5; i++) {
		string word;
		cin >> word;
		arr.push_back(word);
		arr.back().resize(15, ' ');
	}

	for (int c = 0; c < 15; c++) {
		for (int r = 0; r < 5; r++) {
			if (arr[r][c] != ' ') {
				cout << arr[r][c];
			}
		}
	}

	return 0;
}