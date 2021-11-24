/*
[문제이해]

1. 맵에는 벽(#), 빨간구슬(R), 파란구슬(B), 구멍(O)이 각각 1개씩 존재한다.
2. 4가지 기울이기(왼쪽, 오른쪽, 위쪽, 아래쪽)를 통해 구슬을 굴릴 수 있다.
	- 빨간구슬이 구멍에 빠지면 성공
	- 파란구슬이 구멍에 빠지면 실패
	- 빨간구슬과 파란구슬 모두 구멍에 빠져도 실패
3. 보드의 상태가 주어졌을 때 최소 몇 번만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지를 계산해야한다.
	- 기울인 횟수는 10번 이하여야한다. 

[설계]
1. 빨간구슬과 파란구슬에 대해 상,하,좌,우 4방향 BFS를 적용한다.
2. 예를들어 맵을 오른쪽으로 기울였으면, 빨간구슬과 파란구슬 둘 다 오른쪽 방향 BFS를 적용한다.
3. 큐에다가 빨간구슬 x, y 좌표와 파란구슬 x, y 좌표 그리고 기울인 횟수 d를 넣어준다.
3. 기울이고 나서 구슬의 위치는 4차원 배열로 방문처리해둔다. bool visited[rx][ry][bx][by];
4. 구슬은 벽(#)을 만날때까지 굴러가야한다. 구슬에 대해 BFS를 적용할 때 이 부분을 처리해야한다.
5. 구슬이 서로 붙어 있는 경우를 고려해야한다. 더 멀리 이동한 구슬을 움직인 방향을 기준으로 한 칸 뒤로 배치시킨다.
6. 빨간구슬만 구멍을 통해 빼낼 수 없으면, -1을 출력해야한다.

[회고]
1. BFS를 사용하는 이유?
   -> 최소한의 기울임으로 빨간 구슬을 구멍에 빠뜨려야한다. 
   -> BFS는 가중치가 없는 그래프에서 최단경로를 찾을 때 사용되므로 위 문제에 적용될 수 있다.

2. 재귀를 통해서 모든 경우의 수를 찾아보기?
   -> 상,하,좌,우 4방향으로 기울일 수 있고, 최대 10번까지 기울일 수 있다.
   -> 그럼 모든 경우의 수는 4^10(1,048,576)이 된다. 한 번의 경우의 수를 만들때마다 구슬을 굴려야한다.
   -> 4^10 * 20
*/

#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int rx, ry, bx, by, d;
}pos;

char map[10][10];
int n, m;
int res = 11;
bool visited[10][10][10][10];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
queue<pos> q;

void move(int &x, int &y, int &Cnt, int dx, int dy) {
	while (map[x+dx][y+dy] != '#' && map[x][y] != 'O'){
		x += dx;
		y += dy;
		Cnt++;
	}
}

void bfs() {
	while (!q.empty()) {
		int rx = q.front().rx, ry = q.front().ry;
		int bx = q.front().bx, by = q.front().by;
		int d = q.front().d;
		q.pop();

		if (d >= 10) continue;//기울인 횟수가 10이상이라면, 스킵한다. 

		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry; //빨강 구슬의 새로운 좌표
			int nbx = bx, nby = by; //파란 구슬의 새로운 좌표
			int rCnt = 0, bCnt = 0; //빨강, 파랑 구슬이 굴러간 횟수를 카운트 하는 변수
			
			move(nrx, nry, rCnt, dx[i], dy[i]); //빨간구슬 이동
			move(nbx, nby, bCnt, dx[i], dy[i]); //파란구슬 이동

			if (map[nbx][nby] == 'O') //파란 구슬이 구멍에 빠지면, 실패
				continue;

			if (map[nrx][nry] == 'O') {//빨간 구슬만 구멍에 빠진 경우라면, 성공
				res = min(res, d+1);//성공 했을 때, 최솟값 기록
				continue;
			}

			if (nrx == nbx  && nry==nby) {//구슬이 겹치는 경우 = 구슬이 붙어있는 경우
				if (bCnt > rCnt) { //파란구슬이 더 멀리 갔다면, 한 칸 뒤로
					nbx -= dx[i];
					nby -= dy[i];
				}
				else { //빨간구슬이 더 멀리 갔다면, 한 칸 뒤로
					nrx -= dx[i];
					nry -= dy[i];
				}
			}

			if (visited[nrx][nry][nbx][nby]) continue; //이미 방문했다면(이미 알아본 경우의 수라면), 스킵

			visited[nrx][nry][nbx][nby] = true; //방문처리
			q.push({ nrx,nry,nbx,nby,d+1}); //다시 큐에 넣는다. 
		}
	}
}

int main() {
	cin >> n >> m;
	int rx, ry, bx, by; //빨간구슬과 파란구슬의 초기위치 값을 저장하는 변수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				rx = i, ry = j;
			}
			else if (map[i][j] == 'B') {
				bx = i, by = j;
			}
		}
	}
	visited[rx][ry][bx][by]=true;
	q.push({ rx,ry,bx,by,0 }); //두 구슬의 초기위치, 기울인횟수(0)을 큐에 넣어준다.
	bfs();
	if(res == 11)
		printf("-1");
	else 
		printf("%d", res);
	return 0;
}