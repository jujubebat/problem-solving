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
		int mid = (low + high) / 2; // 나무의 높이 h
		long long sum = 0;

		for (int i = 0; i < n; i++) {
			if (trees[i] > mid)
				sum += trees[i] - mid;
		}

		if (sum >= m) { // 적어도 m미터의 나무를 집에 가져가기 위한 H의 최대값
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