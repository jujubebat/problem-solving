/*
�ܼ��� ����.
��ǻ�ʹ� ���� ���� �� �� �ִ�.
��ĭ�� ������, 1���� 9������ ��� �־��.
���������� ���� ��ǥ�� �������� ��, ��, 3x3 ���簢�� ������ ���� �˻縦�Ѵ�.
�˻縦 ����Ѵٸ�, ���ڸ� �ְ� ���� ��ͷ� �����Ѵ�.
��Ͱ� �����Ŀ���, ���� ���ڸ� ���ְ� ���� ���ڸ� �־��.

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
	//��˻�
	for (int i = 0; i < 9; i++) {
		if (map[i][y] == num)
			return false;
	}

	//���˻�
	for (int i = 0; i < 9; i++) {
		if (map[x][i] == num)
			return false;
	}

	x = x / 3 * 3; 
	y = y / 3 * 3;

	//3x3�˻�
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


	if (flag) return; // 1�� �ϼ��ϸ�, ����.

	if (isComplete()) {//�ϼ��ȴٸ� ����.
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