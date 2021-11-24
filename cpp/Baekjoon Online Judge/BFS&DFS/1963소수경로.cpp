#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct {
	int num, cnt;
}password;

int start, dest;
bool visited[10000];

bool isPrime(int n) {
	if (n == 2)
		return true;
	else if (n == 1)
		return false;

	for (int i = 2; i < n; i++) {
		if (n%i == 0)
			return false;
	}

	return true;
}

void bfs() {
	queue<password> q;
	visited[start] = true;
	q.push({ start, 0 });

	while (!q.empty()) {
		int num = q.front().num, cnt = q.front().cnt;
		q.pop();

		if (num == dest) {
			cout << cnt << endl;
			while (!q.empty()) q.pop();
			return;
		}

		int tmp, next, s;
		int d[4] = { 1000,100,10,1 };

		for (int i = 0; i < 4; i++) {
			tmp = num - ((num % (d[i]*10)) / d[i]) * d[i];
			if (i == 0)s = 1;
			else s = 0;
			for (int k = s; k < 10; k++) {
				next = tmp + k * d[i];
				if (isPrime(next) && !visited[next]) {
					visited[next] = true;
					q.push({ next, cnt + 1 });
				}
			}
		}
	}

	cout << "Impossible"<<endl;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> start >> dest;
		bfs();
		memset(visited, false, sizeof(visited));
	}
	return 0;
}