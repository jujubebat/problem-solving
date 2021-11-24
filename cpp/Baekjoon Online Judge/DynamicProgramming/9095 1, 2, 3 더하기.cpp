

/*
동적계획법 Bottom-Up방식 
0. 문제를 쪼갠다.
1. 작은 문제를 풀면서 큰 문제의 답을 구한다.
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