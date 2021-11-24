#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int n, m;
int map[1000][1000];
int visited[1000][1000];
int group[1000001]; // �׷��� �ִ� 1000000������ ������ �� �ִ�. 
int groupNum = 1;
int cnt = 0;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void dfs(int sx, int sy) { // �׷��� ���� ���� dfs
	cnt++; // �׷��� ũ�⸦ ���
	visited[sx][sy] = groupNum;

	for (int i = 0; i < 4; i++) {
		int nx = sx + dx[i], ny = sy + dy[i];
		if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
		if (map[nx][ny] == 0) continue;
		if (visited[nx][ny]) continue;
		dfs(nx, ny);
	}
}

void solve() {
	int ret = 0;

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			if (map[i][j] && !visited[i][j]) {
				cnt = 0;
				dfs(i, j); 
				group[groupNum++] = cnt; // �׷��� ũ�⸦ ����.
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (map[i][j] == 0) { // 0�� ���Ҹ� �������� �����¿츦 Ȯ��.
				int candi = 1; // map[i][j]�� 1�� �ٲ����� ��������� ����� ũ��
				set<int> s; // set���� �̹� ������ �׷� ���θ� Ȯ��.
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
					if (visited[nx][ny] == 0) continue;
					if (s.count(visited[nx][ny])) continue;
					s.insert(visited[nx][ny]);
					candi += group[visited[nx][ny]]; // �ִ밪 ����.
				}
				ret = max(ret, candi);
			}

		}
	}
	cout << ret;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) { // �迭 �Է�.
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	solve();
	return 0;
}