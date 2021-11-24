#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int n, m, k;
int map_nutrient[10][10]; //��и�
int map_S2D2[10][10]; //�κ��� �ִ� ��и�
vector<int> map_tree[10][10]; //������
int ans = 0;

int dx[] = { -1,1,0,0,-1,-1,1,1 }, dy[] = { 0,0,-1,1,-1,1,-1,1 };
int map_dead_tree[10][10];

void season_simul(int season) {
	if (season == 0) { //��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map_tree[i][j].size() == 0) continue;
				sort(map_tree[i][j].begin(), map_tree[i][j].end());

				for (int k = 0; k < map_tree[i][j].size(); k++) {
					if (map_nutrient[i][j] >= map_tree[i][j][k]) {//��иԱ�
						map_nutrient[i][j] -= map_tree[i][j][k];
						map_tree[i][j][k]++;
					}
					else { //����� ���Դ´ٸ� ���δ�. 
						map_dead_tree[i][j] += map_tree[i][j][k] / 2;
						map_tree[i][j].erase(map_tree[i][j].begin()+k);
						k -= 1; //���Ҹ� �ϳ� �����������Ƿ�, �ε��� ���� ���� �ϳ� ���δ�.
					}
				}
			}
		}
	}
	else if (season == 1) { //����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map_nutrient[i][j] += map_dead_tree[i][j];
			}
		}
	}
	else if (season == 2) { //����
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
	else if (season == 3) { //�ܿ�
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
		for (int j = 0; j < 4; j++) { // 0�� ����, 1����, 2�ܿ�
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