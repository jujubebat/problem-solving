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

// dfs�� ����Ͽ� visited �迭�� ��ȣ�� Ŭ�����͸� üũ�Ѵ�.
void dfs(int x, int y) { 
	if (!bottomCluster[cnt] && x == r - 1) // ���� ����ִ� Ŭ�����͸� bottomCluster �迭�� üũ.
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

void fallMineral() { // Ŭ�����͸� ����߸���. 
	cnt = 1;
	memset(visited, 0, sizeof(visited));
	memset(bottomCluster, 0, sizeof(bottomCluster));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'x' && !visited[i][j]) {
				dfs(i, j); // dfs�� �� Ŭ�����͸� ���� ���´�. 
				cnt++;
			}
		}
	}

	// ���߿� �� �ִ� Ŭ�����Ͱ� �ִ��� Ȯ���Ѵ�.
	// (���� ���� �ʾ��ִ� Ŭ������ üũ.)
	bool flag = false;
	for (int i = 1; i < cnt; i++) {
		if (bottomCluster[i] == false) { 
			flag = true;
		}
	}

	if (flag) { // ���߿� ���ִ� ������. �߷��� �ۿ��Ѵ�. 

		vector<pos> v; // ����߸� Ŭ����Ʈ�� ��ǥ�� �����صд�. 
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (visited[i][j] != 0 && !bottomCluster[visited[i][j]]) {
					v.push_back({ i,j });
				}
			}
		}

		bool flag2 = false;

		while (1) { 

			for (int i = 0; i < v.size(); i++) { // ���߿� �ִ� Ŭ�����͸� �켱 map���� �����.
				map[v[i].x][v[i].y] = '.';
			}

			for (int i = 0; i < v.size(); i++) {
				int nx = v[i].x + 1, ny = v[i].y; // �� ĭ �Ʒ� ��ǥ ��ġ ���.
				v[i].x = nx, v[i].y = ny; // ��ǥ ������Ʈ.
				map[nx][ny] = 'x'; // ��ġ.

				// Ŭ�����Ͱ� ���� ��� ���
				if (nx == r - 1) {
					flag2 = true;
				} // Ŭ�����Ͱ� �ٸ� Ŭ�����Ϳ� ��� ���
				else if (map[nx + 1][ny] == 'x' && (visited[v[i].x][v[i].y] != visited[nx + 1][ny])) {
					flag2 = true;
				}

			}
			if (flag2) return; // Ŭ�����Ͱ� ���� ��ų� �ٸ� Ŭ�����Ϳ� ������ Ż��.
		}
	}
}

// flag�� ���� ����, �������� �����Ѵ�.
// h ���̿��� ����⸦ ���� �̳׶��� �μ���.
void breakMineral(bool flag, int h) { 

	h = r - h;
	if (flag) { // ���� h ���̿��� ����⸦ ���� �̳׶��� �μ�.

		for (int col = 0; col < c; col++) {
			if (map[h][col] == 'x') {
				map[h][col] = '.';
				return;
			}
		}

	}
	else { // ������ h ���̿��� ����⸦ ���� �̳׶��� �μ�.

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
		// ���ʿ��� ������, �����ʿ��� ������ �ݺ�.
		breakMineral(flag, stick[i]); 

		if (flag) flag = false; // flag�� ����, �������� ǥ���Ѵ�.
		else flag = true;

		fallMineral(); // �̳׶��� ����߸���. 
	}


	for (int i = 0; i < r; i++) { // ��� ���.
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

}

int main() {

	cin >> r >> c; // map ���� �Է�.
	for (int i = 0; i < r; i++) { 
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	cin >> n; // ����� ��ô ���� �Է�.
	for (int i = 0; i < n; i++) {
		cin >> stick[i];
	}

	solve();
	return 0;
}
