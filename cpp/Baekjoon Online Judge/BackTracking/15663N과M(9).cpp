//순열
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, m;
vector<int> v;
vector<int> arr;
bool visited[9];
bool check[10001];
set<int> s;

void dfs() {

	if (v.size() == m) {
		for (int x : v) {
			printf("%d ", x);
		}
		puts("");

		return;
	}

	bool check[10001] = { false };
	for (int i = 0; i < n; i++) {
		if (!visited[i] && !check[arr[i]]) {
			check[arr[i]] = true;
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

/*
//셋을 활용한 풀이
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int n, m;
vector<int> v;
vector<int> arr;
bool visited[9];
bool check[10001];
set<int> s;

void dfs() {

	if (v.size() == m) {

		int num = 0;
		for (int i = 0; i < v.size(); i++) {
			if (num == 0)
				num += v[i];
			else {
				num *= 10;
				num += v[i];
			}
		}
		pair<set<int>::iterator, bool> pr = s.insert(num);
		if (pr.second == false)
			return;

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
}*/