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

		if (cnt >= m) { //풍선을 m개보다 같거나 많이 만든다면,
			ret = min(ret, mid); 
			high = mid - 1; //시간을 줄여본다.
		}
		else {
			low = mid + 1;
		}

	}

	cout << ret;

	return 0;
}