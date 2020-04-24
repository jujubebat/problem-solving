#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct UnionFind{
	vector<int> parent, rank;

	UnionFind(int n) : parent(n), rank(n,1) {
		for (int i = 0; i < n; i++) {
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
		cin >> op >> a >> b;

		if (op == 0) {
			uf.doUnion(a-1, b-1);
		}
		else if (op == 1) {
			if (uf.find(a-1) == uf.find(b-1))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0; 
}