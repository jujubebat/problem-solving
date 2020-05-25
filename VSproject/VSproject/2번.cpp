// 스택 오버플로우가 나는 버전
#include<iostream>
#include<algorithm>
using namespace std;

int ladderOrSnake[100];
int ret = 0x7fffffff;
bool visited[100][100];

void solve(int cur, int cnt) {
	for (int i = 1; i <= 6; i++) {
		int nCur = cur + i;
		int nCnt = cnt + 1;

		if (nCur >= 100) {
			if(nCur == 100)
			ret = min(ret, nCnt);
			continue;
		}

		if (ladderOrSnake[nCur]) {
			nCur = ladderOrSnake[nCur];
		}

		if (nCur >= 100) {
			if(nCur == 100)
			ret = min(ret, nCnt);
			continue;
		}

		if (visited[nCur][nCnt]) continue;
		visited[nCur][nCnt] = true;
		solve(nCur, nCnt);
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
/*
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int ladderOrSnake[100];
int ret = 0x7fffffff;
bool visited[100][100];

void bfs() {
	queue<pair<int, int>> q;
	visited[1][0] = true;
	q.push(make_pair(1, 0));

	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nCur = cur + i;
			int nCnt = cnt + 1;

			if (nCur >= 100) {
				if (nCur == 100) {
					ret = min(ret, nCnt);
				}
				continue;
			}

			if (ladderOrSnake[nCur])
				nCur = ladderOrSnake[nCur];

			if (nCur >= 100) {
				if (nCur == 100) {
					ret = min(ret, nCnt);
				}
				continue;
			}

			if (visited[nCur][nCnt]) continue;
			visited[nCur][nCnt] = true;
			q.push({ nCur, nCnt });
		}
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

	bfs();
	cout << ret;

	return 0;
}*/