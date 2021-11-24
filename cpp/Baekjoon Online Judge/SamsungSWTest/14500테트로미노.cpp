/***************
date : 20/02/08
design time : 20 min
implementation time :  33 min
debugging time :   15 min
total time :  68 min
****************/
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int map[500][500];
int res = 0;

void lengthCalcul(int x, int y) {//세로네모 3*2 계산
	//L
	res = max(res, map[x][y] + map[x+1][y] + map[x+2][y] + map[x+2][y+1]);
	res = max(res, map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x+2][y+1]);
	res = max(res, map[x][y+1] + map[x+1][y+1] + map[x+2][y+1] + map[x+2][y]);
	res = max(res, map[x][y+1] + map[x][y] + map[x+1][y] + map[x+2][y]);
	//ㄹ
	res = max(res, map[x][y] + map[x+1][y] + map[x+1][y+1] + map[x+2][y+1]);
	res = max(res, map[x][y+1] + map[x+1][y+1] + map[x+1][y] + map[x+2][y]);
	//ㅏ
	res = max(res, map[x][y] + map[x+1][y] + map[x+1][y+1] + map[x+2][y]);
	res = max(res, map[x+1][y] + map[x][y+1] + map[x+1][y+1] + map[x+2][y+1]);
}

void widthCalcul(int x, int y) { //가로네모 2*3 계산
	//L
	res = max(res, map[x][y] + map[x+1][y] + map[x][y+1] + map[x][y+2]);
	res = max(res, map[x][y] + map[x][y+1] + map[x][y + 2] + map[x+1][y + 2]);
	res = max(res, map[x+1][y] + map[x+1][y+1] + map[x+1][y+2] + map[x][y]);
	res = max(res, map[x + 1][y] + map[x + 1][y + 1] + map[x + 1][y + 2] + map[x][y+2]);
	//ㄹ
	res = max(res, map[x+1][y] + map[x+1][y+1] + map[x][y+1] + map[x][y+2]);
	res = max(res, map[x][y] + map[x][y+1] + map[x+1][y+1] + map[x+1][y+2]);
	//ㅏ
	res = max(res, map[x][y] + map[x][y+1] + map[x][y+2] + map[x+1][y+1]);
	res = max(res, map[x+1][y] + map[x+1][y+1] + map[x+1][y+2] + map[x][y+1]);
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 2 < n && j + 1 < m)
				lengthCalcul(i, j); //세로네모 계산
			if (i + 1 < n && j + 2 < m)
				widthCalcul(i, j); //가로네모 계산
			if (j + 3 < m)//가로ㅡ
				res = max(res, map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3]);
			if (i + 3 < n)//세로 ㅣ
				res = max(res, map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j]);
			if (i + 1 < n && j + 1 < m)//네모
				res = max(res, map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1]);
		}
	}

	printf("%d", res);
	return 0;
}