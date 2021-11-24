#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> arr;
int n;
bool visited[9];
int res = -1;

void dfs() {
	if (v.size() == n) {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		res = max(res, sum);
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
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	dfs();
	printf("%d", res);
	return 0;
}