/*
단순한 생각.
컴퓨터는 많은 것을 할 수 있다.
빈칸을 만나면, 1부터 9까지를 모두 넣어본다.
넣을때마다 넣은 좌표를 기준으로 행, 열, 3x3 정사각형 범위에 대해 검사를한다.
검사를 통과한다면, 숫자를 넣고 다음 재귀로 진입한다.
재귀가 끝난후에는, 넣은 숫자를 빼주고 다음 숫자를 넣어본다.

*/

#include<iostream>
using namespace std;

int map[9][9];
bool flag;

bool isComplete() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0)
				return false;
		}
	}
	return true;
}

bool isPossible(int x, int y, int num) {
	//행검사
	for (int i = 0; i < 9; i++) {
		if (map[i][y] == num)
			return false;
	}

	//열검사
	for (int i = 0; i < 9; i++) {
		if (map[x][i] == num)
			return false;
	}

	x = x / 3 * 3; 
	y = y / 3 * 3;

	//3x3검사
	for (int i = x; i < x+3 ; i++) {
		for (int j = y; j < y+3; j++) {
			if (map[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}

void dfs(){

	/*for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ",map[i][j]);
		}
		puts("");
	}
	puts("");*/


	if (flag) return; // 1번 완성하면, 종료.

	if (isComplete()) {//완성된다면 종료.
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", map[i][j]);
			}
			puts("");
		}
		flag = true;
		return;
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				for (int k = 1; k <= 9; k++) {
					if (isPossible(i,j,k)) {
						map[i][j] = k;
						dfs();
						map[i][j] = 0;
					}
				}
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}
	dfs();
	return 0;
}