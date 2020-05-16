#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	long long t[100000];
	long long maxTime = -1;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> t[i];
		maxTime = max(maxTime, t[i]);
	}

	maxTime *= m;

	long long low = 0, high = maxTime;

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long num = 0;

		for (int i = 0; i < n; i++) {
			num += mid / t[i];
		}

		if (num >= m) { // 더 많이 보낼 수 있다. 시간을 줄여보자.
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}

	}

	cout << low;

	return 0;
}