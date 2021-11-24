#include<iostream>
#include<algorithm>
using namespace std;

int n, m, ret;
int trees[1000000];

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> trees[i];
	}

	int low = 0, high = 1000000000;

	while (low <= high) {
		int mid = (low + high) / 2; // ������ ���� h
		long long sum = 0;

		for (int i = 0; i < n; i++) {
			if (trees[i] > mid)
				sum += trees[i] - mid;
		}

		if (sum >= m) { // ��� m������ ������ ���� �������� ���� H�� �ִ밪
			ret = max(ret, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}

	cout << ret;

	return 0;
}