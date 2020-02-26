//¼ø¿­ 
#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> v;
bool visited[10];

void dfs() {
	if (v.size() == m) {
		for (int i : v) {
			printf("%d ", i);
		}
		puts("");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			dfs();
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs();
	return 0;
}