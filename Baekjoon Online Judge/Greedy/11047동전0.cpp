#include<iostream>

using namespace std;

int main() {
	int n, k,tmpK=0;
	int value[10];
	int res = 0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &value[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		res += k / value[i];
		k %= value[i];
		if (k == 0) break;
	}

	printf("%d", res);
}