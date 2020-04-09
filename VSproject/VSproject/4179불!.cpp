#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int x, y;
	int isFire; // 1¿Ã∏È ∫“
}pos;

int r, c;
char map[1000][1000];
int check[1000][1000];
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
queue<pos> q;
int res = -1;

void bfs(int sx, int sy) {
	check[sx][sy] = 1;
	q.push({ sx,sy, 0 });

	while (!q.empty()){
		int x = q.front().x, y = q.front().y; 
		int isFire = q.front().isFire;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx >= r || nx < 0 || ny >= c || ny < 0) {
				if (!isFire) {
					res = check[x][y];
					return;
				}
				continue;
			} 

			if (map[nx][ny] == 'J' || map[nx][ny] == 'F' || map[nx][ny] == '#') continue;
			if (check[nx][ny]) continue;
			check[nx][ny] = check[x][y] + 1;
			q.push({ nx,ny,isFire });

		}
	}

}

int main() {
	int sx, sy;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				sx = i, sy = j;
			}
			else if (map[i][j] == 'F') {
				check[i][j] = 1;
				q.push({ i,j,1 });
			}
		}
	}

	bfs(sx,sy);

	if (res == -1)
		cout << "IMPOSSIBLE";
	else
		cout << res;
	return 0;
}


