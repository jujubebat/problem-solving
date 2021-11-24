#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int map[50][50];
int res = -1;
int n, m;

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 1;
			int size = 1;
			while (1) {
				if (i + cnt >= n || j + cnt >= m) break;
				if(map[i][j] == map[i][j+cnt] 
					&& map[i][j] == map[i + cnt][j]
					&& map[i][j] == map[i + cnt][j + cnt]){
					size = (cnt+1) * (cnt+1);
				}
				cnt++;
			}
			res = max(res, size);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	solve();
	printf("%d", res);
}