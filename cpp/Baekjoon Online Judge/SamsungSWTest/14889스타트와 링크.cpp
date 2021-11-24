#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int map[20][20];
int res = 1e9;
int n;
vector<int> v;
bool visited[20];

void dfs(int cnt) {
	if (v.size() == n / 2) {
		int score_1=0, score_2=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i] && visited[j]) {//score_1
					score_1 += map[i][j];
				}
				else if (!visited[i] && !visited[j]) {//score_2
					score_2 += map[i][j];
				}
			}
		}
		res = min(res, abs(score_1 - score_2));
		return;
	}

	for (int i = cnt; i < n; i++) {
		visited[i] = true;
		v.push_back(i);
		dfs(i + 1);
		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0);
	printf("%d", res);
}