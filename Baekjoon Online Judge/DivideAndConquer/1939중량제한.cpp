#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int,int>> adj[10001]; // 정점 번호, 중량
int s, d;

bool bfs(int w) {
	bool visited[10001] = { false };
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == d) return true;

		for (int i = 0; i < adj[cur].size(); i++) {
			if (visited[adj[cur][i].first]) continue; 
			if (adj[cur][i].second < w) continue;
			visited[adj[cur][i].first] = true;
			q.push(adj[cur][i].first);
		}
	}
	
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}

	cin >> s >> d;

	int low = 0, high = 1000000000;
	int ret = 0;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (bfs(mid)) { // 도착가능하다면
			ret = max(ret, mid); 
			low = mid + 1; //중량을 올려보자.
		}
		else { // 도착 불가능하면
			high = mid - 1; // 중량을 내려본다. 
		}
	}

	cout << ret;
	return 0;
}