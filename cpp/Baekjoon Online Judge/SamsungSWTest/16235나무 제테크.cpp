#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k;
int map_nutrient[10][10]; //양분맵
int map_S2D2[10][10]; //로봇이 주는 양분맵
vector<int> map_tree[10][10]; //나무맵
int ans = 0;

int dx[] = { -1,1,0,0,-1,-1,1,1 }, dy[] = { 0,0,-1,1,-1,1,-1,1 };
int map_dead_tree[10][10];

void season_simul(int season) {
	if (season == 0) { //봄
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map_tree[i][j].size() == 0) continue;
				sort(map_tree[i][j].begin(), map_tree[i][j].end());

				for (int k = 0; k < map_tree[i][j].size(); k++) {
					if (map_nutrient[i][j] >= map_tree[i][j][k]) {//양분먹기
						map_nutrient[i][j] -= map_tree[i][j][k];
						map_tree[i][j][k]++;
					}
					else { //양분을 못먹는다면 죽인다. 
						map_dead_tree[i][j] += map_tree[i][j][k] / 2;
						map_tree[i][j].erase(map_tree[i][j].begin()+k);
						k -= 1; //원소를 하나 삭제해줬으므로, 인덱스 값도 역시 하나 줄인다.
					}
				}
			}
		}
	}
	else if (season == 1) { //여름
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map_nutrient[i][j] += map_dead_tree[i][j];
			}
		}
	}
	else if (season == 2) { //가을
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < map_tree[i][j].size(); k++) {
					if (map_tree[i][j][k] >=5 && map_tree[i][j][k] % 5 == 0) {
						for (int l = 0; l < 8; l++) {
							int nx = i + dx[l], ny = j + dy[l];
							if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
							map_tree[nx][ny].push_back({ 1 });
						}
					}
				}
			}
		}
	}
	else if (season == 3) { //겨울
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map_nutrient[i][j] += map_S2D2[i][j];
			}
		}
	}

}

void solve() {

	for (int i = 0; i < k; i++){
		fill(&map_dead_tree[0][0], &map_dead_tree[n - 1][n - 1] + 1, 0);
		for (int j = 0; j < 4; j++) { // 0봄 여름, 1가을, 2겨울
			season_simul(j);
		}
	}

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			ans += map_tree[i][j].size();
		}
	}

	cout << ans;
}

int main() {
	

	cin >> n >> m >> k;

	fill(&map_nutrient[0][0], &map_nutrient[n - 1][n - 1] + 1, 5);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map_S2D2[i][j];
		}
	}

	int x, y, z;

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		map_tree[x-1][y-1].push_back(z);
	}

	solve();
	return 0;
}