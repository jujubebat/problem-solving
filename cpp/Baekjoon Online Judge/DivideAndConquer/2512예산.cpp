//������ �ִ��� �� ������ �����ؾ��Ѵ�. == ������ �ִ��� ���Ѿ��� ���Ѵ�.
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
		int mid = (low + high) / 2; // ���Ѿ�

		sum = 0;
		for (int i = 0; i < n; i++) { // ���Ѿ��� �������� �� ���� ������ ���Ѵ�.
			if (regions[i] > mid)
				sum += mid;
			else
				sum += regions[i];
		}

		if (sum <= m) { // �� ���� ������ ���� �������� Ŀ���� �� ������
			ret = max(ret, mid); // ���� ū ���Ѿ��� ���Ѵ�. 
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ret;

	return 0;
}

