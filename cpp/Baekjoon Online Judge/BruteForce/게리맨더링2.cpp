/*
5���� ���ű�
���ű��� ������ �ּ� �ϳ� ����
�� ���ű��� ��ο���


//�߰��� ���ϴ� ������ ������ 0�� �̻��̾�� �ϰ�, 
//��� ���� ���ű��� ���Ե� �����̾�� �Ѵ�.
*/
/*d1, d2 �� 1, 
1 �� x < x + d1 + d2 �� N, 

1 �� y - d1 < y < y + d2 �� N


d1,d2
1 1
1 2
2 1

10������ 2���̴� ����Ǽ�
��ĭ���� ����Ǽ�
*/
//���ĭ�� ��ȸ�Ҷ����� 10���� 2�� �̴� ������ ����� ���� ����� 

//���ĭ���� 10P2�� d1,d2 ���Ѵ�.
//���� d1,d2�� ���ǿ� ���� �ʸ����
//���� ���ű��� �������� ��� �����ؾ���. -> dfs ������ count 5���� üũ
//�� �����, �׿� ���� �α��� ���ؼ� res = min(res, abs(���帹���α��� - �����α���)); 



/*
�����ؾ���
1,1 �������� �����ϸ� �� ����. 
���� ä�ﶧ �ϳ��� �������� �غ���.
�ڵ� �ִ��� ���� ������

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int map[20][20];
int check[20][20];
int n;
int res = 1e9;
int x, y;
vector<int> v;
bool visited[11];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void dfs(int x, int y) {
	check[x][y] = 5;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
		if (check[nx][ny] == 5) continue;
		check[nx][ny] = 5;
		dfs(nx, ny);
	}
}

bool isOut(int x, int y) {
	if (x >= n || x < 0 || y >= n || y < 0) 
		return true;
	return false;
}

void makeMapAndCheck(int d1, int d2) {
	//1�� 1 �� r < x+d1, 1 �� c �� y
	for (int i = 0; i < x + d1; i++) {
		for (int j = 0; j <= y; j++) {
			if (isOut(i, j)) return;
			check[i][j] = 1;
		}
	}
	
	//2�� 1 �� r �� x+d2, y < c �� N
	for (int i = 0; i <= x + d2; i++) {
		for (int j = y+1; j <= n-1; j++) {
			if (isOut(i, j)) return;
			check[i][j] = 2;
		}
	}
	
	//3�� x+d1 �� r �� N, 1 �� c < y-d1+d2
	for (int i = x+d1; i <= n-1; i++) {
		for (int j = 0; j < y-d1+d2; j++) {
			if (isOut(i, j)) return;
			check[i][j] = 3;
		}
	}
	
	//4�� x+d2 < r �� N, y-d1+d2 �� c �� N
	for (int i = x+d2+1; i <= n-1; i++) {
		for (int j = y-d1+d2; j <= n-1; j++) {
			if (isOut(i, j)) return;
			check[i][j] = 4;
		}
	}

	//5��
	check[x][y] = 5; // /
	int tmp_x = x, tmp_y = y;
	while (1) {
		tmp_x++;
		tmp_y--;
		if (isOut(tmp_x, tmp_y)) return;
		check[tmp_x][tmp_y] = 5;
		if (tmp_x == x + d1 && tmp_y == y - d1)
			break;
	}
	
	tmp_x = x, tmp_y = y; // �»� �밢
	while (1) {
		tmp_x++;
		tmp_y++;
		if (isOut(tmp_x, tmp_y)) return;
		check[tmp_x][tmp_y] = 5;
		if (tmp_x == x + d2 && tmp_y == y + d2)
			break;
	}
	
	tmp_x = x+d1, tmp_y = y-d1;
	
	while (1) {
		tmp_x++;
		tmp_y++;
		if (isOut(tmp_x, tmp_y)) return;
		check[tmp_x][tmp_y] = 5;
		if (tmp_x == x + d1+d2 && tmp_y == y - d1+d2)
			break;
	}
	
	tmp_x = x+d2, tmp_y = y+d2;
	while (1) {
		tmp_x++;
		tmp_y--;
		if (isOut(tmp_x, tmp_y)) return;
		check[tmp_x][tmp_y] = 5;
		if (tmp_x == x + d2+d1 && tmp_y == y + d2- d1)
			break;
	}

	dfs(x+1, y);

	check[x][y] = 5; 
	tmp_x = x, tmp_y = y;
	while (1) {
		tmp_x++;
		tmp_y--;
		if (isOut(tmp_x, tmp_y)) return;
		if (tmp_x == x + d1 && tmp_y == y - d1)
			break;
		dfs(tmp_x + 1, tmp_y);
	}

	tmp_x = x, tmp_y = y; // �»� �밢
	while (1) {
		tmp_x++;
		tmp_y++;
		if (isOut(tmp_x, tmp_y)) return;
		if (tmp_x == x + d2 && tmp_y == y + d2)
			break;
		dfs(tmp_x + 1, tmp_y);
	}

	int nums[5] = { 0,0,0,0,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(check[i][j]==1){
				nums[0]+=map[i][j];
			}
			else if (check[i][j] == 2) {
				nums[1] += map[i][j];
			}
			else if (check[i][j] == 3) {
				nums[2] += map[i][j];
			}
			else if (check[i][j] == 4) {
				nums[3] += map[i][j];
			}
			else if (check[i][j] == 5 ) {
				nums[4] += map[i][j];
			}
		}
	}

	sort(nums, nums + 5);
	res = min(res, abs(nums[0] - nums[4]));
}

void permutaion() {
	if (v.size() == 2) {
		memset(check, 0, sizeof(check));
		makeMapAndCheck(v[0], v[1]);
		return;
	}

	for (int i = 1; i <= 10; i++) {
		v.push_back(i);
		permutaion();
		v.pop_back();
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x = i, y = j;
			memset(visited, 0, sizeof(visited));
			permutaion();
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	solve();
	printf("%d",res);
	return 0;
}