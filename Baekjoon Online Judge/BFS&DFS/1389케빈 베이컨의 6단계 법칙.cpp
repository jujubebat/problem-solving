#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int n, m;
vector<int> arr[100];
bool visited[100];
int res = 1e9;
int score[100];
int sum[100];

void dfs(int n, int cnt) {
	visited[n] = true;
	if (score[n] != 0)
		score[n] = min(score[n], cnt);
	else
		score[n] = cnt;
	for (int x : arr[n]) {
		if (!visited[x]) {
			dfs(x, cnt + 1);
			visited[x] = false;
		}
	}
}

void solve() {
	int minValue = 1e9;
	for (int i = 1; i <= n; i++) {
		memset(score, 0, sizeof(score));
		memset(visited, 0, sizeof(visited));
		dfs(i, 0);

		int num = 0;
		for (int j = 1; j <= n; j++) {
			num += score[j];
		}
		sum[i] = num;

		if (num < minValue) {
			minValue = num;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (sum[i] == minValue) {
			printf("%d", i);
			break;
		}
	}
}

int main() {
	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	solve();
	return 0;
}