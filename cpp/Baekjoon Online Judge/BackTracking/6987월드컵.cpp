#include<iostream>
#include<vector>
#include<cstring>
#include <numeric>
using namespace std;

vector<vector<int>> gameResult(6, vector <int>(3, 0));
vector<vector<int>> candi(6, vector <int>(3, 0));

int aTeam[15] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int bTeam[15] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4 ,5, 4, 5, 5 };
bool flag;

void dfs(int round) {
	if (flag) return;
		
	if (round == 15) {
		if (gameResult == candi) {
			flag = true;
		}
		return;
	}

	// a팀이 이기는 경우
	candi[aTeam[round]][0]++, candi[bTeam[round]][2]++;
	dfs(round + 1);
	candi[aTeam[round]][0]--, candi[bTeam[round]][2]--;
	
	// 무승부인 경우
	candi[aTeam[round]][1]++, candi[bTeam[round]][1]++;
	dfs(round + 1);
	candi[aTeam[round]][1]--, candi[bTeam[round]][1]--;

	// a팀이 지는 경우
	candi[aTeam[round]][2]++, candi[bTeam[round]][0]++;
	dfs(round + 1);
	candi[aTeam[round]][2]--, candi[bTeam[round]][0]--;
}

int main() {
	
	for (int t = 0; t < 4; t++) {

		gameResult.assign(6, vector<int>(3, 0));
		candi.assign(6, vector<int>(3, 0));

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> gameResult[i][j];
			}
		}

		flag = false;

		dfs(0);

		if (flag)
			cout << 1 << " ";
		else
			cout << 0 << " ";

	}
	
	return 0;
}