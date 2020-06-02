#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;

int p[15];
int n, l, r, x;
int ret = 0;

bool check(long long bit) {

	int cnt = 0;
	int score = 0;
	int maxScore = 1, minScore = 10000000;

	for (int i = 0; i < n; i++) {
		int flag = bit & (1 << i);

		if (flag != 0) {
			score += p[i];
			maxScore = max(maxScore, p[i]);
			minScore = min(minScore, p[i]);
			cnt++;
		}

	}

	if ((score >= l && score <= r)
		&& abs(maxScore - minScore) >= x
		&& cnt >= 2) {
		return true;
	}
	else
		return false;
}

int main() {

	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	for (long long bit = 0; bit < (1 << n); bit++) {
		if (check(bit)) {
			ret++;
		}
	}

	cout << ret;
	return 0;
}