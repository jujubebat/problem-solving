#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int g, x;
		cin >> g >> x;
		arr[x] = g;
	}

	int cnt = 0;
	int len = k * 2 + 1;

	// 만약 구간이 총 우리 크기보다 크다면, 모든 우리에 있는 얼음합이 최대값이다. 
	if (len > 1000000) {
		for (int i = 0; i <= 1000000; i++) {
			cnt += arr[i];
		}
		cout << cnt << endl;
		return 0;
	}

	// 엘버트는 좌우로 k만큼 떨어진 양동이에 접근할 수 있다.
	// 이를 k*2+1 길이의 구간으로 생각했다. 
	// 첫 구간에 대한 계산한다.
	for (int i = 0; i < len; i++) {
		cnt += arr[i];
	}

	int ret = cnt;

	// 모든 k*2+1 길이의 구간에 대한 얼음량을 계산하고, 최대 값을 갱신한다. 
	for (int i = len; i <= 1000000; i++) {
		cnt -= arr[i - len];
		cnt += arr[i];
		ret = max(ret, cnt);
	}

	cout << ret;
	return 0;
}