// 위쪽부터 위쪽에 가까운 파이프를 설치한다.(그리디하게)
// 위쪽에서 방문한 경로는 방문하지 않도록한다. 
// 위족에서 방문한 경로는 파이프 설치가 실패했더라도 방문하지
// 않는다. 어차피 그 경로는 답이 없는 경로이다. 

#include<iostream>
using namespace std;

char map[10000][500];
int r, c;

const int dx[] = { -1,0,1 }, dy[] = { 1,1,1 };

bool dfs(int x, int y) {
	map[x][y] = 'x';

	if (y == c - 1)
		return true;

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= r || nx < 0 || ny >= c || ny < 0) continue;
		if (map[nx][ny] == 'x') continue;
		if (dfs(nx, ny))
			return true;
	}

	return false;
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	int ret = 0;

	//첫 번째 열 위쪽부터 탐색해본다.  
	for (int row = 0; row < r; row++) {
		if (dfs(row, 0)) // 파이프 설치가 가능하면
			ret++;
	}

	cout << ret;
	return 0;
}

