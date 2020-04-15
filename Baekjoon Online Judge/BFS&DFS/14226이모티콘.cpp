#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int screen, clipBoard, cnt;
}eomticon;

int s;
bool check[1001][1001];

void bfs() {
	queue<eomticon> q;

	check[1][0]=true;
	q.push({ 1,0,0 });

	while (!q.empty()) {
		int screen = q.front().screen, clipBoard = q.front().clipBoard, cnt = q.front().cnt;
		q.pop();

		if (screen == s){
			cout << cnt;
			return;
		}

		for (int i = 0; i < 3; i++) {
			int ns, nc;

			if (i == 0) { //화면 -> 클립보드
				ns = screen, nc = screen;
			}
			else if (i == 1) {//클립보드 -> 화면
				if (clipBoard == 0) continue;
				ns = screen + clipBoard, nc = clipBoard;
			}
			else if (i == 2) { // 화면에서 임티 하나삭제
				if (screen <= 0) continue;
				ns = screen - 1, nc = clipBoard;
			}

			if (ns > 1000) continue;
			if (check[ns][nc]) continue;

			check[ns][nc] = true;
			q.push({ ns, nc, cnt + 1 });
		}
	}
}

int main() {
	cin >> s;
	bfs();
	return 0;
}