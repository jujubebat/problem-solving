#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int dx[] = { 0, 0,1,1 }, dy[] = { 0,1,0,1 };
vector<string> g_board;

void fall(int m, int n) { //����� ����߸��� �Լ�.
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

				if (i + 1 >= m || j + 1 >= n) continue; // ����ó�� : �迭 ���� �ʰ�

				int cnt = 0;

				// 2x2 ������ ��� ���� ����� �ִ��� Ȯ��
				for (int r = i; r < i + 2; r++) {
					for (int c = j; c < j + 2; c++) {
						if (g_board[r][c] != 'x') {
							if (g_board[r][c] == g_board[i][j]) cnt++;
						}
					}
				}

				// �ִٸ�, check �迭�� üũ
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


//������ �ڵ�
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

		// m-1, n-1 ������ Ȯ���ص� �ȴ�. �̷��� �迭 ���� �ʰ��� ���� ����ó�� �ڵ� �ۼ����� �ʾƵ� �ȴ�.
		for (int i = 0; i < m - 1; i++) { 
			for (int j = 0; j < n - 1; j++) {

				// ����ó�� : ����ִ� ����.
				if (board[i][j] == 0) continue;

				// 2x2 ������ ��� ���� ����� �ִ��� Ȯ���Ѵ�.
				if ((board[i][j] == board[i + 1][j])
					&& (board[i][j] == board[i][j + 1])
					&& (board[i][j] == board[i + 1][j + 1])) {
					check[i][j] = true;
					check[i + 1][j] = true;
					check[i][j + 1] = true;
					check[i + 1][j + 1] = true;
					flag = true; // flag set : �Ͷ߸� �� �ִ� ����� �����Ѵ�.
				}

			}
		}

		if (!flag) break; // �Ͷ߸� �� �ִ� ����� ���� ��� Ż��

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j]) {
					answer++; // ��� ���� üũ 

					// �Ͷ߸� �� �ִ� ��� �ٷ� ������ �� ������ ���������� �Ʒ��� �ϳ��� �ű��.
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