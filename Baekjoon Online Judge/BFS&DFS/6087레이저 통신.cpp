#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int x, y;
}pos;

int w, h;
char map[100][100];
int visited[100][100];
queue<pos> q;
int res_x, res_y;
int dx[] = { 0,0,-1,1 }, dy[] = { 1,-1,0,0 };

void bfs() {
	while (!q.empty()){
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			while (nx >=0 && nx <h && ny >=0 && ny <w && map[nx][ny]!='*'){
				if (visited[nx][ny] == 0) {
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx,ny });
				}
				nx += dx[i], ny += dy[i];
			}
		}
	}
}

int main() {
	bool flag = true;

	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				if (flag) {
					q.push({ i,j });
					flag = false;
				}
				else{
					res_x = i, res_y = j;
				}
			}
		}
	}

	bfs();
	cout << visited[res_x][res_y]-1;
	return 0;
}