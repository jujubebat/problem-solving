//а╤гу
#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int>	v;

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
			dfs(i+1);
			v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	dfs(1);
	return 0;
}
//1234
//12, 13,14, ,23,24, 34.