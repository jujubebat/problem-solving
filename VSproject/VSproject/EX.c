#include<vector>
using namespace std;

struct OptimazedDisjointSet {

	vector<int> parent, rank;

	//n개의 원소가 각각의 집합에 포함되어 있도록 초기화한다. 
	OptimazedDisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	//find(u)를 통해 u가 속하는 트리의 루트를 찾아냈다. 이때 parnet[u]를 찾아낸 루트로 아예 바꿔 버리면,
	//다음번에 find(u)가 호출되었을 때는 경로를 따라 올라갈 것 없이 바로 루트를 찾을 수 있다.
	//즉, 부모노드를 루트노드로 바꿔버리는 것이다. 
	//재귀적인 구현 덕분에 u에서 루트까지 올라가는 경로상에 있는 모든 노드들에도 경로 압축 최적화가 자동으로 수행된다.
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	//두 개의 트리를 합칠 때, 항상 높이가 더 낮은 트리를 더 높은 트리 및에 집어 넣는다.
	//그럼으로서 트리의 높이가 높아지는 상황을 방지한다. (사향 트리 방지)
	void doUnion(int u, int v) {
		u = find(u);
		v = find(v);

		if (u == v) return; //u와 v가 이미 같은 집합에 속하는 경우를 걸러낸다.
		if (rank[u] > rank[v]) swap(u, v); //이제 rank[v]가 항상 rank[u] 이상이므로 u를 v의 자식으로 넣는다.
		parent[u] = v; 
		if (rank[u] == rank[v]) rank[v]++; //두 트리의 높이가 같을 경우에만 트리의 높이를 1 늘려준다.
	}

};

