
//���� �μ����� �μ��� ���� �� ���� ������.
//���� �μ� ���� ���� �ϳ��� �迭�� ����ص� ���� ���� �ʴ´�. (���ذ� ���� ���� ��..)
//�ٽ� Ǯ������ϴ� ����

#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	int x, y, w; // w�� 1�̸� ���� �μ� ����
}pos;

int n, m;
int map[1000][1000];
int visited[1000][1000][2];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
queue<pos> q;

int bfs() {
	q.push({ 0,0,0 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, w = q.front().w;
		q.pop();

		if (x == n - 1 && y == m - 1) return visited[x][y][w]; //������ �����ϸ� ��� ����

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue; //���� ����� ��ŵ
			if (visited[nx][ny][w]) continue; //�̹� ��ϵ� ��ġ��� ��ŵ

			if (map[nx][ny] == 0) {//���� ��ġ�� �̵� �����ϸ�
				visited[nx][ny][w] = visited[x][y][w] + 1;
				q.push({ nx,ny,w });
			}
			if (map[nx][ny] == 1 && w == 0) { //���� ��ġ�� ���̰�, ���� �μ� �� �ִٸ�,
				visited[nx][ny][1] = visited[x][y][w] + 1;
				q.push({ nx,ny,1 });
			}

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					printf("%d", visited[j][k][0]);

				}
				puts("");

			}
			puts("�ѤѤѤѤѤѤѤѤѤѤѤѤ�");

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					printf("%d", visited[j][k][1]);
				}
				puts("");
			}
			puts("");
		}
	}

	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d", bfs());

	return 0;
}

