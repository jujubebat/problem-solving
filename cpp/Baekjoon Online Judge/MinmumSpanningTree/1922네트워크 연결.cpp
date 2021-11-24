#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> rank;

	UnionFind(int n) : parent(n), rank(n,0) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void doUnion(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return;

		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;

		if (rank[u] == rank[v]) rank[v]++;
	}
};

int n, m;

int main() {
	cin >> n;
	cin >> m;

	vector< pair<int, pair<int, int>>> edgeList;

	for (int i = 0; i < m; i++) {
		pair<int, pair<int, int>> edge;
		int u, v, cost;
		scanf_s("%d %d %d", &edge.second.first, 
			&edge.second.second, &edge.first);
		edgeList.push_back(edge);
	}

	sort(edgeList.begin(), edgeList.end());


	UnionFind uf(n);
	int ret=0;

	for (int i = 0; i < edgeList.size(); i++) {
		int u = uf.find(edgeList[i].second.first-1);
		int v = uf.find(edgeList[i].second.second-1);
		if (u == v) continue;
		uf.doUnion(u, v);
		ret += edgeList[i].first;
	}

	cout << ret;

	return 0;
}