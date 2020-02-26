
//벽을 부순경우와 부수지 않은 두 경우로 나눈다.
//벽을 부순 여러 경우는 하나의 배열에 기록해도 문제 되지 않는다. (이해가 가지 않음 잘..)
//다시 풀어봐야하는 문제

#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	int x, y, w; // w가 1이면 벽을 부순 것임
}pos;

int n, m;
int map[1000][1000];
int visited[1000][1000][2];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
queue<pos> q;

int bfs() {
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, w = q.front().w;
		q.pop();

		if (x == n - 1 && y == m - 1) return visited[x][y][w]; //끝까지 도달하면 결과 리턴

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue; //범위 벗어나면 스킵
			if (visited[nx][ny][w]) continue; //이미 기록된 위치라면 스킵

			if (map[nx][ny] == 0) {//다음 위치가 이동 가능하면
				visited[nx][ny][w] = visited[x][y][w] + 1;
				q.push({ nx,ny,w });
			}
			if (map[nx][ny] == 1 && w == 0) { //다음 위치가 벽이고, 벽을 부술 수 있다면,
				visited[nx][ny][1] = visited[x][y][w] + 1;
				q.push({ nx,ny,1 });
			}

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					printf("%d", visited[j][k][0]);

				}
				puts("");

			}
			puts("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ");

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					printf("%d", visited[j][k][1]);
				}
				puts("");
			}
			puts("");
		}
	}

	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d", bfs());

	return 0;
}

