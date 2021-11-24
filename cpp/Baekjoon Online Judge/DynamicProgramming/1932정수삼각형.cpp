#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int arr[500][500];
	int d[500][500];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}
	}

	d[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			int x = j - 1;
			if (x < 0) x = 0;
			d[i][j] = arr[i][j] + max(d[i - 1][j], d[i - 1][x]);
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, d[n - 1][i]);
	}

	printf("%d", res);
}