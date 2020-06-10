#include<iostream>
#include<algorithm>
using namespace std;

typedef struct {
	int num, dir;
}info;

typedef struct {
	int x,y, num, dir;
}shark;

int ret = 0;

// 상 - 0, 좌상 - 1, 좌 - 2, 좌하 -3 , 하 - 4, 우하 - 5, 우 - 6, 우상 - 7
int dx[] = { -1,-1,0,1,1,0,1 }, dy[] = { 0,-1,-1,-1,0,1,1 };

/*
bool sharkSimulatioin(info shark) {
	int num = map[0][0].num;
	int dir = map[0][0].dir;

	shark.num 
}*/

bool fishSimulation(){

}

void solve(int map[][4], info shark) {

	//if (!sharkSimulatioin()) return; // 상어 시뮬 불가능하면 종료.
	
	int distance = 0;

	while (1) {
		
	}


	if (!fishSimulation()) return; // 물고기 시뮬 불가능하면 종료.
	solve();
}

int main() {

	info map[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			map[i][j] = { num, dir };
		}
	}

	shark TeenagerShark;

	TeenagerShark.num = 0, TeenagerShark.dir = 0;

	solve(map, shark);

	return 0;
}