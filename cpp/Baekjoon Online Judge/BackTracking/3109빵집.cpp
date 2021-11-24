// ���ʺ��� ���ʿ� ����� �������� ��ġ�Ѵ�.(�׸����ϰ�)
// ���ʿ��� �湮�� ��δ� �湮���� �ʵ����Ѵ�. 
// �������� �湮�� ��δ� ������ ��ġ�� �����ߴ��� �湮����
// �ʴ´�. ������ �� ��δ� ���� ���� ����̴�. 

#include<iostream>
using namespace std;

char map[10000][500];
int r, c;

const int dx[] = { -1,0,1 }, dy[] = { 1,1,1 };

bool dfs(int x, int y) {
	map[x][y] = 'x';

	if (y == c - 1)
		return true;

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= r || nx < 0 || ny >= c || ny < 0) continue;
		if (map[nx][ny] == 'x') continue;
		if (dfs(nx, ny))
			return true;
	}

	return false;
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	int ret = 0;

	//ù ��° �� ���ʺ��� Ž���غ���.  
	for (int row = 0; row < r; row++) {
		if (dfs(row, 0)) // ������ ��ġ�� �����ϸ�
			ret++;
	}

	cout << ret;
	return 0;
}

