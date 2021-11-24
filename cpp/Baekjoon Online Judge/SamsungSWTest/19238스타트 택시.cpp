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

// �ִܰŸ��� ���� �մ��� �������� ��� �Ʒ� �������� sort �ϸ�ȴ�.
bool comp(pos a, pos b) {
	if (a.f == b.f) {
		if (a.x == b.x) {
			return a.y < b.y; // ����ȣ�� ����������
		}
		else
			return a.x < b.x; // ���ȣ�� ����������
	}
	else
		return a.f > b.f; // ���ᰡ ����������(�Ÿ��� ����������)
}

// �մ��� ������(=destNum)�� �������ִ� bfs 
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

		// ���������
		if (destInfo[destNum].first == x
			&& destInfo[destNum].second == y) {
			// �ý� ��ġ, ���� ���� ������Ʈ
			tx = x, ty = y, fuel = f + (fuel - f) * 2; // �Ҹ��� ������ 2�� �߰�.
			return true;
		}

		if (f == 0) continue; // ���ᰡ 0�� ���

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			int nf = f;
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny]) continue;
			if (check[nx][ny]) continue;

			nf--; // ���� ����
			check[nx][ny] = true;
			q.push({ nx, ny, nf });
		}

	}

	return false;
}

bool rideClient() { // �ִܰŸ��� �ִ� �մԵ� �¿췯���� bfs �Լ�
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

		if (f == 0) continue; // ���ᰡ 0�� ���

		if (clientMap[x][y] > 0) {
			if (f >= maxVal) { // v���Ḧ �� �Ҹ��ؾ� ����� ���̴�.
				candi.push_back({ x,y,f }); // �մ� �ĺ����� �ִ´�.
			}
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			int nf = f;
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (map[nx][ny]) continue;
			if (check[nx][ny]) continue;
			nf--; // ���� ����
			check[nx][ny] = true;
			q.push({ nx,ny, nf });
		}

	}

	if (candi.size() == 0) // �մ� �ĺ����� ���ٸ�
		return false;

	// ������ ����� ��, ���� ���� �մ��� ã�´�.
	sort(candi.begin(), candi.end(), comp);

	int x = candi[0].x, y = candi[0].y, f = candi[0].f;
	int destNum = clientMap[x][y];
	clientMap[x][y] = 0; // clientMap ���� ������Ʈ
	tx = x, ty = y, fuel = f; // �ý� ���� ������Ʈ

	return goToDest(destNum); // �¿� �մ� ��ȣ(=������ ��ȣ)�� �ִ´�.
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

	for (int i = 0; i < n; i++) { // map ������ �Է¹޴´�. 
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> tx >> ty; // �ý� ���� �Է�
	tx--, ty--;

	for (int i = 1; i <= m; i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		clientMap[sx - 1][sy - 1] = i; // �մ� ��ġ ������ 2���� �迭�� ����
		destInfo[i] = { ex - 1, ey - 1 }; // �մ��� ������ ������ hash map���� ����
	}

	cout << solve();

	return 0;
}