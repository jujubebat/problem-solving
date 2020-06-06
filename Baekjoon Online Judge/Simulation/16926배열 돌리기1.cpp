#include<vector>
#include<queue>
using namespace std;

// 정점의 개수
int V;

// 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치) 쌍을 담는다.
vector<pair<int, int>> adj[100];

vector<int> dijkstra(int src) {
	vector<int> dist(V, 0x7fffffff); // 각 정점의 최단 경로를 담는 dist 배열은 초기에 최대값으로 셋팅한다. 
	dist[src] = 0;
	priority_queue<pair<int, int>> pq; // (해당 정점에 대한 현재까지 구한 최단경로, 정점 번호)
	pq.push({ 0, src });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면, 지금꺼낸 것을 무시한다.
		if (dist[here] < cost) continue;

		//인접한 정점들을 모두 검사한다.
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first; // 인접 정점 번호
			int nextDist = cost + adj[here][i].second; // 해당 인접 정점까지의 거리 

			if (dist[there] > nextDist) { // 인접 정점에 대한 최단 경로라면,
				dist[there] = nextDist; // dist 배열에 업데이트
				pq.push({ -nextDist, there }); // (해당 정점에 대한 새로운 최단경로, 정점 번호)
			}
		}
	}

	return dist;
}