/***************
[2017 ��ݱ� �Ｚ SW �׽�Ʈ ����  : �κ� û�ұ�]
date : 20/02/08
design time : 24 min
implementation time : 35 min
debugging time :  20 min
total time : 79 min
****************/

#include<iostream>

using namespace std;

typedef struct {
	int x, y;
}pos;

int map[50][50];
int res = -1e9;
int r, c, d;
int dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};

pos leftAndFoward(int x, int y) {
	pos next;
	if (d == 0) {
		next.x = x, next.y = y - 1;
		return next;
	}
	if (d == 1) {
		next.x = x-1, next.y = y;
		return next;
	}
	if (d == 2) {
		next.x = x, next.y = y + 1;
		return next;
	}
	if (d == 3) {
		next.x = x + 1, next.y = y;
		return next;
	}
}

void dfs(int x, int y, int cnt, bool back) {
	if (!back) {
		map[x][y] = cnt;
		if (cnt > res)
			res = cnt;
	}
	
	int nx, ny;
	pos nextPos;

	//4���� Ž���õ�
	for (int i = 0; i < 4; i++) {
		nextPos = leftAndFoward(x, y); //����ȸ���� ���� ��ġ
		nx = nextPos.x, ny = nextPos.y;
		if (map[nx][ny] == 0) {
			if (d == 0) d = 3; //ȸ��
			else d -= 1;
			dfs(nx, ny, cnt + 1, false);
			return;
		}
		else {
			if (d == 0) d = 3;
			else d -= 1;
		}
	}

	//�����õ�
	if (d == 0 && map[x + 1][y] != 1)
		dfs(x + 1, y, cnt, true);
	else if (d == 1 && map[x][y-1] != 1)
		dfs(x, y-1, cnt, true);
	else if (d == 2 && map[x - 1][y] != 1)
		dfs(x - 1, y, cnt, true);
	else if (d == 3 && map[x][y+1] != 1)
		dfs(x, y+1, cnt, true);
	
	//������ ���Ұ��
	return;
}

int main() {
	int n, m;

	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dfs(r,c,2,false);
	printf("%d\n", res-1);
}