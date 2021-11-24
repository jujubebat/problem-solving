#include<iostream>

using namespace std;

bool num[1000000];
int map[5][5];
int res = 0;
int dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};

void dfs(int x, int y, int cnt, int number) {
	if (cnt == 6) {
		num[number] = true;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 5 || nx < 0 || ny >= 5 || ny < 0)continue;
		dfs(nx, ny, cnt + 1, number * 10 + map[nx][ny]);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i,j,1,map[i][j]);
		}
	}
	
	for (int i = 0; i < 1000000; i++) {
		if (num[i])
			res++;
	}
	printf("%d", res);
}