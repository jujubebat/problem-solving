//bfs �⺻ ���信 ����ؼ� ���� ���� Ǯ����, 
//������ ť�������� �湮 ǥ�ø� ����� bfs�� �ùٸ��� �۵��ϴµ�, ������ ť���� ���� �湮 ó���� ���ִ� �Ǽ��� �Ͽ� �ߺ� �湮�� ������ �޸� �ʰ� ������ �߻��߾���

#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

typedef struct {
	int x;
	int y;
}cabbage;

int t, m, n, k;
int map[50][50];
queue<cabbage> q;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 }; //x�� ��, y�� �� 

void bfs(int a, int b) {
	q.push({ a,b });
	map[a][b] = 0;
	
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //�迭���� ����� ����
			if (map[nx][ny] == 1) {
				map[nx][ny] = 0;
				q.push({ nx,ny });
			}
		}
	}
}

int solve() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				bfs(i,j);
				res++;
			}
		}
	}
	return res;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		int x, y;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		int res = solve();
		printf("%d\n", res);
		memset(map, 0, sizeof(map));
	}
	return 0;
}