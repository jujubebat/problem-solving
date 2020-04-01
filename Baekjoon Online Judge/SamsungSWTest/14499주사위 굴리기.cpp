#include<cstdio>
#include<iostream>

using namespace std;

int n, m, x, y, k;
int map[20][20];
int dice[6], temp[6];

const int direct[4][6] = {
	{2,1,5,0,4,3},
	{3,1,0,5,4,2},
	{4,0,2,3,5,1},
	{1,5,2,3,0,4}
};

const int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };

void solve() {
	while (k--) {
		int d;
		cin >> d; d--;

		x += dx[d], y += dy[d];
		if (x < 0 || x >= n || y < 0 || y >= m) {
			x -= dx[d], y -= dy[d];
			continue;
		}

		for (int i = 0; i < 6; i++) {
			temp[i] = dice[i];
		}

		for (int i = 0; i < 6; i++) {
			dice[i] = temp[direct[d][i]];
		}

		if (map[x][y]) {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
		else {
			map[x][y] = dice[5];
		}
		cout << dice[0] << endl;
	}
}

int main() {
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	solve();
	return 0;
}