#include<cstdio>
#include<queue>
using namespace std;

int n, k, m;
int x, y, z, d, ans;
int a[100][100], t[101];
int c[101];
const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 }; //동서북남
const int L[] = { 2,3,1,0 }, D[] = { 3,2,0,1 };
queue<pair<int, int>> q;

void solve() {
	a[0][0] = 2;
	q.push({ 0,0 });
	while (1) {
		x += dx[d], y += dy[d];
		ans++;
		if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] == 2) {//범위를 벗어났거나, 꼬리라면 종료
			printf("%d\n", ans);
			return;
		}
		if (a[x][y] == 0) { //빈위치라면, 꼬리 없애줌.
			int nx = q.front().first, ny = q.front().second;
			q.pop();
			a[nx][ny] = 0;
		}
		a[x][y] = 2; //사과(1)라면 길이증가하고
		q.push({ x,y });//꼬리넣어줌
		if (ans == t[z]) {//방향바꿀시간 되면 방향을 바꾼다. 
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
		a[u - 1][v - 1] = 1; //사과
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %c", &t[i], &c[i]);
	}
	d = 3;
	solve();
	return 0;
}