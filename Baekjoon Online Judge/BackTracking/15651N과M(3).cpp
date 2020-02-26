//중복순열
#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> v;

void dfs() {
	if (v.size() == m) {
		for (int i : v) {
			printf("%d ", i);
		}
		puts("");
		return;
	}

	for (int i = 1; i <= n; i++) {
			v.push_back(i);
			dfs();
			v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	dfs();
	return 0;
}
//1234, 두개뽑는 중복 순열
//11, 12, 13, 14, 21, 22,23,24, 31,32,33,34, 41,42,43,44
