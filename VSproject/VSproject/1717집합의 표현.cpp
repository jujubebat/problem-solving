#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct UnionFind{
	vector<int> parent, rank;

	UnionFind(int n) : parent(n+1), rank(n+1,1) {
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u == parent[u]) 
			return u;
		else 
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

int main() {
	int n, m;

	cin >> n >> m;

	UnionFind uf(n);

	for (int i = 0; i < m; i++) {
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);

		if (op == 0) {
			uf.doUnion(a, b);
		}
		else if (op == 1) {
			if (uf.find(a) == uf.find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0; 
}