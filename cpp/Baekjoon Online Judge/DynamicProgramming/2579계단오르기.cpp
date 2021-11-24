

/*
������ ����� ��� 2���� ���
1. ��ĭ�� ��� ������ ĭ�� ��� ���(����ĭ�� ������ �ȵ�!)
->������ĭ������ �ִ밪 + ��ĭ + ����ĭ
2. ���� ĭ�� ��� ������ ĭ�� ��� ���
->����ĭ������ �ִ밪  + ����ĭ 
1,2���� �ִ��� ���ؾ��� 
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int stair[301];
int dp[301]; //i��° ��ܱ����� �ִ밪�� �����س��� �迭.
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