#include<iostream>
#include<string.h>
#include<string>
using namespace std;

bool check[10][10];
int map[9][9];
int n;
int dx[] = { 0,1}, dy[] = { 1,0 };
int cnt;
bool flag = false;

void print_map() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d", map[i][j]);
		}
		puts("");
	}
}

void writing(int u, int v, string lu, string lv) {
	check[u][v] = check[v][u] = true; //체크

	int x, y;
	x = lu[0] - 'A', y = lu[1] - '0'-1;
	map[x][y] = u;

	x = lv[0] - 'A', y = lv[1] - '0'-1;
	map[x][y] = v;
}

bool isPossible(int x, int y, int n) {
	//행 검사
	for (int i = 0; i < 9; i++) {
		if (map[i][y] == n)
			return false;
	}
	//열 검사
	for (int i = 0; i < 9; i++) {
		if (map[x][i] == n)
			return false;
	}

	x = (x / 3) * 3;
	y = (y / 3) * 3;
	//3*3 검사
	for (int i = x; i < x+3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (map[i][j] == n)
				return false;
		}
	}
	return true;
}

bool isComplete() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0)
				return false;
		}
	}
	return true;
}

void dfs() {
	if (flag)return;

	if (isComplete()) {
		printf("Puzzle %d\n", cnt);
		print_map();
		flag = true;
		return;
	}

	for (int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				for (int k = 0; k < 2; k++) {//gu
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= 9 || nx < 0 || ny >= 9 || ny < 0) continue;
					if (map[nx][ny] != 0) continue;

					for (int a = 1; a < 9; a++) {
						for (int b = a+1; b <= 9; b++) {
							if (check[a][b] || check[b][a]) continue;
							//if (a == b) continue;
							check[a][b] = check[b][a] = true; //ex) a=1, b=2 이 가능하다면, 
							    //[1 2]로 놓는 경우의 수
								if (isPossible(i, j, a) && isPossible(nx, ny, b)) { //a,b를 스도쿠 판에 놓을 수 있는지 각각 검사.
									map[i][j] = a;
									map[nx][ny] = b;
									dfs();
									map[i][j] = 0;
									map[nx][ny] = 0;
								}
								//[2 1]로 놓는 경우의 수
								if (isPossible(i, j, b) && isPossible(nx, ny, a)) { 
									map[i][j] = b;
									map[nx][ny] = a;
									dfs();
									map[i][j] = 0;
									map[nx][ny] = 0;
								}
						    check[a][b] = check[b][a] = false;
						}
					}
				}
				return; //해당하는 
			}
		}
	}
}

int main() {
	while (1){
		cin >> n;

		if (n == 0) return 0;

		memset(check, 0, sizeof(check));
		memset(map, 0, sizeof(map));
		flag = false;

		int u, v;
		string lu, lv;

		for (int i = 0; i < n; i++) {
			cin >> u >> lu >> v >> lv;
			writing(u,v,lu,lv);
		}
		 
		for (int i = 1; i <= 9; i++) {
			cin >> lu;
			map[lu[0] - 'A'][lu[1] - '0' -1 ] = i;
		}
		cnt++;
		dfs();
	}
	return 0;
}