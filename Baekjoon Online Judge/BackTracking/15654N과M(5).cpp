#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> arr;
int n, m;
bool visited[9];

void dfs() {
	
	if (v.size() == m) {
		for (int x : v) {
			printf("%d ", x);
		}
		puts("");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(arr[i]);
			dfs();
			v.pop_back();
			visited[i] = false;
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
	dfs();
	return 0;
}
