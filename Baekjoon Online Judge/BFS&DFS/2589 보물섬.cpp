/***************
date : 20/02/11
design time :  10 min
implementation time :  17min
debugging time :   min
total time :  min
****************/

/*
각 육지마다 BFS를 돌려서 최댓값을 구한다.
*/
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct {
	int x, y;
}pos;

int n, m;
char map[50][50];
int check_map[50][50];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
int res = 0;
queue<pos> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue; //범위
			if(check_map[nx][ny] != 0) continue; //방문여부
			if (map[nx][ny] != 'L') continue; //육지여부
			int time = check_map[x][y] + 1;
			check_map[nx][ny] = time;
			if (time > res) res = time;
			q.push({ nx,ny });
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				q.push({ i,j });
				memset(check_map, 0, sizeof(check_map));
				//fill(&check_map[0][0], &check_map[n][m], 0);
				/*
				puts("");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						printf("%d ", check_map[i][j]);
					}
					puts("");
				}
				puts("");
				*/
				check_map[i][j] = 1;
				bfs();
			}
		}
	}
	if (res == 0)
		printf("0");
	else
		printf("%d", res-1);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	solve();
}