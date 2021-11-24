/*#include<iostream>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	int arr[30000];
	int n, d, k, c;

	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) { // 초밥 정보 입력
		cin >> arr[i];
	}

	deque<pair<int, int>> window; // 인덱스, 초밥 종류
	map<int, int> m; // 구간 : 초밥 종류, 개수
	int ret = -1;

	for (int i = 0; i < n+k; i++) {

		int idx = i;
		if (idx >= n) idx -= n;

		if (!window.empty() && window.front().first <= i - k ) {
			m[window.front().second]--; // 구간에서 초밥 뺴준다.
			if (m[window.front().second] <= 0)
				m.erase(window.front().second);
			window.pop_front(); // 윈도우에서 초밥을 빼준다.
		}

		window.push_back({ idx, arr[idx] });
		m[arr[idx]]++;

		if (window.size() == k) {
			int num = (int)m.size();
			if (m.count(c) == 0) num++;
			ret = max(ret, num);
		}
	}

	cout << ret;
	return 0;
	
}*/

#include<iostream>
#include<algorithm>
using namespace std;

int table[30001];
int check[3001];

int main() {
	int n, d, k, c;

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}

	int size = 0;
	int cnt = 0;

	for (int i = 0; i < k; i++) { // 첫 k 구간을 계산한다. 
		if (check[table[i]]++ == 0) // 처음 포함되는 초밥이라면, 카운트.
			cnt++;
	}

	int ret = cnt;

	for (int i = k; i < n + k; i++) { // n+k 전까지 k길이의 슬라이딩 윈도우를 민다. 

		//슬라이딩 윈도우를 미는 부분.
		if (--check[table[i - k]] == 0) cnt--; // 앞 초밥을 빼준다. check가 0이면, 종류 카운트 -1
		if (check[table[i%n]]++ == 0) cnt++; // 뒤 초밥을 더한다. check가 0이면, 종류 카운트 +1

		if (check[c] == 0) // 쿠폰을 고려하여 종류의 개수를 갱신한다. 
			ret = max(ret, cnt + 1);
		else
			ret = max(ret, cnt);
	}

	cout << ret;
	return 0;
}