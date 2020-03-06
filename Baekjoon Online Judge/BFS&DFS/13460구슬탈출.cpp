/*
어려운  BFS 문제..
두개의 구슬에 대한 방문처리를 해야함 -> 4차원배열활용
구슬이 겹칠경우를 처리해야함
*/
#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int rx, ry, bx, by,d;
}pos;

int n, m;
char map[10][10];
bool check[10][10][10][10];
const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
queue<pos> q;

void move(int &x, int &y, int &c, int dx, int dy) {
	while (map[x + dx][y + dy] != '#' && map[x][y] != 'O') {
		x += dx;
		y += dy;
		c++;
	}
}

void bfs() {
	while (!q.empty()){
		int rx = q.front().rx, ry = q.front().ry;
		int bx = q.front().bx, by = q.front().by;
		int d = q.front().d;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rCnt = 0, bCnt = 0;
			if (d >= 10) break;

			move(nrx, nry,rCnt,dx[i],dy[i]);
			move(nbx, nby,bCnt,dx[i],dy[i]);

			if (map[nbx][nby] == 'O') continue;
			if (map[nrx][nry] == 'O') {
				printf("1\n");
				return;
			}

			if (nrx == nbx && nry == nby) {
				if (rCnt > bCnt)
					nrx -= dx[i], nry -= dy[i];
				else
					nbx -= dx[i], nby -= dy[i];
			}

			if (check[nrx][nry][nbx][nby]) continue;
			check[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby, d+1 });
		}
	}
	printf("0\n");
}

int main() {
	cin >> n >> m;
	int rx = 0, ry = 0, bx = 0, by = 0;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				rx = i, ry = j;
			}
			else if (map[i][j] == 'B') {
				bx = i, by = j;
			}
		}
	}
	q.push({ rx,ry,bx,by,0});
	check[rx][ry][bx][by] = true;
	bfs();
	return 0;
}