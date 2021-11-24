

/*
������ȹ�� Bottom-Up��� 
0. ������ �ɰ���.
1. ���� ������ Ǯ�鼭 ū ������ ���� ���Ѵ�.
*/

#include<iostream>

using namespace std;

int dp[11];

void solve() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}

int main() {
	int t, n;
	cin >> t;
	solve();
	for (int i = 0; i < t; i++) {
		cin >> n;
		printf("%d\n", dp[n]);
	}
}