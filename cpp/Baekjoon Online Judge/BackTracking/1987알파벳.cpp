//dfs�� ���� 
//������ ���ĺ� ����� dfs �Ű������� ��ӳѰ��ش�.
//Ż������ : �̹� ������ ���ĺ��� ��� �ִ밪 �����ϰ� Ż��
//�Ű����� : x,y,cnt,���ĺ� ���

#include<iostream>
#include<vector>

using namespace std;

int r, c,res = 0;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
char map[20][20];
bool history[26];
bool visited[20][20]; //2���� �迭�� 0���� �ʱ�ȭ �ȵǳ�? ���������� �׷���?

void dfs(int x, int y, int cnt) {
	if (cnt > res) res = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= r || nx < 0 || ny >= c || ny < 0) continue;
		if (visited[nx][ny]) continue;
		if (history[map[nx][ny] - 'A']) continue;

		visited[nx][ny] = true;
		history[map[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt + 1);
		history[map[nx][ny] - 'A'] = false;
		visited[nx][ny] = false;
	}
}

int main() {
	scanf("%d %d", &r, &c);
	getchar();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%1c", &map[i][j]);
		}
		getchar();
	}
	visited[0][0] = true;
	history[map[0][0] - 'A'] = true;
	dfs(0,0,1);
	printf("%d", res);
}

