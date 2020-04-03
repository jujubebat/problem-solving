#include<iostream>
#include<vector>
using namespace std;

typedef struct {
	int num, x, y;
	char d;
}robot;

typedef struct {
	int num; 
	char op;
	int count;
}operation;

vector<operation> operatinos;
vector<robot> robots;
int a, b, n, m;
bool resFlag = true;
char dir[] = { 'E','S','W','N' }; // µ¿ ³² ¼­ ºÏ
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int map[100][100];

void simulation(int Robotnum, char op) {

	int curDir;
	int nx, ny;

	int x = robots[Robotnum].x, y = robots[Robotnum].y;
	for (int i = 0; i < 4; i++) {
		if (dir[i] == robots[Robotnum].d) {
			curDir = i;
		}
	}

	if (op == 'L') {
		int nIdx = curDir - 1;
		if (nIdx < 0) nIdx = 3;
		robots[Robotnum].d = dir[nIdx];
	}
	else if (op == 'R') {
		int nIdx = (curDir + 1) % 4;
		robots[Robotnum].d = dir[nIdx];
	}
	else if (op == 'F') {
		nx = x + dx[curDir], ny = y + dy[curDir];
		if (nx >= b || nx < 0 || ny >= a || ny < 0) {
			printf("Robot %d crashes into the wall", Robotnum + 1);
			resFlag = false;
			return;
		}

		if (map[nx][ny]) {
			printf("Robot %d crashes into robot %d", Robotnum + 1, map[nx][ny]+1);
			resFlag = false;
			return;
		}

		map[nx][ny] = Robotnum;
		map[x][y] = 0;
		robots[Robotnum].x = nx, robots[Robotnum].y = ny;
	}
}

void solve() {
	for (int i = 0; i < operatinos.size(); i++) {
		int Robotnum = operatinos[i].num, count = operatinos[i].count;
		char op = operatinos[i].op;
		for (int j = 0; j < count; j++) {
			if (!resFlag) return;
			simulation(Robotnum, op);
		}
	}
}

int main() {
	cin >> a >> b;
	cin >> n >> m;

	int num, x, y;
	char d;

	for (int i = 0; i < n; i++) { //·Îº¿ÀÔ·Â
		cin >> y >> x >> d;

		x -= 1, y -= 1; //ÁÂÇ¥º¯È¯
		x *= -1;
		x += b-1, y += 0;

		map[x][y] = i;
		robots.push_back({ i, x, y, d });
	}

	int count;
	char op;

	for (int i = 0; i < m; i++) { // ¸í·É¾î
		cin >> num >> op >> count;
		operatinos.push_back({ num-1, op, count });
	}

	solve();

	if (resFlag)
		cout << "OK";

	return 0;
}

