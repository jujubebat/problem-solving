#include<iostream> 
using namespace std;

int c, h, w;
const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool set(int map[][20], int x, int y, int type, int delta) {
	bool flag = true;

	for (int i = 0; i < 3; i++) {
		int nx = x + coverType[type][i][0];
		int ny = y + coverType[type][i][1];
		
		if (nx >= h || nx < 0 || ny >= w || ny < 0)
			flag = false;
		else if ((map[nx][ny] += delta) > 1)
			flag = false;
	}

	return flag;
}

int cover(int map[][20]) {
	int x = -1, y = -1;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 0) {
				x = i, y = j;
				break;
			}
		}
		if (x != -1)
			break;
	}

	if (x == -1) return 1;
	int ret = 0;

	for (int type = 0; type < 4; type++) {
		if (set(map, x, y, type, 1))
			ret += cover(map);
		set(map, x, y, type, -1);
	}

	return ret;
}

int main() {

	cin >> c;

	for (int t = 0; t < c; t++) {
		int map[20][20];
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char ch;
				cin >> ch;
				if (ch == '#') map[i][j] = 1;
				else if (ch == '.') map[i][j] = 0;
			}
		}
		cout << cover(map) << endl;
	}
}