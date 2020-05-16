#include<iostream>
using namespace std;

int main() {
	int n, m;
	int money[100000];

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	int low = 0, high = 1000000000;
	int ret;

	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 1, sum = mid;

		cout << low << " :  " <<high << endl;

		for (int i = 0; i < n; i++) {

			if (mid < money[i]) {
				cnt = m + 1;
				break;
			}

			if (sum < money[i]) {
				sum = mid;
				cnt++;
			}
			sum -= money[i];
		}
		if (cnt <= m) {
			ret = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}

	}

	cout << ret;
	return 0;
}