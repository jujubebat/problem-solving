#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int dx[] = { 0, 0,1,1 }, dy[] = { 0,1,0,1 };
vector<string> g_board;

void fall(int m, int n) { //블록을 떨어뜨리는 함수.
	for (int col = 0; col < n; col++) {
		for (int row = m - 1; row >= 0; row--) {
			if (g_board[row][col] != 'x') {
				for (int k = m - 1; k >= row; k--) {
					if (g_board[k][col] == 'x') {
						swap(g_board[row][col], g_board[k][col]);
						break;
					}
				}
			}
		}
	}
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool flag;
	bool check[30][30];
	g_board = board;

	while (1) {
		flag = false;
		memset(check, false, sizeof(check));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {

				if (i + 1 >= m || j + 1 >= n) continue; // 예외처리 : 배열 범위 초과

				int cnt = 0;

				// 2x2 공간에 모두 같은 블록이 있는지 확인
				for (int r = i; r < i + 2; r++) {
					for (int c = j; c < j + 2; c++) {
						if (g_board[r][c] != 'x') {
							if (g_board[r][c] == g_board[i][j]) cnt++;
						}
					}
				}

				// 있다면, check 배열에 체크
				if (cnt == 4) {
					flag = true;
					for (int r = i; r < i + 2; r++) {
						for (int c = j; c < j + 2; c++) {
							if (g_board[r][c] != 'x') {
								check[r][c] = true;
							}
						}
					}
				}
			}
		}

		if (!flag) return answer;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] && g_board[i][j] != 'x') {
					g_board[i][j] = 'x';
					answer++;
				}
			}
		}
		fall(m, n);
	}

	return answer;
}


//개선한 코드
/*
#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool flag;

	while (1) {
		flag = false;
		bool check[30][30] = { false };

		// m-1, n-1 까지만 확인해도 된다. 이러면 배열 범위 초과에 대한 예외처리 코드 작성하지 않아도 된다.
		for (int i = 0; i < m - 1; i++) { 
			for (int j = 0; j < n - 1; j++) {

				// 예외처리 : 비어있는 공간.
				if (board[i][j] == 0) continue;

				// 2x2 공간에 모두 같은 블록이 있는지 확인한다.
				if ((board[i][j] == board[i + 1][j])
					&& (board[i][j] == board[i][j + 1])
					&& (board[i][j] == board[i + 1][j + 1])) {
					check[i][j] = true;
					check[i + 1][j] = true;
					check[i][j + 1] = true;
					check[i + 1][j + 1] = true;
					flag = true; // flag set : 터뜨릴 수 있는 블록이 존재한다.
				}

			}
		}

		if (!flag) break; // 터뜨릴 수 있는 블록이 없을 경우 탈출

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j]) {
					answer++; // 블록 개수 체크 

					// 터뜨릴 수 있는 블록 바로 위부터 맨 위까지 순차적으로 아래로 하나씩 옮긴다.
					for (int k = i - 1; k >= 0; k--) {
						board[k + 1][j] = board[k][j];
						board[k][j] = 0;
					}
				}
			}
		}
	}

	return answer;
}*/