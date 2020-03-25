#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	printf("q.size() : %d, q.front() : %d, q.back() : %d\n",q.size(), q.front(), q.back());

	q.pop();
	q.pop();

	printf("q.size() : %d, q.front() : %d, q.back() : %d\n", q.size(), q.front(), q.back());

	q.pop();
	q.pop();

	if (q.empty())
		printf("큐가 비어있습니다.");

	return 0;
}


