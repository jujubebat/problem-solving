#include<iostream>
#include<algorithm>
using namespace std;

char map[50][50];
int dx[] = {-1,0}, dy[] = {0,1};
int res = -1;
int n;

void checkMax() {
	for (int i = 0; i < n; i++) { //행 검사
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (map[i][j] == map[i][j + 1]) 
				cnt++;
			else {
				res = max(res, cnt);
				cnt = 1;
			}
		}
	}

	for (int j = 0; j < n; j++) {//열 검사
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			if (map[i][j] == map[i+1][j])
				cnt++;
			else {
				res = max(res, cnt);
				cnt = 1;
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 2; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
				swap(map[i][j], map[nx][ny]);
				checkMax();
				swap(map[i][j], map[nx][ny]);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	printf("%d", res);
}
