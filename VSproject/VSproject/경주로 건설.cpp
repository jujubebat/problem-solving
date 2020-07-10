#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct {
	// xy 좌표 직선도로 개수, 코너 개수, 비용, 방향
	int x, y, straight, corner, cost, dist;
}road;

// x좌표, y좌표, 직선도로 개수, 코너 개수! 이렇게 4가지로 그래프의 정점을 정의한다.
bool check[25][25][500][500];
const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

int bfs(vector<vector<int>> board) {
	int ret = 0x7fffffff; // (n-1, n-1)까지의 최소 비용을 저장할 변수
	int size = board[0].size();

	queue<road> q;
	q.push({ 0,0,0,0,0,0 }); // (0,0)에서 시작한다. 
	check[0][0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y,
			straight = q.front().straight, corner = q.front().corner,
			cost = q.front().cost, dist = q.front().dist;
		q.pop();

		if (ret <= cost) continue; // cost가

		// (n-1, n-1)에 도착했다면, 최소비용인지 확인한다!
		if (x == size - 1 && y == size - 1) {
			ret = min(ret, cost);
			continue;
		}

		// 4방향 BFS 탐색
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			
			// board 범위를 초과할 경우
			if (nx >= size || nx < 0 || ny >= size || ny < 0) continue;
			// 방문할 곳에 벽이 있을 경우
			if (board[nx][ny]) continue; 
			// nCost : 도로 건설 비용은 100이다.
			int nStraight = straight, nCorner = corner, nCost = cost + 100;

			// (0,0) 에서 시작하는 경우 방향을 아래와 같이 보정해준다. 
			if (x == 0 && y == 0) dist = i; 

			if (i == dist) { // 직선 도로일 경우(방향이 안바뀌는 경우)
				nStraight++; // 직선 도로개수 증가
			}
			else { // 코너일경우 
				corner++; // 코너 개수 증가
				nCost += 500; // 코너 건설비용 500 추가
			}

			// 이미 방문했던 정점이라면(이미 확인했던 경우의 수라면), 스킵
			if (check[nx][ny][nStraight][corner]) continue; 
			check[nx][ny][nStraight][corner] = true;
			q.push({ nx,ny,nStraight, nCorner, nCost, i });
		}
	}

	return ret;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	return bfs(board);
}