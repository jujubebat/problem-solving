#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int x, y;
}laser;

int w, h, ex, ey = -1;
queue<laser> q;
char map[100][100];
int visited[100][100];
const int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0 - 1 };

void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			while (0 <= nx && nx < h && 0 <= ny && ny < w && map[nx][ny] != '*') {
				if (!visited[nx][ny]) {
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx, ny });
				}
				nx += dx[i], ny += dy[i];
			}
		}
	}
	puts("");
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d ", visited[i][j]);
		}
		puts("");
	}
	puts("");
}

int main() {
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				if (ey == -1) ex = i, ey = j;
				else q.push({ i,j });
			}
		}
	}

	bfs();
	cout << visited[ex][ey] - 1;
	return 0;
}


