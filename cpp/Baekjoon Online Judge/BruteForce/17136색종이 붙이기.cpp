#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int source_map[10][10];
int res = 1e9;
bool visited[6][6][6][6][6];
int a[5] = { 5,5,5,5,5 };

bool check(int map[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1)
				return false;
		}
	}
	return true;
}

void dfs(int map[][10],int cnt) {

	if (check(map)) {
		res = min( res, 25 - (a[0] + a[1] + a[2] + a[3] + a[4]));
		return;
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (map[i][j]) {
				int tmp_map[10][10];

				for (int k = 0; k < 5; k++) {
					
					bool flag = false;
					if (i + k >= 10 || j + k >= 10) continue;

					memcpy(tmp_map, map, sizeof(tmp_map));
					
					for (int x = i; x <= i + k; x++) {
						for (int y = j; y <= j + k; y++) {
							if (tmp_map[x][y])
								tmp_map[x][y] = 0;
							else {
								flag = true;
								break;
							}
						}
						if (flag) break;
					}

					if (flag) continue;
					
					a[k]--;
					if(a[k] >= 0)
						dfs(tmp_map,cnt+1);
					a[k]++;
				}
				return;
			}
		}
	}
}

int main(){

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> source_map[i][j];
		}
	}

	dfs(source_map,0);

	if (res == 1e9)
		cout << -1;
	else
		cout << res;

	return 0;
}