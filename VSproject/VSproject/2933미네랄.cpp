#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef struct {
	int x, y;
}pos;

char map[100][100];
int r, c;
int n;
int stick[100];
int visited[100][100];
int cnt = 1;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };
bool bottomCluster[101];

void dfs(int x, int y) {
	if (!bottomCluster[cnt] && x == r - 1) // 땅에 닿아있는 클러스터 체크
		bottomCluster[cnt] = true;
	visited[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= r || nx < 0 || ny >= c || ny < 0) continue;
		if (visited[nx][ny]) continue;
		if (map[nx][ny] == '.') continue;
		dfs(nx, ny);
	}
}



void fallMineral() {
	cnt = 1;
	memset(visited, 0, sizeof(visited));
	memset(bottomCluster, 0, sizeof(bottomCluster));
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'x' && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	cout << "바닥에 닿아있는 클러스터 목록";
	for (int i = 0; i < 100; i++) {
		if (bottomCluster[i])
			cout << i << " ";
	}
	cout << endl;


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << visited[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	vector<pos> v;
	
	if (cnt > 2) { // 분리된 클러스터가 생긴경우. 중력을 작용한다. 
		// 떨어뜨릴 클러스트의 좌표를 저장해둔다. 
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {

				if (visited[i][j] != 0 && !bottomCluster[visited[i][j]]) {
					cout << i << j << endl;
					v.push_back({ i,j });
				}

			}
		}

		bool flag = false;

		cout << "v.size() : " <<  v.size();

		while (1){
			for (int i = 0; i < v.size(); i++) {
				map[v[i].x][v[i].y] = '.';
			}

			/*for (int i = 0; i < v.size(); i++) {
				int nx = v[i].x + 1, ny = v[i].y;
				map[nx][ny] = 'x';

				if (nx + 1 == r || map[nx+1][ny] == 'x')
					flag = true;
			}*/

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cout << map[i][j];
				}
				cout << endl;
			}

			if (flag) return;
		}
	
	}
}

void breakMineral(bool flag, int h) {

	h = r - h;
	if (flag) { //왼쪽
		
		for (int col = 0; col < c; col++) {
			if (map[h][col] == 'x') {
				map[h][col] = '.';
				return;
			}
		}

	}
	else {

		for (int col = c-1; col >= 0; col--) {
			if (map[h][col] == 'x') {
				map[h][col] = '.';
				return;
			}
		}

	}

}

void solve() {

	bool flag = true; // 왼쪽
	for (int i = 0; i < n; i++) {
		breakMineral(flag, stick[i]);

		if (flag) flag = false;
		else flag = true;

		fallMineral();
	}
}

int main() {

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> stick[i];
	}
	
	solve();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout<< map[i][j];
		}
		cout << endl;
	}

	return 0;
}

// 미네랄을 부순다.
// 클러스터가 새로 생기는지 검사.
// 클러스터가 생겼다면, 중력 작용
// 클러스터에 대한 중력 작용 구현?.
// 해당클러스터가 바닥 또는 다른 클러스에 도달할때 까지 1칸씩 중력작용


/*

........
........
...x.xx.
...xxx..
...xx...
..x.x...
..x...x.
.xxx..x.

*/