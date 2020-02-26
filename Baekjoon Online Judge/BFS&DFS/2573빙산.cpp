
//얼음이 녹는 시뮬레이션 함수
//빙산 분리 확인 함수
//빙산이 분리 되는 최초의 년도를 구해야함
//설계가 엉성했음 너무.. 
//생각을 제대로 안하고 짜서 잔오류가 너무 많았음

#include<iostream>

using namespace std;

int map[300][300],tmp_map[300][300];
bool visited[300][300];
int res;
int n, m;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

void melting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int iceNum = 0;
			if (map[i][j] > 0) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (map[nx][ny] == 0) iceNum++;
				}
			}
			int height = map[i][j] - iceNum;
			if (height < 0)
				tmp_map[i][j] = 0;
			else
				tmp_map[i][j] = height;
		}
	}
	copy(&tmp_map[0][0], &tmp_map[n-1][m-1], &map[0][0]);
}

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (map[nx][ny] == 0) continue;
		if (visited[nx][ny]) continue;
		dfs(nx, ny);
	}
}

bool isDivided() {
	fill(&visited[0][0], &visited[n][m], false);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0 && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	if (cnt >= 2)
		return true;
	else
		return false;
}
bool isAllmelted() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0) {
				return false;
			}
		}
	}
	return true;
}

void solve() {
	while (1) {
		melting();
		res++;
		if (isDivided())
			break;
		if (isAllmelted())
		{
			printf("0\n");
			return;
		}
	}
	printf("%d", res);
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
