#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int num, dir, x, y, eatCount; // 물고기 번호, x, y, 방향, 먹은 개수 
}fish;

const int dx[] = { -1,-1,0,1,1,1,0,-1 }, dy[] = { 0,-1,-1,-1,0,1,1,1 };
int ret = -1;

void fishMoving(vector<vector<int>>& map, vector<fish>& fishList) {
	for (int i = 0; i < 16; i++) { // 번호 순서대로 물고기 탐색.
		int num = fishList[i].num, dir = fishList[i].dir;
		int x = fishList[i].x, y = fishList[i].y;

		if (num == 0) continue; // 죽은 물고기면 스킵.
		int nx, ny, ndir;
		bool flag = false; // 이동 가능 여부 플래그.

		for (int k = dir, cnt = 0; ; k++, cnt++) { // 이동 가능한 방향 탐색
			if (cnt > 9) break; // 모든 방향을 탐색했으면 중단. 
			ndir = k % 8, nx = x + dx[ndir], ny = y + dy[ndir];
			if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue; // 이동할 위치가 범위를 벗어나면 스킵.
			if (map[nx][ny] == -1) continue; // 이동할 위치에 상어가 있으면 스킵.
			flag = true; break; // 이동가능한 최소 위치를 찾으면 중단.
		}

		if (flag) { // 이동 가능하다면
			fishList[num - 1] = { num, ndir, nx, ny };
			if (map[nx][ny] > 0) { // 물고기가 이동할 위치에 물고기가 있을 경우.
				fishList[map[nx][ny] - 1].x = x;
				fishList[map[nx][ny] - 1].y = y;
			}
			swap(map[nx][ny], map[x][y]); // 이동 
		}
	}
}

void solve(vector<vector<int>> map, vector<fish> fishList, fish shark) {
	ret = max(ret, shark.eatCount);
	vector<vector<int>> afterFishMovedMap = map; // 물고기가 움직인후 맵
	vector<fish> afterFishMovedFishList = fishList; // 물고기가 움직인후 물고기 리스트

	fishMoving(afterFishMovedMap, afterFishMovedFishList);

	int x = shark.x, y = shark.y, dir = shark.dir, eatCount = shark.eatCount;
	bool flag = false;

	for (int i = 0; i <= 3; i++) {
		int nx = x + dx[dir] * i, ny = y + dy[dir] * i;
		if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue;
		if (map[nx][ny] == 0) continue; // 물고기가 없는 칸이면, 스킵.

		vector<vector<int>> afterSharkMovedMap = afterFishMovedMap;
		vector<fish> afterSharkMovedFishList = afterFishMovedFishList;

		fish nShark = { -1, dir, nx, ny, eatCount + afterSharkMovedMap[nx][ny] }; // 새롭게 업데이트 된 상어.

		afterSharkMovedFishList[map[nx][ny] - 1] = { 0,0,0,0,0 }; // 물고기 리스트에서 물고기 죽음 처리.
		afterSharkMovedMap[x][y] = 0;
		afterSharkMovedMap[nx][ny] = -1;

		solve(afterSharkMovedMap, afterSharkMovedFishList, nShark);
	}
}

bool comp(fish a, fish b) {
	return a.num < b.num;
}

int main() {
	vector<vector<int>> map(4, vector<int>(4, 0)); // 4x4 map
	vector<fish> fishList; // 물고기 리스트

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j] = a; // map에 물고기를 넣어준다.
			fishList.push_back({ a, b - 1, i, j }); // 물고리 정보 리스트를 만든다.
		}
	}
	sort(fishList.begin(), fishList.end(), comp);
	fish shark = { -1, fishList[map[0][0] - 1].dir, 0, 0, map[0][0] };
	fishList[map[0][0] - 1] = { 0, 0, 0, 0, 0 }; // 먹힌 물고기 0으로
	map[0][0] = -1; // 상어가 있는 위치는 -1

	solve(map, fishList, shark);
	cout << ret;

	return 0;
}

