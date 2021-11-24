#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int x, y;
int r, c, t;
int map[50][50];
int airConUpXpos;
const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

void diffuseDust() {

	int tmpMap[50][50];

	// 동시 확산 처리를 위해, 원본 map을 임시 tmpMap에 복사해둔다. 
	memcpy(tmpMap, map, sizeof(map)); 

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] >= 5) { // 확산이 가능한 미세먼지인 경우.
				int diffuseAmount = map[i][j] / 5; // 확산될 미세먼지 양 계산.
				for (int k = 0; k < 4; k++) { // 상하좌우 인접 위치를 확인한다.
					int nx = i + dx[k], ny = j + dy[k];

					// 인접 위치에 공기 청정기가 있는 경우.
					if (map[nx][ny] == -1) continue; 

					// 범위를 벗어난 경우.
					if (nx >= r || nx < 0 || ny >= c || ny < 0) continue; 

					// map을 기준으로 확산여부를 판단하고, 결과반영은 tmpMap에 한다.
					// 이렇게 하면, map은 바뀌지 않으므로 먼저 확산시킨 먼지의 결과가 
					// 나중에 확산시킬 먼지의 결과에 영향을 주지 않게할 수 있다.

					// 인접 위치에 미세먼지 확산.
					tmpMap[nx][ny] += diffuseAmount; 

					// 확산 시켰으니까, 현재 위치 미세먼지 감소.
					tmpMap[i][j] -= diffuseAmount;  
				}
			}
		}
	}

	// map을 tmpMap으로 교체하여 원본 배열에 시뮬레이션 결과 반영.
	memcpy(map, tmpMap, sizeof(tmpMap)); 
}

void airConditionerWork() {

	// main에서 구한 에어컨 위쪽 좌표 기준으로 에어컨 위쪽 공기 순환 수행.
	x = airConUpXpos - 1, y = 0;
	while (x > 0) map[x][y] = map[x - 1][y], x--; // ↓

	x = 0, y = 0;
	while (y < c - 1) map[x][y] = map[x][y + 1], y++; // ←

	x = 0, y = c - 1;
	while (x < airConUpXpos)  map[x][y] = map[x + 1][y], x++; // ↑

	x = airConUpXpos, y = c - 1;
	while (y > 1) map[x][y] = map[x][y - 1], y--;  // →

	map[airConUpXpos][1] = 0; // 공기 청정기에서 공기가 나오는 부분은 0으로 만듦.

	// main에서 구한 에어컨 위쪽 좌표 + 1 = 에어컨 아래쪽 좌표
	// 에어컨 아래쪽 공기 순환 수행.

	int airConDownXpos = airConUpXpos + 1;

	x = airConDownXpos + 1, y = 0; // ↑
	while (x < r - 1) map[x][y] = map[x + 1][y], x++;

	x = r - 1, y = 0;
	while (y < c - 1) map[x][y] = map[x][y + 1], y++; // ←

	x = r - 1, y = c - 1;
	while (x > airConDownXpos) map[x][y] = map[x - 1][y], x--; // ↓

	x = airConDownXpos, y = c - 1;
	while (y > 1) map[x][y] = map[x][y - 1], y--; // →

	map[airConDownXpos][1] = 0; // 공기 청정기에서 공기가 나오는 부분은 0으로 만듦.

}

void solve() {

	while (t--) { // t초 만큼 시뮬레이션한다.
		diffuseDust(); // 먼지를 확산시킨다.
		airConditionerWork(); // 공기순환을 시킨다. 
	}

	int ret = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) ret += map[i][j]; // 남아있는 미세먼지를 모두 더한다.
		}
	}

	cout << ret; // 결과 출력.
}

int main() {
	cin >> r >> c >> t; // 값 입력.
	bool flag = true;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && flag) {
				airConUpXpos = i;  // 에어컨 위쪽부분 X 좌표를 저장해둔다. 
				flag = false;
				// X 좌표만 저장해둬도 된다. 에어컨은 항상 왼쪽 첫째 열에 위치하기 때문.
				// 최초로 만나는 -1이 에어컨 위쪽 부분 X좌표이다.
				// flag를 통해 최초 한 번만 저장 하도록 구현.
			}
		}
	}

	solve();
	return 0;
}