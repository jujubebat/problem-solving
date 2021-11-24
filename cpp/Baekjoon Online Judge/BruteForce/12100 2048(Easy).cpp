#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int res = -1;

void moving(int dir, int map[][21]) {//0123 동서남북
	if (dir == 0) { //동쪽으로 이동 
		//moving
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j]) {
					for (int k = j; k < n - 1; k++) {
						if (map[i][k + 1] == 0)
							swap(map[i][k], map[i][k + 1]);
					}
				}
			}
		}

		//sum
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 1; j--) {
				if (map[i][j] == map[i][j - 1]) {
					map[i][j] *= 2;
					res = max(res, map[i][j]);
					map[i][j - 1] = 0;
					for (int k = n - 1; k >= 1; k--) {
						if (map[i][k] == 0 && map[i][k - 1])
							swap(map[i][k], map[i][k - 1]);
					}
				}
			}
		}
	}
	else if (dir == 1) { //서쪽으로 이동
		//moving
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j]) {
					for (int k = j; k >= 1; k--) {
						if (map[i][k - 1] == 0)
							swap(map[i][k], map[i][k - 1]);
					}
				}
			}
		}
		//sum
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (map[i][j] == map[i][j + 1]) {
					map[i][j] *= 2;
					res = max(res, map[i][j]);
					map[i][j + 1] = 0;
					for (int k = 0; k < n - 1; k++) {
						if (map[i][k] == 0 && map[i][k + 1])
							swap(map[i][k], map[i][k + 1]);
					}
				}
			}
		}
	}
	else if (dir == 2) { //남쪽으로 이동

		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i >= 0; i--) {
				if (map[i][j]) {
					for (int k = i; k < n - 1; k++) {
						if (map[k][j] && map[k + 1][j] == 0)
							swap(map[k][j], map[k + 1][j]);
					}
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i >= 0; i--) {
				if (map[i][j] == map[i - 1][j]) {
					map[i][j] *= 2;
					res = max(res, map[i][j]);
					map[i - 1][j] = 0;
					for (int k = n - 1; k >= 1; k--) {
						if (map[k][j] == 0 && map[k - 1][j])
							swap(map[k][j], map[k - 1][j]);
					}
				}
			}
		}
	}
	else if (dir == 3) { //북쪽으로 이동
		//moving
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (map[i][j]) {
					for (int k = i; k >= 1; k--) {
						if (map[k][j] && map[k - 1][j] == 0)
							swap(map[k][j], map[k - 1][j]);
					}
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (map[i][j] == map[i + 1][j]) {
					map[i][j] *= 2;
					res = max(res, map[i][j]);
					map[i + 1][j] = 0;
					for (int k = 0; k < n - 1; k++) {
						if (map[k][j] == 0 && map[k + 1][j])
							swap(map[k][j], map[k + 1][j]);
					}
				}
			}
		}
	}
}

void go(int cnt, int map[][21]) {

	if (cnt >= 5) return;

	int next_map[21][21];

	for (int i = 0; i < 4; i++) {
		//copy(&map[0][0], &map[n - 1][n - 1] + 1, &next_map[0][0]);
		memcpy(next_map, map, sizeof(next_map));
		moving(i, next_map);
		go(cnt + 1, next_map);
	}
}

int main() {
	cin >> n;

	int map[21][21];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res = max(res, map[i][j]);
		}
	}

	go(0, map);

	printf("%d", res);
	return 0;
}