#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[300000];
int sum = 0;

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	int low = 1, high = 1000000000;
	int ret = 1000000000;
	while (low <= high) {
		cout << low << " " << high << endl;
		int mid = (low + high) / 2; // 나눠줄 보석의 개수단위
		int cnt = 0; // mid 기준으로 몇 명에게 나눠줄 수 있는지 카운트

		for (int i = 0; i < m; i++) {
			cnt += arr[i] / mid;
			if (arr[i] % mid)
				cnt++;
		}

		if (n >= cnt) { // n명보다 같거나 적게 나눠줄 수 있었다.
			ret = min(ret, mid);
			high = mid - 1; // 나눠줄 보석 개수 단위를 줄여서 더 많이 나눠줘보자!
		}
		else { // n명보다 많이 나눠줄 수 있었다.
			low = mid + 1; // 나눠줄 보석 개수 단위를 늘려서 더 적게 나눠줘보자!
		}
	}

	//cout << low;
	cout << ret;
	return 0;
}
