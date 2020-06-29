#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[501];
bool check[501];

typedef struct {
	int num, dist;
}person;

void bfs() {
	int ret = 0;

	queue<person> q;
	check[1] = true;
	q.push({ 1,0 });

	while (!q.empty()) {
		int num = q.front().num;
		int dist = q.front().dist;
		q.pop();

		if (num != 1 && dist <= 2) {
			ret++;
		}

		for (int i = 0; i < adj[num].size(); i++) {
			if (check[adj[num][i]]) continue;
			check[adj[num][i]] = true;
			q.push({ adj[num][i], dist + 1 });
		}
	}

	cout << ret;

}

int main() {
	int n;
	cin >> n;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();

	return 0;
}