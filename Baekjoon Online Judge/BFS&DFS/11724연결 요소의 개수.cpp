#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[1001];
int visited[1001];
int res = 0;

void dfs(int n) {
	visited[n] = true;
	for (int x : adj[n]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}

int main() {
	int n, m;
	int u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			res++;
		}
	}
	printf("%d", res);
}