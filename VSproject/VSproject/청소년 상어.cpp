


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int num, dir;
	int x, y;
	int count;
}fish;

const int dx[] = {-1,-1,0,1,1,1,0,-1 }, dy[] = {0,-1,-1,-1,0,1,1,1 };
int ret = -1;

void fishMoving(vector<vector<fish>>& map, vector<fish>& fishList) {
	cout << "fishMoving" << endl;
	for (int i = 0; i < 16; i++) { // 번호 순서대로 물고기 탐색.
		cout << "i : " << i << endl;
		int num = fishList[i].num, dir = fishList[i].dir;
		int x = fishList[i].x, y = fishList[i].y;

		if (num == 0) continue; // 죽은 물고기면 스킵.
		cout << "i2 : " << i << endl;

		int nx, ny, ndir;
		bool flag = false; // 이동 가능 여부 플래그.

		for (int k = dir, cnt = 0; ;k++, cnt++) { // 이동 가능한 방향 탐색
			if (cnt > 8) break; // 모든 방향을 탐색했으면 중단. 
			cout << "cnt : " << cnt << endl;
			nx = x + dx[k % 8], ny = y + dy[k % 8], ndir = k % 8;
			if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue; // 이동할 위치가 범위를 벗어나면 스킵.
			if (map[nx][ny].num == -1) continue; // 이동할 위치에 상어가 있으면 스킵.
			flag = true; break; // 이동가능한 위치를 찾으면 중단.
		}
		cout << "도도" << endl;

		if (flag) { // 이동 가능하다면
			map[x][y].dir = ndir; // 움질일 물고기의 방향 갱신.

			if (map[nx][ny].num == 0) { // 물고기가 이동할 위치가 비어있을 경우.
				fishList[i].dir = ndir; // 이동 시킬 물고기의 방향과, 위치 갱신.
				fishList[i].x = nx;
				fishList[i].y = ny;
			}
			else if (map[nx][nx].num > 0) { // 다른 물고기가 있을경우.
				fish tmp = fishList[i];

				fishList[i].dir = ndir;  // 이동 시킬 물고기의 방향과, 위치 갱신.
				fishList[i].x = nx;
				fishList[i].y = ny;

				fishList[map[nx][nx].num - 1].x = tmp.x; // 원래위치에 있던 물고기 위치 좌표 갱신 
				fishList[map[nx][nx].num - 1].y = tmp.y;
			}

			swap(map[x][y], map[nx][ny]);
		}

		cout << "도도 끝" << endl;
	}
}

void solve(vector<vector<fish>> map, fish shark, vector<fish> fishList) {
	cout << "호우" << endl;
	ret = max(ret, shark.count);
	
	vector<vector<fish>> afterFishMovedMap = map;
	vector<fish> afterFishMovedFishList = fishList;
	// 피시 무빙
	fishMoving(afterFishMovedMap, afterFishMovedFishList);

	cout << "도도 끝2" << endl;

	int nx = shark.x, ny = shark.y, ncount = shark.count;

	while (1) {

		nx += dx[shark.dir], ny += dy[shark.dir];

		if (nx >= 4 || nx < 0 || ny >= 4 || ny < 0) break; // 이동할 위치가 범위를 벗어나면 스킵.

		cout << nx << " " << ny << " " << shark.dir << endl;

		if (map[nx][ny].num == 0) continue; // 물고기가 없는 칸이면, 스킵.

		vector<vector<fish>> afterSharkMovedMap = afterFishMovedMap;
		vector<fish> afterSharkMovedFishList = afterFishMovedFishList;

		afterSharkMovedMap[shark.x][shark.y] = { 0,0,0,0,0 }; // 기존 상어 위치 비우기.
		cout << "밍밍1" << endl;
		fish nShark = { -1, shark.dir, nx, ny, ncount + map[nx][ny].num }; // 새롭게 업데이트 된 상어.
		
		// 물고리 리스트 업데이트(죽은 물고기 0으로 초기화)
		if(afterSharkMovedMap[nx][ny].num > 0)
			afterSharkMovedFishList[afterSharkMovedMap[nx][ny].num - 1] = { 0,0,0,0,0 };
		cout << "밍밍2" << endl;

		// 상어 이동.
		afterSharkMovedMap[nx][ny] = nShark;  
		cout << "밍밍2" << endl;

        // map에 있는 상어 위치 바꿔주고, 최대 값 갱신해야함. 
		solve(afterSharkMovedMap, nShark, afterSharkMovedFishList);
	}

}

bool comp(fish a, fish b) {
	return a.num < b.num;
}

int main() {
	vector<vector<fish>> map(4, vector<fish>(4)); // 4x4 map
	vector<fish> fishList; // 물고기 리스트

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j] = { a,b-1,i,j }; // map에 물고기를 넣어준다.
			fishList.push_back({ a,b-1,i,j }); // 물고리 정보 리스트를 만든다.
		}
	}

	// 물고기 번호순으로 오름차순 정렬.
	sort(fishList.begin(), fishList.end(), comp);

	// 청소년 상어는 최초 (0,0)에 있는 물고기를 먹는다. 
	// 상어는 -1 이며, 먹은 물고기의 방향을 가진다, 좌표는 (0,0)으로 설정.
	// count에 먹은 물고기의 번호를 누적한다.
	fish shark = { -1,map[0][0].dir,0,0,map[0][0].num}; 
	
	fishList[0] = { 0,0,0,0,0 }; // 물고기 리스트 업데이트
	map[0][0] = { -1,0,0,0,0 }; // 맵 업데이트

	solve(map, shark, fishList);

	cout << ret;

	return 0;
}


/*
4x4 공간
각 물고기는 번호와 방향을 가지고 있다. (번호는 ~ 16)
8가지 방향이 있다.
상어는 0,0 에서 시작한다.
물고기는 번호가 작은 물고기부터 순서대로 이동한다.
물고기는 한 칸을 이동한다. 이동 가능한 칸은 빈칸 또는 다른 물고기가 있는칸
물고기가 이동할 수 없는 칸은 상어가 있거나 범위를 벗어나는 경우
각 물고기는 방향이 이동할 수 있는 칸을 향할때까지 45도 반시계 회전을 한다.
물고기는 이동할 수 있는 칸이 없으면 이동하지 않는다.
물고기가 다른 물고기가 있는 칸으로 이동할 때는 서로의 위치를 바꾸는 방식으로 이동한다.

물고기의 이동이 모두 끝나면 상어가 이동한다. 상어는 방향에 있는 칸으로 이동할 수 있는데
한 번에 여러 칸을 이동할 수 있다. 상어가 물고기가 있는 칸으로 이동했다면, 그 칸에 있는 물고기를먹고
그 물고기의 방향을 가진다. 물고기가 없는 칸으로는 이동할 수 없다.
상어가 이동할 수 있는 칸이 없으면 집으로간다.
*/