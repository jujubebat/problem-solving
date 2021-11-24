//���� �ڽ��� ũ�⺸�� ū ������ ���� �� ����
//���� �ڱ⺸�� ���� ����⸦ ���� ���ִ�.
//���� ���� ũ���� ����⸦ ������ �� �ִ�.
//����� ũ��� ó���� 2
//�ڽ��� ũ�⸸ŭ ����⸦ ������ ũ�Ⱑ ����
//���̻� ���� ����Ⱑ ������ ��ȿ


//���� �ĺ����� ť�� �ְ�, �Ÿ��� ������� �»� �ִ� ���� ����
//bfs�� ������ visited �迭�� �Ÿ�ǥ�� ���� ���� ���� ��ġ ��ȯ
//������ ���̷� ��� �̵� ��Ű��

#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef struct{
	int x, y;
	int moveCnt;
}shark;

int n;
int map[20][20];
int visited[20][20];
int dx[] = {1,-1,0,0}, dy[] = {0,0,-1,1};
int sharkSize=2, eatingCnt=0, time = 0;
queue<shark> q;
shark s = { 0,0,0 };

void bfs() {//bfs�� ���̱����� �ִ� ��θ� ã�´�. (visited �迭�� ���)
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int moveCnt = q.front().moveCnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i]; //�����¿� ������ ���ο� ��ǥ
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue; //���ο� ��ǥ�� �迭 ���� �ʰ��� ��ŵ!
			if (sharkSize < map[nx][ny]) continue; //���ο� ��ǥ�� �ڽ� ���� ū ������� ��ŵ!
			if (visited[nx][ny] != 0) continue; //���ο� ��ǥ�� �̵��� �� ���� ���̶�� ��ŵ!
			visited[nx][ny] = moveCnt+1; //bfs ����ϱ�
			q.push({ nx, ny, moveCnt + 1 });
		}
	}
}

int moveShark() {
	int min = 9999;
	bool check[20][20] = { 0 };
	int nx = -1, ny = -1;
	//�ּҰŸ��� ����. (��� ũ�⺸�� �۰�, �� �ƴϰ�, ���̰� ���� ���� �ƴϰ� ,�� �� ���� ���� �ƴϸ鼭 �Ÿ��� ���� ª�� ���̸� �ԾƳ���.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] < sharkSize && map[i][j] != 9 && map[i][j] != 0 && visited[i][j] != 0) {
				if (visited[i][j] <= min) {
					min = visited[i][j];
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {//�̵��� �ĺ� ���̸� check �迭�� true�� ǥ���Ѵ�.
		for (int j = 0; j < n; j++) {
			if (map[i][j] < sharkSize && map[i][j] != 9 && map[i][j] != 0 && visited[i][j] != 0) {
				if (visited[i][j] == min) {
					check[i][j] = true;
				}
			}
		}
	}

	//�ĺ� ���̰� ���� ���� ��� �»�� ��ġ�� �ִ� ��ġ�� �湮�Ѵ�. 
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) {
				nx = i, ny = j;//���� �̵��� ������ ��ġ ����
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	if (nx == -1 && ny == -1) // ���� �̵��� ������ ��ġ�� ���� �������� ����
		return -1;

	map[s.x][s.y] = 0;
	map[nx][ny] = 9; //��ũ �̵�
	s.x = nx, s.y = ny; //��ũ ��ġ ����
	s.moveCnt = visited[nx][ny];//��ũ �� �̵��Ÿ�(�ð�) ����
	eatingCnt++; // ���� ����� �� ����

	if (eatingCnt == sharkSize) { // ���� ����� ���� ���� ��� ũ�� ����
		eatingCnt = 0;
		sharkSize++;
	}
	return s.moveCnt; //������� �� �� �̵���(�ð�) ��ȯ
}

void solve() {
	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 9) {
					memset(visited, 0, sizeof(visited)); // visted �迭 �ʱ�ȭ
					s.x = i, s.y = j;
					q.push(s);//ť�� �����ġ �����ϰ�,
					bfs(); //���� ��ġ�� ã������ bfs����
					int tmp = moveShark(); // bfs�� ������� visited �迭�� map �迭�� ����Ͽ� ��� �̵�
					if (tmp == -1) //�� �̻� �̵��� �� ������ ����
						return;
					time = tmp; //��ũ �̵��Ÿ�(�ð�) ����
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	solve();
	printf("%d", time);
}