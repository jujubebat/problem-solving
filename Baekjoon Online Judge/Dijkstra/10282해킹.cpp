#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<pair<int, int>> adj[10001]; // <정점, 가중치>
int n, d, c;

void dijkstra(int src, vector<int>& dist) { // 다익스트라 알고리즘.

	priority_queue<pair<int, int>> pq; // <가중치, 정점>

	dist[src] = 0; // 시작점 최단거리 0으로 초기화.
	pq.push({ 0, src }); // pq에 넣는다.

	while (!pq.empty()) {
		int cost = -pq.top().first; // 현재까지 구한 최단거리(minHeap 이므로 '-' 를 붙여줌).
		int here = pq.top().second; // 정점.
		pq.pop();

		if (dist[here] < cost) continue; // 이미 더 짧은 최단거리가 구해졌으면, 스킵.

		for (int i = 0; i < adj[here].size(); i++) { // 인접 정점 검사.
			int next = adj[here][i].first; // 다음에 방문할 정점.
			int nextCost = cost + adj[here][i].second; // 다음에 방문할 정점까지의 거리.

			if (dist[next] > nextCost) { // 다음에 방문할 정점까지의 거리가 최단거리라면,
				dist[next] = nextCost; // 최단 거리 갱신.
				pq.push({ -nextCost, next }); // pq에 넣어준다.
			}
		}
	}
}

int main() {
	int t;
	cin >> t; // 테스트 케이스 입력

	while (t--) {

		for (int i = 0; i <= n; i++) { // 인접 리스트 그래프 초기화.
			adj[i].clear();
		}

		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].push_back({ a,s }); // b 컴퓨터가 감염되면, s초후 a 컴퓨터 감염.
		}

		vector<int> dist(10001, 0x7fffffff); // 최단 거리 배열 초기화.
		dijkstra(c, dist); // 시작점 : 최초 해킹 당한 컴퓨터 c.

		int cnt = 0, time = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] < 0x7fffffff) { // 감염된 컴퓨터일 경우.
				cnt++; // 수 증가.
				// 마지막 컴퓨터가 감염되기까지 걸린 시간 = 최단 거리중 가장 큰 값.
				time = max(time, dist[i]); 
			}
		}

		cout << cnt << " " << time << endl; // 결과 출력.
	}

	return 0;
}