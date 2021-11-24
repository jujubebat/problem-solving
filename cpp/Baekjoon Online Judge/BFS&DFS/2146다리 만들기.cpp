/***************
date : 20/02/07
design time : 25min
implementation time : 32 min
debugging time : 0 min
****************/

/*
//Ž���� �����ϴ� ���� 2�� ǥ���Ѵ�.
//�ٴٿ� �����ϴ� �������� bfs�� ������. 
//üũ�迭�� �Ÿ��� ����ϸ鼭 Ž���Ѵ�.
//�̰������� ���� �ٸ� ���� �����ٸ�, �� ��ο� ���� �ּҰ��� ����Ѵ�. 
*/

/*
Ž�������ϱ� ���� ���� ��ȸ���� ���� dfs�� ����Ͽ� ���ڷ� ǥ��(2���� ����)
���� ��ȸ���� ���� �ٴٿ� ������ �������� bfs�� ����(üũ�迭���)
���� ������ �ٴٿ� �����ϴ� ������ ���ؼ�, bfs�� ������.(0���� ����ؼ� �ٸ����� ��´ٸ�, �ּҰ�����ϰ� ����)
�ð��ʰ� ���� ������ ����(bfs�� �ð����⵵�� O(v+e)�̴ϱ�..
*/
#include<iostream>
#include<queue>

using namespace std;
typedef struct {
	int x;
	int y;
}pos;

int map[100][100];
int check[100][100];
int res = 1e9;
int n, num = 1;
int dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};
queue<pos> curLand;
queue<pos> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny] == num) continue; //������ȸ���� ���̸� ��ŵ
			if (map[nx][ny] != 0) {//�ٸ����ϰ��
				if (check[x][y] + 1 < res)
					res = check[x][y] + 1; //�Ÿ��ּڰ����
				continue;
			}
			if (check[nx][ny] != 0) continue;
			if (check[x][y] > res) continue; // ���� �ּұ��̺��� ��ٸ�
			check[nx][ny] = check[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	puts("");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ",check[i][j]);
		}
		puts("");
	}
	puts("");
}

void findShortest() {
	int flag = false;
	while (!curLand.empty())
	{
		int x = curLand.front().x, y = curLand.front().y;
		curLand.pop();
		flag = false;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny] == 0)
				flag = true; //�ٴٿ� ������ ������� true
		}

		fill(&check[0][0], &check[n][n], 0);//üũ�迭 �ʱ�ȭ 
		if (flag) {
			q.push({ x,y });
			check[x][y] = -1;
			bfs();
		}
	}
}

void dfs(int x, int y) {
	map[x][y] = num;
	curLand.push({ x,y });
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
		if (map[nx][ny] != 1) continue;
		dfs(nx, ny);
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				num++; 
				dfs(i,j);
				findShortest();
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
	solve();
	printf("%d", res);
}