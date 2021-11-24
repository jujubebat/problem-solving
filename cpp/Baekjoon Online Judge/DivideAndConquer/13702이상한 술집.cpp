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

		if (count >= k) { // ī��Ʈ�� ���
			ret = max(ret, mid);
			low = mid + 1; // ���ɸ� ���� �÷�����.
		}
		else {
			high = mid - 1; // ���ɸ� ���� �ٿ�����.
		}
	}

	cout << ret;
	return 0;
}