#include<iostream>	
#include<vector>

using namespace std;

int n,s;
int arr[20];
int res = 0;
vector<int> v;

void dfs(int cnt) {
	
	int sum=0;
	for (int i = 0; i < v.size(); i++) {
		sum += arr[v[i]];
	}

	if (v.size() > 0 && sum == s) {
		res++;
	}
	
	if (v.size() == n) {
		return;
	}

	for (int i = cnt; i < n; i++) {
		v.push_back(i);
		dfs(i + 1);
		v.pop_back();
	}
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	dfs(0);
	printf("%d", res);
}