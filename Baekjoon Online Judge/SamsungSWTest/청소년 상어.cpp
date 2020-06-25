#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int id, dir, x, y, eatCount; // 물고기 번호, x, y, 방향, 먹은 개수 
}fish;

const int dx[] = { -1,-1,0,1,1,1,0,-1 }, dy[] = { 0,-1,-1,-1,0,1,1,1 };
int ret = -1;

void fishMoving(vector<vector<fish>>& map) {
	bool check[17] = { false };
	for (int id = 1; id <= 16; id++) { // 번호 순서대로 물고기 탐색.
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {

				if (id == map[i][j].id && !check[id]) {
					check[id] = true;
					fish curFish = map[i][j];
					for (int k = 0; k < 8; k++) {
						int ndir = (curFish.dir + k) % 8;
						int nx = curFish.x + dx[ndir];
						int ny = curFish.y + dy[ndir];

						if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue; // 이동할 위치가 범위를 벗어나면 스킵.
						if (map[nx][ny].id == -1) continue; // 이동할 위치에 상어가 있으면 스킵.

						swap(map[curFish.x][curFish.y], map[nx][ny]); // 이동 
						break;
					}
				}

			}
		}
	}
	
	cout << "물고기 이동 후 " <<endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j].id << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void solve(vector<vector<fish>> map, fish shark) {
	ret = max(ret, shark.eatCount);
	fishMoving(map);

	int x = shark.x, y = shark.y, dir = shark.dir, eatCount = shark.eatCount;

	for (int i = 1; i <= 3; i++) {
		int nx = x + dx[dir]*i, ny = y + dy[dir]*i;

		if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue;
		if (map[nx][ny].id ==  0) continue; // 물고기가 없는 칸이면, 스킵.

		vector<vector<fish>> tempMap = map;

		int nDir = tempMap[nx][ny].dir;
		int nEatCount = eatCount + tempMap[nx][ny].id;
		
		fish nShark = { -1, nDir, nx, ny, nEatCount }; // 새롭게 업데이트 된 상어.
		
		tempMap[x][y] = { 0,0,0,0,0 };
		tempMap[nx][ny] = nShark;

		solve(tempMap, nShark);
	}
}

int main() {
	vector<vector<fish>> map(4, vector<fish>(4, { 0,0,0,0,0 })); // 4x4 map

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j] = { a, b-1, i, j, 0 }; // map에 물고기를 넣어준다.
		}
	}

	fish shark = { -1, map[0][0].dir, 0, 0, map[0][0].id};
	map[0][0] = shark; // 상어가 있는 위치는 -1

	solve(map, shark);
	cout << ret;

	return 0;
}
