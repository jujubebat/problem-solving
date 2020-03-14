/*
https://www.acmicpc.net/board/view/38887 해설참조 
*/

#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int loc, cnt;
}pos;

int start, dest;
bool visited[100001];

void bfs() {
	deque<pos> q;
	visited[start] = true;
	q.push_back({ start,0 });

	while (!q.empty()){
		int loc = q.front().loc;
		int cnt = q.front().cnt;
		q.pop_front();

		//printf("%d %d\n", loc, cnt);

		if (loc == dest) {
			printf("%d", cnt);
			return;
		}

		for (int i = 0; i < 3; i++) {
			int nloc;
			if (i == 0) {
				nloc = 2 * loc;
			}
			else if (i == 1) {
				nloc = loc + 1;

			}
			else if (i == 2) {
				nloc = loc - 1;
			}

			if (nloc > 100000 || nloc < 0) continue;
			if (visited[nloc]) continue;
			visited[nloc] = true;

			if (i == 1 || i == 2) {
				q.push_back({ nloc,cnt +1});
			}
			else if (i == 0) {
				q.push_front({ nloc,cnt});
			}
		}

	}
}


int main() {
	cin >> start >> dest;
	bfs();
	return 0;
}