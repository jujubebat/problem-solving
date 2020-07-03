#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string a, b;

	cin >> a >> b;
	
	int aIdx = -1, bIdx = -1;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) {
				aIdx = i;
				bIdx = j;
				break;
			}
		}
		if (aIdx != -1 && bIdx != -1) break;
	}

	vector<vector<char>> map(b.size(), vector<char>(a.size(), '.'));

	for (int col = 0; col < a.size(); col++) {
		map[bIdx][col] = a[col];
	}

	for (int row = 0; row < b.size(); row++) {
		map[row][aIdx] = b[row];
	}

	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}
