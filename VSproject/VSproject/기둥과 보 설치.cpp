#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool pillar[101][101]; // 기둥
bool barrage[101][101]; // 보
int N;

bool check() {

	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {

			if (pillar[i][j]) {
				if (i == N) continue; // 기둥이 바닥에 있는 경우.
				if (pillar[i + 1][j]) continue;// 기둥이 다른 기둥 위에 있는 경우.
				if (barrage[i][j]) continue; // 기둥이 보 왼쪽 끝위에 있는 경우.
				if (j > 0 && barrage[i][j - 1]) continue; // 기둥이 보 오른쪽 끝 경우에 있는경우.
				return false;
			}

			if (barrage[i][j]) {
				if (pillar[i + 1][j] || pillar[i + 1][j + 1]) continue; // 보의 한쪽 끝 부분이 기둥 위에 있는 경우.
				if (j > 0 && j < N) {
					if (barrage[i][j - 1] && barrage[i][j + 1]) continue; // 보의 양쪽 끝부분이 다른 보와 연결되어있을떄
				}
				return false;
			}

		}
	}

	return true;
}

void build(int x, int y, bool structure, bool action) {
	if (structure)
		barrage[x][y] = action; // 설치 or 삭제
	else
		pillar[x][y] = action;

	if (!check()) { // 설치 불가능할 경우 복구.
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

		int x = n - build_frame[i][1]; // 행렬 기준 좌표계로 변환
		int y = build_frame[i][0];
		int a = build_frame[i][2];
		int b = build_frame[i][3];

		build(x, y, a, b); // 기둥과 보 건설을 시도한다.
	}

	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {

			int x = j, y = n - i; // 처음에 주어진 좌표계로 변환

			if (pillar[i][j]) {
				answer.push_back({ x,y,0 });
			}

			if (barrage[i][j]) {
				answer.push_back({ x,y,1 });
			}

		}
	}

	sort(answer.begin(), answer.end()); // 문제 조건에 맞추어 정렬.
	return answer;
}


// 1000 * 100
// 100,000

/*
N이 들어오면
N+1 크기의 2차원 배열을 만들고

(x, y) -> (N - y, x) 이렇게 좌표변환을 한다.

N + 1 * N + 1

0, 0->N, 0

1, 0->N, 1

2, 2->N - 2, 2

3, 2->N - 2, 3

5, 0->N - 0, 5

*/

int main() {
	bool flag;

	flag = 1;

	if (!flag)
		cout << "true";
	else
		cout << "false";

	return 0;
}

