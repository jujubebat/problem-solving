//못푼문제,다시풀어봐야하는 문제, 나한테는 너무 어렵게 느껴졌음.
#include <cstdio>
#include <queue>
using namespace std;

struct robot {
	int x, y, d;
};

int n, m;
int sx, sy, sd, ex, ey, ed;
int a[100][100];
int dist[100][100][4];
const int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };

void bfs() {
	queue<robot> q;
	q.push({ sx - 1, sy - 1,sd - 1 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, d = q.front().d; 
		q.pop();
		if (x == ex - 1 && y == ey - 1 && d == ed - 1) {
			printf("%d\n", dist[x][y][d]);
			return;
		}
		for (int i = 1; i <= 3; i++) {
			int nx = x + dx[d] * i, ny = y + dy[d] * i;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)break;
			if (a[nx][ny]) break;
			if (dist[nx][ny][d]) continue;
			q.push({ nx,ny,d });
			dist[nx][ny][d] = dist[x][y][d] + 1;
		}
		for (int i = 0; i < 4; i++) {
			if (i == d) continue;
			int k = (i + d) % 4 == 1 ? 2 : 1;
			if (dist[x][y][i])continue;
			q.push({ x,y,i });
			dist[x][y][i] = dist[x][y][d] + k;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d %d %d", &sx, &sy, &sd);
	scanf("%d %d %d", &ex, &ey, &ed);
	bfs();
	return;
}