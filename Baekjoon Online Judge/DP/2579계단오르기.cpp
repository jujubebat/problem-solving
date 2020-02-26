

/*
마지막 계단을 밟는 2가지 경우
1. 전칸을 밟고 마지막 칸을 밟는 경우(전전칸은 밟으면 안됨!)
->전전전칸까지의 최대값 + 전칸 + 현재칸
2. 전전 칸을 밟고 마지막 칸을 밝는 경우
->전전칸까지의 최대값  + 현재칸 
1,2에서 최댓값을 구해야함 
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int stair[301];
int dp[301]; //i번째 계단까지의 최대값을 저장해놓는 배열.
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &stair[i]);
	}
	
	dp[0] = stair[0];
	dp[1] = max(stair[0] + stair[1], stair[2]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	printf("%d", dp[n - 1]);
	return 0;
}