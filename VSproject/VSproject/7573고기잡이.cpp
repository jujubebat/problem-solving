#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pos {
	int x, y;
};

int n, m, l, res = 0;
vector<pos>arr;

void calc(int x, int y, int xx, int yy) {
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (x <= arr[i].x && arr[i].x <= x + xx && y <= arr[i].y && arr[i].y <= y + yy)
			cnt++;
		res = max(res, cnt);
	}
}

int main() {
	scanf_s("%d %d %d", &n, &l, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf_s("%d %d", &x, &y);
		arr.push_back({ x, y });
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i].x << arr[j].y << endl;
			for (int k = 1; k < l / 2; k++) {
				calc(arr[i].x, arr[j].y, k, l / 2 - k);
			}
		}
	}
	printf("%d", res);
}