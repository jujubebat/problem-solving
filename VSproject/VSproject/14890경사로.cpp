//자기보다 1 높은 길을 만나면, 
//자신의 위치에서 -L 만큼 자신만큼 크기가 있는 길이 있는지 확인
//자기보다 1 낮은 길을 만나면, 
//자신의 위치에서 +L 만큼 자신만큼 크기가 있는 길이 있는지 확인
//길을 확인하다가 안되는 경우가 있으면, 탈출

#include<iostream>
using namespace std;

int map[100][100];
int res = 0;
int N, L;

bool checkRow(int row){
	bool check[100] = { false };
	int cnt;
	for (int j = 0; j < N-1; j++) {
		if (map[row][j] == map[row][j + 1] - 1) {// 다음 길이 1높은 길
			cnt = 1;
			while (j - cnt >= 0) {
				if (map[row][j] + 1 == map[row][j - cnt]) {
					if (check[j - cnt]) return false; //이미 경사로를 놓았으면, x
					check[j - cnt] = true;
					cnt++;
				}
				else break;
			}
			if (cnt != L) return false;
			if (j + cnt != 0 && map[row][j + cnt - 1] != map[row][j] + 1)
				return false;
		}
		else if (map[row][j] == map[row][j + 1] + 1) { //다음 길이 1낮은 길
			cnt = 1;
			while (j + cnt < N) {
				if (map[row][j] - 1 == map[row][j + cnt]) {
					if (check[j + cnt]) return false;  //이미 경사로를 놓았으면, x
					check[j + cnt] = true;
					cnt++;
				}
				else break;
			}
			if (cnt != L) return false;
			if (j + cnt != N - 1 && map[row][j + cnt + 1] != map[row][j] - 1)
				return false;
		}
		else
			return false;
			
	}
}

bool checkColumn(int col) {
	int row=0;
	bool check[100] = { false };
	int cnt;
	for (int j = 0; j < N - 1; j++) {
		if (map[row][j] == map[row][j] - 1) {// 다음 길이 1높은 길
			cnt = 1;
			while (j - cnt >= 0) {
				if (map[row][j] + 1 == map[row][j - cnt]) {
					if (check[j - cnt]) return false; //이미 경사로를 놓았으면, x
					check[j - cnt] = true;
					cnt++;
				}
				else break;
			}
			if (cnt != L) return false;
			if (j + cnt != 0 && map[row][j + cnt - 1] != map[row][j] + 1)
				return false;
		}
		else if (map[row][j] == map[row][j] + 1) { //다음 길이 1낮은 길
			cnt = 1;
			while (j + cnt < N) {
				if (map[row][j] - 1 == map[row][j + cnt]) {
					if (check[j + cnt]) return false;  //이미 경사로를 놓았으면, x
					check[j + cnt] = true;
					cnt++;
				}
				else break;
			}
			if (cnt != L) return false;
			if (j + cnt != N - 1 && map[row][j + cnt + 1] != map[row][j] - 1)
				return false;
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		if (checkRow(i))
			res++;

		//if (checkColumn(i))
			//res++;
	}
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	printf("%d", res);
	return 0;
}