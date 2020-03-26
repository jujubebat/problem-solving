#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

typedef struct {
	int x, y, t;
}pos;

char map[8][8];
queue<pos> q;
bool visited[8][8][9];

int dx[] = { 0,0,1,-1,1,-1,1,-1,0 };
int dy[] = { 1,-1,0,0,1,1,-1 - 1,0 };

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf_s("%1c", &map[i][j]);
		}
	}

	q.push({ 7,0,0 });
	bool ans = false;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, t = q.front().t; 
		q.pop();
		if (x == 0 && y == 7) ans = true;

		for (int k = 0; k < 9; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nt = min(t + 1, 8);

			if (nx >= 8 || nx < 0 || ny >= 8 || ny < 0) continue;
			if (nx - t >= 0 && map[nx - t][ny] == '#') continue;
			if (nx - t - 1 >= 0 && map[nx - t-1][ny] == '#') continue;
			if (visited[nx][ny][nt]) continue;

			visited[nx][ny][nt] = true;
			q.push({ nx,ny,nt });
		}
	}

	if (ans)
		cout << 1;
	else
		cout << 0;

	return 0;
}