#include<iostream>
using namespace std;

typedef struct {
	int x, y;
}pos;

int map[16][16];
int n;
int res = 0;
int dx[] = { 0,1,1 }, dy[] = { 1,0,1 }; // →,↓, ↘ 
int d_0[2] = { 0,2 }, d_1[2] = { 1,2 }, d_2[3] = { 0,1,2 };
int dir = 0; //0 가로, 1 세로, 2 대각
pos tail, head;

bool isWall(int x, int y, int d) {
	if (d == 0 || d == 1) {//→,↓
		if (map[x][y] == 1)
			return true;
	}
	else if (d == 2) {// ↘
		if (map[x][y] == 1 || map[x][y - 1] == 1 || map[x - 1][y])
			return true;
	}
	return false;
}

void dfs(pos head) {// 파이프 이동함수
	if (head.x == n - 1 && head.y == n - 1) {
		res++;
		return;
	}

	int nx, ny;
	if (dir == 0) {//가로
		for (int i = 0; i < 2; i++) {
			nx = head.x + dx[d_0[i]], ny = head.y + dy[d_0[i]]; //→,↘ 
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (!isWall(nx, ny, d_0[i])) {//벽 여부 체크 
				dir = d_0[i]; //방향 바꿔주기
				dfs({ nx,ny });
			}
		}
	}
	else if (dir == 1) {//세로
		for (int i = 0; i < 2; i++) {
			nx = head.x + dx[d_1[i]], ny = head.y + dy[d_1[i]]; //↓, ↘
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (!isWall(nx, ny, d_1[i])) {//벽 여부 체크 
				dir = d_1[i]; //방향 바꿔주기
				dfs({ nx,ny });
			}
		}
	}
	else if (dir == 2) {//대각
		for (int i = 0; i < 3; i++) {
			nx = head.x + dx[d_2[i]], ny = head.y + dy[d_2[i]]; // →,↓, ↘ 
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (!isWall(nx, ny, d_2[i])) {//벽 여부 체크 
				dir = d_2[i]; //방향 바꿔주기
				dfs({ nx,ny });
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	head.x = 0, head.y = 1;
	dir = 0; // 가로
	dfs(head);
	printf("%d", res);
	return 0;
}

/*
파이프 이동함수
-가로
-세로
-대각
-벽만나는 경우 고려

dfs로 재귀하다가 n-1, n-1 만나면 카운트
*/
