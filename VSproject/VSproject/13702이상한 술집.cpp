#include<iostream>
#include<algorithm>
using namespace std;

int arr[10000];

int main() {

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int low = 0, high = 0x7fffffff;
	int ret = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		int count = 0;

		for (int i = 0; i < n; i++) {
			count += arr[i] / mid;
		}

		if (count >= k) { // 카운트가 충분
			ret = max(ret, mid);
			low = mid + 1; // 막걸리 양을 늘려본다.
		}
		else {
			high = mid - 1; // 막걸리 양을 줄여본다.
		}
	}

	cout << ret;
	return 0;
}