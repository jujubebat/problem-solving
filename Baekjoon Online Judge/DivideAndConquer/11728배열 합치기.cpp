#include<iostream>
using namespace std;

int a[1000000], b[1000000], c[2000000];

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	int i = 0, j = 0, idx = 0;
	while (i < n && j < m) {
		if (a[i] >= b[j])
			c[idx++] = b[j++];
		else if (a[i] < b[j])
			c[idx++] = a[i++];
	}

	while (i < n)
		c[idx++] = a[i++];

	while (j < m)
		c[idx++] = b[j++];

	for (int i = 0; i < n + m; i++)
		printf("%d ", c[i]);

	return 0;
}


