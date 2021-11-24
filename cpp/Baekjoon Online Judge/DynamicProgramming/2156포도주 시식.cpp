

/*
1.�� �� + �������� : ������ �� dp + �� ��+ ��������
2.���� �� + ������ �� : ���� �� dp + ��������
3.���� ��+ ���� : �������� �� dp + ������ + ���� -> �׳� ���� dp �ϸ� ��... 2��° Ǯ�� ����
//3���� ��� �� max��

-> ��ȭ���� ȿ�������� ¥�� ����. 
-> �� dp���� �ִ��� ����Ǿ��ִٴ� ����� ����.
*/

/*
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	int arr[10000]; //������ ���
	int dp[10000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], max(arr[1] + arr[2], arr[0]+arr[1]));
	dp[3] = max(arr[0] + arr[1] + arr[3] , max(arr[1] + arr[2], arr[0] + arr[2] + arr[3]));

	if (n == 0) {
		printf("%d", dp[0]);
		return 0;
	}
	
	if (n == 1) {
		printf("%d", dp[1]);
		return 0;
	}
	if (n == 2) {
		printf("%d", dp[2]);
		return 0;
	}
	if (n == 3) {
		printf("%d", dp[3]);
		return 0;
	}
	for (int i = 4; i < n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], max(dp[i - 2] + arr[i], dp[i - 4] + arr[i - 2] + arr[i - 1]));
	}

	printf("%d", dp[n - 1]);
}*/

/*�ι�° Ǯ��*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, d[10001], p[10001];

void solve() {
	d[0] = p[0], d[1] = p[0] + p[1];
	d[2] = max(p[0] + p[2], max(p[1] + p[2], p[0] + p[1]));
	for (int i = 3; i < n; i++) {
		d[i] = d[i - 1];
		d[i] = max(d[i], d[i - 2] + p[i]);
		d[i] = max(d[i], d[i - 3] + p[i - 1] + p[i]);
	}
	printf("%d\n", d[n-1]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	solve();
	return 0;
}
