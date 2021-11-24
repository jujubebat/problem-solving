//배열의 특성을 이용하여 품
#include<iostream>
#include<cstdlib>
using namespace std;

int n, res = 0;
bool a[27], b[27], c[14];

void dfs(int i) {
	if (i == n) {
		res++;
		return;
	}
	for (int j = 0; j < n; j++) {
		//  /, \, | 
		if (a[i + j] || b[i-j + n - 1] || c[j])
			continue;

		a[i + j] = b[i - j + n - 1] = c[j] = true;
		dfs(i + 1);
		a[i + j] = b[i - j + n - 1] = c[j] = false;
	}
}

int main() { 
	cin >> n;
	dfs(0);
	printf("%d", res);
	return 0;
}