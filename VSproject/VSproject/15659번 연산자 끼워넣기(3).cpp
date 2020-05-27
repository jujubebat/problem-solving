#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> a;
int opCount[4];
vector<int> op;
int n;
int maxRet = -0x7fffffff, minRet = 0x7fffffff;

void cal() {
	vector<int> a2;
	vector<int> op2;
	bool flag = false;
	int num = a[0];

	for (int i = 0; i < a.size() - 1; i++) {
		if (!flag) num = a[i];

		if (op[i] < 2) { // +, - 老 版快
			if (flag)
				a2.push_back(num);
			else
				a2.push_back(a[i]);

			op2.push_back(op[i]);

			flag = false;
		}
		else { // x, / 老 版快
			if (op[i] == 2)
				num *= a[i + 1];
			else
				num /= a[i + 1];

			flag = true;
		}
	}
	if (op[n - 2] < 2)
		a2.push_back(a[n - 1]);
	else
		a2.push_back(num);

	int candi = a2[0];

	for (int i = 0; i < op2.size(); i++) {
		if (op2[i] == 0)
			candi += a2[i + 1];
		if (op2[i] == 1)
			candi -= a2[i + 1];
	}

	maxRet = max(maxRet, candi);
	minRet = min(minRet, candi);
}

void solve() {
	if (op.size() == n - 1) {
		cal();
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opCount[i] == 0) continue;
		opCount[i]--;
		op.push_back(i);
		solve();
		op.pop_back();
		opCount[i]++;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < 4; i++) {
		cin >> opCount[i];
	}

	solve();

	cout << maxRet << endl;
	cout << minRet;

	return 0;
}
