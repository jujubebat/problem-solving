//오름차순 중복 조합
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
vector<int> v;
int n, m;

void dfs(int cnt) {
	if (v.size() == m) {
		for (int x : v)
			printf("%d ", x);
		puts("");
		return;
	}

	for (int i = cnt; i < n; i++) {
		v.push_back(arr[i]);
		dfs(i);
		v.pop_back();
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