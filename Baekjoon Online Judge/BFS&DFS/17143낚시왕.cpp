#include<iostream>
#include<cstring>
using namespace std;

typedef struct {
	int s, d, z;
}shark;

int r, c, m;
shark map[100][100];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 }; //»ó,ÇÏ,¿ì,ÁÂ

void solve() {
	int sum = 0;
	for (int y = 0; y < c; y++) { //³¬½Ã¿Õ ¿­ ÀÌµ¿
		shark tmpMap[100][100] = { 0 };

		for (int x = 0; x < r; x++) { //³¬½Ã¿ÕÀÌ ³¬½Ã¸¦ ÇÑ´Ù. 
			if (map[x][y].z) {
				sum += map[x][y].z;
				map[x][y] = { 0,0,0 };
				break;
			}
		}

		for (int i = 0; i < r; i++) { //»ó¾îÀÌµ¿
			for (int j = 0; j < c; j++) {
				if (map[i][j].z) {
					if (map[i][j].d < 2) {
						int s = map[i][j].s % ((r - 1) * 2);
						int d = map[i][j].d;
						int nx = i;
						while (s--) {
							if (nx == 0 && d == 0) d = 1;
							if (nx == r - 1 && d == 1) d = 0;
							nx += dx[d];
						}
						if (map[i][j].z > tmpMap[nx][j].z)
							tmpMap[nx][j] = { map[i][j].s, d, map[i][j].z };
					}
					else {
						int s = map[i][j].s % ((c - 1) * 2);
						int d = map[i][j].d;
						int ny = j;
						while (s--) {
							if (ny == 0 && d == 3) d = 2;
							if (ny == c - 1 && d == 2) d = 3;
							ny += dy[d];
						}
						if (map[i][j].z > tmpMap[i][ny].z)
							tmpMap[i][ny] = { map[i][j].s, d, map[i][j].z };
					}
				}
			}
		}
		memcpy(map, tmpMap, sizeof(tmpMap));
	}
	cout << sum;
}

int main() {
	cin >> r >> c >> m;

	while (m--) { //»ó¾î m¸¶¸® ÀÔ·Â
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		map[x - 1][y - 1] = { s, d - 1, z };
	}
	solve();
	return 0;
}

