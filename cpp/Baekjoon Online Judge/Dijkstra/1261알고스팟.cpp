

/* <����>
-���� �ּ� �� �� �μž� �ϴ��� ���ؾ���.
-BFS�� ������ q���ٰ� ���μ� ���� ���{x,y,w}
-�����µ� ���� ����(���� �μ� �� ���� ��� ���), üũ�迭 ���� -> ���ѷ��� 
-BFS�� ������ (n,m)�� �����Ҷ� ���� 
-�����ϸ�, �μ� ���� ������ �����Ѵ�. (n,m)�ڸ� ����
-�̰� ���ͽ�Ʈ�� �����ΰ�? -> (n,m)�� �����ϴµ� ��� �ּ� ����� ���ϴ� ����
-���ͽ�Ʈ�� �˰��� ��ü�� ���°� ���� ������..
*/

/*<���� ����>
-üũ�迭�� �� ��ġ�� �����Ҷ������� �ּ� ����� ��� 
*/

/*
�����ɸ� ����
-�켱���� ť ���� �ٲٴ� ����� ������
-fill�Լ� ������ ������
-�����, ������ ���� ����� �Ǽ�
-���ͽ�Ʈ�� �˰���(�ڵ巹��)������ ���� ����. 
*/

#include<stdio.h>
#include<queue>

using namespace std;

typedef struct {
	int x, y, w;
}pos;

struct cmp {//�켱���� ť�� w �������� �����ϰ� �Ϸ��� ��� 
	bool operator()(pos x, pos y) {
		return x.w > y.w;
	}
};

int n, m;
int map[100][100];
int dist[100][100];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
const int INF = 0x7fffffff;

void daijkstra(int x, int y) {
	priority_queue<pos, vector<pos>,cmp> pq;
	dist[y][x] = 0;
	pq.push({ x, y, 0 });
	while (!pq.empty())
	{
		int here_x = pq.top().x;
		int here_y = pq.top().y;
		int cost = -pq.top().w;
		pq.pop();
		if (dist[here_y][here_x] < cost) continue; //�ִܰŸ��� �ƴѰ��
		for (int i = 0; i < 4; i++) {
			int nx = here_x + dx[i], ny = here_y + dy[i];
			int newDist = cost + map[ny][nx];
			if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
			if (newDist < dist[ny][nx]) {
				dist[ny][nx] = newDist;
				pq.push({ nx,ny,-newDist });
			}
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	fill(&dist[0][0], &dist[0][0] + 100 * 100, INF);
	daijkstra(0, 0);
	printf("%d", dist[n-1][m-1]);
}