#include <string>
#include <vector>
#include<iostream>
using namespace std;
int m, n;
int mapSize;

bool open(int sx, int sy, vector<vector<int>> &key, vector<vector<int>> map) {

	// ���� ��ġ sx, sy���� ���踦 �ڹ��迡 ��������. 
	for (int i = sx; i < sx + m; i++) { 
		for (int j = sy; j < sy + m; j++) {
			map[i][j] += key[i - sx][j - sy]; // �ڹ��迡 ���踦 ���Ѵ�.
		}
	}

	// map�� ��ġ�� �ڹ����� ��� ���Ұ� 1�̶��, �ڹ��谡 ���� ���̴�. 
	// ���Ұ� 2���, ���� �κ��� ��ģ����.

	for (int i = m - 1; i < m - 1 + n; i++) {
		for (int j = m - 1; j < m - 1 + n; j++) {
			if (map[i][j] != 1) return false; // 0 �Ǵ� 2�� open ����.
		}
	}

	return true;
}

// 2���� �迭�� ���������� 90�� ȸ�� ��Ų��.
void rotateKey(vector<vector<int>>& key) { 

	vector<vector<int>> tmp = key;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			key[i][j] = tmp[m - j - 1][i];
		}
	}

}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	m = key.size(); // ���� ũ�� ����.
	n = lock.size(); // �ڹ��� ũ�� ����.

	mapSize = n + (m - 1) * 2; // map ������.
	vector<vector<int>> map(mapSize, vector<int>(mapSize, 0)); // map�� �����.

	for (int i = m - 1; i < m - 1 + n; i++) { // map�� �߾ӿ� �ڹ��踦 �ִ´�. 
		for (int j = m - 1; j < m - 1 + n; j++) {
			map[i][j] = lock[i - (m - 1)][j - (m - 1)];
		}
	}

	for (int i = 0; i < 4; i++) { // ���踦 ȸ�� ��Ű�鼭,

		for (int r = 0; r < m + n - 1; r++) {
			for (int c = 0; c < m + n - 1; c++) {
				// ������ �� ��ġ���� �ڹ��谡 �������� Ȯ���Ѵ�.
				if (open(r, c, key, map)) return true; 
			}
		}
		rotateKey(key); // ���踦 ȸ�� ��Ų��.
	}

	return false;
}
