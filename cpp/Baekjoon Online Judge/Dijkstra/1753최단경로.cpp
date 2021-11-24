#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int v, e, k;
vector<pair<int, int>> adj[20001]; //정점까지의 최단거리, 정점
const int INF = 0x7fffffff;

vector<int> dijkstra(int src) {
	vector<int> dist(v+1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, src });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].second;
			int nextDist = cost + adj[here][i].first;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ -nextDist,there });
			}
		}
	}
	return dist;
}

int main() {
	
	scanf("%d %d", &v, &e);
	getchar();
	scanf("%d", &k);
	getchar();

	int a, b, c;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ c,b });
		getchar();
	}

	vector<int> res = dijkstra(k);

	for (int i = 1; i <= v; i++) {
		if (res[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", res[i]);
	}
}