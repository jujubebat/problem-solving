//bfs 기본 개념에 충실해서 비교적 쉽게 풀었음, 
//정점을 큐에넣을때 방문 표시를 해줘야 bfs가 올바르게 작동하는데, 정점을 큐에서 빼고 방문 처리를 해주는 실수를 하여 중복 방문을 저질러 메모리 초과 오류가 발생했었음

#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef struct {
	int x;
	int y;
}cabbage;

int t, m, n, k;
int map[50][50];
queue<cabbage> q;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 }; //x는 행, y는 열 

void bfs(int a, int b) {
	q.push({ a,b });
	map[a][b] = 0;
	
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //배열범위 벗어나면 예외
			if (map[nx][ny] == 1) {
				map[nx][ny] = 0;
				q.push({ nx,ny });
			}
		}
	}
}

int solve() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				bfs(i,j);
				res++;
			}
		}
	}
	return res;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		int x, y;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		int res = solve();
		printf("%d\n", res);
		memset(map, 0, sizeof(map));
	}
	return 0;
}