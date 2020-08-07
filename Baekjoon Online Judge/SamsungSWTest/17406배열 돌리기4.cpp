#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cstring>
using namespace std;

typedef struct {
	int r, c, s;
}rotationInfo;

int n, m, k;
int map[50][50];
int tmpMap[50][50];
unordered_map<int, rotationInfo> info;
vector<int> arr;

void rotate(rotationInfo info) {
	int r = info.r;
	int c = info.c;
	int s = info.s;
	int tmp[50][50];
	memcpy(tmp, tmpMap, sizeof(tmpMap));

	int len = (r + s) - (r - s) + 1;
	int cnt = len / 2 + 1;
	int sx = r - s - 1, sy = c - s -1;

	while (cnt--) {
		// 위쪽 행  →
		for (int col = sy; col < sy + len - 1; col++) {
			tmpMap[sx][col + 1] = tmp[sx][col];
		}

		// 오른쪽 열 ↓
		for (int row = sx; row < sx + len - 1; row++) {
			tmpMap[row + 1][sy + len - 1] = tmp[row][sy + len - 1];
		}
	
		// 아래쪽 행  ←
		for (int col = sy + len - 1; col > sy; col--) {
			tmpMap[sx + len - 1][col-1] = tmp[sx+len - 1][col];
		}

		// 왼쪽 열 ↑
		for (int row = sx + len - 1; row > sx; row--) {
			tmpMap[row - 1][sy] = tmp[row][sy];
		}
		sx++, sy++, len-=2;
	}
}

int main() {
	int ret = 0x7fffffff;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		info[i] = { r,c,s };
		arr.push_back(i);
	}

	do {
		memcpy(tmpMap, map, sizeof(map));
	
		for (int order : arr) {
			rotate(info[order]);
		}

		for (int r = 0; r < n; r++) {
			int candi = 0;
			for (int c = 0; c < m; c++) {
				candi += tmpMap[r][c];
			}
			ret = min(ret, candi);
		}
	} while (next_permutation(arr.begin(), arr.end()));

	cout << ret;

	return 0;
}