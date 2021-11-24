#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct {
	// xy ��ǥ �������� ����, �ڳ� ����, ���, ����
	int x, y, straight, corner, cost, dist;
}road;

// x��ǥ, y��ǥ, �������� ����, �ڳ� ����! �̷��� 4������ �׷����� ������ �����Ѵ�.
bool check[25][25][500][500];
const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

int bfs(vector<vector<int>> board) {
	int ret = 0x7fffffff; // (n-1, n-1)������ �ּ� ����� ������ ����
	int size = board[0].size();

	queue<road> q;
	q.push({ 0,0,0,0,0,0 }); // (0,0)���� �����Ѵ�. 
	check[0][0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y,
			straight = q.front().straight, corner = q.front().corner,
			cost = q.front().cost, dist = q.front().dist;
		q.pop();

		if (ret <= cost) continue; // cost��

		// (n-1, n-1)�� �����ߴٸ�, �ּҺ������ Ȯ���Ѵ�!
		if (x == size - 1 && y == size - 1) {
			ret = min(ret, cost);
			continue;
		}

		// 4���� BFS Ž��
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			
			// board ������ �ʰ��� ���
			if (nx >= size || nx < 0 || ny >= size || ny < 0) continue;
			// �湮�� ���� ���� ���� ���
			if (board[nx][ny]) continue; 
			// nCost : ���� �Ǽ� ����� 100�̴�.
			int nStraight = straight, nCorner = corner, nCost = cost + 100;

			// (0,0) ���� �����ϴ� ��� ������ �Ʒ��� ���� �������ش�. 
			if (x == 0 && y == 0) dist = i; 

			if (i == dist) { // ���� ������ ���(������ �ȹٲ�� ���)
				nStraight++; // ���� ���ΰ��� ����
			}
			else { // �ڳ��ϰ�� 
				corner++; // �ڳ� ���� ����
				nCost += 500; // �ڳ� �Ǽ���� 500 �߰�
			}

			// �̹� �湮�ߴ� �����̶��(�̹� Ȯ���ߴ� ����� �����), ��ŵ
			if (check[nx][ny][nStraight][corner]) continue; 
			check[nx][ny][nStraight][corner] = true;
			q.push({ nx,ny,nStraight, nCorner, nCost, i });
		}
	}

	return ret;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	return bfs(board);
}