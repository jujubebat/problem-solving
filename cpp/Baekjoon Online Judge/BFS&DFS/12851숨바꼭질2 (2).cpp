#include<iostream>
#include<queue>
using namespace std;

int start, dest;
int dist[10000001];
int fastestTime, NumOfMethod;
bool flag = true;

typedef struct {
	int d, cnt;
}pos;

void bfs() {
	queue<pos> q;

	q.push({ start, 0 });

	while (!q.empty()) {
		int d = q.front().d;
		int cnt = q.front().cnt;
		q.pop();
		
		if (!flag && cnt > fastestTime)
			return;

		if (d == dest) {

			if (flag) {
				fastestTime = cnt;
				flag = false;
				NumOfMethod++;
			}else if(!flag) {
				if (fastestTime == cnt)
					NumOfMethod++;
			}
			
		}

		int nd;
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				nd = d - 1;
			}
			else if (i == 1) {
				nd = d + 1;
			}
			else if (i == 2) {
				nd = 2 * d ;
			}

			if (nd < 0 || nd > 100000) continue;
			if (dist[nd] && dist[nd] != dist[d] + 1) continue;
			dist[nd] = dist[d] + 1;
			q.push({ nd,cnt + 1 });
		}
	}
}

int main() {
	cin >> start >> dest;
	bfs();
	printf("%d\n", fastestTime);
	printf("%d", NumOfMethod);
	return 0;
}