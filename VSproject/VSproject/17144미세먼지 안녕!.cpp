#include<iostream>
#include<algorithm>
using namespace std;

int x, y;
int r, c, t;
int map[50][50];
int airConUpSideXpos;
const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

void diffuseDust() {

	int tmpMap[50][50] = { 0 };

	tmpMap[airConUpSideXpos][0] = -1;
	tmpMap[airConUpSideXpos + 1][0] = -1;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) { // 미세먼지일 경우.

				int diffusedCount = 0, diffuseAmount = map[i][j] / 5;

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (map[nx][ny] == -1) continue; // 공기 청정기가 있는 경우.
					if (nx >= r || nx < 0 || ny >= c || ny < 0) continue; // 칸이 없는 경우.

					tmpMap[nx][ny] += diffuseAmount, diffusedCount++;
					//map[nx][ny] += diffuseAmount, diffusedCount++; // 확산, 확산 개수 증가.

				}
				if (diffusedCount > 0) {

					tmpMap[i][j] = map[i][j] - diffuseAmount * diffusedCount;
					if (tmpMap[i][j] < 0) tmpMap[i][j] = 0;

					//map[i][j] -= diffuseAmount * diffusedCount; // 원래 위치 먼지량 계산.
					//if (map[i][j] < 0) map[i][j] = 0;
				}
				else
					tmpMap[i][j] = map[i][j];

			}
		}
	}

	/*
	cout << "먼지 퍼지기" << endl;
	cout << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << tmpMap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/


	copy(&tmpMap[0][0], &tmpMap[r - 1][c - 1], &map[0][0]);

	//map, 

}

void airConditionerWork() {
	// 위쪽 공기 순환.

	//맨 왼쪽열 아래 방향으로 순환.
	x = airConUpSideXpos - 1, y = 0;
	while (x > 0) {
		map[x][y] = map[x - 1][y], x--;
	}
	//맨 위쪽열 왼쪽 방향으로 순환.
	x = 0, y = 0;
	while (y < c - 1) {
		map[x][y] = map[x][y + 1], y++;
	}
	//맨 오른쪽열 위쪽 방향으로 순환.
	x = 0, y = c - 1;
	while (x < airConUpSideXpos) {
		map[x][y] = map[x + 1][y], x++;
	}
	//아래쪽 열 오른쪽 방향으로 순환.
	x = airConUpSideXpos, y = c - 1;
	while (y > 0) {
		if (y == 1) {
			map[x][y] = 0;
		}
		else
			map[x][y] = map[x][y - 1];
		y--;
	}

	// 아래쪽 공기 순환
	int airConDownSideXpos = airConUpSideXpos + 1;

	// 왼쪽열 위쪽 방향으로 순환.
	x = airConDownSideXpos + 1, y = 0;
	while (x < r - 1) {
		map[x][y] = map[x + 1][y], x++;
	}

	// 아래쪽 열 왼쪽 방향으로 순환.
	x = r - 1, y = 0;
	while (y < c - 1) {
		map[x][y] = map[x][y + 1], y++;
	}

	// 왼쪽열 아래쪽 방향을 순환. 
	x = r - 1, y = c - 1;
	while (x > airConDownSideXpos) {
		map[x][y] = map[x - 1][y], x--;
	}

	x = airConDownSideXpos, y = c - 1;
	while (y > 0) {
		if (y == 1) {
			map[x][y] = 0;
		}
		else
			map[x][y] = map[x][y - 1];
		y--;
	}

}

void solve() {

	while (t--) {
		diffuseDust();

		/*cout << "먼지 퍼지기" << endl;
		cout << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/

		airConditionerWork();

		/*cout << "공기 청정기 돌리기" << endl;
		cout << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}

	int ret = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) ret += map[i][j];
		}
	}

	cout << ret;
}

int main() {
	cin >> r >> c >> t;
	bool flag = true;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && flag) { // 참고 에어컨은 첫번째 열에만 존재한다. 
				airConUpSideXpos = i;  // 에어컨 윗쪽 부분 X좌표 저장.
				flag = false;
			}
		}
	}

	solve();
	return 0;
}