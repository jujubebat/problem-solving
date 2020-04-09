#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int res = 0x7fffffff;
int s[20][20];
bool visited[20];

void solve(int idx, int cnt) {
	
	if (cnt > n / 2) return;

	if (cnt >= 1) {
		int aPower = 0, bPower = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i] && visited[j])
					aPower += s[i][j];
				else if (!visited[i] && !visited[j]) {
					bPower += s[i][j];
				}
			}
		}
		res = min(res, abs(aPower - bPower));
	}

	if (idx >= n) return;

	visited[idx] = true;
	solve(idx + 1, cnt + 1); //현재 팀을 고르는 경우
	visited[idx] = false;
	solve(idx + 1, cnt); //현재 팀을 고르지 않는 경우
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	solve(0, 0);
	cout << res;
	return 0;
}