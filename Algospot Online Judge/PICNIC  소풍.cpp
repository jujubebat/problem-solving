#include<iostream>
#include<string.h>
using namespace std;

bool map[10][10];
int n, m;


int solve(bool t[10]) {
	int firstFree = -1;

	for (int i = 0; i < n; i++) {
		if (!t[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;

	int ret = 0;

	for (int i = firstFree + 1; i < n; i++) {
		if (!t[i] && map[firstFree][i]) {
			t[firstFree] = t[i] = true;
			ret += solve(t);
			t[firstFree] = t[i] = false;
		}
	}

	return ret;
}

int main() {
	int c;
	cin >> c;

	while (c--) {
		memset(map, false, sizeof(map));
		bool taken[10] = { false };
		
		cin >> n >> m;
	
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			map[a][b] = true;
			map[b][a] = true;
		}
		
		cout << solve(taken) << endl;
	}

	return 0;
}