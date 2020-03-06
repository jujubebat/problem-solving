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
		if (x == festival.x && y == festival.y) {//도착지인지 검사.
			flag = true;
			break;
		} 

		for (int i = 0; i <= n; i++) {//모든편의점과 도착지에대해
			int nx = store[i].x, ny = store[i].y;
			if (!isPassible(x, y, nx, ny)) continue; //거리체크
			if (check[i]) continue; //이미 방문한 편의점이라면.
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
맥주 1박스에는 맥주 20병
50미터에 1병씩

bfs로 탐색
집에서 출발해서 페스티벌까지 도착하는 최단거리

편의점, 도착지 모두 후보에 넣는다.
bfs를 돌린다.
도착하면, 표시한다.
*/