#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct {
	int x, y;
}pos;

pos start, festival, store[100];
int n;
bool check[101];

bool isPassible(int x1, int y1, int x2, int y2) {
	int distance = abs(x1 - x2) + abs(y1 - y2);
	if (distance > 1000)
		return false;
	else
		return true;
}

bool bfs(int sx, int sy) {
	bool flag = false;
	queue<pos> q;
	q.push({ sx,sy });

	while (!q.empty()){
		int x = q.front().x, y = q.front().y;
		q.pop();
		if (x == festival.x && y == festival.y) {//���������� �˻�.
			flag = true;
			break;
		} 

		for (int i = 0; i <= n; i++) {//����������� ������������
			int nx = store[i].x, ny = store[i].y;
			if (!isPassible(x, y, nx, ny)) continue; //�Ÿ�üũ
			if (check[i]) continue; //�̹� �湮�� �������̶��.
			check[i] = true;
			q.push({ nx,ny });
		}
	}
	return flag;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> start.x >> start.y;
		for (int j = 0; j <= n; j++) {
			cin >> store[j].x >> store[j].y;
		}
		festival.x = store[n].x;
		festival.y = store[n].y;
		memset(check, 0, sizeof(check));
		if (bfs(start.x, start.y))
			printf("happy\n");
		else
			printf("sad\n");
	}
	return 0;
}

/*
���� 1�ڽ����� ���� 20��
50���Ϳ� 1����

bfs�� Ž��
������ ����ؼ� �佺Ƽ������ �����ϴ� �ִܰŸ�

������, ������ ��� �ĺ��� �ִ´�.
bfs�� ������.
�����ϸ�, ǥ���Ѵ�.
*/