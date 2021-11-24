#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int n, a, b, m;
vector<int> adj[101];
int check[101];
queue<int> q;

void bfs(int n) {
	check[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : adj[x]) {
			if (check[y] == -1) {
				check[y] = check[x] + 1;
				q.push(y);
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> a >> b;
	cin >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	fill(&check[0], &check[n+1], -1);

	bfs(a);

	printf("%d ", check[b]);
}