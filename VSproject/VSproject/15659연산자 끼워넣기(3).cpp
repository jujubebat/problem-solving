#include<iostream>
#include<algorithm>
using namespace std;

int a[100];
int op[4];
int n;
int maxRet = -0x7fffffff, minRet = 0x7fffffff;

void solve(int idx, int sum) {

	if (idx == n) {
		maxRet = max(maxRet, sum);
		minRet = min(minRet, sum);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;
		op[i]--;
		if (i == 0) { // +
			solve(idx + 1, sum + a[idx]);
		}
		else if (i == 1) { // -
			solve(idx + 1, sum - a[idx]);
		}
		else if (i == 2) { // x
			solve(idx + 1, sum * a[idx]);
		}
		else if (i == 3) { // /
			solve(idx + 1, sum / a[idx]);
		}
		op[i]++;
	}

}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	solve(1, a[0]);

	cout << maxRet << endl << minRet;
	return 0;
}

+ + + +  /