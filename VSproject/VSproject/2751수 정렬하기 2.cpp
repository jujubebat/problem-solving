#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;

	priority_queue<int> pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		scanf_s("%d", &num);
		pq.push(-num);
	}

	while (!pq.empty()){
		printf("%d\n", -pq.top());
		pq.pop();
	}

	return 0;
}