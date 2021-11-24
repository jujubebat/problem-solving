#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int x, y;
}pos;

vector<pos> arr;
vector<pos> v;
int map[30][10];
int check[30][10];
int n, m, h; //n은 열, h는 행
int res = 0x7fffffff;

bool checking() {
	for (int j = 0; j < n; j++) {
		int col = j;
		for (int i = 0; i < h; i++) {
			if (check[i][col] == 1) {
				col++;
			}
			else if (col > 0 && check[i][col - 1] == 1) {
				col--;
			}
		}
		if (j != col)
			return false;
	}
	return true;
}

void combination(int cnt) {
	if (v.size() > 3) return;

	if (checking()) {
		res = min(res, (int)v.size());
	}

	for (int i = cnt; i < arr.size(); i++) {
		if (arr[i].y > 0 && check[arr[i].x][arr[i].y - 1] == 1)
			continue;
		if (arr[i].y < n - 1 && check[arr[i].x][arr[i].y + 1] == 1)
			continue;
		if (arr[i].y == n - 1)
			continue;

		v.push_back(arr[i]);
		check[arr[i].x][arr[i].y] = 1;
		combination(i + 1);
		check[arr[i].x][arr[i].y] = 0;
		v.pop_back();
	}
}

int main() {
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
		check[x - 1][y - 1] = 1;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0)
				arr.push_back({ i,j });
		}
	

	combination(0);

	if (res == 0x7fffffff)
		cout << -1;
	else
		cout << res;

	return 0;
}