#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
long long arr[1000000];

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long low = 1, high = 1000000000000;
	long long ret = 1000000000000;

	while (low <= high) {
		long long mid = (low + high) / 2;
		long long cnt = 0;

		for (int i = 0; i < n; i++) {
			cnt += mid / arr[i];
		}

		if (cnt >= m) { //ǳ���� m������ ���ų� ���� ����ٸ�,
			ret = min(ret, mid); 
			high = mid - 1; //�ð��� �ٿ�����.
		}
		else {
			low = mid + 1;
		}

	}

	cout << ret;

	return 0;
}