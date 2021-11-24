#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef struct {
	int x, y;
}pos;

int w, h;
int map[50][50];
bool visited[50][50];
int dx[] = { -1,1,0,0,-1,-1,1,1, }, dy[] = { 0,0,-1,1, -1,1,-1,1 };

void bfs(int sx, int sy) {

	queue<pos> q;
	visited[sx][sy] = true;
	q.push({ sx,sy });

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (visited[nx][ny]) continue;
			if (!map[nx][ny]) continue;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		memset(visited, false, sizeof(visited));

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visited[i][j]) {
					bfs(i,j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}