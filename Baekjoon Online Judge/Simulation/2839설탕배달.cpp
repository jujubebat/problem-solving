#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int res = 1e9;
int d[5000];

int dfs(int sugar, int cnt) {
	if (sugar < 0)
		return -1;

	if (sugar == 0) {
		res = min(res, cnt);
		return cnt;
	}

	if (sugar - 5 >= 0) {
		if (d[sugar - 5] == 0) {
			d[sugar - 5] = cnt + 1;
			dfs(sugar - 5, cnt + 1);
		}
	}

	if (sugar - 3 >= 0) {
		if (d[sugar - 3] == 0) {
			d[sugar - 3] = cnt + 1;
			dfs(sugar - 3, cnt + 1);
		}
	}
}

int main() {
	int n;
	/*cin >> n;
	dfs(n, 0);
	
	if (res == 1e9)
		printf("-1");
	else
		printf("%d", res);
	*/
	for (int i = 3; i <= 5000; i++) {
		printf("설탕 %d 킬로그램 : ", i);
		memset(d, 0, sizeof(d));
		res = 1e9;
		dfs(i, 0);
		if (res == 1e9)
			printf("-1\n");
		else
			printf("%d\n", res);
	}
}