#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	int inTurnel = m;
	int ret = -1;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		inTurnel = inTurnel + s - e;

		if (inTurnel < 0) {
			cout << 0;
			return 0;
		}

		ret = max(ret, inTurnel);
	}

	cout << ret;

	return 0;
}