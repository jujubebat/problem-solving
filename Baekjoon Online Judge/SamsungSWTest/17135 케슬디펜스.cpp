#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct {
	int x, y, d;
}enemy;

int n, m, d, res = -1;
int map[16][15];
int tmp_map[16][15];
vector<int> v;

bool isEnd() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp_map[i][j] == 1)
				return false;
		}
	}
	return true;
}

int simulation() {
	int cnt = 0;

	while (1) {
		// 타겟 설정
		for (int j = 0; j < m; j++) {
			if (tmp_map[n][j]) {
				int x = n, y = j;
				enemy target;
				target.x = -1;
				target.y = -1;
				target.d = 1e9;

				for (int row = n - 1; row >= 0; row--) {
					for (int col = m - 1; col >= 0; col--) {
						if (tmp_map[row][col]) { //적이라면,
							int dist = abs(x - row) + abs(y - col);
							if (dist > d) continue;
							if (dist < target.d) {
								target.x = row, target.y = col, target.d = dist;
							}
							else if (dist == target.d) {
								if (col < target.y) {
									target.x = row, target.y = col, target.d = dist;
								}
							}
						}
					}
				}
				if (target.x == -1 && target.y == -1) continue;
				tmp_map[target.x][target.y] = 2;
			}
		}
		//적 제거 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp_map[i][j] == 2) {
					tmp_map[i][j] = 0;
					cnt++;
				}
			}
		}
		// 적 이동
		for (int j = 0; j < m; j++) {
			for (int i = n - 1; i >= 0; i--) {
				if (tmp_map[i][j] == 1) {
					if (i == n - 1)
						tmp_map[i][j] = 0;
					else {
						swap(tmp_map[i][j], tmp_map[i + 1][j]);
					}
				}
			}
		}
		if (isEnd()) return cnt;
	}
}

void combination(int cnt) {
	if (v.size() == 3) {
		memcpy(tmp_map, map, sizeof(map));

		for (int i : v) {
			tmp_map[n][i] = 1;
		}
		
		res = max(res, simulation());
		return;
	}

	for (int i = cnt; i < m; i++) {
		v.push_back(i);
		combination(i + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	combination(0);
	cout << res;
	return 0;
}