//dfs로 품 . 나중에 bfs로 풀어보기
//구현자체는 빨리했음. 입력문제로 시간 많이 잡아먹었음(getchar로 해결)

#include<iostream>
#include<string.h>

using namespace std;

int n;
int cnt = 0;
char map[100][100];
int check[100][100];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
char color;

void dfs_1(int x, int y) {
	check[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
		if (map[nx][ny] != color || check[nx][ny] != 0) continue;
		dfs_1(nx, ny);
	}
}

void dfs_2(int x, int y) { //색약
	check[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
		if (map[nx][ny] == 'G') map[nx][ny] = 'R';
		if (map[nx][ny] != color || check[nx][ny] != 0) continue;
		dfs_2(nx, ny);
	}
}

int main() {
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1c", &map[i][j]);
		}
		getchar();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				color = map[i][j];
				dfs_1(i, j);
				cnt++;
			}
		}
	}

	printf("%d ", cnt);

	memset(check, 0, sizeof(check));
	cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				if (map[i][j] == 'G') 
					color = 'R';
				else
					color = map[i][j];

				dfs_2(i, j);
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}




