#include<iostream>
#include<queue>
using namespace std;

int main() {
	priority_queue<int> pq;
	
	for (int i = 0; i < 2; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		pq.push(a + b + c + d);
	}

	cout << pq.top();
	return 0;
}