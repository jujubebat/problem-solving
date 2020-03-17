#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
vector<int> v;
int n, m;

void dfs() {
	if (v.size() == m) {
		for (int x : v) {
			printf("%d ", x);
		}
		puts("");
		return;
	}

	bool visited[10001] = { false };

	for (int i = 0; i < n; i++) {
		if (!visited[arr[i]]) {
			visited[arr[i]] = true;
			v.push_back(arr[i]);
			dfs();
			v.pop_back();
		}
	}
}

int main() {
	int num;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	dfs();

	return 0;
}



//1799
//중복순열. 한번뽑은 순열은 안뽑음.