#include<iostream>
#include<unordered_map>
using namespace std;

int map[10][10];
int num = 1;
const int dx[] = { -1,1 }, dy[] = { -1,1 };
unordered_map<int, int> blockInfo; // <블록번호, 블록종류>
// 블록 종류
// 0 : 한 개 짜리
// 1 : 세로
// 2 : 가로

int greenMove(int t, int x, int y) { // 초록부분 이동 시뮬레이션
	int score = 0;

	// 빨간 영역에 블록을 놓은 기준으로 블록을 떨어뜨리는 시뮬레이션
	if (t == 1) {
		while (1) {
			if (x + 1 > 9 || map[x + 1][y]) {
				map[x][y] = num;
				blockInfo[num++] = 0;
				break;
			}
			x++;
		}
	}
	else if (t == 2) {
		while (1) {
			if (x + 1 > 9 || map[x + 1][y] || map[x + 1][y + 1]) {
				map[x][y] = num, map[x][y + 1] = num;
				blockInfo[num++] = 2;
				break;
			}
			x++;
		}
	}
	else if (t == 3) {
		while (1) {
			if (x + 2 > 9 || map[x + 2][y]) {
				map[x][y] = num, map[x + 1][y] = num;
				blockInfo[num++] = 1;
				break;
			}
			x++;
		}
	}

	// 행에 블록이 꽉찬경우 지우고, 떨어뜨리는 시뮬레이션
	bool isfall = true;
	while (isfall) {
		isfall = false;

		for (int r = 9; r >= 4; r--) {
			bool flag = true;
			for (int c = 0; c < 4; c++) {
				if (map[r][c] == 0) {
					flag = false;
					break;
				}
			}

			if (flag) { // 행에 블록이 4칸 차지해서 꽉찼다면 
				isfall = true;
				score++;

				for (int c = 0; c < 4; c++) { // 행을 지운다.
					// 만약 세로 블록이 있으면 낱개 블록으로 정보를 갱신한다.
					// (행을 지움으로써 잘라졌으므로)
					if (blockInfo[map[r][c]] == 1) {
						blockInfo[map[r][c]] = 0;
					}
					map[r][c] = 0;
				}
			}
		}

		// 블록을 지우는 시뮬레이션
		for (int col = 0; col < 4; col++) {
			for (int row = 9; row >= 4; row--) {
				if (map[row][col]) {
					// 낱개 또는 세로 블록인 경우, 낱개 단위로 블록을 떨어뜨려도 무방하다.
					if (blockInfo[map[row][col]] == 0 || blockInfo[map[row][col]] == 1) {
						int start = row;
						while (1) {
							if (start >= 9 || map[start + 1][col]) break;
							if (!map[start + 1][col]) {
								swap(map[start][col], map[start + 1][col]);
							}
							start++;
						}
					}
					// 가로 블록인 경우, 2x1 단위로 블록을 떨어뜨려야한다.
					else if (blockInfo[map[row][col]] == 2) {
						int start = row;
						int ny;

						// 2x1을 구성하는 다른 낱개 블록을 구하는 로직
						for (int i = 0; i < 4; i++) {
							ny = col + dy[i];
							if (ny >= 4 || ny < 0) continue;
							if (ny != col && map[start][ny] == map[row][col]) {
								break;
							}
						}
						while (1) { // 2x1 단위로 블록을 떨어뜨린다.

							// 2x1 블록을 구성하는 작은 낱개 블록중 하나라도
							// 벽 또는 바닥에 닿으면 떨어뜨리는 것을 멈춘다.
							if (start >= 9 || map[start + 1][col]) break;
							if (start >= 9 || map[start + 1][ny]) break;

							swap(map[start][col], map[start + 1][col]);
							swap(map[start][ny], map[start + 1][ny]);
							start++;
						}
					}
				}
			}
		}
	}

	// 연한 초록 부분에 블록이 존재할 경우 처리하는 시뮬레이션
	int count = 0;

	//연한 초록 부분에 블록이 몇 개의 행에 존재하는지 검사한다.
	for (int r = 4; r <= 5; r++) {
		bool flag = false;
		for (int c = 0; c < 4; c++) {
			if (map[r][c]) {
				flag = true;
				break;
			}
		}
		if (flag) count++;
	}

	// 연한 초록 부분에 블록이 존재하는 행이 1개일때
	if (count == 1) {

		// 맨 아래쪽 열 1개를 지우고
		for (int c = 0; c < 4; c++) {
			map[9][c] = 0;
		}

		// 블록들을 떨어뜨린다.
		for (int r = 8; r >= 4; r--) {
			for (int c = 0; c < 4; c++) {
				map[r + 1][c] = map[r][c];
				map[r][c] = 0;
			}
		}
	}
	// 연한 초록 부분에 블록이 존재하는 행이 2개일때
	else if (count == 2) {

		//맨 아래쪽 열 2개를 지우고
		for (int c = 0; c < 4; c++) {
			map[9][c] = 0;
			map[8][c] = 0;
		}

		// 블록들을 떨어뜨린다.
		for (int r = 7; r >= 4; r--) {
			for (int c = 0; c < 4; c++) {
				map[r + 2][c] = map[r][c];
				map[r][c] = 0;
			}
		}
	}

	// 이번 시뮬레이션에 대한 점수결과 반환
	return score;
}

int blueMove(int t, int x, int y) {

	int score = 0;

	if (t == 1) {
		while (1) {
			if (y + 1 > 9 || map[x][y + 1]) {
				map[x][y] = num;
				blockInfo[num++] = 0;
				break;
			}
			y++;
		}
	}
	else if (t == 2) {
		while (1) {
			if (y + 2 > 9 || map[x][y + 2]) {
				map[x][y] = num, map[x][y + 1] = num;
				blockInfo[num++] = 1;
				break;
			}
			y++;
		}
	}
	else if (t == 3) {
		while (1) {
			if (y + 1 > 9 || map[x][y + 1] || map[x + 1][y + 1]) {
				map[x][y] = num, map[x + 1][y] = num;
				blockInfo[num++] = 2;
				break;
			}
			y++;
		}
	}
	bool f = true;

	while (f) {
		f = false;
		for (int c = 9; c >= 4; c--) {
			bool flag = true;

			for (int r = 0; r < 4; r++) {
				if (map[r][c] == 0) {
					flag = false;
					break;
				}
			}

			if (flag) {
				f = true;
				score++;

				for (int r = 0; r < 4; r++) {
					if (blockInfo[map[r][c]] == 1) {
						blockInfo[map[r][c]] = 0;
					}
					map[r][c] = 0;
				}
				c = 10;
			}
		}

		for (int row = 0; row < 4; row++) {
			for (int col = 9; col >= 4; col--) {

				if (map[row][col]) {

					if (blockInfo[map[row][col]] == 0 || blockInfo[map[row][col]] == 1) { //세로 또는 낱개인 경우
						int start = col;


						while (1) {
							if (start >= 9 || map[row][start + 1]) break;
							if (!map[row][start + 1]) {
								swap(map[row][start], map[row][start + 1]);
							}
							start++;
						}
					}
					else if (blockInfo[map[row][col]] == 2) {

						int start = col;
						int nx;

						for (int i = 0; i < 4; i++) {
							nx = row + dx[i];
							if (nx >= 4 || nx < 0) continue;
							if (nx != row && map[nx][start] == map[row][col]) {
								break;
							}
						}
						while (1) {
							if (start >= 9 || map[row][start + 1]) break;
							if (start >= 9 || map[nx][start + 1]) break;

							swap(map[row][start], map[row][start + 1]);
							swap(map[nx][start], map[nx][start + 1]);
							start++;
						}
					}
				}
			}
		}
	}

	int count = 0;

	for (int c = 4; c <= 5; c++) {
		bool flag = false;
		for (int r = 0; r < 4; r++) {
			if (map[r][c]) {
				flag = true;
				break;
			}
		}
		if (flag) count++;
	}

	if (count == 1) {
		for (int r = 0; r < 4; r++) {
			map[r][9] = 0;
		}

		for (int c = 8; c >= 4; c--) {
			for (int r = 0; r < 4; r++) {
				map[r][c + 1] = map[r][c];
				map[r][c] = 0;
			}
		}

	}
	else if (count == 2) {
		for (int r = 0; r < 4; r++) {
			map[r][9] = 0;
			map[r][8] = 0;
		}

		for (int c = 7; c >= 4; c--) {
			for (int r = 0; r < 4; r++) {
				map[r][c + 2] = map[r][c];
				map[r][c] = 0;
			}
		}
	}

	return score;
}

int move(int t, int x, int y) { // 도미노 블록 이동 시뮬레이션 
	int score = 0;
	score += greenMove(t, x, y); // 초록 부분 이동 시뮬레이션
	score += blueMove(t, x, y); // 파란 부분 이동 시뮬레이션
	return score;
}

int main() {
	int score = 0;
	int count = 0;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int t, x, y;
		cin >> t >> x >> y; // 블록정보를 입력받을때마다
		score += move(t, x, y); //도미노를 진행시키고 점수를 얻는다.
	}

	cout << score << endl; // 최종 점수 출력

	for (int i = 0; i < 10; i++) {  // 블록이 차지하는 map의 크기 계산
		for (int j = 0; j < 10; j++) {
			if (map[i][j]) count++;
		}
	}

	cout << count << endl; // 블록이 차지하는 map의 크기 출력

	return 0;
}