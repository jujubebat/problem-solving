#include<iostream>
#include<queue>
using namespace std;

typedef struct {
	int x, y;
}pos;

int map[1000][1000];
int ret = 1;
const int dx[] = { -1,1,0, 0 }, dy[] = { 0,0,-1,1 };
int n, m;
bool visited[1000][1000];

int bfs(int sx, int sy) {
	int cnt = 1;
	queue<pos> q;
	visited[sx][sy] = true;

	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (map[nx][ny] == 0) continue;
			if (visited[nx][ny]) continue;

			cnt++;
			visited[nx][ny] = true;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j])
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}
	cout << endl;


	return cnt;
}

void bfsSolve() {

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(map[i][j])
				ret = max(ret, bfs(i,j));
		}
	}
}

void solve() {

	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {

				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
					if (map[nx][ny]) cnt++;
				}

				if (cnt >= 2) {
					// bfs를 돌린다. 
					map[i][j] = 1;
					bfsSolve();
					map[i][j] = 0;
					if (flag) flag = false;
				}
			}
		}
	}

	if (flag) {
		//bfs 돌리고 최대값을 찾는다. 
		bfsSolve();
	}

	cout << ret;
}

int main() {
	bool flag = false;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				flag = true;
		}
	}


	if (flag) {
		cout << n * m;
		return 0;
	}

	solve();
	return 0;
}

/*
1 000 000 * 1 000 000
1 000 000 * 1 000 000

백만번을 1을 0으로 바꿔봐야함....
시간복잡도가 너무 큰데

0을 1로 바꿔바야함.

모든 0을 1로바꿔보고 dfs / bfs를 돌려서 최대크기 확인
시간복잡도가 터짐... 다른 아이디어필요
*/

/*
모든 0을 1로 바꿔보지 않고
0에서 인접한 1이 두개 이상있는 경우에만 바꿔본다.
인접합 1이두개 이상 없는 경우에는 최대 모양 +1 을
해준다.
모든 칸이 1이라면 그냥 출력한다.

0 0 0 0
1 0 0 0
0 0 1 1

1 1 1 1
1 1 1 1
1 1 1 1 */


