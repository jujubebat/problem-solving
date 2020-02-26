//https://rebas.kr/692 참고함 
//dfs 풀이
//경우를 나누어 재귀를 돌리면 됨.
//dp로 나중에 풀어보자.

#include<iostream>

using namespace std;

int n, ans;
int t[16], p[16];

void solve(int day, int profit) {
	if (day == n + 1) {
		if (ans < profit) ans = profit;
		return;
	}
	if (day > n + 1) return;
	solve(day + t[day], profit + p[day]); //day 번째 일에 상담을 하는 경우
	solve(day + 1, profit);  //day 번째 일에 상담을 하지 않는 경우
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &t[i], &p[i]);

	solve(1, 0);
	printf("%d", ans);
	return 0;
}