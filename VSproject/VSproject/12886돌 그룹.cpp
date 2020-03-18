#include<iostream>
using namespace std;

int res = 0;
bool visited[1001][1001];
bool flag;

void go(int a, int b, int c) {
	//printf("%d %d %d\n", a, b, c);
	if (flag) return;

	if (a == b && b == c) {
		res = 1;
		flag = true;
		return;
	}

	if (a > 1000 || b > 1000 || c > 1000) return;

	if (visited[a][b]) return;

	visited[a][b] = true;

	int na, nb, nc;
	if (a < b) {
		na = a + a, nb = b - c, nc = c;
		if (na >= 0 && nb >= 0 && nc >= 0) {
			go(na, nb, nc);
		}
	}
	else if (a > b) {
		na = a - b, nb = b + b, nc = c;
		if (na >= 0 && nb >= 0 && nc >= 0) {
			go(na, nb, nc);
		}
	}

	if (b < c) {
		na = a, nb = b + b, nc = c - b;
		if (na >= 0 && nb >= 0 && nc >= 0) {
			go(na, nb, nc);
		}
	}
	else if (b > c) {
		na = a, nb = b - c, nc = c + c;
		if (na >= 0 && nb >= 0 && nc >= 0) {
			go(na, nb, nc);
		}
	}

	if (a > c) {
		na = a - c, nb = b, nc = c + c;
		if (na >= 0 && nb >= 0 && nc >= 0) {
			go(na, nb, nc);
		}
	}
	else if (a < c) {
		na = a + a, nb = b, nc = c - a;
		if (na >= 0 && nb >= 0 && nc >= 0) {
			go(na, nb, nc);
		}
	}
}

int main() {
	int a, b, c;

	cin >> a >> b >> c;
	go(a, b, c);

	printf("%d", res);
	return 0;
}