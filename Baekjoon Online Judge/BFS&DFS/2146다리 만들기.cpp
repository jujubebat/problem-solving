/***************
date : 20/02/07
design time : 25min
implementation time : 32 min
debugging time : 0 min
****************/

/*
//탐색을 시작하는 섬은 2로 표시한다.
//바다와 인접하는 육지에서 bfs를 돌린다. 
//체크배열에 거리를 기록하면서 탐색한다.
//이과정에서 만약 다른 섬을 만났다면, 그 경로에 대한 최소값을 기록한다. 
*/

/*
탐색시작하기 전에 현재 조회중인 섬을 dfs를 사용하여 숫자로 표시(2부터 시작)
현재 조회중인 섬중 바다와 인접한 지역에서 bfs를 돌림(체크배열사용)
현재 섬에서 바다와 인접하는 육지를 택해서, bfs를 돌린다.(0부터 기록해서 다른섬에 닿는다면, 최소값기록하고 종료)
시간초과 문제 없을거 같음(bfs의 시간복잡도는 O(v+e)이니까..
*/
#include<iostream>
#include<queue>

using namespace std;
typedef struct {
	int x;
	int y;
}pos;

int map[100][100];
int check[100][100];
int res = 1e9;
int n, num = 1;
int dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};
queue<pos> curLand;
queue<pos> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny] == num) continue; //현재조회중인 섬이면 스킵
			if (map[nx][ny] != 0) {//다른섬일경우
				if (check[x][y] + 1 < res)
					res = check[x][y] + 1; //거리최솟값기록
				continue;
			}
			if (check[nx][ny] != 0) continue;
			if (check[x][y] > res) continue; // 현재 최소길이보다 길다면
			check[nx][ny] = check[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	puts("");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ",check[i][j]);
		}
		puts("");
	}
	puts("");
}

void findShortest() {
	int flag = false;
	while (!curLand.empty())
	{
		int x = curLand.front().x, y = curLand.front().y;
		curLand.pop();
		flag = false;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny] == 0)
				flag = true; //바다와 인접한 육지라면 true
		}

		fill(&check[0][0], &check[n][n], 0);//체크배열 초기화 
		if (flag) {
			q.push({ x,y });
			check[x][y] = -1;
			bfs();
		}
	}
}

void dfs(int x, int y) {
	map[x][y] = num;
	curLand.push({ x,y });
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
		if (map[nx][ny] != 1) continue;
		dfs(nx, ny);
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				num++; 
				dfs(i,j);
				findShortest();
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	printf("%d", res);
}