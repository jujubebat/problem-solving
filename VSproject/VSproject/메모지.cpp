// 터뜨리기
for (int r = 9; r >= 4; r--) {
	bool flag = true;
	for (int c = 0; c < 4; c++) {
		if (map[r][c] == 0) {
			flag = false;
			break;
		}
	}

	if (flag) {
		score++;

		// 지우기
		for (int c = 0; c < 4; c++) {

			if (blockInfo[map[r][c]]) {
				blockInfo[map[r][c]] = false;
			}

			map[r][c] = 0;

		}

		cout << "지우기" << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;

		// 전체 블록 떨어뜨리기

		for (int col = 0; col < 4; col++) {
			for (int row = 9; row >= 4; row--) {

				if (map[row][col]) {
					cout << "블록 번호 : " << map[row][col] << endl;
					if (!blockInfo[map[row][col]]) { //낱개인 경우
						cout << "날개인 경우" << endl;
						int start = row;
						while (1) {
							if (start >= 9 || map[start + 1][col]) break;
							if (!map[start + 1][col]) {
								swap(map[start][col], map[start + 1][col]);
							}
							start++;
						}
					}
					else { // 2x1 인경우
						cout << "2x1 인경우" << endl;
						blockInfo[map[row][col]] = false;

						int start = row;
						int nx, ny;
						for (int i = 0; i < 4; i++) {
							ny = col + dy[i];
							if (ny >= 4 || ny < 0) continue;
							if (ny != col && map[start][ny] == map[row][col]) {
								break;
							}
						}
						while (1) {
							if (start >= 9 || map[start + 1][col]) break;
							if (start >= 9 || map[start + 1][ny]) break;

							if (!map[start + 1][col]) {
								swap(map[start][col], map[start + 1][col]);
							}

							if (!map[start + 1][ny]) {
								swap(map[start][ny], map[start + 1][ny]);
							}
							start++;
						}
					}
				}
			}
		}

		/*
		cout << "떨어뜨리고 나서" << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;*/

		r = 10; // 다시 맨 아래부터 검사
	}

}