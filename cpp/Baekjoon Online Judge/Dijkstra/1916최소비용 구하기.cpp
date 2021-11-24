/***************
date : 20/02/01
design time : 2 min
implementation time : 15 min
debugging time : 0 min
****************/

/* <설계>
-다익스트라 알고리즘
-a정점에서 b정점으로 가는 최단 경로 구하기.
-adj 인접행렬 그래프 만들고, dijkstra 한번 돌리고
-res[b] 출력.
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];//{가중치, 정점}
const int INF = 0x7fffffff;

vector<int> dijkstra(int src) {
	vector<int> dist(n+1, INF);
	priority_queue<pair<int, int>> pq;
	dist[src] = 0;//시작점 최단 거리 0 셋팅
	pq.push({ 0,src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue; //최단 경로가 아닐경우 스킵

		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].second;
			int nextDist = cost + adj[here][i].first;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ -nextDist,there });//min heap
			}
		}
	}
	return dist;
}

int main() {
	int a, b;

	scanf("%d %d", &n, &m);
	getchar();

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		getchar();
		adj[u].push_back({ w,v });
	}

	scanf("%d %d", &a, &b);

	vector<int> res = dijkstra(a);

	printf("%d", res[b]);
}