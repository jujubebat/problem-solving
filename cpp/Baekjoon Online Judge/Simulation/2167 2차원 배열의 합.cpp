#include<iostream>
using namespace std;

int arr[300][300];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int k;
	cin >> k;

	while (k--) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		sx--, sy--, ex--, ey--;

		// (0,2) ~ (1,2)
		int ret = 0;

		for (int i = sx; i <=ex; i++) {
			for (int j = sy; j <= ey; j++) {
				ret += arr[i][j];
			}
		}

		cout << ret << endl;
	}

	return 0;
}