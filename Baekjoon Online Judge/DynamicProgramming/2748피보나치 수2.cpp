#include<iostream>

using namespace std;

long long dp[91]; //long long 은 최대 100경 자리까지 감..

long long fibo(int n) {
	if (n == 0)	return 0;
	if (n == 1) return 1;

	if (dp[n] != 0)
		return dp[n];

	return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%lld", fibo(n));
}