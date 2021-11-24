#include<iostream>
#include<vector>
#include<string>
using namespace std;

char map[5][5];
vector<string> words;
bool check[10];
int dx[] = { -1,1,0,0,-1,-1,1,1 };
int dy[] = { 0,0,-1,1,-1,1,-1,1 };
int n;

bool search(int x, int y, const string& word) {
	if (map[x][y] != word[0]) return false;
	if (word.size() == 1) return true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
		if (search(nx, ny, word.substr(1)))
			return true;
	}
	return false;
}

bool checking(string word) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (search(i, j, word))
				return true;
		}
	}
	return false;
}

int main() {
	int c;
	cin >> c;

	for (int t = 0; t < c; t++) {

		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 5; c++) {
				cin >> map[r][c];
			}
		}

		cin >> n;

		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			words.push_back({ str });
		}

		for (int i = 0; i < n; i++) {
			if (checking(words[i]))
				cout << words[i] << " YES\n";
			else
				cout << words[i] << " NO\n";

		}
	}

	return 0;
}

