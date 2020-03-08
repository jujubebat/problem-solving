#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int x, y;
}pos;

char map[20][20];
int n, m;
int res = 1e9;
vector<pos> coin;
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
//bool check[20][20][20][20]; ±»ÀÌ Ã¼Å©¸¦ ¾ÈÇØÁàµµµÊ.. 
bool isFail;

void dfs(pos a, pos b, int cnt) {

	if (cnt > 10) return;

	for (int i = 0; i < 4; i ++) {
		int nax = a.x + dx[i], nay = a.y + dy[i];
		int nbx = b.x + dx[i], nby = b.y + dy[i];
		bool a_flag = false, b_flag = false;

		if (nax >= n || nax < 0 || nay >= m || nay < 0) a_flag = true;  //aµ¿ÀüÀÌ Å»Ãâ
		if (nbx >= n || nbx < 0 || nby >= m || nby < 0) b_flag = true;//bµ¿ÀüÀÌ Å»Ãâ

		if (!a_flag && !b_flag) {
			//if (check[nax][nay][nbx][nby]) continue;
		}

		if (a_flag == !b_flag) {
			res = min(res, cnt);
		}
		
		if (a_flag || b_flag) continue;

		if (map[nax][nay] == '#' ) {
			nax = a.x, nay = a.y;
		}

		if (map[nbx][nby] == '#' ) {
			nbx = b.x, nby = b.y;
		}
		//check[nax][nay][nbx][nby] = true;
		dfs({ nax,nay }, { nbx,nby }, cnt + 1);
		//check[nax][nay][nbx][nby] = false;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') {
				coin.push_back({ i,j });
				map[i][j] = '.';
			}
		}
	}

	//check[coin[0].x][coin[0].y][coin[1].x][coin[1].y] = true;
	dfs(coin[0], coin[1],1);

	if (res == 1e9)
		cout << -1;
	else
		cout << res;
	return 0;
}