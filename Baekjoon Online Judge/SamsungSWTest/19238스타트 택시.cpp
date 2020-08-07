#include<iostream>
#include<unordered_map>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct {
	int x, y, f;
}pos;

int n, m, fuel, tx, ty;
int map[20][20];
int clientMap[20][20];
unordered_map<int, pair<int, int>> destInfo;
const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

// 최단거리가 같은 손님이 여러명일 경우 아래 기준으로 sort 하면된다.
bool comp(pos a, pos b) {
	if (a.f == b.f) {
		if (a.x == b.x) {
			return a.y < b.y; // 열번호가 적은순으로
		}
		else
			return a.x < b.x; // 행번호가 적은순으로
	}
	else
		return a.f > b.f; // 연료가 많은순으로(거리가 가까운순으로)
}

// 손님을 목적지(=destNum)에 데려다주는 bfs 
bool goToDest(int destNum) {
	queue<pos> q;
	bool check[20][20];
	int maxVal = -0x7fffffff; 
	vector<pos> candi;

	memset(check, 0, sizeof(check));
	q.push({ tx,ty,fuel });

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y,
			f = q.front().f;
		q.pop();

		// 도착지라면
		if (destInfo[destNum].first == x
			&& destInfo[destNum].second == y) {
			// 택시 위치, 연료 정보 업데이트
			tx = x, ty = y, fuel = f + (fuel - f) * 2; // 소모한 연료의 2배 추가.
			return true;
		}

		if (f == 0) continue; // 연료가 0일 경우

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			int nf = f;
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny]) continue;
			if (check[nx][ny]) continue;

			nf--; // 연료 감소
			check[nx][ny] = true;
			q.push({ nx, ny, nf });
		}

	}

	return false;
}

bool rideClient() { // 최단거리에 있는 손님들 태우러가는 bfs 함수
	queue<pos> q;
	bool check[20][20];
	int maxVal = -0x7fffffff;
	vector<pos> candi;

	memset(check, 0, sizeof(check));
	q.push({ tx,ty,fuel });

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y,
			f = q.front().f;
		q.pop();

		if (f == 0) continue; // 연료가 0일 경우

		if (clientMap[x][y] > 0) {
			if (f >= maxVal) { // v연료를 덜 소모해야 가까운 곳이다.
				candi.push_back({ x,y,f }); // 손님 후보군을 넣는다.
			}
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			int nf = f;
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny]) continue;
			if (check[nx][ny]) continue;
			nf--; // 연료 감소
			check[nx][ny] = true;
			q.push({ nx,ny, nf });
		}

	}

	if (candi.size() == 0) // 손님 후보군이 없다면
		return false;

	// 정렬을 사용해 행, 열이 적은 손님을 찾는다.
	sort(candi.begin(), candi.end(), comp);

	int x = candi[0].x, y = candi[0].y, f = candi[0].f;
	int destNum = clientMap[x][y];
	clientMap[x][y] = 0; // clientMap 정보 업데이트
	tx = x, ty = y, fuel = f; // 택시 정보 업데이트

	return goToDest(destNum); // 태울 손님 번호(=목적지 번호)를 넣는다.
}

int solve() {
	for (int i = 0; i < m; i++) {
		if (!rideClient())
			return -1;
	}

	return fuel;
}

int main() {

	cin >> n >> m >> fuel;

	for (int i = 0; i < n; i++) { // map 정보를 입력받는다. 
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> tx >> ty; // 택시 정보 입력
	tx--, ty--;

	for (int i = 1; i <= m; i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		clientMap[sx - 1][sy - 1] = i; // 손님 위치 정보를 2차원 배열로 관리
		destInfo[i] = { ex - 1, ey - 1 }; // 손님의 도착지 정보를 hash map으로 관리
	}

	cout << solve();

	return 0;
}