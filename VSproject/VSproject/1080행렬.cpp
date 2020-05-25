#include<iostream>
#include<algorithm>
using namespace std;

int ladderOrSnake[100];
int ret = 0x7fffffff;
bool visited[100][100];

void solve(int cur, int cnt) {

	if (cur == 100) {
		ret = min(ret, cnt);
	}

	for (int i = 1; i <= 6; i++) {
		int nCur;

		if (ladderOrSnake[cur + i]) {
			nCur = ladderOrSnake[cur + i];
		}
		else
			nCur = cur + i;

		if (nCur > 100) continue;

		if (visited[nCur][cnt + 1]) continue;
		visited[nCur][cnt + 1] = true;

		solve(nCur, cnt + 1);
	}

}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ladderOrSnake[x] = y;
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ladderOrSnake[u] = v;
	}

	visited[1][0] = true;
	solve(1, 0);

	cout << ret;

	return 0;
}