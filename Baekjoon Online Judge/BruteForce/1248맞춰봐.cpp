#include<iostream>
#include<vector>
using namespace std;

int n;
char map[10][10];
vector<int> v;

bool check(int idx) {
	int sum = 0;
	for (int i = idx; i >= 0; i--) {
		sum += v[i];
		if (map[i][idx] == '+' && sum <= 0) return false;
		if (map[i][idx] == '-' && sum >= 0) return false;
		if (map[i][idx] == '0' && sum != 0) return false;
	}
	return true;
}                                                                            

void solve(int idx) {
	if (idx == n) {
		for (int k : v)
			printf("%d ", k);
		exit(0);
	}

	for (int i = -10; i <= 10; i++) {
		v.push_back(i);
		if (check(idx))
			solve(idx + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> map[i][j];
		}
	}

	solve(0);

	return 0;
}