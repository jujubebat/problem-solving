#include<iostream>
#include<vector>
using namespace std;

typedef struct {
	int k, x, y, d; //정점 번호, 현재위치 xy, 방향
}piece;

int color_map[12][12];
vector<piece> chess_map[12][12];
vector<piece> arr;
int n, k, res;
int dx[] = { 0, 0, -1, 1 }, dy[] = { 1, -1, 0, 0 }; //0123,  우좌상하
int r[4] = { 1, 0, 3, 2 };
bool resFlag; 

void move(int k, int x, int y, int nx, int ny, bool colorFlag) {
	int size = chess_map[x][y].size();
	for (int i = 0; i < size; i++) {
		if (chess_map[x][y][i].k == k) {
			if (colorFlag) { // whiteMoving 
				for (int j = i; j < size; j++) {
					int cur_k = chess_map[x][y][j].k;
					int cur_d = chess_map[x][y][j].d;
					chess_map[nx][ny].push_back({ cur_k, nx, ny, cur_d });
					arr[cur_k].x = nx, arr[cur_k].y = ny;
				}
			}
			else { // redMoving
				for (int j = size - 1; j >= i; j--) {
					int cur_k = chess_map[x][y][j].k;
					int cur_d = chess_map[x][y][j].d;
					chess_map[nx][ny].push_back({ cur_k, nx, ny, cur_d });
					arr[cur_k].x = nx, arr[cur_k].y = ny;
				}
			}
			if (chess_map[nx][ny].size() >= 4) {
				resFlag = true;
				return;
			}
			chess_map[x][y].erase(chess_map[x][y].begin() + i, chess_map[x][y].end());
			return;
		}
	}
}

void simulation() {
	for (int i = 0; i < arr.size(); i++) {
		int x = arr[i].x, y = arr[i].y, d = arr[i].d;
		int nx = x + dx[d], ny = y + dy[d];
		int nextPosColor = color_map[nx][ny];

		if (nextPosColor == 2 || nx >= n || nx < 0 || ny >= n || ny < 0) {
			arr[i].d = r[d];
			nx = x + dx[r[d]], ny = y + dy[r[d]];
			nextPosColor = color_map[nx][ny];
			if (color_map[nx][ny] == 2 || nx >= n || nx < 0 || ny >= n || ny < 0) {
				continue;
			}
			else if (nextPosColor == 0) {
				move(i, x, y, nx, ny, true);
				arr[i].x = nx, arr[i].y = ny;
			}
			else if (nextPosColor == 1) {
				move(i, x, y, nx, ny, false);
				arr[i].x = nx, arr[i].y = ny;
			}
		}
		else if (nextPosColor == 0) {
			move(i, x, y, nx, ny, true);
			arr[i].x = nx, arr[i].y = ny;
		}
		else if (nextPosColor == 1) {
			move(i, x, y, nx, ny, false);
			arr[i].x = nx, arr[i].y = ny;
		}
	}
}

void solve() {
	while (1) {
		res++;
		simulation();
		if (resFlag) return;
		if (res > 1000) {
			res = -1;
			return;
		}
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> color_map[i][j];
		}
	}

	int x, y, d;

	for (int i = 0; i < k; i++) {
		cin >> x >> y >> d;
		x -= 1, y -= 1, d -= 1;
		arr.push_back({ i, x, y, d });
		chess_map[x][y].push_back({ i, x, y, d });
	}

	solve();
	printf("%d", res);
	return 0;
}