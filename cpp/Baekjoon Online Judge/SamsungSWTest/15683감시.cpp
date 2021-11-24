#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int cctv, x, y, d;
}cctv;

int map[8][8];
vector<cctv> arr;
int res = 0;
int n, m;
int check[8][8];

void observe(int x, int y, int d) {
	if (d == 0) { //µ¿
		for (int i = y + 1; i < m; i++) {
			if (map[x][i] == 6) break;
			if (map[x][i] == 0) check[x][i] = -1;
		}
	}
	else if (d == 1) { //³²
		for (int i = x + 1; i < n; i++) {
			if (map[i][y] == 6) break;
			if (map[i][y] == 0) check[i][y] = -1;
		}
	}
	else if (d == 2) { //¼­
		for (int i = y -1 ; i >= 0; i--) {
			if (map[x][i] == 6) break;
			if (map[x][i] == 0) check[x][i] = -1;
		}
	}
	else if (d == 3) { //ºÏ
		for (int i = x - 1; i >=0 ; i--) {
			if (map[i][y] == 6) break;
			if (map[i][y] == 0) check[i][y] = -1;
		} 
	}
}

void calcul() {
	copy(&map[0][0], &map[n-1][m], &check[0][0]);
	for (int i = 0; i < arr.size(); i++) {
		int cctv = arr[i].cctv, x = arr[i].x, y = arr[i].y, d = arr[i].d;
		if (cctv == 1) {
			observe(x, y, d);
		}
		else if (cctv == 2) {
			observe(x, y, d);
			observe(x, y, d+2);
		}
		else if (cctv == 3) {
			observe(x, y, d);
			d--;
			if (d < 0) d = 3;
			observe(x, y, d);
		}
		else if (cctv == 4) {
			observe(x, y, d);
			d--;
			if (d < 0) d = 3;
			observe(x, y, d);
			d--;
			if (d < 0) d = 3;
			observe(x, y, d);
		}
		else if (cctv == 5) {
			observe(x, y, 0);
			observe(x, y, 1);
			observe(x, y, 2);
			observe(x, y, 3);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0) cnt++;
		}
	}
	res = min(res, cnt);
}

void dfs(int n) {
	if (n == arr.size()) {
		calcul();
		return;
	}

	if (arr[n].cctv == 1) {
		for (int i = 0; i < 4; i++) {
			arr[n].d = i;
			dfs(n + 1);
		}
	}
	else if (arr[n].cctv == 2) {
		for (int i = 0; i < 2; i++) {
			arr[n].d = i;
			dfs(n + 1);
		}
	}
	else if (arr[n].cctv == 3) {
		for (int i = 0; i < 4; i++) {
			arr[n].d = i;
			dfs(n + 1);
		}
	}
	else if (arr[n].cctv == 4) {
		for (int i = 0; i < 4; i++) {
			arr[n].d = i;
			dfs(n + 1);
		}
	}
	else if (arr[n].cctv == 5) {
		dfs(n + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if(0 != map[i][j] && map[i][j] != 6){
				arr.push_back({ map[i][j],i,j,0 });
			}
			else if(map[i][j] == 0)
				res++;
		}
	}
	if(arr.size() != 0)
		dfs(0);
	printf("%d", res);
}