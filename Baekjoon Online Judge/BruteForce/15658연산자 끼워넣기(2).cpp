#include<iostream>
#include<algorithm>
using namespace std;

int arr[100];
int op[4];
int n;
int minRes = 1e9, maxRes = -1e9;

void dfs(int idx, int sum) {

	if (idx == n) {
		minRes = min(minRes, sum);
		maxRes = max(maxRes, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			--op[i];
			if (i == 0) {// +
				dfs(idx + 1, sum + arr[idx]);
			}
			else if (i == 1) {// -
				dfs(idx + 1, sum - arr[idx]);
			}
			else if (i == 2) {// *
				dfs(idx + 1, sum * arr[idx]);
			}
			else if (i == 3) {// /
				dfs(idx + 1, sum / arr[idx]);
			}
			++op[i];
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} 

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}	

	dfs(1, arr[0]);
	cout << maxRes << endl;
	cout << minRes;

	return 0;
}