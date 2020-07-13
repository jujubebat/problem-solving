#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[100001];
bool check[100001];
int ret[100001];

void dfs(int parent, int num) {
	ret[num] = parent;
	check[num] = true;

	for (int i = 0; i < tree[num].size(); i++) {
		if (!check[tree[num][i]])
			dfs(num,tree[num][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(0,1);

	for (int i = 2; i <= n; i++)
		cout << ret[i] << '\n';
	
	return 0;
}