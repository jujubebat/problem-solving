#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool pillar[101][101]; // ���
bool barrage[101][101]; // ��
int N;

bool check() {

	for (int i = 0; i <= N; i++) { // �� ���� �˻�.
		for (int j = 0; j <= N; j++) {
			if (barrage[i][j]) {
				// ���� �� �� �� �κ��� ��� ���� �ִ� ���.
				if (pillar[i + 1][j] || pillar[i + 1][j + 1]) continue; 
				// ���� ���� �� �κ��� ���ÿ� �ٸ� ���� ������ִ� ���.
				if (barrage[i][j - 1] && barrage[i][j + 1]) continue; 
				return false;
			}
		}
	}

	for (int i = 0; i <= N; i++) { // ��� ���� �˻�.
		for (int j = 0; j <= N; j++) {
			if (pillar[i][j]) {
				if (i == N) continue; // ����� �ٴڿ� �ִ� ���.
				if (pillar[i + 1][j]) continue;// ����� �ٸ� ��� ���� �ִ� ���.
				// ����� �� ���� �Ǵ� ������ �� ���� �ִ� ���.
				if (barrage[i][j] || barrage[i][j - 1]) continue; 
				return false;
			}
		}
	}

	return true;
}

void build(int x, int y, bool structure, bool action) {

	if (structure)
		barrage[x][y] = action; // ��ġ or ����.
	else
		pillar[x][y] = action;

	if (!check()) { // �۾��� ����� ������ �����ϸ�, ���� ����.
		if (structure)
			barrage[x][y] = !action;
		else
			pillar[x][y] = !action;
	}
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	N = n;

	for (int i = 0; i < build_frame.size(); i++) {
		int x = N - build_frame[i][1]; // ��� ���� ��ǥ��� ��ȯ.
		int y = build_frame[i][0];
		int a = build_frame[i][2];
		int b = build_frame[i][3];

		build(x, y, a, b); // ��հ� �� �Ǽ��� �õ��Ѵ�.
	}

	// ��� �۾��� ���� �� ���������� ���� ����� �����Ѵ�.
	for (int i = 0; i <= N; i++) {  
		for (int j = 0; j <= N; j++) {

			int x = j, y = N - i; // ó���� �־��� ��ī��Ʈ ��ǥ��� ��ȯ.

			if (pillar[i][j]) { // ��� ���� ����.
				answer.push_back({ x,y,0 });
			}

			if (barrage[i][j]) { // �� ���� ����.
				answer.push_back({ x,y,1 });
			}
			// ���� : ��հ� ���� ���� ��ġ�� �� �� �ִ�.
		}
	}

	sort(answer.begin(), answer.end()); // ���� ���ǿ� ���߾� ���� ����.
	return answer;
}


// 1000 * 100
// 100,000

/*
N�� ������
N+1 ũ���� 2���� �迭�� �����

(x, y) -> (N - y, x) �̷��� ��ǥ��ȯ�� �Ѵ�.

N + 1 * N + 1

0, 0->N, 0

1, 0->N, 1

2, 2->N - 2, 2

3, 2->N - 2, 3

5, 0->N - 0, 5

*/


/*
����� �ٴ� ���� �ְų�, ���� ���� �� �κ� ���� �ְų�, �ٸ� ������� �־�� �Ѵ�.
���� ���� �� �κ��� ��� ���� �ְų�, ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־���Ѵ�.

*/