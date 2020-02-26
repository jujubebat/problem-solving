#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> arr;
int n, m;

void dfs(int cnt) {
	if (v.size() == m) {
		for (int x : v) {
			printf("%d ", x);
		}
		puts("");
	}

	bool check[10001] = { false };
	for (int i = cnt; i < n; i++) {
		if (!check[arr[i]]) {
			check[arr[i]] = true;
			v.push_back(arr[i]);
			dfs(i + 1);
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