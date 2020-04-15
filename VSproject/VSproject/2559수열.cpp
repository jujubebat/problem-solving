#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
int arr[100000];

int main() {
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int s = 0, e = 0;
	int sum = 0, res = -0x7fffffff;

	while (e <= n) {
		if (e-s < k) {
			sum += arr[e++];
		}
		else if (e - s == k) {
			res = max(sum, res);
			sum -= arr[s++];
		}
	}

	cout << res;
	return 0;
}