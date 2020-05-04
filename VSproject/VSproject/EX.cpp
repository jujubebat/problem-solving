#include<vector>
#include<algorithm>

using namespace std;

struct DisjointSet;
const int MAX_V = 100;
int V; //정점의 개수
vector<pair<int, int>> adj[MAX_V]; //그래프의 인접리스트. (연결된 정점 번호, 간선 가중치) 쌍을 담는다.


int kruskal(vector<int, pair<int, int>>& selected) {
	int ret = 0;
	selected.clear();

	// (가중치, (정점1, 정점2)) 목록을 얻는다. 
	vector <pair<int, pair<int, int>>> edges;
	for (int u = 0; u < V; u++) {
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back({ cost, {u,v} });
		}
	}

	//가중치 순으로 정렬한다. 
	sort(edges.begin(), edges.end());

	DisjointSet sets(V);

	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;

		//u와 v가 같은 집합이라면, 현재 조회중인 간선을 추가하지 않는다.
		if (sets.find(u) == sets.find(v)) continue;
		set.doUnion(u, v);
		selected.push_back({ u,v });
		ret += cost;
	}

	return ret;
}