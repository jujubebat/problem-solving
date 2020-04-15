#include<iostream>
#include<queue>
using namespace std;

queue<long long> q;
long long arr[1000001];

int main() {
	
	for (int i = 1; i <= 9; i++)
		q.push(i);

	int idx = 1;

	while (!q.empty()) {
		long long num = q.front();
		arr[idx++] = num;
		if (idx > 1000000) break;
		q.pop();
		for (int i = 0; i < 10; i++) {
			if (num % 10 > i) {
				long long tmp = num * 10 + i;
				q.push(tmp);
			}
		}
	}

	int n;
	cin >> n;
	if (n > 1022)
		cout << -1;
	else
		cout << arr[n];

	return 0;
}
