#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool pillar[101][101]; // 기둥
bool barrage[101][101]; // 보
int N;

bool check() {

	for (int i = 0; i <= N; i++) { // 보 조건 검사.
		for (int j = 0; j <= N; j++) {
			if (barrage[i][j]) {
				// 보의 한 쪽 끝 부분이 기둥 위에 있는 경우.
				if (pillar[i + 1][j] || pillar[i + 1][j + 1]) continue; 
				// 보의 양쪽 끝 부분이 동시에 다른 보와 연결돼있는 경우.
				if (barrage[i][j - 1] && barrage[i][j + 1]) continue; 
				return false;
			}
		}
	}

	for (int i = 0; i <= N; i++) { // 기둥 조건 검사.
		for (int j = 0; j <= N; j++) {
			if (pillar[i][j]) {
				if (i == N) continue; // 기둥이 바닥에 있는 경우.
				if (pillar[i + 1][j]) continue;// 기둥이 다른 기둥 위에 있는 경우.
				// 기둥이 보 왼쪽 또는 오른쪽 끝 위에 있는 경우.
				if (barrage[i][j] || barrage[i][j - 1]) continue; 
				return false;
			}
		}
	}

	return true;
}

void build(int x, int y, bool structure, bool action) {

	if (structure)
		barrage[x][y] = action; // 설치 or 삭제.
	else
		pillar[x][y] = action;

	if (!check()) { // 작업의 결과가 조건을 위배하면, 원상 복구.
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
		int x = N - build_frame[i][1]; // 행렬 기준 좌표계로 변환.
		int y = build_frame[i][0];
		int a = build_frame[i][2];
		int b = build_frame[i][3];

		build(x, y, a, b); // 기둥과 보 건설을 시도한다.
	}

	// 모든 작업이 끝난 후 구조물들의 최종 결과를 저장한다.
	for (int i = 0; i <= N; i++) {  
		for (int j = 0; j <= N; j++) {

			int x = j, y = N - i; // 처음에 주어진 데카르트 좌표계로 변환.

			if (pillar[i][j]) { // 기둥 정보 저장.
				answer.push_back({ x,y,0 });
			}

			if (barrage[i][j]) { // 보 정보 저장.
				answer.push_back({ x,y,1 });
			}
			// 참고 : 기둥과 보는 같은 위치에 올 수 있다.
		}
	}

	sort(answer.begin(), answer.end()); // 문제 조건에 맞추어 정렬 수행.
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


/*
기둥은 바닥 위에 있거나, 보의 한쪽 끝 부분 위에 있거나, 다른 기둥위에 있어야 한다.
보는 한쪽 끝 부분이 기둥 위에 있거나, 양쪽 끝 부부이 다른 보와 동시에 연결되어 있어야한다.

*/