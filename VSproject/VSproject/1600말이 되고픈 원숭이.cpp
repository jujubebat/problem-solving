#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	int x, y, z;
}pos;

int k, w, h;
int map[200][200];
int visited[200][200][31];
int monkey_dx[] = {-1,1,0,0}, monkey_dy[] = {0,0,-1,1};
int horse_dx[] = {-1,-1,-2,-2,1,1,2,2}, horse_dy[] = {2,-2,-1,1,-2,2,-1,1};

int bfs() {
	queue<pos> q;
	visited[0][0][0] = 1;
	q.push({ 0,0,0 });

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z;
		q.pop();

		if (x == h - 1 && y == w - 1) {
			return visited[x][y][z];
		}

		int nx, ny, nz; 

		for (int i = 0; i < 4; i++) { //¿ø¼þÀÌ
			nx = x + monkey_dx[i], ny = y + monkey_dy[i], nz = z;
			if (nx >= h || nx < 0 || ny >= w || ny < 0) continue;
			if (visited[nx][ny][nz]) continue;
			if (map[nx][ny]) continue;

			visited[nx][ny][nz] = visited[x][y][z] + 1;
			q.push({ nx,ny,nz });
		}

		if (z >= k) continue;

		for (int i = 0; i < 8; i++) { //¸»
			nx = x + horse_dx[i], ny = y + horse_dy[i], nz = z+1;
			if (nx >= h || nx < 0 || ny >= w || ny < 0) continue;
			if (visited[nx][ny][nz]) continue;
			if (map[nx][ny]) continue;

			visited[nx][ny][nz] = visited[x][y][z] + 1;
			q.push({ nx,ny,nz });
		}
	}

	return -1;
}

int main() {
	cin >> k;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	int res = bfs();

	if (res == -1)
		cout << -1;
	else
		cout << res - 1;

	return 0;
}