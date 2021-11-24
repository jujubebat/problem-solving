//중복조합
#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int>	v;
bool visited[10];

void dfs(int cnt) {

	if (v.size() == m) {
		for (int i : v) {
			printf("%d ", i);
		}
		puts("");
		return;
	}

	for (int i = cnt; i <= n; i++) {
		v.push_back(i);
		dfs(i);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	dfs(1);
	return 0;
}