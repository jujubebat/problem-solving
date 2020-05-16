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

		if (cnt >= m) { //나눠줄 수 있는 과자 개수가 많다면, 
			ret = max(ret, mid);
			low = mid + 1; //과자의 길이를 늘려본다. 
		}
		else {
			high = mid - 1;
		}
			
	}

	cout << ret;

	return 0;
}