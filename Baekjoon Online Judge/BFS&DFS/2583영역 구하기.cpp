#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[100][100];
vector<int> res;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int m, n, k;
int cnt;

void dfs(int x, int y) {
	map[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
		if (map[nx][ny]) continue;
		dfs(nx, ny);
	}
}

int main() {
	cin >> m >> n >> k;
	
	int x1,y1,x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int x, y = 0;
		for (int i = m - 1; i >= 0; i--) {
			y++;
			x = 0;
			for (int j = 0; j < n; j++) {
			x++;
			if (y > y1 && y <= y2 && x > x1 && x <= x2) {
				map[i][j] = 1;
			}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cnt = 0;
			if (!map[i][j]) {
				dfs(i, j);
			}
			if(cnt)
			   res.push_back(cnt);
		}
	}

	sort(res.begin(), res.end());

	printf("%d\n", res.size());
	for (int x : res) {
		printf("%d ", x);
	}
}