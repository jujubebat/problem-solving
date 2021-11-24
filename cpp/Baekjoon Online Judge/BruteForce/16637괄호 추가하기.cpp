#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> numbers;
vector<char> operations;
long long res = -0x7fffffff;

long long cal(long long p1, long long p2, char operation) {
	switch (operation) {
	case '+':
		return p1 + p2;
	case '*':
		return p1 * p2;
	case '-':
		return p1 - p2;
	}
}

void solve(long long var, int cnt) {
	if (cnt == n / 2) {
		res = max(var, res);
		return;
	}

	long long nextVar = cal(var, numbers[cnt + 1], operations[cnt]);
	solve(nextVar, cnt + 1);

	if (cnt + 2 <= n / 2 ) {
		nextVar = cal(numbers[cnt + 1], numbers[cnt + 2], operations[cnt + 1]);
		nextVar = cal(var, nextVar, operations[cnt]);
		solve(nextVar, cnt + 2);
	}
}

int main() {
	char c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c;
		if (isdigit(c))
			numbers.push_back(c - '0');
		else
			operations.push_back(c);
	}

	solve(numbers[0], 0);
	cout << res;
	return 0;
}