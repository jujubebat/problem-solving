#include<iostream>
using namespace std;

int a[10000];

int main() {
	int n, m;
	int s = 0, e = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int sum = 0;
	int res = 0;

	while (e <= n) {
		if (sum < m) {
			e++;
			sum += a[e - 1];
		}
		else if (sum > m) {
			s++;
			sum -= a[s - 1];
		}
		else if (sum == m) {
			res++;
			e++;
			sum += a[e - 1];
		}
	}

	cout << res;

	return 0;
}