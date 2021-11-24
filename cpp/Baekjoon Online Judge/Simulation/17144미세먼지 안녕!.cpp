#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int x, y;
int r, c, t;
int map[50][50];
int airConUpXpos;
const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,-1,1 };

void diffuseDust() {

	int tmpMap[50][50];

	// ���� Ȯ�� ó���� ����, ���� map�� �ӽ� tmpMap�� �����صд�. 
	memcpy(tmpMap, map, sizeof(map)); 

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] >= 5) { // Ȯ���� ������ �̼������� ���.
				int diffuseAmount = map[i][j] / 5; // Ȯ��� �̼����� �� ���.
				for (int k = 0; k < 4; k++) { // �����¿� ���� ��ġ�� Ȯ���Ѵ�.
					int nx = i + dx[k], ny = j + dy[k];

					// ���� ��ġ�� ���� û���Ⱑ �ִ� ���.
					if (map[nx][ny] == -1) continue; 

					// ������ ��� ���.
					if (nx >= r || nx < 0 || ny >= c || ny < 0) continue; 

					// map�� �������� Ȯ�꿩�θ� �Ǵ��ϰ�, ����ݿ��� tmpMap�� �Ѵ�.
					// �̷��� �ϸ�, map�� �ٲ��� �����Ƿ� ���� Ȯ���Ų ������ ����� 
					// ���߿� Ȯ���ų ������ ����� ������ ���� �ʰ��� �� �ִ�.

					// ���� ��ġ�� �̼����� Ȯ��.
					tmpMap[nx][ny] += diffuseAmount; 

					// Ȯ�� �������ϱ�, ���� ��ġ �̼����� ����.
					tmpMap[i][j] -= diffuseAmount;  
				}
			}
		}
	}

	// map�� tmpMap���� ��ü�Ͽ� ���� �迭�� �ùķ��̼� ��� �ݿ�.
	memcpy(map, tmpMap, sizeof(tmpMap)); 
}

void airConditionerWork() {

	// main���� ���� ������ ���� ��ǥ �������� ������ ���� ���� ��ȯ ����.
	x = airConUpXpos - 1, y = 0;
	while (x > 0) map[x][y] = map[x - 1][y], x--; // ��

	x = 0, y = 0;
	while (y < c - 1) map[x][y] = map[x][y + 1], y++; // ��

	x = 0, y = c - 1;
	while (x < airConUpXpos)  map[x][y] = map[x + 1][y], x++; // ��

	x = airConUpXpos, y = c - 1;
	while (y > 1) map[x][y] = map[x][y - 1], y--;  // ��

	map[airConUpXpos][1] = 0; // ���� û���⿡�� ���Ⱑ ������ �κ��� 0���� ����.

	// main���� ���� ������ ���� ��ǥ + 1 = ������ �Ʒ��� ��ǥ
	// ������ �Ʒ��� ���� ��ȯ ����.

	int airConDownXpos = airConUpXpos + 1;

	x = airConDownXpos + 1, y = 0; // ��
	while (x < r - 1) map[x][y] = map[x + 1][y], x++;

	x = r - 1, y = 0;
	while (y < c - 1) map[x][y] = map[x][y + 1], y++; // ��

	x = r - 1, y = c - 1;
	while (x > airConDownXpos) map[x][y] = map[x - 1][y], x--; // ��

	x = airConDownXpos, y = c - 1;
	while (y > 1) map[x][y] = map[x][y - 1], y--; // ��

	map[airConDownXpos][1] = 0; // ���� û���⿡�� ���Ⱑ ������ �κ��� 0���� ����.

}

void solve() {

	while (t--) { // t�� ��ŭ �ùķ��̼��Ѵ�.
		diffuseDust(); // ������ Ȯ���Ų��.
		airConditionerWork(); // �����ȯ�� ��Ų��. 
	}

	int ret = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) ret += map[i][j]; // �����ִ� �̼������� ��� ���Ѵ�.
		}
	}

	cout << ret; // ��� ���.
}

int main() {
	cin >> r >> c >> t; // �� �Է�.
	bool flag = true;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1 && flag) {
				airConUpXpos = i;  // ������ ���ʺκ� X ��ǥ�� �����صд�. 
				flag = false;
				// X ��ǥ�� �����صֵ� �ȴ�. �������� �׻� ���� ù° ���� ��ġ�ϱ� ����.
				// ���ʷ� ������ -1�� ������ ���� �κ� X��ǥ�̴�.
				// flag�� ���� ���� �� ���� ���� �ϵ��� ����.
			}
		}
	}

	solve();
	return 0;
}