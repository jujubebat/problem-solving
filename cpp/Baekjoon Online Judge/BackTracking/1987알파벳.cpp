//dfs로 구현 
//지나온 알파벳 목록을 dfs 매개변수로 계속넘겨준다.
//탈출조건 : 이미 지나온 알파벳일 경우 최대값 갱신하고 탈출
//매개변수 : x,y,cnt,알파벳 목록

#include<iostream>
#include<vector>

using namespace std;

int r, c,res = 0;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
char map[20][20];
bool history[26];
bool visited[20][20]; //2차원 배열을 0으로 초기화 안되나? 지역변수라 그런가?

void dfs(int x, int y, int cnt) {
	if (cnt > res) res = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= r || nx < 0 || ny >= c || ny < 0) continue;
		if (visited[nx][ny]) continue;
		if (history[map[nx][ny] - 'A']) continue;

		visited[nx][ny] = true;
		history[map[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt + 1);
		history[map[nx][ny] - 'A'] = false;
		visited[nx][ny] = false;
	}
}

int main() {
	scanf("%d %d", &r, &c);
	getchar();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%1c", &map[i][j]);
		}
		getchar();
	}
	visited[0][0] = true;
	history[map[0][0] - 'A'] = true;
	dfs(0,0,1);
	printf("%d", res);
}

