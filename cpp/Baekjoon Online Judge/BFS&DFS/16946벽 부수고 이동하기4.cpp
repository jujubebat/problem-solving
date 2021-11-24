#include<iostream>
#include<queue>
#include<set>
#include<vector>
using namespace std;

typedef struct {
	int x, y;
}pos;

int map[1000][1000];
int res[1000][1000];
int n, m;
const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

int visited[1000][1000];

int group[1000001];
int cnt = 1;

void dfs(int x, int y) {
	visited[x][y] = cnt;
	group[cnt]++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny]) continue;
		dfs(nx, ny);
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				set <int> s;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
					s.insert(visited[nx][ny]);
				}
				
				res[i][j] += 1;
				for (int x : s) {
					res[i][j] += group[x];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", res[i][j]%10);
		}
		puts("");
	}
	puts("");

}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	solve();
	return 0;
}