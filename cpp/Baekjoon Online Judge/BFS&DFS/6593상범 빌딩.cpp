#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct {
	int x, y, z;
}pos;

int L, R, C;//zxy
char map[30][30][30];
int visited[30][30][30];
int sx, sy, sz;
int ex, ey, ez;
int dx[] = {-1,1,0,0,0,0}, dy[] = {0,0,-1,1,0,0}, dz[] = {0,0,0,0,-1,1};

int bfs(int sx, int sy, int sz) {
	queue<pos> q;
	visited[sx][sy][sz] = 1;
	q.push({ sx,sy,sz });

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z;
		q.pop();
		//도착처리
		if (x == ex && y == ey && z == ez) {
			return visited[x][y][z];
		}

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if (nx >= R || nx < 0 || ny >= C || ny < 0 || nz >= L || nz < 0) continue;
			if (visited[nx][ny][nz]) continue;
			if (map[nx][ny][nz] == '#') continue;

			visited[nx][ny][nz] = visited[x][y][z] + 1;
			q.push({ nx,ny,nz });
		}
	}

	return -1;
}

void solve(int a, int b, int c) {//zxy

	for (int z = 0; z < a; z++) {
		for (int x = 0; x < b; x++) {
			for (int y = 0; y < c; y++) {
				cin >> map[x][y][z];
				if (map[x][y][z] == 'S')
					sx = x, sy = y, sz = z;
				if (map[x][y][z] == 'E')
					ex = x, ey = y, ez = z;
			}
		}
	}

	//check 배열 초기화
	memset(visited, 0, sizeof(visited));
	int num = bfs(sx,sy,sz);

	if (num == -1)
		cout << "Trapped!\n";
	else
		printf("Escaped in %d minute(s).\n", num-1);
}

int main() {
    
	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		solve(L, R, C);
	}
	return 0;
}

