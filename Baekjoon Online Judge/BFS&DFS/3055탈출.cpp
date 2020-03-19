#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int x, y, isBiber;
}pos;

int r, c;
char map[50][50];
int visited[50][50];
queue<pos> q;
int sx, sy;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

int bfs() {
	visited[sx][sy] = 1;
	q.push({ sx,sy,1 });

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, isBiber = q.front().isBiber;
		q.pop();

		puts("");

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%d", visited[i][j]);
			}
			puts(""); 

		}
		puts("");

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= r || nx < 0 || ny >= c || ny < 0) continue;
			if (map[nx][ny] == 'X' || visited[nx][ny]) continue;

			if (map[nx][ny] == 'D') {
				if (isBiber == 0) continue;
				return  visited[x][y];
			}
			visited[nx][ny]= visited[x][y] + 1;
			q.push({ nx,ny,isBiber });
		}
	}

	return -1;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				sx = i, sy = j;
			}
			else if (map[i][j] == '*') {
				q.push({ i,j,0 }); //0Àº ¹°
			}
		}
	}

	int res = bfs();
	if (res == -1)
		cout << "KAKTUS";
	else
		cout << res<<endl;

	

	return 0;
}