
#include<iostream>
#include<algorithm>

using namespace std;

int n, m,res = 1000000;
bool arr[10];

int solve(int num) {

	int tmp = num;
	int cnt = 0;

	if (tmp == 0) {
		if (arr[tmp % 10])
			return -1;
		else
			cnt = 1;
	}

	while (tmp != 0)
	{
		if (arr[tmp % 10])
			return -1;

		tmp /= 10;
		cnt++;
	}

	cnt = cnt + abs(num - n);
	return cnt;
}

int main() {
	
	scanf("%d", &n);
	getchar();

	scanf("%d", &m);
	getchar();

	for (int i = 0; i < m; i++) {
		int tmp;
		scanf("%d", &tmp);
		getchar();
		arr[tmp] = true;
	}
	
	int res = abs(n - 100);

	for (int i = 0; i <= 1000000; i++) {
		int tmp = solve(i);//리모컨 조작 횟수 반환
		if (tmp != -1 && tmp < res) {
			res = tmp;
		}
	}
	printf("%d", res);
}
