#include<iostream>
#include<algorithm>
using namespace std;

int m, n;
int arr[1000000];

int main() {

	cin >> m >> n;

	for (int i=0; i < n; i++) {
		cin >> arr[i];
	}

	int low = 1, high = 1000000000;
	int ret = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] >= mid)
				cnt += arr[i] / mid;
		}

		if (cnt >= m) { //������ �� �ִ� ���� ������ ���ٸ�, 
			ret = max(ret, mid);
			low = mid + 1; //������ ���̸� �÷�����. 
		}
		else {
			high = mid - 1;
		}
			
	}

	cout << ret;

	return 0;
}