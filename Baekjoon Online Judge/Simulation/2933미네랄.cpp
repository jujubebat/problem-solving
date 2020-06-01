#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef struct {
	int x, y;
}pos;

char map[100][100];
int visited[100][100];
int r, c, n, cnt = 1;
int stick[100], bottomCluster[101];
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };

// dfs을 사용하여 visited 배열에 번호로 클러스터를 체크한다.
void dfs(int x, int y) { 
	if (!bottomCluster[cnt] && x == r - 1) // 땅에 닿아있는 클러스터를 bottomCluster 배열에 체크.
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

void fallMineral() { // 클러스터를 떨어뜨린다. 
	cnt = 1;
	memset(visited, 0, sizeof(visited));
	memset(bottomCluster, 0, sizeof(bottomCluster));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'x' && !visited[i][j]) {
				dfs(i, j); // dfs로 각 클러스터를 구분 짓는다. 
				cnt++;
			}
		}
	}

	// 공중에 떠 있는 클러스터가 있는지 확인한다.
	// (땅에 닿지 않아있는 클러스터 체크.)
	bool flag = false;
	for (int i = 1; i < cnt; i++) {
		if (bottomCluster[i] == false) { 
			flag = true;
		}
	}

	if (flag) { // 공중에 떠있는 생긴경우. 중력을 작용한다. 

		vector<pos> v; // 떨어뜨릴 클러스트의 좌표를 저장해둔다. 
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (visited[i][j] != 0 && !bottomCluster[visited[i][j]]) {
					v.push_back({ i,j });
				}
			}
		}

		bool flag2 = false;

		while (1) { 

			for (int i = 0; i < v.size(); i++) { // 공중에 있는 클러스터를 우선 map에서 지운다.
				map[v[i].x][v[i].y] = '.';
			}

			for (int i = 0; i < v.size(); i++) {
				int nx = v[i].x + 1, ny = v[i].y; // 한 칸 아래 좌표 위치 계산.
				v[i].x = nx, v[i].y = ny; // 좌표 업데이트.
				map[nx][ny] = 'x'; // 배치.

				// 클러스터가 땅에 닿는 경우
				if (nx == r - 1) {
					flag2 = true;
				} // 클러스터가 다른 클러스터에 닿는 경우
				else if (map[nx + 1][ny] == 'x' && (visited[v[i].x][v[i].y] != visited[nx + 1][ny])) {
					flag2 = true;
				}

			}
			if (flag2) return; // 클러스터가 땅에 닿거나 다른 클러스터에 닿으면 탈출.
		}
	}
}

// flag에 따라 왼쪽, 오른쪽을 구분한다.
// h 높이에서 막대기를 던져 미네랄을 부순다.
void breakMineral(bool flag, int h) { 

	h = r - h;
	if (flag) { // 왼쪽 h 높이에서 막대기를 던져 미네랄을 부숨.

		for (int col = 0; col < c; col++) {
			if (map[h][col] == 'x') {
				map[h][col] = '.';
				return;
			}
		}

	}
	else { // 오른쪽 h 높이에서 막대기를 던져 미네랄을 부숨.

		for (int col = c - 1; col >= 0; col--) {
			if (map[h][col] == 'x') {
				map[h][col] = '.';
				return;
			}
		}

	}

}

void solve() {

	bool flag = true; 
	for (int i = 0; i < n; i++) {
		// 왼쪽에서 던지고, 오른쪽에서 던지고 반복.
		breakMineral(flag, stick[i]); 

		if (flag) flag = false; // flag는 왼쪽, 오른쪽을 표현한다.
		else flag = true;

		fallMineral(); // 미네랄을 떨어뜨린다. 
	}


	for (int i = 0; i < r; i++) { // 결과 출력.
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

}

int main() {

	cin >> r >> c; // map 정보 입력.
	for (int i = 0; i < r; i++) { 
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	cin >> n; // 막대기 투척 정보 입력.
	for (int i = 0; i < n; i++) {
		cin >> stick[i];
	}

	solve();
	return 0;
}
