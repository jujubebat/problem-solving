//바이러스 위치 뽑는 함수 (조합)
//바이러스 퍼뜨리는 함수 (BFS)
//바이러스 다 퍼졌는지 확인하는 함수(최소시간 갱신)

#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

typedef struct {
	int x, y;
}pos;

int n, m;
int map[50][50];
int visited[50][50];
int res = 1e9;

vector<pos> vir_loc;
vector<pos> v;
queue<pos> q;

int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void bfs() {

	while (!q.empty()){
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny] == 1) continue;
			if (visited[nx][ny]) continue;

			visited[nx][ny] = visited[x][y]+1;
			q.push({ nx,ny });
		}
	}

	int time=-1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) continue;
			if (visited[i][j] == 0) return;
			time = max(time, visited[i][j]);
		}
	}

	res = min(time-1,res);
}


void dfs(int cnt) {
	if (v.size() == m) {
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < m; i++) {
			visited[v[i].x][v[i].y] = 1;
			q.push(v[i]);
		}

		bfs();
		return;
	}

	for (int i = cnt; i < vir_loc.size(); i++) {
		v.push_back(vir_loc[i]);
		dfs(i + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				vir_loc.push_back({ i,j });
				map[i][j] == 0;
			}
		}
	}

	dfs(0);

	if (res == 1e9)
		cout << -1;
	else
		cout << res;
	return 0;
}

