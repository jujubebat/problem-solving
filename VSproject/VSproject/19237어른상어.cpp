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

bool move() { 
	smellInfo tmpSmellMap[20][20];
	int tmpSharkMap[20][20];
	memset(tmpSharkMap, 0, sizeof(tmpSharkMap));
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
				int sharkNum = sharkMap[i][j];
				int sharkDir = sharkInfo[sharkNum].dir;
				vector<pos> clearCandi; 
				vector<pos> mySmellCandi; 

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;

					if (smellMap[nx][ny].num == 0) {
						clearCandi.push_back({ nx, ny, k + 1 });
					} 

					if (smellMap[nx][ny].num == sharkMap[i][j]) 
						mySmellCandi.push_back({ nx, ny, k + 1 });
				}

				pos next = { -1,-1,-1 };

				if (clearCandi.size() > 0) {
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
				sharkMap[i][j] = 0;

				if (tmpSharkMap[next.x][next.y] == 0
					|| sharkNum < tmpSharkMap[next.x][next.y]) {
					tmpSharkMap[next.x][next.y] = sharkNum;
					tmpSmellMap[next.x][next.y].num = sharkNum;
					tmpSmellMap[next.x][next.y].smellCnt = k;
					sharkInfo[sharkNum].dir = next.dir;
				}
			}
		}
	}

	memcpy(sharkMap, tmpSharkMap, sizeof(tmpSharkMap));
	memcpy(smellMap, tmpSmellMap, sizeof(tmpSmellMap));
	int flag = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sharkMap[i][j] > 0)
				flag++;
			if (flag > 1) return false;
		}
	}

	if (flag == 1)
		return true;
}

int solve() {
	int ret = 0;

	while (1) {
		ret++;

		if (move())
			break;

		if (ret >= 1000)
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