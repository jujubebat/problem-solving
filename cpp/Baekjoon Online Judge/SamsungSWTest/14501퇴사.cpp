//https://rebas.kr/692 ������ 
//dfs Ǯ��
//��츦 ������ ��͸� ������ ��.
//dp�� ���߿� Ǯ���.

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
	solve(day + t[day], profit + p[day]); //day ��° �Ͽ� ����� �ϴ� ���
	solve(day + 1, profit);  //day ��° �Ͽ� ����� ���� �ʴ� ���
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &t[i], &p[i]);

	solve(1, 0);
	printf("%d", ans);
	return 0;
}