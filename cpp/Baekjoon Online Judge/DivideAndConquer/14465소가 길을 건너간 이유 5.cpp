/*#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
	int n, k, b;
	bool arr[100001] = { false };

	cin >> n >> k >> b;

	for (int i = 0; i < b; i++) { // 고장난 신호등 정보를 bool 배열에 기록
		int num;
		cin >> num;
		arr[num] = true;
	}

	int low = 0, high = 100000; // 0개를 수리해도, 조건을 만족할 수 있다.
	int ret = 100000;

	while (low <= high) {
		int mid = (low + high) / 2; // 수리한 신호등의 개수 
		bool flag = false;
		deque<int> window;

		// 덱을 사용한 슬라이딩 윈도우로 연속한 k개의 신호등이 연속돼있는지 확인한다. 
		for (int i = 1; i <= n; i++) {
			if (i > k && !window.empty() && window.front() <= i-k)
				window.pop_front();

			if (!arr[i])
				window.push_back(i);
   
			if (i >= k && k - window.size() <= mid) {
				flag = true;
			}
		}

		if (flag) { // mid개이하 만큼 신호등을 수리 했을때 K개의 신호등이 연속돼있다면,
			ret = min(ret, mid); // 최소 수리 개수를 구한다.
			high = mid - 1; // 신호등을 더 적게 수리해본다. 
		}
		else { // mid개이하 만큼 신호등을 수리 했을때 K개의 신호등이 연속 되지 않다면,
			low = mid + 1; // 신호등을 더 많이 수리해본다.
		}
	}

	cout << ret;

	return 0;
}*/


#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
	int n, k, b;
	bool arr[100001] = { false };

	cin >> n >> k >> b;

	for (int i = 0; i < b; i++) {
		int num;
		cin >> num;
		arr[num] = true;
	}

	int broken = 0;

	for (int i = 1; i <=k; i++) {
		if (arr[i])
			broken++;
	}

	int ret = broken;

	for (int i = k + 1; i <= n; i++) {
		if (arr[i])
			broken++;
		if (arr[i - k])
			broken--;

		ret = min(ret, broken);
	}

	cout << ret;
	return 0;
}

