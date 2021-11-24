//25개중에 7개를 뽑는 조합을 만듬
//각 조합마다 이다솜파의 수를 체크, dfs로 조직원들이 인접해있는지 체크
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

char map[5][5];
int res;
bool visited[5][5];
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
vector<int> v;
int dfsCnt;

void dfs(int x, int y) {
	visited[x][y] = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 5 || nx < 0 || ny >= 5 || ny < 0) continue;
		if (visited[nx][ny]) {
			dfsCnt++;
			dfs(nx, ny);
		}
	}
}

void combination(int cnt, int numOfY) {
	int x = cnt / 5, y = cnt % 5;

	if (numOfY >= 4) {
		return;
	}

	if (v.size() == 7) {
		memset(visited, 0, sizeof(visited));
		for (int x : v) {
			visited[x / 5][x % 5] = true;
		}
		dfsCnt = 1;
		dfs(v[0] / 5, v[0] % 5);
		if (dfsCnt == 7)
			res++;
		return;
	}

	for (int i = cnt; i < 25; i++) {
		bool flag = false;
		v.push_back(i);
		if (map[i/5][i%5] == 'Y') flag = true;
		if(flag)
			combination(i + 1, numOfY+1);
		else
			combination(i + 1, numOfY);
		v.pop_back();
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	combination(0,0);
	printf("%d", res);
	return 0;
}