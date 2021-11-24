#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int>> adj[1001]; // (������ȣ, ����ġ)
int n, m, x, ret = -1;

void dijkstra(int src, vector<int>& dist) {
	dist[src] = 0;
	priority_queue<pair<int, int>> pq; // (�ִܰ��, ������ȣ)
	pq.push({ 0, src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextCost = cost + adj[here][i].second;
			
			if (dist[there] > nextCost) {
				dist[there] = nextCost;
				pq.push({ -nextCost, there });
			}
		}
	}

}

int main() {

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	// ��Ƽ���� �����ΰ��� �ִܰ�� ���ϱ�
	vector<int> distToHome(1001, 0x7fffffff);
	dijkstra(x, distToHome);

	// �� �л��� ��Ƽ�� ���� �ִܰ�� ���ϱ�
	for (int i = 1; i <= n; i++) {
		vector<int> distToParty(1001, 0x7fffffff);
		dijkstra(i, distToParty);
		ret = max(ret, distToHome[i] + distToParty[x]);
	}

	cout << ret;

	return 0;
}