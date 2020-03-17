#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> arr;
vector<int> v;

void dfs(int cnt) {
	if (v.size() == m) {
		for (int x : v) {
			printf("%d ", x);
		}
		puts("");
		return;
	}

	bool visited[10001] = { false };

	for (int i = cnt; i < n; i++) {
		if (!visited[arr[i]]) {
			visited[arr[i]] = true;
			v.push_back(arr[i]);
			dfs(i);
			v.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	dfs(0);

	return 0;
}

// 1799