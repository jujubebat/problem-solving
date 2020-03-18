#include<iostream>
using namespace std;
int d[101][10];

int main() {
	int mod = 1000000000;
	

	int n;
	cin >> n;

	d[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				d[i][j] = d[i - 1][1] % mod;
			}
			else if (j==9) {
				d[i][j] = d[i - 1][8] % mod;
			}else
				d[i][j] = (d[i - 1][j + 1] + d[i - 1][j - 1])% mod;
		}
	}

	long long res = 0;

	for (int i = 0; i < 10; i++) {
		res += d[n][i];
	}

	cout << res % mod;
	return 0;
}