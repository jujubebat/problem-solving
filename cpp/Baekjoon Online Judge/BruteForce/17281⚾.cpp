#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int inning[50][10];
int n, res = -1;
bool visited[10];
vector<int> v;

void simulation(){
	int s = 0 , score = 0;
	int roo[4];

	for (int i = 0; i < n; i++) {
		memset(roo, 0, sizeof(roo));
		int out = 0;

		while (1) { //이닝 시작
			int result = inning[i][v[s]];
			s = (s + 1) % 9;
			
			if (result == 1) { //1루타
				for (int k = 3; k >=1; k--) {
					if (roo[k] == 1) {
						if (k == 3) {
							roo[k] = 0;
							score++;
						}
						else {
							roo[k+1] = 1;
							roo[k] = 0;
						}
					}
				}
				roo[1] = 1;
			}
			else if (result == 2) {//2루타
				for (int k = 3; k>= 1; k--) {
					if (roo[k] == 1) {
						if (k == 3 || k==2) {
							roo[k] = 0;
							score++;
						}
						else {
							roo[k + 2] = 1;
							roo[k] = 0;
						}
					}
				}
				roo[2] = 1;
			}
			else if (result == 3) {
				for (int k = 3; k >= 1; k--) {
					if (roo[k] == 1) {
						roo[k] = 0;
						score++;
					}
				}
				roo[3] = 1;
			}
			else if (result == 4) { //홈런
				for (int k = 1; k < 4; k++) {
					if (roo[k] == 1) {
						score++;
						roo[k] = 0;
					}
				}
				score++;
			}
			else if (result == 0) {
				out++;
				if (out == 3) break;
			}
		}
	}

	res = max(res, score);
}

void permutation() {

	if (v.size() == 9) {
		if (v[3] != 0) return;
		simulation();
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			permutation();
			v.pop_back();
			visited[i] = false;
		}
	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> inning[i][j];
		}
	}

	permutation();
	cout << res;
	return 0;
}
