#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int x, y, broken, day; //0Àº ³·, 1Àº ¹ã
}pos;

int n, m, k;
int res = 1e9;
int map[1000][1000];
int visited[1000][1000][11][2];
int dx[] = { -1,1,0,0,0 }, dy[] = { 0,0,-1,1,0 };

void bfs() {
	queue<pos> q;
	visited[0][0][0][0] = 1;
	q.push({ 0,0,0,0 });

	while (!q.empty()){
		int x = q.front().x, y = q.front().y;
		int broken = q.front().broken, day = q.front().day;
		int nextDay;

		if (day == 0) nextDay = 1;
		else nextDay = 0;

		q.pop();

		if (x == n - 1 && y == m - 1) {
			res = min(res, visited[x][y][broken][day]);
		}

		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			
			if(x == nx && y== ny){
				if (visited[nx][ny][broken][nextDay] == 0) {
					visited[nx][ny][broken][nextDay] = visited[nx][ny][broken][day] + 1;
					q.push({ nx,ny,broken,nextDay });
				}
			}
			else if (map[nx][ny] == 0 && visited[nx][ny][broken][nextDay] == 0) {
				visited[nx][ny][broken][nextDay] = visited[x][y][broken][day] + 1;
				q.push({ nx, ny, broken, nextDay });
			}
			else if (map[nx][ny] == 1 && visited[nx][ny][broken + 1][nextDay] == 0) {
				if (day == 1) continue;
				if (broken + 1 > k) continue;
				visited[nx][ny][broken + 1][nextDay] = visited[x][y][broken][day] + 1;
				q.push({ nx, ny, broken + 1,nextDay });
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