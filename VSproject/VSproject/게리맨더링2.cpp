/*
5개의 선거구
선거구는 구역을 최소 하나 포함
한 선거구는 모두연결


//중간에 통하는 인접한 구역은 0개 이상이어야 하고, 
//모두 같은 선거구에 포함된 구역이어야 한다.
*/
/*d1, d2 ≥ 1, 
1 ≤ x < x + d1 + d2 ≤ N, 

1 ≤ y - d1 < y < y + d2 ≤ N


d1,d2
1 1
1 2
2 1

10개에서 2개뽑는 경우의수
매칸마다 경우의수
*/
//모든칸을 조회할때마다 10에서 2를 뽑는 순열을 경우의 수를 만들어 

//모든칸마다 10P2로 d1,d2 구한다.
//구한 d1,d2로 조건에 따라 맵만들고
//같은 선거구의 구역들은 모두 인접해야함. -> dfs 돌려서 count 5인지 체크
//맵 만들면, 그에 따른 인구수 구해서 res = min(res, abs(가장많은인구수 - 적은인구수)); 



/*
복기해야함
1,1 기준으로 생각하면 더 편함. 
맵을 채울때 하나의 포문으로 해보기.
코드 최대한 쉽게 만들어보기

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
	//1번 1 ≤ r < x+d1, 1 ≤ c ≤ y
	for (int i = 0; i < x + d1; i++) {
		for (int j = 0; j <= y; j++) {
			if (isOut(i, j)) return;
			check[i][j] = 1;
		}
	}
	
	//2번 1 ≤ r ≤ x+d2, y < c ≤ N
	for (int i = 0; i <= x + d2; i++) {
		for (int j = y+1; j <= n-1; j++) {
			if (isOut(i, j)) return;
			check[i][j] = 2;
		}
	}
	
	//3번 x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
	for (int i = x+d1; i <= n-1; i++) {
		for (int j = 0; j < y-d1+d2; j++) {
			if (isOut(i, j)) return;
			check[i][j] = 3;
		}
	}
	
	//4번 x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
	for (int i = x+d2+1; i <= n-1; i++) {
		for (int j = y-d1+d2; j <= n-1; j++) {
			if (isOut(i, j)) return;
			check[i][j] = 4;
		}
	}
	



	//5번
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
	
	tmp_x = x, tmp_y = y; // 좌상 대각
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

	check[x][y] = 5; // /
	tmp_x = x, tmp_y = y;
	while (1) {
		tmp_x++;
		tmp_y--;
		if (isOut(tmp_x, tmp_y)) return;
		if (tmp_x == x + d1 && tmp_y == y - d1)
			break;
		dfs(tmp_x + 1, tmp_y);
	}

	tmp_x = x, tmp_y = y; // 좌상 대각
	while (1) {
		tmp_x++;
		tmp_y++;
		if (isOut(tmp_x, tmp_y)) return;
		if (tmp_x == x + d2 && tmp_y == y + d2)
			break;
		dfs(tmp_x + 1, tmp_y);
	}


	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] != 5) {
				int c = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
					if (check[nx][ny] == 5)
						c++;
				}
				if (c == 4)
					check[i][j] = 5;
			}
				
		}
	}*/
	//선거구 완성
	
	/*cout << "x: " <<x << "y: "<<y << endl;
	cout << "d1: " << d1 << "d2: " << d2 << endl;
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(check[i][j]==5)
				cout << check[i][j] << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	



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
		//if (!visited[i]) {
			//visited[i] = true;
			v.push_back(i);
			permutaion();
			v.pop_back();
			//visited[i] = false;
		//}
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