//dfs로 그룹짓고.
//지은 그룹에 대해서 맵변경하고(++인구이동횟수)
//그룹 하나라도 지을 수 없으면 종료
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct {
	int x, y;
}pos;

int N, L, R;
int map[50][50];
int res;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int cnt=1;
int visited[50][50];
int arr[2501];

bool bfs(int sx, int sy, int cnt) {
	queue<pos> q;
	bool flag=false;

	int numOfUnited = 1;
	int sumOfUnited = map[sx][sy];

	visited[sx][sy] = cnt;
	q.push({ sx, sy });

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
			if (visited[nx][ny]) continue;

			int diff = abs(map[x][y] - map[nx][ny]);
			if (diff >= L && diff <= R) {
				flag = true;
				visited[nx][ny] = cnt;

				numOfUnited++;
				sumOfUnited += map[nx][ny];

				q.push({ nx,ny });
			}
		}
	}

	arr[cnt] = sumOfUnited / numOfUnited;

	if (!flag)
		visited[sx][sy] = 0;

	return flag;
}

bool openLoad() {

	bool flag = false;
	memset(visited, 0, sizeof(visited));
	cnt = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0) {
				
				bool signal = bfs(i, j, cnt);

				if (!flag) {
					if (signal)
						flag = true;
				}

				cnt++;
			}
		}
	}

	return flag;
}

void moving() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) {
				map[i][j] = arr[visited[i][j]];
			}
		}
	}
}

void solve() {
	while (1) {
		if (openLoad()) {
			moving();
			res++;
		}
		else {
			cout << res;
			return;
		}
	}
}

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	solve();

	return 0;
}