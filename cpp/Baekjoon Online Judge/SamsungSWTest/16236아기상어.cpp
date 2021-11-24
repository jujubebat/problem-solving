//상어는 자신의 크기보다 큰 물고기는 지날 수 없음
//상어는 자기보다 작은 물고기를 먹을 수있다.
//상어는 같은 크기의 물고기를 지나갈 수 있다.
//상어의 크기는 처음에 2
//자신의 크기만큼 물고기를 먹으면 크기가 증가
//더이상 먹을 물고기가 없으면 종효


//먹이 후보군을 큐에 넣고, 거리가 같은경우 좌상에 있는 먹이 선택
//bfs를 돌려서 visited 배열에 거리표시 가장 작은 숫자 위치 반환
//선택한 먹이로 상어 이동 시키기

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

void bfs() {//bfs로 먹이까지의 최단 경로를 찾는다. (visited 배열에 기록)
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int moveCnt = q.front().moveCnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i]; //상하좌우 방향의 새로운 좌표
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue; //새로운 좌표가 배열 범위 초과시 스킵!
			if (sharkSize < map[nx][ny]) continue; //새로운 좌표가 자신 보다 큰 물고기라면 스킵!
			if (visited[nx][ny] != 0) continue; //새로운 좌표가 이동할 수 없는 곳이라면 스킵!
			visited[nx][ny] = moveCnt+1; //bfs 기록하기
			q.push({ nx, ny, moveCnt + 1 });
		}
	}
}

int moveShark() {
	int min = 9999;
	bool check[20][20] = { 0 };
	int nx = -1, ny = -1;
	//최소거리를 고른다. (상어 크기보다 작고, 상어가 아니고, 먹이가 없는 곳이 아니고 ,갈 수 없는 곳이 아니면서 거리가 가장 짧은 먹이를 솎아낸다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] < sharkSize && map[i][j] != 9 && map[i][j] != 0 && visited[i][j] != 0) {
				if (visited[i][j] <= min) {
					min = visited[i][j];
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {//이동할 후보 먹이를 check 배열에 true로 표시한다.
		for (int j = 0; j < n; j++) {
			if (map[i][j] < sharkSize && map[i][j] != 9 && map[i][j] != 0 && visited[i][j] != 0) {
				if (visited[i][j] == min) {
					check[i][j] = true;
				}
			}
		}
	}

	//후보 먹이가 여러 개일 경우 좌상단 위치에 있는 위치를 방문한다. 
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) {
				nx = i, ny = j;//다음 이동할 먹이의 위치 저장
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	if (nx == -1 && ny == -1) // 다음 이동할 먹이의 위치를 얻지 못했으면 종료
		return -1;

	map[s.x][s.y] = 0;
	map[nx][ny] = 9; //샤크 이동
	s.x = nx, s.y = ny; //샤크 위치 갱신
	s.moveCnt = visited[nx][ny];//샤크 총 이동거리(시간) 갱신
	eatingCnt++; // 먹은 물고기 수 갱신

	if (eatingCnt == sharkSize) { // 먹은 물고기 수에 따른 상어 크기 증가
		eatingCnt = 0;
		sharkSize++;
	}
	return s.moveCnt; //현재까지 상어가 총 이동한(시간) 반환
}

void solve() {
	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 9) {
					memset(visited, 0, sizeof(visited)); // visted 배열 초기화
					s.x = i, s.y = j;
					q.push(s);//큐에 상어위치 갱신하고,
					bfs(); //먹이 위치를 찾기위한 bfs수행
					int tmp = moveShark(); // bfs로 만들어진 visited 배열과 map 배열을 사용하여 상어 이동
					if (tmp == -1) //더 이상 이동할 수 없으면 종료
						return;
					time = tmp; //샤크 이동거리(시간) 갱신
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