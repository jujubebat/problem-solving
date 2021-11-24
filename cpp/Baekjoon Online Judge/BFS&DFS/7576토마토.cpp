/*
좌표계에서 알아둬야할 것 
우리는 흔히 좌표계를 표현할 때 다음과 같이 함 (x,y)
2차월 배열은 다음과 같이 표현됨 arr[y][x]
즉, 우리가 쓰는 좌표계는 (열,행) 좌표계지만 배열은 (행,열) 좌표계임 
이 두가지를 통일 하기 위해서 우리는 (행,열) 좌표계를 써야함 
즉, x는 '행' y는 '열'로 표현한다.
*/

//BFS로 익은 토마토가 전파되는 것을 동작한다.
//익은 토마토는 1 이상의 정수로 표현된다.
//익은 토마토가 전파될때, 마다 +1을 해주어 모든 토마토가 익은 날짜를 얻을 수 있게한다.
//맵에 익지 않은 토마토가 있다면 -1을 출력한다.

//우선 익은 토마토(의 위치좌표)를 큐에 넣는다.
//해당 큐에 대해 bfs를 수행하여 익은 토마토가 전파되게 한다. 
//전파될때는 +1을 해주어 날짜 카운트를 한다.

/*
<새롭게 배운점>
-BFS의 전파 기간을 맵(2차원 배열)에 숫자를 기록함으로써 계산하는 방법
-BFS의 실제 활용이 어떻게 이루어지는지 대충 알게 되었다.
*/
#include<cstdio>
#include<queue>

using namespace std;

//x는 행 , y는 열
typedef struct {
	int x, y;
}tomato;

int m, n, ans;
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0}; //상하좌우
int map[1000][1000];
queue<tomato> q;

void bfs() {
	while (!q.empty()) //큐에 익은 토마토가 없을때까지
	{
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //익은 토마토의 상하좌우 좌표가 배열 범위를 벗어나면 스킵
			if (map[nx][ny]) continue; //이미 익은 토마토거나, 토마토가 들어있지 않은 칸일 경우 스킵
			map[nx][ny] = map[x][y] + 1;
			q.push({ nx, ny }); //새롭게 익은 토마토를 큐에 넣어준다.
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push({ i, j }); //큐에 익은 토마토(의 좌표)를 넣는다.
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) { //익지 않은 토마토가 있다면 -1 출력하고 종료
				printf("-1\n");
				return 0;
			}
			if (ans < map[i][j]) //가장 큰 카운트를 찾는다.
				ans = map[i][j];
		}
	}

	printf("%d", ans - 1);//토마토가 모두 익기까지의 날짜 출력
	return 0;
}