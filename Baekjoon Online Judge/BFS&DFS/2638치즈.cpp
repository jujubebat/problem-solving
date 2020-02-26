//나의 풀이
/*
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

typedef struct {
	int x, y;
}pos;

int n, m; //세로, 가로
int map[100][100];
int res = 0;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };
int flag = true;
int check[100][100];

bool isAllMelting() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1)
				return false;
		}
	}
	return true;
}

void melting() {
	bool tmpCheck[100][100];
	memset(tmpCheck, false, sizeof(tmpCheck));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) { //치즈라면,
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (check[nx][ny] == 2)
						cnt++;
					if (cnt >= 2) {
						tmpCheck[i][j] = true;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && tmpCheck[i][j]) {
				map[i][j] = 0;
			}
		}
	}
}

void bfs() {
	queue<pos> q;
	check[0][0] = 2;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue; //범위 초과
			if (map[nx][ny] != 0) continue; //공기가 아니라면, 스킵
			if (check[nx][ny]) continue;
			check[nx][ny] = 2;
			q.push({ nx,ny });
		}
	}
}

void solve() {
	while (1){
		memset(check, false, sizeof(check));
		bfs();
		melting();
		res++;
		if (isAllMelting())
			break;
	}
	printf("%d", res);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	solve();
}
*/
/*
1. bfs로 외부 공기를 2로 표시해준다. (모든 종이의 맨 가장자리에는 치즈가 놓이지 않음!)
2. 외부공기(2)와 닿는 치즈를 없애준다(0으로 만듬)
3. 치즈가 다 녹았는지 검사한다.
*/

/*
bfs()
melting()
isAllMelting()
*/

//더 좋은 풀이
#include<cstdio>
#include<cstring>
#include<queue>	
using namespace std;

struct cheese {
	int x, y;
};

int n, m, ans;
int a[100][100];
bool check[100][100];
const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

void bfs() {
	memset(check, false, sizeof(check));
	queue<cheese> q;
	q.push({ 0,0 });
	check[0][0] = true;
	
	while(!q.empty()){
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (check[nx][ny]) continue;
			if (a[nx][ny] >= 1) {
				a[nx][ny] += 1;
				continue;
			}
			q.push({ nx,ny });
			check[nx][ny] = true;
		}
	}
}

bool melt() {
	bool melted = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] >= 3) {
				a[i][j] = 0;
				melted = true;
			}
			else if (a[i][j] == 2) {
				a[i][j] = 1;
			}
		}
	}
	return melted;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	while (1){
		bfs();
		if (melt()) 
			ans++;
		else
			break;
	}
	printf("%d", ans);
	return 0;
}