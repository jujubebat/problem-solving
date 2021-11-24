//BFS로 품
#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	int x, y;
}pos;

int n;
int map[100][100], check[100][100];
int minValue = 1e9, maxValue = -1e9;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
queue<pos> q;

void bfs(int std) {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (check[nx][ny] || map[nx][ny] <= std)continue;
			check[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

void solve() {
	int res = 1;// 최종 안전영역 개수
	for (int std = minValue; std < maxValue; std++) {
		fill(&check[0][0], &check[0][0] + 100 * 100, 0);
		int cnt = 0; //안전영역 개수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > std && check[i][j] == 0) {
					check[i][j] = 1;
					q.push({ i,j });
					bfs(std);
					cnt++;
				}
			}
		}
		if (cnt > res) res = cnt;
	}
	printf("%d", res);
}

int main() {
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] < minValue)
				minValue = map[i][j];
			if (map[i][j] > maxValue)
				maxValue = map[i][j];
		}
		getchar();
	}
	solve();
}