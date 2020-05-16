//가능한 최대의 총 예산을 배정해야한다. == 가능한 최대의 상한액을 구한다.
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	int regions[10000];

	cin >> n;

	int ret = 0, sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> regions[i];
		sum += regions[i];
		ret = max(ret, regions[i]);
	}

	cin >> m;

	if (sum <= m) {
		cout << ret;
		return 0;
	}

	int low = 0, high = 1000000000;
	ret = 0;

	while (low <= high) {
		int mid = (low + high) / 2; // 상한액

		sum = 0;
		for (int i = 0; i < n; i++) { // 상한액을 기준으로 총 지방 예산을 구한다.
			if (regions[i] > mid)
				sum += mid;
			else
				sum += regions[i];
		}

		if (sum <= m) { // 총 지방 예산을 정부 예산으로 커버할 수 있을때
			ret = max(ret, mid); // 가장 큰 상한액을 구한다. 
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ret;

	return 0;
}

