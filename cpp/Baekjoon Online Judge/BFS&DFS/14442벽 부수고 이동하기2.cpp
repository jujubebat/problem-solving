#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int x, y, broken;
}pos;

int n, m, k;
int map[1000][1000];
int visited[1000][1000][11];
int res=1e9;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void bfs() {
	queue<pos> q;
	visited[0][0][0] = 1;
	q.push({ 0,0,0 });
		
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, broken = q.front().broken;
		q.pop();

		// ÃÖ¼Ú°ª °»½Å
		if (x == n - 1 && y == m - 1) {
			res = min(res, visited[x][y][broken]);
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (map[nx][ny] == 0 && visited[nx][ny][broken] == 0) {
				visited[nx][ny][broken] = visited[x][y][broken] + 1;
				q.push({ nx,ny,broken });
			}
			else if (map[nx][ny] == 1 && visited[nx][ny][broken + 1] == 0) {
				if (broken + 1 > k) continue;
				visited[nx][ny][broken+1] = visited[x][y][broken] + 1;
				q.push({ nx, ny, broken + 1 });
			}
		}
	}
}

int main() {

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	
	bfs();
	
	if (res == 1e9)
		cout << -1;
	else
		cout << res;

	return 0;
}