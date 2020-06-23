#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

bool check(int num) {
	for (int i = 1; i <= sqrt(num); i++) {
		if (i*i == num) // 완전 제곱수일 경우.
			return true;
	}

	return false;
}

int main() {

	priority_queue<int> pq;

	int ret = 0;

	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		if (check(i)) {
			ret += i;
			pq.push(-i);
		} 
	}

	if (ret == 0)
		cout << -1 << endl;
	else {
		cout << ret << endl;
		cout << -pq.top() << endl;
	}

	return 0;
}
