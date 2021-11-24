#include <string>
#include <vector>
#include<iostream>
using namespace std;
int m, n;
int mapSize;

bool open(int sx, int sy, vector<vector<int>> &key, vector<vector<int>> map) {

	// 기준 위치 sx, sy에서 열쇠를 자물쇠에 끼워본다. 
	for (int i = sx; i < sx + m; i++) { 
		for (int j = sy; j < sy + m; j++) {
			map[i][j] += key[i - sx][j - sy]; // 자물쇠에 열쇠를 더한다.
		}
	}

	// map에 위치한 자물쇠의 모든 원소가 1이라면, 자물쇠가 열린 것이다. 
	// 원소가 2라면, 돌기 부분이 겹친경우다.

	for (int i = m - 1; i < m - 1 + n; i++) {
		for (int j = m - 1; j < m - 1 + n; j++) {
			if (map[i][j] != 1) return false; // 0 또는 2면 open 실패.
		}
	}

	return true;
}

// 2차원 배열을 오른쪽으로 90도 회전 시킨다.
void rotateKey(vector<vector<int>>& key) { 

	vector<vector<int>> tmp = key;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			key[i][j] = tmp[m - j - 1][i];
		}
	}

}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	m = key.size(); // 열쇠 크기 저장.
	n = lock.size(); // 자물쇠 크기 저장.

	mapSize = n + (m - 1) * 2; // map 사이즈.
	vector<vector<int>> map(mapSize, vector<int>(mapSize, 0)); // map을 만든다.

	for (int i = m - 1; i < m - 1 + n; i++) { // map의 중앙에 자물쇠를 넣는다. 
		for (int j = m - 1; j < m - 1 + n; j++) {
			map[i][j] = lock[i - (m - 1)][j - (m - 1)];
		}
	}

	for (int i = 0; i < 4; i++) { // 열쇠를 회전 시키면서,

		for (int r = 0; r < m + n - 1; r++) {
			for (int c = 0; c < m + n - 1; c++) {
				// 적절한 각 위치에서 자물쇠가 열리는지 확인한다.
				if (open(r, c, key, map)) return true; 
			}
		}
		rotateKey(key); // 열쇠를 회전 시킨다.
	}

	return false;
}
