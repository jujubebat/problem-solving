#include<iostream>
#include<map>
using namespace std;

int score[200][3];
int ret[200];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> score[i][j];
		}
	}

	for (int c = 0; c < 3; c++) {
		map<int, int> m;
		for (int r = 0; r < n; r++) {
			m[score[r][c]]++;
		}

		for (int r = 0; r < n; r++) {
			if (m[score[r][c]] >= 2) continue;
			ret[r] += score[r][c];
		}
	}

	for (int i = 0; i < n; i++)
		cout << ret[i] << endl;
	
	return 0;
}