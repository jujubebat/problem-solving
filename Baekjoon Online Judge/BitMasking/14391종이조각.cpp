#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

int n, m;
int map[4][4];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &map[i][j]);
		}
	}

	int res = -1;

	for (int bit = 0; bit < (1 << (n*m)); bit++) {
		//cout << bitset<32>(bit) << endl;
		int sum = 0;

		for (int i = 0; i < n; i++) { //가로 조각 계산
			int num = 0;
			for (int j = 0; j < m; j++) {
				int k = i * m + j;
				if ((bit & (1 << k)) == 0) {
					num = num * 10 + map[i][j];
				}
				else {
					sum += num;
					num = 0;
				}
			}
			sum += num;
		}

		for (int j = 0; j < m; j++) {//세로 조각 계산
			int num = 0;
			for (int i = 0; i < n; i++) {
				int k = i * m + j;
				if ((bit & (1 << k)) != 0) {
					num = num * 10 + map[i][j];
				}
				else {
					sum += num;
					num = 0;
				}
			}
			sum += num;
		}
		res = max(res, sum);
	}

	cout << res << endl;
	return 0;
}