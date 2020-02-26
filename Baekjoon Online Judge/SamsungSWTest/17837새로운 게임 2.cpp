//////////아직 풀지 못함///////////////

/*
while(1){
말이동 함수(1번부터 k번말까지 이동시키기)
 -흰색일 경우
 -빨간색일 경우
 -파란색일 경우
말이 4개 쌓여있는지 검사
 -말이 4개 쌓여있다면, 턴수 출력
}
*/

#include<iostream>
#include<vector>

using namespace std;

typedef struct {
	int num, d;
	int x, y;
}piece;

int n, k;
int map[12][12]; //0 흰색, 1 빨간색, 2 파란색 
int res = 0;
vector<int> pieceMap[12][12]; 
piece pieceInfo[11]; //말 정보에 대한 배열

void whiteMoving(int p, int nx, int ny) {
	int x = pieceInfo[p].x, y = pieceInfo[p].y,idx=0;
	for (int i = 0; i < pieceMap[x][y].size(); i++) {//p의 현재 좌표에서 말목록 조회
		if (p == pieceMap[x][y][i]) { //p를 발견하면,
			idx = i;
			for (int j = i; j < pieceMap[x][y].size(); j++) {//p와 p위의 말들을 새로운 좌표로 옮김
				int cur = pieceMap[x][y][j];
				pieceMap[nx][ny].push_back(cur);
				pieceInfo[cur].x = nx, pieceInfo[cur].y = ny;
			}
			break;
		}
	}
	pieceMap[x][y].erase(pieceMap[x][y].begin() + idx, pieceMap[x][y].end());
}

void redMoving(int p, int nx, int ny) {
	int x = pieceInfo[p].x, y = pieceInfo[p].y, idx = 0;
	for (int i = 0; i < pieceMap[x][y].size(); i++) {//p의 현재 좌표에서 말목록 조회
		if (p == pieceMap[x][y][i]) { //p를 발견하면,
			idx = i;
			for (int j = pieceMap[x][y].size() - 1; j >= i; j--) {//p와 p위의 말들을 새로운 좌표로 옮김
				int cur = pieceMap[x][y][j];
				pieceMap[nx][ny].push_back(cur);
				pieceInfo[cur].x = nx, pieceInfo[cur].y = ny;
			}
			break;
		}
	}
	pieceMap[x][y].erase(pieceMap[x][y].begin() + idx, pieceMap[x][y].end());
}

void blueMoving(int p) {
	int d = pieceInfo[p].d, x= pieceInfo[p].x, y = pieceInfo[p].y;
	int nx, ny;

	if (d == 1) {//오른쪽
		nx = x, ny = y - 1;
		pieceInfo[p].d = 2;
	}
	else if (d == 2) {//왼쪽
		nx = x, ny = y + 1;
		pieceInfo[p].d = 1;
	}
	else if (d == 3) {//위쪽
		nx = x+1, ny = y;
		pieceInfo[p].d = 4;
	}
	else if (d == 4) {//아래쪽 
		nx = x-1, ny = y;
		pieceInfo[p].d = 3;
	}

	//반대쪽 칸 검사
	if (nx >= n || nx < 0 || ny >= n || ny < 0 || map[nx][ny] == 2) 
		return;
	else if (map[nx][ny] == 0) {
		whiteMoving(p, nx, ny);
	}
	else if (map[nx][ny] == 1) {
		redMoving(p, nx, ny);
	}
}

//방향 : 1 우, 2 좌, 3 상, 4 하 
void movingPiece(int p, int nx, int ny) {
	if (nx >= n || nx < 0 || ny >= n || ny < 0 || map[nx][ny] == 2) { // 파란색 or 체스판 외부
		blueMoving(p);
	}
	else if (map[nx][ny] == 0) { // 흰색
		whiteMoving(p, nx, ny);
	}
	else if (map[nx][ny] == 1) {// 빨간색
		redMoving(p, nx, ny);
	}
}

void movingAll() {//말의 방향과 현재 위치에 따른 다음 좌표
	for (int i = 1; i <= k; i++) {
		int x = pieceInfo[i].x, y = pieceInfo[i].y, d = pieceInfo[i].d;
		if (d == 1) {//오른쪽
			movingPiece(i, x, y + 1);
		}
		else if (d == 2) {//왼쪽
			movingPiece(i, x, y - 1);
		}
		else if (d == 3) {//위쪽
			movingPiece(i, x - 1, y);
		}
		else if (d == 4) {//아래쪽 
			movingPiece(i, x + 1, y);
		}
	}
}

bool isFourStack() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pieceMap[i][j].size() >= 4)
				return true;
		}
	}
	return false;
}

void solve() {
	while (1) {
		movingAll();
		res++;
		if (res >= 1000) {
			printf("-1");
			return;
		}
		if (isFourStack())
			break;
	}
	printf("%d", res);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int x, y, d;
	for (int i = 1; i <= k; i++) {
		cin >> x >> y >> d;
		x -= 1, y -= 1;
		pieceInfo[i] = { i, d, x, y };
		pieceMap[x][y].push_back(i);
	}
	solve();
}