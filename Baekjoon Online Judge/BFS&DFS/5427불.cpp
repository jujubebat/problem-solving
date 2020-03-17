#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct {
	int x, y;
}pos;

char map[1000][1000];

int w, h;
int visited_fire[1000][1000];
int visited_person[1000][1000];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

queue<pos> q_fire;
queue<pos> q_person;

void bfs_fire() {
	memset(visited_fire, 0, sizeof(visited_fire));

	while (!q_fire.empty()) {
		int x = q_fire.front().x, y = q_fire.front().y;
		q_fire.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= h || nx < 0 || ny >= w || ny < 0) continue;
			if (map[nx][ny] == '#' || map[nx][ny] == '*') continue;
			if (visited_fire[nx][ny]) continue;
			visited_fire[nx][ny] = visited_fire[x][y] + 1;
			q_fire.push({ nx, ny });
		}
	}
}

int bfs_person() {
	memset(visited_person, 0, sizeof(visited_person));

	while (!q_person.empty()) {
		int x = q_person.front().x, y = q_person.front().y;
		q_person.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= h || nx < 0 || ny >= w || ny < 0) {
				puts("");
				return visited_person[x][y] + 1;
				
			}
			if (map[nx][ny] == '#' || map[nx][ny] == '*' || map[nx][ny] == '@') continue;
			if (visited_person[nx][ny]) continue;
			if (visited_fire[nx][ny] != 0) {
				if (visited_person[x][y] + 1 >= visited_fire[nx][ny]) continue;
			}
			visited_person[nx][ny] = visited_person[x][y] + 1;
			q_person.push({ nx, ny });
		}
	}

	return 0;
}

int main() {
	int t;
	cin >> t;

	for (int k = 0; k < t; k++) {
		cin >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '*') q_fire.push({ i,j });
				if (map[i][j] == '@') q_person.push({ i,j });
			}
		}

		bfs_fire();
		int res = bfs_person();
		if (res == 0)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",res);

		while (!q_fire.empty()) q_fire.pop();
		while (!q_person.empty()) q_person.pop();
	}

	return 0;
}

/*

*/