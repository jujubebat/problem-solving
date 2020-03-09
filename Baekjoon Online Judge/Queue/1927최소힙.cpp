#include<iostream>
#include<queue>
using namespace std;

int main() {
	priority_queue<int> pq;

	int num, n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);//cin >> num;
		if(num > 0)
			pq.push(num * -1);
		else if (num == 0) {
			if (pq.empty())
				printf("0\n"); //<< 0 << endl;
			else {
				printf("%d\n", pq.top() * -1); // cout << pq.top() * -1 << endl;
				pq.pop();
			}
		}
	}

	return 0;
}