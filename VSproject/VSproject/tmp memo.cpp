#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;

typedef struct {
	int dir;
	int priorInfo[4][4];
}shark;

typedef struct {
	int x, y, dir;
}pos;

typedef struct {
	int num, smellCnt;
}smellInfo;

int n, m, k;
int sharkMap[20][20];
smellInfo smellMap[20][20];
unordered_map<int, shark> sharkInfo;
const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

bool move() { // 1번상어만 격자에 남으면 true 반환.
	//cout << "move 시작" << endl;
	smellInfo tmpSmellMap[20][20];
	int tmp[20][20];
	memset(tmp, 0, sizeof(tmp));
	memcpy(tmpSmellMap, smellMap, sizeof(smellMap));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmpSmellMap[i][j].smellCnt > 0)
				tmpSmellMap[i][j].smellCnt--;

			if (tmpSmellMap[i][j].smellCnt == 0)
				tmpSmellMap[i][j].num = 0;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (sharkMap[i][j] > 0) {
				// cout << sharkMap[i][j] << endl;


				int sharkNum = sharkMap[i][j];
				int sharkDir = sharkInfo[sharkNum].dir;

				vector<pos> clearCandi; // 빈 공간
				vector<pos> mySmellCandi; // 자신의 냄새가 있는공간.

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;

					// cout << smellMap[nx][ny].num << endl;
					// cout << smellMap[nx][ny].smellCnt << endl;

					if (smellMap[nx][ny].num == 0) {
						clearCandi.push_back({ nx, ny, k + 1 });

					} // 빈 공간 

					if (smellMap[nx][ny].num == sharkMap[i][j]) // 자신의 냄새가 있는 공간
						mySmellCandi.push_back({ nx, ny, k + 1 });
				}

				pos next = { -1,-1,-1 };

				if (clearCandi.size() > 0) {

					//cout << "sharkNum : " << sharkNum << endl;
					//cout << "candi 목록" << endl;



					for (int prior : sharkInfo[sharkNum].priorInfo[sharkDir - 1]) {
						for (pos candi : clearCandi) {
							if (candi.dir == prior) {
								next = candi;
								break;
							}
						}
						if (next.dir != -1) break;
					}
				}
				else {
					for (int prior : sharkInfo[sharkNum].priorInfo[sharkDir - 1]) {
						for (pos candi : mySmellCandi) {
							if (candi.dir == prior) {
								next = candi;
								break;
							}
						}
						if (next.dir != -1) break;
					}
				}
				/*
				cout << "next : ";
				cout << next.x << " " << next.y << " " << next.dir << endl;
				cout << "tmp[next.x][next.y] : " << tmp[next.x][next.y] << endl;
				cout << "sharkNum : " << sharkNum << endl;
				*/
				sharkMap[i][j] = 0;

				if (tmp[next.x][next.y] == 0
					|| sharkNum < tmp[next.x][next.y]) {
					tmp[next.x][next.y] = sharkNum;
					tmpSmellMap[next.x][next.y].num = sharkNum;
					tmpSmellMap[next.x][next.y].smellCnt = k;
					sharkInfo[sharkNum].dir = next.dir;
				}
			}

		}


	}

	memcpy(sharkMap, tmp, sizeof(tmp));
	memcpy(smellMap, tmpSmellMap, sizeof(tmpSmellMap));
	int flag = 0;
	/*
	cout << "이동결과!!!!!!!!!" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << sharkMap[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << smellMap[i][j].smellCnt;
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;


	cout << "move 끝" << endl;
	*/

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sharkMap[i][j] > 0)
				flag++;

			if (flag > 1) return false;
		}
	}
	//cout << "flag : " << flag << endl;

	if (flag == 1)
		return true;
}

int solve() {
	int ret = 0;

	while (1) {
		ret++;

		if (move())
			break;

		if (ret > 1000)
			return -1;
	}

	return ret;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sharkMap[i][j];
			if (sharkMap[i][j] > 0) {
				smellMap[i][j].num = sharkMap[i][j];
				smellMap[i][j].smellCnt = k;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << sharkMap[i][j];
		}
		cout << endl;
	}

	for (int i = 1; i <= m; i++) {
		int dir;
		cin >> dir;
		sharkInfo[i].dir = dir;
	}

	for (int i = 1; i <= m; i++) {
		for (int a = 0; a < 4; a++) {
			for (int b = 0; b < 4; b++) {
				int num;
				cin >> num;
				sharkInfo[i].priorInfo[a][b] = num;
			}
		}
	}

	cout << solve();
	return 0;
}

//상어 번호, 방향, 우선순위 정보

// (상어번호, 냄새) 정보를 표현하는 2차원 배열
// 상어는 이동할때마다 자신의 자리에 냄새를 뿌린다.
// 냄새는 상어가 k번 이동하면 사라진다.
// 이동하기 전에 맵에있는 모든 냄새 -1
// 이동할때 현재 방향에 따른 우선순위 정보 참조해서 이동
// 상어가 1마리 남을때까지 몇초걸리는지 출력
// 1000초가 넘어도 다른 상어가 격자에 있으면 -1 출력