#include<iostream>
using namespace std;

char map[100][100];

int main() {
	int r, c;

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	for (int col = c - 1, nCol = c; col >= 0; col--, nCol++) {
		for (int row = 0; row < r; row++) {
			map[row][nCol] = map[row][col];
		}
	}

	for (int row = r - 1, nRow = r; row >= 0; row--, nRow++) {
		for (int col = 0; col < c; col++) {
			map[nRow][col] = map[row][col];
		}
	}

	for (int col = c - 1, nCol = c; col >= 0; col--, nCol++) {
		for (int row = r; row < r * 2; row++) {
			map[row][nCol] = map[row][col];
		}
	}

	int x, y;
	cin >> x >> y;
	x--, y--;

	if (map[x][y] == '.')
		map[x][y] = '#';
	else if (map[x][y] == '#')
		map[x][y] = '.';

	for (int i = 0; i < r * 2; i++) {
		for (int j = 0; j < c * 2; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}