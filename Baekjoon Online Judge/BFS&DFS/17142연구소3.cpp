#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

typedef struct {
	int x, y;
}pos;

int map[50][50];
int visited[50][50];
int n, m;
int res = 1e9;
vector<pos> virPos;
vector<pos> v;
queue<pos> q;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void bfs(){
	while (!q.empty()){
		int x = q.front().x, y = q.front().y;
		q.pop();
			
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == 1) continue;

			visited[nx][ny] = visited[x][y] + 1;
			q.push({ nx,ny });
			
		}
	}

	int cnt = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 1 && visited[i][j] == 0) return;
			if (map[i][j] == 2 && visited[i][j] != 1) continue;
			cnt = max(cnt, visited[i][j]);
		}
	}
	res = min(res, cnt);
}

void combination(int cnt) {

	if (v.size() == m) {
		memset(visited, 0, sizeof(visited));
		for (pos p : v) {
			visited[p.x][p.y] = 1;
			q.push(p);
		}

		bfs();
		return;
	}

	for (int i = cnt; i < virPos.size(); i++) {
		v.push_back(virPos[i]);
		combination(i + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virPos.push_back({ i,j });
			}
		}
	}

	combination(0);

	if (res == 1e9)
		cout << -1;
	else
		cout << res - 1;

	return 0;
}