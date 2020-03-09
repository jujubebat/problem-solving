#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char Inequality[9];
long long maxNum = -10e9, minNum = 10e9;
vector<int> minRes, maxRes, v;
bool visited[10];
int k = 2;
int cnt;

void dfs(int cnt) {
	if (v.size() == k + 1) {
		long long num = 0;
		for (int i = 0; i < k + 1; i++) {
			if (num == 0)
				num += v[i];
			else {
				num *= 10;
				num += v[i];
			}
		}
		if (minNum > num) {
			minNum = num;
			minRes = v;
		}
		if (maxNum < num) {
			maxNum = num;
			maxRes = v;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			int size = v.size();
			if (size >= 1) {
				if (Inequality[size - 1] == '>') {
					if (v[size - 1] < i) continue;
				}
				else if (Inequality[size - 1] == '<') {
					if (v[size - 1] > i) continue;
				}
			}
			visited[i] = true;
			v.push_back(i);
			dfs(cnt + 1);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> Inequality[i];
	}
	dfs(0);
	for (int i = 0; i < maxRes.size(); i++) {
		printf("%d", maxRes[i]);
	}
	puts("");

	for (int i = 0; i < minRes.size(); i++) {
		printf("%d", minRes[i]);
	}
}