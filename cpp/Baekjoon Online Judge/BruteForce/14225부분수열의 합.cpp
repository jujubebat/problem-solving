/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> arr;
vector<int> v;
int n, k;

bool check[2000001] = { false };

void dfs(int cnt) {
	if (v.size() == k) {
		bool c[20] = { false };
		for (int x : v) {
			c[x] = true;
		}

		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (c[i])
				a += arr[i];
			else
				b += arr[i];
		}

		check[a] = true;
		check[b] = true;

		return;
	}

	for (int i = cnt; i < n; i++) {
		v.push_back(i);
		dfs(i + 1);
		v.pop_back();
	}
}
int main() {
	cin >> n;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}

	int size = arr.size();

	if (size % 2 == 0)
		k = size / 2;
	else
		k = n / 2 + 1;

	sort(arr.begin(), arr.end());

	while (k <= n) {
		dfs(0);
		k++;
	}
	int i = 1;
	while (1) {
		if (!check[i])
			break;
		i++;
	}
	printf("%d", i);
	return 0;
}*/


//더 간단하고 좋은 풀이
#include<iostream> 
using namespace std;

int arr[20];
int n;
bool c[2000001];

void dfs(int idx, int sum, int size) {
	c[sum] = true;

	if (size > n || idx >= n)  return;

	dfs(idx + 1, sum + arr[idx], size + 1);
	dfs(idx + 1, sum, size);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0, 0, 0);
	int i = 1;
	while (1) {
		if (c[i] == false)
			break;
		i++;
	}
	cout << i;

	return 0;
}

