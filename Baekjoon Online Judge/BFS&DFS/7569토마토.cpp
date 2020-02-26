#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	int x;//행
	int y;//열
	int z;//높이
}pos;

int m, n, h;
int map[100][100][100];
int dx[] = {0,0,1,-1,0,0}, dy[] = {0,0,0,0,1,-1}, dz[] = {1,-1,0,0,0,0};
queue<pos> q;
int res = 0;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0 || nz >= h || nz < 0) continue;
			if (map[nx][ny][nz] != 0) continue;
			map[nx][ny][nz] = map[x][y][z] + 1;
			q.push({ nx,ny,nz });
		}
	}
}

int main() {
	bool flag = true;

	scanf("%d %d %d", &m, &n, &h);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf("%d", &map[j][k][i]);
				if (map[j][k][i] == 1)
					q.push({ j,k,i }); // 행, 열, 높이
				if (map[j][k][i] == 0)
					flag = false;
			}
		}
	}

	if (flag) {
		printf("0");
		return 0;
	}

	bfs();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[j][k][i] == 0) {
					printf("-1");
					return 0;
				}
				if (map[j][k][i] > res)
					res = map[j][k][i];
			}
		}
	}
	printf("%d", res - 1);
}