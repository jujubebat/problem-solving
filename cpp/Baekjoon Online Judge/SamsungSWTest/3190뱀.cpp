#include<cstdio>
#include<queue>
using namespace std;

int n, k, m;
int x, y, z, d, ans;
int a[100][100], t[101];
int c[101];
const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 }; //�����ϳ�
const int L[] = { 2,3,1,0 }, D[] = { 3,2,0,1 };
queue<pair<int, int>> q;

void solve() {
	a[0][0] = 2;
	q.push({ 0,0 });
	while (1) {
		x += dx[d], y += dy[d];
		ans++;
		if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] == 2) {//������ ����ų�, ������� ����
			printf("%d\n", ans);
			return;
		}
		if (a[x][y] == 0) { //����ġ���, ���� ������.
			int nx = q.front().first, ny = q.front().second;
			q.pop();
			a[nx][ny] = 0;
		}
		a[x][y] = 2; //���(1)��� ���������ϰ�
		q.push({ x,y });//�����־���
		if (ans == t[z]) {//����ٲܽð� �Ǹ� ������ �ٲ۴�. 
			if (c[z] == 'L') d = L[d];
			else d = D[d];
			z++;
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u - 1][v - 1] = 1; //���
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %c", &t[i], &c[i]);
	}
	d = 3;
	solve();
	return 0;
}