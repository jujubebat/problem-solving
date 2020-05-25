#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, h;

	cin >> n >> h;

	vector<int> bottom(n / 2, 0);
	vector<int> top(n / 2, 0);

	for (int i = 0; i < n / 2; i++) {
		cin >> bottom[i] >> top[i];
	}

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int ret = 0x7fffffff;
	int cnt = 1;

	for (int i = 1; i <= h; i++) {
		int candi
			= distance(lower_bound(bottom.begin(), bottom.end(), i), bottom.end())
			+ distance(lower_bound(top.begin(), top.end(), h + 1 - i), top.end());

		if (ret == candi) cnt++;

		if (ret > candi) {
			ret = candi;
			cnt = 1;
		}
	}

	cout << ret << " " << cnt;

	return 0;
}

