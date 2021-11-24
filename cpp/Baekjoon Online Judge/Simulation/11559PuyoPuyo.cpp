//뿌요를 터뜨리는 함수, 뿌요가 터뜨려지면 cnt++;
//4연결인지 판별 -> dfs
//중력작용함수

#include<iostream>
#include<string.h>
using namespace std;

char map[12][6];
int visited[12][6];
bool check[12][6];
int res = 0;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
char puyo;
int cnt;

void dfs(int x, int y) {
	visited[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 12 || nx < 0 || ny >= 6 || ny < 0) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] != puyo) continue;
		cnt++;
		dfs(nx, ny);
	}
}

bool boomCheck() {
	int flag = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] != '.') {
				memset(visited, 0, sizeof(visited));
				cnt = 1;
				puyo = map[i][j];
				dfs(i,j);
				if (cnt >= 4) {
					flag = true;
					for (int k = 0; k < 12; k++) {
						for (int l = 0; l < 6; l++) {
							if (visited[k][l])
								check[k][l] = true;
						}
					}
				}
			}
		}
	}
	return flag;
}

void boom() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (check[i][j]) {
				map[i][j] = '.';
			}
		}
	}
	memset(check, 0, sizeof(check));
	int flag = false;
	int cnt=0;
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >=0; i--) {
			if (map[i][j] == '.') continue;
			for (int k = 11; k >= i; k--) {
				if (map[k][j] == '.') {
					map[k][j] = map[i][j];
					map[i][j] = '.';
					break;
				}
			}
		}
	}
}

void solve() {
	while (1) {
		if (boomCheck()) {
			boom();
			res++;
		}
		else
			break;
	}
	printf("%d", res);
}

int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	return 0;
}