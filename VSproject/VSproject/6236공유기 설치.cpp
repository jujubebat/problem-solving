#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, c;
	int house[200000];
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}

	sort(house, house + n);

	int low = 0, high = 1000000000;
	int ret = 1000000000;
	while (low + 1 < high) {
		int mid = (low + high) / 2;
		int cnt = 1;
		int beforeHouse = house[0];

		for (int i = 1; i < n; i++) {
			if (house[i] - beforeHouse >= mid) {
				beforeHouse = house[i];
				cnt++;
			}
		}	
		
		if (cnt >= c) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	cout << low << endl;

	return 0;
}

/*

https://romanceboong.tistory.com/entry/%EB%B0%B1%EC%A4%80-2110%EB%B2%88-%EB%AC%B8%EC%A0%9C-%EA%B3%B5%EC%9C%A0%EA%B8%B0-%EC%84%A4%EC%B9%98
https://js1jj2sk3.tistory.com/66

*/