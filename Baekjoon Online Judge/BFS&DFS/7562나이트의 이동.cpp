
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

typedef struct {
	int x, y;
}pos;

int st_x, st_y, ed_x, ed_y;
int map[300][300];
int res;
int t, l;
int dx[] = {-1,-2,-2,-1,1,2,2,1}, dy[] = {-2,-1,1,2,2,1,-1,-2};

void bfs() {
	queue<pos> q;
	q.push({ st_x, st_y });
	while (!q.empty()){
		int x = q.front().x, y = q.front().y; 
		q.pop();
		if (x == ed_x && y == ed_y) {
			printf("%d\n", map[x][y]);
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= l || nx < 0 || ny >= l || ny < 0) continue;
			if (map[nx][ny]) continue;
			map[nx][ny] = map[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l;
		cin >> st_x >> st_y;
		cin >> ed_x >> ed_y;
		memset(map, 0, sizeof(map));
		bfs();
	}
	return 0;
}

