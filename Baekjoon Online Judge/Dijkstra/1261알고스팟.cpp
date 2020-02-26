

/* <설계>
-벽을 최소 몇 개 부셔야 하는지 구해야함.
-BFS를 돌린다 q에다가 벽부순 개수 기록{x,y,w}
-퍼지는데 제한 없음(단지 부순 벽 개수 계속 기록), 체크배열 없음 -> 무한루프 
-BFS를 돌린다 (n,m)에 도달할때 까지 
-도달하면, 부순 벽의 개수를 갱신한다. (n,m)자리 갱신
-이게 다익스트라 문제인가? -> (n,m)에 도달하는데 드는 최소 비용을 구하는 문제
-다익스트라 알고리즘 자체를 쓰는것 같진 않은데..
*/

/*<설계 수정>
-체크배열에 각 위치에 도달할때까지의 최소 비용을 계산 
*/

/*
오래걸린 이유
-우선순위 큐 기준 바꾸는 방법을 몰랐음
-fill함수 사용법을 몰랐음
-입출력, 변수명 관련 사소한 실수
-다익스트라 알고리즘(코드레벨)에서의 이해 부족. 
*/

#include<stdio.h>
#include<queue>

using namespace std;

typedef struct {
	int x, y, w;
}pos;

struct cmp {//우선순위 큐가 w 기준으로 동작하게 하려고 사용 
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
		if (dist[here_y][here_x] < cost) continue; //최단거리가 아닌경우
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